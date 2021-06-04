
#include "Poseidon.h"


// Round key add, state[i] ^= c[i]
static void AddRoundKey(Fr state[], const Fr c[], uint64_t len)
{
	uint64_t i = 0;

	//printf("Running add round key!\n");
	for (i = 0; i < len; i++)
	{
		//printf("Round [%d], constant = ", i);
		//HexPrintInBigNum(c[i].u8, FR_SIZE);

		FrAdd(&state[i], &c[i], &state[i]);
	}
}

// Sbox substitution, Sbox(x) = x^5 % N
static void SubWords(Fr state[], uint64_t len, uint64_t fullRounds, uint64_t partialRounds, uint64_t idx)
{
	uint64_t i = 0;
	Fr aux = { 0 };
	Fr* pX = NULL;
	uint64_t halfFullRounds = fullRounds / 2;

	for (i = 0; i < len; i++)
	{
		FrIntoMontg(state + i, state + i);
	}

	if (idx < halfFullRounds || idx >= (halfFullRounds + partialRounds))
	{
		//printf("Running full round for sbox!\n");
		for (i = 0; i < len; i++)
		{
			//printf("Full round[%d]\n", i);
			
			// X = X^5
			pX = &state[i];
			//FrPrint(pX);
			FrCopy(&aux, pX);
			FrSquare(pX, pX);
			//FrPrint(pX);
			FrSquare(pX, pX);
			//FrPrint(pX);
			FrMul(pX, &aux, pX);
			//FrPrint(pX);
		}
	}
	else
	{
		//printf("Running partial round for sbox!\n");
		// X = X^5
		pX = &state[0];
		FrCopy(&aux, pX);
		FrSquare(pX, pX);
		FrSquare(pX, pX);
		FrMul(pX, &aux, pX);
	}

	for (i = 0; i < len; i++)
	{
		FrFromMontg(state + i, state + i);
	}
}

// Mix column, M*state
static void MixLayer(Fr state[], uint64_t len, const Fr m[9][9])
{
	uint64_t i = 0, j = 0;
	Fr newState[8] = { 0 };
	Fr mij = { 0 };
	
	// M: t*t matrix
	// state: t*1 matrix, just a column vector
	// C: t*1 matrix, the same as state
	// t is the size
	//        M     *    state = C           
	//A00 A01 A02 A03 A04  B0  C0
	//A10 A11 A12 A13 A14  B1  C1a
	//A20 A21 A22 A23 A24  B2  C2
	//A30 A31 A32 A33 A34  B3  C3
	//A40 A41 A42 A43 A44  B4  C4
	//printf("Running mix column layer!\n");

	for (i = 0; i < len; i++)
	{
		FrIntoMontg(state + i, state + i);
	}

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			FrCopy(&mij, &m[i][j]);
			//FrPrint(&mij);
			//FrPrint(&state[j]);
			FrMul(&mij, &state[j], &mij);
			//FrPrint(&mij);
			FrAdd(&newState[i], &mij, &newState[i]);
			//FrPrint(&newState[i]);
			//puts("");
		}
	}

	for (i = 0; i < len; i++)
	{
		FrCopy(&state[i], &newState[i]);
	}

	//for (i = 0; i < len; i++)
	//{
	//	FrFromMontg(state + i, state + i);
	//}
}

// Input Fr[len], Output one Fr, len <= PARTIAL_ROUND_LEN
void PoseidonHash(Fr input[], uint64_t len, Fr* output)
{
	uint64_t i = 0;
	uint64_t t = len + 1;    // Width of Merkle Tree
	uint64_t offset = 0;
	uint64_t totalR = 0;
	POSEIDON_CTX ctx = { 0 };
	const Fr *pCt = NULL;          // Point to the Round Constant
	const Fr **pMt = NULL;         // Point to the MDS matrix

	if (!input || !output || len == 0 || len >= (PARTIAL_ROUND_LEN - 1))
	{
		return;
	}

	// M --> Security levels
	ctx.len = t;    // t --> Merkle Tree arity
	ctx.fullR = ROUND_FULL;               // 8
	ctx.partialR = g_RoundPartial[t - 2]; // 2-arity  => 57
	totalR = ctx.fullR + ctx.partialR;    // 2-arity  =>8+57=65
	
	//FrIntoMontg(ctx.state + 0, ctx.state + 0);
	for (i = 0; i < len; i++)
	{
		//FrIntoMontg(ctx.state + i + 1, input + i);
		FrCopy(ctx.state + i + 1, input + i);
	}

	printf("Input fr element len = %d\n", len);
	printf("Full round number = %d\n", ctx.fullR);
	printf("Partial round number = %d\n", ctx.partialR);

	MyPrintLine();
	MyPrint("Initial state:");
	FrPrintArr(ctx.state, ctx.len);


	pCt = g_ConstC[t - 2];     // 2-arity  => g_ConstC[1]
	pMt = g_ConstM[t - 2];     // 2-arity  => g_ConstM[1]
	for (i = 0; i < totalR; i++)
	{
		offset = i * t;        // 2-arity  => i * 3 

		//printf("Round [%d]\n", i);
		//MyPrint("state:");
		//FrPrintArr(ctx.state, ctx.len);

		AddRoundKey(ctx.state, pCt + offset, ctx.len);

		//MyPrint("After ARK, state:");
		//FrPrintArr(ctx.state, ctx.len);

		SubWords(ctx.state, ctx.len, ctx.fullR, ctx.partialR, i);

		//MyPrint("After Sbox, state:");
		//FrPrintArr(ctx.state, ctx.len);
		//puts("");

		MixLayer(ctx.state, ctx.len, pMt);
		//MixLayer2(ctx.state, ctx.len, pMt);

		//MyPrint("After Mix column, state:");
		//FrPrintArr(ctx.state, ctx.len);

		//puts("");
		//break; // For debug
	}

	FrCopy(output, &(ctx.state[0]));
}


// r = x^5
static void QuinticForSBox(Fr* r, const Fr* x)
{
	Fr t = { 0 };
	Fr y = { 0 };

	FrSquareV2(x, &t);    // t = x^2
	FrSquareV2(&t, &t);   // t = x^4
	FrMulV2(&t, x, &y);   // y = x^5
	FrCopy(r, &y);
}

static void RoundProductMds(PPOSEIDON_RUNTIME_CTX ctx)
{
	uint32_t sparseOffset = ctx->halfFullRounds - 1;
	uint32_t idx = 0;
	uint32_t off = 0;

	do
	{
		if (ctx->currRound == sparseOffset)
		{
			VecMulMatrix(ctx->state, ctx->preSparseMatrix, ctx->stateTmp, ctx->width);

			//MyPrint("currRound == sparseOffset:");
			//MyPrint("state:");
			//FrPrintArrEx(ctx->state, ctx->width);

			//MyPrint("preSM:");
			//FrPrintMatrixEx(ctx->preSparseMatrix, ctx->width);

			//MyPrint("newState:");
			//FrPrintArrEx(ctx->stateTmp, ctx->width);
		}
		else
		{
			off = ctx->halfFullRounds + ctx->partialRounds;
			if (ctx->currRound > sparseOffset && ctx->currRound < off)
			{
				idx = ctx->currRound - sparseOffset - 1;
				VecMulSparseMatrix(ctx->state, ctx->sparseMatrices + idx, ctx->stateTmp, ctx->width);
			}
			else
			{
				VecMulMatrix(ctx->state, ctx->mds.m, ctx->stateTmp, ctx->width);
			}
		}

		FrCopyArr(ctx->state, ctx->stateTmp, ctx->width);

	} while (0);

}

static void RunFullRound(PPOSEIDON_RUNTIME_CTX ctx, bool isLastRound)
{
	uint64_t i = 0;
	Fr t = { 0 };
	const Fr* crc = NULL;

	if (isLastRound)
	{
		for (i = 0; i < ctx->width; i++)
		{
			QuinticForSBox(ctx->state + i, ctx->state + i); // t = state[i]^5
		}
	}
	else
	{
		crc = ctx->compressedRoundConst + ctx->crcRoundOffset;
		for (i = 0; i < ctx->width; i++)
		{
			QuinticForSBox(&t, ctx->state + i); // t = state[i]^5
			FrAdd(&t, crc + i, ctx->state + i); // state[i] = t + crc[i]
		}
		ctx->crcRoundOffset += ctx->width;
	}

	// Round product mds matrix
	RoundProductMds(ctx);
}

static void RunPartialRound(PPOSEIDON_RUNTIME_CTX ctx)
{
	Fr t = { 0 };
	const Fr* crc = NULL;

	crc = ctx->compressedRoundConst + ctx->crcRoundOffset;

	QuinticForSBox(&t, ctx->state + 0); // t = state[0]^5
	FrAdd(&t, crc, ctx->state + 0); // state[0] = t + crc[0]

	ctx->crcRoundOffset += 1;

	// Round product mds matrix
	RoundProductMds(ctx);
}

// Generate constants for Poseidon hash
// Success return the context, failed return NULL
PPOSEIDON_RUNTIME_CTX GetPoseidonRuntimeCtx(uint32_t arity, Fr* tag)
{
	bool bRes = false;
	bool bRet = false;
	uint32_t i = 0;
	uint32_t size = 0;
	uint32_t rcSize = 0;
	PPOSEIDON_RUNTIME_CTX ctx = NULL;

	do
	{
		size = sizeof(POSEIDON_RUNTIME_CTX);
		ctx = (PPOSEIDON_RUNTIME_CTX)malloc(size);
		if (!ctx)
		{
			break;
		}
		Memset(ctx, 0, size);

		ctx->arity = arity;
		ctx->width = arity + 1;
		ctx->state = FrArrMalloc(ctx->width * 2);
		if (!ctx->state)
		{
			break;
		}
		ctx->stateTmp = FrGetMatrixRowOffset(ctx->state, 1, ctx->width);
		FrArrReset(ctx->state, ctx->width * 2);

		// Set poseidon tag
		FrCopy(&ctx->poseidonTag, tag);
		FrCopy(ctx->state, tag);


		// Get full round number and partial round number
		bRes = GetRoundNumberForArity(arity, &(ctx->fullRounds), &(ctx->partialRounds));
		if (!bRes)
		{
			break;
		}
		ctx->halfFullRounds = ctx->fullRounds / 2;

		// Alloca memory for mdss and set its width
		bRes = MdssAlloc(ctx->width, &(ctx->mds));
		if (!bRes)
		{
			break;
		}

		// Generate mds matrix by the [width] parameter
		bRes = CreateMdsMatrices(&(ctx->mds));
		if (!bRes)
		{
			break;
		}

		// Generate round constants
		rcSize = (ctx->fullRounds + ctx->partialRounds) * ctx->width;
		ctx->roundConstant = FrArrMalloc(rcSize);
		if (!ctx->roundConstant)
		{
			break;
		}
		ctx->roundConstSize = rcSize;

		GenRoundConstant(1, 1, 255, ctx->width, ctx->fullRounds, ctx->partialRounds, ctx->roundConstant, &rcSize);
		if (ctx->roundConstSize != rcSize)
		{
			break;
		}

		// Generate compressed round constants
		rcSize = ctx->fullRounds * ctx->width + ctx->partialRounds;
		ctx->compRoundConstSize = rcSize;
		ctx->compressedRoundConst = FrArrMalloc(rcSize);
		if (!ctx->compressedRoundConst)
		{
			break;
		}
		bRes = CompressRoundConstant(ctx->width, ctx->fullRounds, ctx->partialRounds, 
			ctx->roundConstant, ctx->mds.m, ctx->partialRounds, ctx->compressedRoundConst);
		if (!bRes)
		{
			break;
		}

		// Generate pre-sparse matrix and sparse matrice
		ctx->preSparseMatrix = FrMatrixMalloc(ctx->width);
		if (!ctx->preSparseMatrix)
		{
			break;
		}
		ctx->sparseMatrices = SparseMatricesMalloc(ctx->width, ctx->partialRounds);
		if (!ctx->sparseMatrices)
		{
			break;
		}
		bRes = FactorToSparseMatrix(ctx->mds.m, ctx->width, ctx->partialRounds, ctx->preSparseMatrix, ctx->sparseMatrices);
		if (!bRes)
		{
			break;
		}

		ctx->currRound = 0;

		bRet = true;

	} while (0);

	if (!bRet)
	{
		DelPoseidonRuntimeCtx(ctx);
		ctx = NULL;
	}

	return ctx;
}

// Delete Poseidon context
void DelPoseidonRuntimeCtx(PPOSEIDON_RUNTIME_CTX ctx)
{
	if (!ctx)
	{
		return;
	}

	if (ctx->state)
	{
		FrArrFree(ctx->state);
		ctx->state = NULL;
	}

	MdssFree(&ctx->mds);

	if (ctx->roundConstant)
	{
		FrArrFree(ctx->roundConstant);
		ctx->roundConstant = NULL;
	}

	if (ctx->compressedRoundConst)
	{
		FrArrFree(ctx->compressedRoundConst);
		ctx->compressedRoundConst = NULL;
	}

	if (ctx->preSparseMatrix)
	{
		FrMatrixFree(ctx->preSparseMatrix);
		ctx->preSparseMatrix = NULL;
	}

	SparseMatricesFree(ctx->sparseMatrices, ctx->partialRounds);

	Memset(ctx, 0, sizeof(POSEIDON_RUNTIME_CTX));
	free(ctx);
	ctx = NULL;
}

// Reset Poseidon context for reuse this context with the same arity
// Set the tag at the first element of [state]
void ResetPoseidonRuntimeCtx(PPOSEIDON_RUNTIME_CTX ctx)
{
	ctx->currRound = 0;
	ctx->crcRoundOffset = 0;
	FrArrReset(ctx->state, ctx->width * 2);
	FrCopy(ctx->state + 0, &ctx->poseidonTag);
}

// Input an initialized [ctx] and [input], Output one Fr [output]
// The input length is saved in [ctx->arity]
// Reference from neptune:hash_optimized_static()
void PoseidonHashV2Ex(PPOSEIDON_RUNTIME_CTX ctx, Fr* input, Fr* output)
{
	bool bRes = false;
	uint64_t i = 0;

	do
	{
		if (!input || !output)
		{
			break;
		}

		// Init the ctx state
		for (i = 0; i < ctx->arity; i++)
		{
			FrCopy(ctx->state + i + 1, input + i);
		}

		// The first round for add-round-key
		AddRoundKey(ctx->state, ctx->compressedRoundConst, ctx->width);
		ctx->crcRoundOffset += ctx->width;

		// Run half full round
		for (i = 0; i < ctx->halfFullRounds; i++)
		{
			RunFullRound(ctx, false);
			ctx->currRound++;
		}

		// Run partial round
		for (i = 0; i < ctx->partialRounds; i++)
		{
			RunPartialRound(ctx);
			ctx->currRound++;
		}

		// Run half full round minus 1
		for (i = 0; i < (ctx->halfFullRounds - 1); i++)
		{
			RunFullRound(ctx, false);
			ctx->currRound++;
		}

		// Last special full round
		RunFullRound(ctx, true);
		ctx->currRound++;

		// Return state[1] instead of standard one : state[0]
		FrCopy(output, ctx->state + 1);
		//bRet = true;

	} while (0);
}

// Input Fr[len], Output one Fr,
// Currently supported input length is: 2, 4, 8, 16, 24, 36, 11
void PoseidonHashV2Wrapper(Fr* input, uint32_t len, Fr* output)
{
	bool bRes = false;
	uint64_t i = 0;
	PPOSEIDON_RUNTIME_CTX ctx = NULL;
	uint32_t arity = 0;
	Fr tag = { 0 };

	do
	{
		if (!input || !output)
		{
			break;
		}

		arity = len;
		bRes = GeneratePoseidonTag(&tag, arity + 1);
		if (!bRes)
		{
			break;
		}

		// We can reuse the ctx
		ctx = GetPoseidonRuntimeCtx(arity, &tag);
		if (!ctx)
		{
			break;
		}

		//printf("Input fr element len = %d, full_round = %d, partial round = %d\n",
		//	arity, ctx->fullRounds, ctx->partialRounds);

		PoseidonHashV2Ex(ctx, input, output);

		//bRet = true;

	} while (0);

	DelPoseidonRuntimeCtx(ctx);
}


#define MAX_STATIC_BUFFER_SIZE (10 * 1024 * 1024)
bool GetOneTestCaseFromFile(FILE* file, Fr* input, uint32_t arity, Fr* output)
{
	bool bRet = false;
	bool bRes = false;
	bool startFlag = false;
	static char buf[MAX_STATIC_BUFFER_SIZE]; // 10MB buffer
	char* ptr = NULL;
	int retNum = 0;
	const char* startTag = "TestCase";
	int startTagLen = 0;
	uint32_t i = 0;
	char tbuf[200] = { 0 };


	startFlag = false;
	startTagLen = sizeof(startTag);
	while (true)
	{
		Memset(buf, 0, startTagLen);

		ptr = fgets(buf, MAX_STATIC_BUFFER_SIZE, file);
		if (!ptr)
		{
			break;
		}

		if (0 == strncmp(buf, startTag, startTagLen))
		{
			startFlag = true;
			break;
		}
	}

	do
	{
		if (!startFlag)
		{
			break;
		}
		
		// Get [=]
		retNum = fscanf(file, "Input %s ", tbuf);
		if (retNum < 1)
		{
			break;
		}

		// Parse input
		ptr = buf;
		Memset(tbuf, 0, sizeof(tbuf));
		Memcpy(tbuf, ptr, 66);
		bRes = true;
		for (i = 0; i < arity; i++)
		{
			Memset(tbuf, 0, sizeof(tbuf));
			retNum = fscanf(file, "%s, ", tbuf);
			if (retNum < 1)
			{
				bRes = false;
				break;
			}
			tbuf[66] = 0; // Remove [,] if it has

			bRes = FrFromHexStringInBigNum(input + i, tbuf);
			if (!bRes)
			{
				bRes = false;
				break;
			}
		}

		retNum = fscanf(file, "%s", tbuf);  // Get the [Output]
		retNum = fscanf(file, "%s", tbuf);  // Get the [=]
		//retNum = fscanf(file, "%s", tbuf);  // Get the [0xtttttttttttt...]

		if (!bRes)
		{
			break;
		}

		// Get output (Only has one element)
		Memset(tbuf, 0, sizeof(tbuf));
		retNum = fscanf(file, "%s", tbuf);
		if (retNum < 1)
		{
			break;
		}

		// Parse output
		bRes = FrFromHexStringInBigNum(output, tbuf);
		if (!bRes)
		{
			break;
		}

		bRet = true;

	} while (0);
	
	return bRet;
}

// [inFileName] save the reference input and output data
// [arity] specify the arity
void BenchPoseidon(char* inFileName, uint32_t arity)
{
	bool bRes = false;
	uint64_t i = 0;
	PPOSEIDON_RUNTIME_CTX ctx = NULL;
	Fr tag = { 0 };
	Fr* input = NULL;
	Fr output = { 0 };
	Fr standardOutput = { 0 };
	FILE* file = NULL;
	uint32_t totalTC = 0;
	uint32_t passTC = 0;
	uint32_t failTC = 0;


	do
	{
		input = FrArrMalloc(arity);
		if (!input)
		{
			break;
		}

		bRes = GeneratePoseidonTag(&tag, arity + 1);
		if (!bRes)
		{
			break;
		}

		// We can reuse the ctx
		ctx = GetPoseidonRuntimeCtx(arity, &tag);
		if (!ctx)
		{
			break;
		}

		file = fopen(inFileName, "r");
		if (!file)
		{
			break;
		}

		printf("Input fr element len = %d, full_round = %d, partial round = %d\n",
			arity, ctx->fullRounds, ctx->partialRounds);

		i = 0;
		while (true)
		{
			bRes = GetOneTestCaseFromFile(file, input, arity, &standardOutput);
			if (!bRes)
			{
				break;
			}

			totalTC++;

			ResetPoseidonRuntimeCtx(ctx);
			PoseidonHashV2Ex(ctx, input, &output);

			bRes = FrEqual(&output, &standardOutput);
			if (!bRes)
			{
				failTC++;
				printf("Test case [%d] failed!\n", i);
			}
			else
			{
				passTC++;
				printf("Test case [%d] success!\n", i);
			}
			i += 1;
		}
		
		fclose(file);
		file = NULL;

		printf("Total test [%d] cases, [%d] pass and [%d] failed!\n", totalTC, passTC, failTC);

		//bRet = true;

	} while (0);

	DelPoseidonRuntimeCtx(ctx);
}


// Naive implemenation of running full round
static void RunFullRoundNaive(PPOSEIDON_RUNTIME_CTX ctx)
{
	uint64_t i = 0;
	const Fr* RC = NULL;
	
	
	RC = ctx->roundConstant + ctx->crcRoundOffset;
	AddRoundKey(ctx->state, RC, ctx->width);
	
	for (i = 0; i < ctx->width; i++)
	{
		QuinticForSBox(ctx->stateTmp + i, ctx->state + i); // t = state[i]^5
	}

	ctx->crcRoundOffset += ctx->width;
	
	// Round product mds matrix
	VecMulMatrix(ctx->stateTmp, ctx->mds.m, ctx->state, ctx->width);
}

// Naive implemenation of running partial round
static void RunPartialRoundNaive(PPOSEIDON_RUNTIME_CTX ctx)
{
	const Fr* RC = NULL;

	RC = ctx->roundConstant + ctx->crcRoundOffset;
	AddRoundKey(ctx->state, RC, ctx->width);
	ctx->crcRoundOffset += ctx->width;

	QuinticForSBox(ctx->state + 0, ctx->state + 0); // t = state[0]^5
	FrCopyArr(ctx->stateTmp, ctx->state, ctx->width);

	// Round product mds matrix
	VecMulMatrix(ctx->stateTmp, ctx->mds.m, ctx->state, ctx->width);
}

// Input an initialized [ctx] and [input], Output one Fr [output]
// The input length is saved in [ctx->arity]
// Reference from neptune:hash_correct()
void PoseidonHashV2Naive(PPOSEIDON_RUNTIME_CTX ctx, Fr* input, Fr* output)
{
	bool bRes = false;
	uint64_t i = 0;

	do
	{
		if (!input || !output)
		{
			break;
		}

		// Init the ctx state
		for (i = 0; i < ctx->arity; i++)
		{
			FrCopy(ctx->state + i + 1, input + i);
		}

		//MyPrint("Before running full round:");
		//MyPrint("state:");
		//FrPrintArrEx(ctx->state, ctx->width);

		// Run half full round
		for (i = 0; i < ctx->halfFullRounds; i++)
		{
			RunFullRoundNaive(ctx);

			//printf("After full round1 [%d]\n", i);
			//MyPrint("state:");
			//FrPrintArrEx(ctx->state, ctx->width);
		}

		// Run partial round
		for (i = 0; i < ctx->partialRounds; i++)
		{
			RunPartialRoundNaive(ctx);

			//printf("After partial round [%d]\n", i);
			//MyPrint("state:");
			//FrPrintArrEx(ctx->state, ctx->width);

		}

		// Run half full round
		for (i = 0; i < ctx->halfFullRounds; i++)
		{
			RunFullRoundNaive(ctx);

			//printf("After full round2 [%d]\n", i);
			//MyPrint("state:");
			//FrPrintArrEx(ctx->state, ctx->width);
		}

		// Return state[1] instead of standard one : state[0]
		FrCopy(output, ctx->state + 1);

	} while (0);
}

// Input Fr[len], Output one Fr,
// Currently supported input length is: 2, 4, 8, 16, 24, 36, 11
void PoseidonHashV2NaiveWrapper(Fr* input, uint32_t len, Fr* output)
{
	bool bRes = false;
	uint64_t i = 0;
	PPOSEIDON_RUNTIME_CTX ctx = NULL;
	uint32_t arity = 0;
	Fr tag = { 0 };

	do
	{
		if (!input || !output)
		{
			break;
		}

		arity = len;
		bRes = GeneratePoseidonTag(&tag, arity + 1);
		if (!bRes)
		{
			break;
		}

		// We can reuse the ctx
		ctx = GetPoseidonRuntimeCtx(arity, &tag);
		if (!ctx)
		{
			break;
		}

		//printf("Input fr element len = %d, full_round = %d, partial round = %d\n",
		//	arity, ctx->fullRounds, ctx->partialRounds);

		PoseidonHashV2Naive(ctx, input, output);

		//bRet = true;

	} while (0);

	DelPoseidonRuntimeCtx(ctx);
}




// Generate round constants and save result to [out],
// If the input buffer [out] has no enough size, return the needed size in [outlen]
// And return false, otherwise, return ture
bool GenRoundConstantDemo(Fr out[], uint32_t* outlen)
{
	bool bRet = false;
	uint8_t   field = 1;          //  2 bits bi,  0  <= i <= 1, //  field = 1 --> x^5
	uint8_t   sbox = 1;           //  4 bits bi,  2  <= i <= 5, //  sbox = 1  --> Gf(p)
	uint32_t  field_size = 255;   // 12 bits bi,  6  <= i <= 17
	uint32_t  t = 9;              // 12 bits bi,  18 <= i <= 29, t=9 for 8-arity input
	uint32_t  r_f = 8;            // 10 bits bi,  30 <= i <= 39
	uint32_t  r_p = 57;           // 10 bits bi,  40 <= i <= 49
	ROUND_STATE_CTX ctx;

	uint8_t bv = 0;
	uint32_t i = 0;
	uint32_t idx = 0;
	Fr tmpFr = { 0 };
	uint32_t numConst = (r_f + r_p) * t;
	uint32_t elemBytes = field_size / 8 + ((field_size % 8) > 0);
	uint32_t elemBits = elemBytes * 8;
	static uint8_t buf[MAX_FIELD_ELEM_BYTES + 2];  // Max number of bytes for each element in the field

	
	if (*outlen < numConst)
	{
		*outlen = numConst;
		return false;
	}

	*outlen = numConst;
	InitGenRoundConstantCtx(&ctx, field, sbox, field_size, t, r_f, r_p);

	for (i = 0; i < numConst; i++)
	{
		while (true)
		{
			GenNextByteBufEx(&ctx, buf, elemBits);
			FrReadFromBe(&tmpFr, buf);
			if (FrIsValid(&tmpFr))
			{
				FrCopy(out + i, &tmpFr);
				break;
			}
		}
	}

	bRet = true;
	return bRet;
}

// R[w] = M[w][w] * V[w]
// w: width of matrix
// M: w*w matrix
// V: column vector with w elements
// R: column vector with w elements
// V and R should not point to the same vector
bool ProductMatrix(const Fr* M, const Fr* V, Fr* R, uint64_t w)
{
	bool bRet = false;
	uint64_t i = 0;
	uint64_t j = 0;
	Fr tmp = { 0 };
	Fr sum = { 0 };
	Fr* pMi = NULL;

	if (!M || !V || !R)
	{
		return false;
	}

	for (i = 0; i < w; i++)
	{
		FrZero(&tmp);
		FrZero(&sum);
		pMi = M + i * w;
		for (j = 0; j < w; j++)
		{
			FrMul(pMi + j, &V[j], &tmp);     // tmp = M[i][j] * V[j];
			FrAdd(&sum, &tmp, &sum);         // sum += tmp;
		}
		FrCopy(&R[i], &sum);
	}

	bRet = true;
	return bRet;
}

// field       //  2 bits bi,  0  <= i <= 1,  //  field = 1 --> x^5
// sbox        //  4 bits bi,  2  <= i <= 5,  //  sbox  = 1 --> Gf(p)
// field_size  // 12 bits bi,  6  <= i <= 17
// t           // 12 bits bi,  18 <= i <= 29, // t=9 for 8-arity input
// r_f         // 10 bits bi,  30 <= i <= 39
// r_p         // 10 bits bi,  40 <= i <= 49
uint64_t GenRoundConstant(uint8_t field, uint8_t sbox, uint32_t field_size, uint32_t t, uint32_t r_f, uint32_t r_p, Fr out[], uint32_t* outlen)
{
	uint64_t ret = 0;
	uint32_t i = 0;
	Fr tmpFr = { 0 };
	ROUND_STATE_CTX ctx = { 0 };
	uint32_t numConst = (r_f + r_p) * t;
	static uint8_t buf[MAX_FIELD_ELEM_BYTES + 2];  // Max number of bytes for each element in the field


	if (*outlen < numConst)
	{
		*outlen = numConst;
		return 0;
	}

	*outlen = numConst;
	InitGenRoundConstantCtx(&ctx, field, sbox, field_size, t, r_f, r_p);

	for (i = 0; i < numConst; i++)
	{
		while (true)
		{
			GenNextByteBufEx(&ctx, buf, field_size);
			FrReadFromBe(&tmpFr, buf);
			if (FrIsValid(&tmpFr))
			{
				//FrPrint(&tmpFr);
				//HexPrintInBigNum(tmpFr.u8, FR_SIZE);
				FrCopy(out + i, &tmpFr);
				break;
			}
			else
			{
				//puts("Got one constant, but not valid!");
			}
		}
	}

	ret = numConst;
	return ret;
}

// Compare to round constants [a] and [b],
// Return value equal to len if they are all equal
// Else return the ith unequal value
uint64_t RoundConstCmp(Fr a[], Fr b[], uint64_t len)
{
	uint64_t i = 0;

	for (i = 0; i < len; i++)
	{
		if (!FrEqual(a + i, b + i))
		{
			break;
		}
	}

	return i;
}

// Compare to MDS matrix [a] and [b],
// Return value equal to [t^2] if they are all equal
// Else return the ith unequal value
uint64_t MDSMatrixCmp(Fr* a, Fr* b, uint64_t t)
{
	uint64_t i = 0;
	uint64_t j = 0;
	uint64_t ret = 0;
	Fr* ra = NULL;
	Fr* rb = NULL;
	bool bEuqal = true;

	for (i = 0; i < t; i++)
	{
		ra = FrGetMatrixRowOffset(a, i, t);
		rb = FrGetMatrixRowOffset(b, i, t);
		for (j = 0; j < t; j++)
		{
			if (!FrEqual(ra + j, rb + j))
			{
				bEuqal = false;
				break;
			}
		}
		if (!bEuqal) break;
	}

	if (bEuqal)
	{
		ret = t * t;
	}
	else
	{
		ret = i * t + j;
	}
	
	return ret;
}

// Standard version of genrating tag
// [t] == [arity-1]
bool GeneratePoseidonTag(Fr* tag, uint32_t t)
{
	bool bRet = false;
	uint64_t tmp = 1;

	if (!tag || t < 2)
	{
		return false;
	}

	tmp <<= (t - 1);
	tmp -= 1;
	FrSet(tag, tmp);

	bRet = true;
	return bRet;
}

// Input: width * (full_rounds + partial_rounds) elements of round_constants
// Output:width * (full_rounds) + partial_rounds elements of compressed round_constants
bool CompressRoundConstant(uint32_t width, uint32_t full_rounds, uint32_t partial_rounds, const Fr* round_constants,
	const Fr* mds_matrix, uint32_t partial_preprocessed, Fr* compressed_round_constants)
{
	// Ref: neptune/src/preprocessing.rs
	bool bRet = false;
	bool bRes = false;
	Fr* mds_inv = NULL;
	uint32_t hafl_full_rounds = 0;
	uint32_t uncompressed = 0;
	uint32_t end = 0;
	uint32_t compressed_idx = 0;
	uint32_t final_round = 0;
	const Fr* final_round_key = 0;
	const Fr* previous_round_key = 0;
	uint64_t i = 0, j = 0;
	const Fr* round_key = NULL;
	const Fr* nex_round = NULL;
	Fr* round_acc = NULL;
	Fr* acc = NULL;
	Fr* partial_keys = NULL;
	uint32_t partial_key_idx = 0;
	Fr* inverted = NULL;
	uint32_t numRoundConst = 0;

	do
	{
		hafl_full_rounds = full_rounds / 2;

		mds_inv      = FrMatrixMalloc(width);
		round_acc    = FrArrMalloc(width);
		acc          = FrArrMalloc(width);
		partial_keys = FrArrMalloc(partial_rounds);
		inverted     = FrArrMalloc(width);
		if (!mds_inv || !round_acc || !acc || !partial_keys || !inverted)
		{
			break;
		}
		
		bRes = MatrixInverse(mds_matrix, width, mds_inv);
		if (!bRes)
		{
			break;
		}
		//puts("Enter function [CompressRoundConstant]!");
		//printf("Parameter: width = [%d], full_rounds = [%d], partial_rounds = [%d]\n", width, full_rounds, partial_rounds);

		//MyPrint("MDS matrix:");
		//FrPrintMatrixEx(mds_matrix, width);

		//MyPrint("Inverse of MDS matrix:");
		////FrPrintMatrix(mds_inv, width);
		//FrPrintMatrixEx(mds_inv, width);

		// First round constant not changed
		FrCopyArr(compressed_round_constants, round_constants, width);
		compressed_idx = width;

		uncompressed = partial_rounds - partial_preprocessed;
		if (uncompressed > 0)
		{
			end = hafl_full_rounds;
		}
		else
		{
			end = hafl_full_rounds - 1;
		}

		for (i = 1; i <= end; i++)
		{
			nex_round = round_constants + i * width;
			VecMulMatrix(nex_round, mds_inv, compressed_round_constants + compressed_idx, width);

			//printf("[%d] Next round:\n", i-1);
			//FrPrintArrEx(nex_round, width);

			//MyPrint("inverted:");
			//FrPrintArrEx(compressed_round_constants + compressed_idx, width);

			compressed_idx += width;
		}
		
		final_round = hafl_full_rounds + partial_rounds;
		final_round_key = round_constants + final_round * width;

		numRoundConst = (full_rounds + partial_rounds) * width;
		//printf("final_round = %d, numRoundConst = %d, partial_preprocessed = %d\n", final_round, numRoundConst, partial_preprocessed);
		//MyPrint("round_constants:");
		//FrPrintArrEx(round_constants, numRoundConst);

		FrCopyArr(acc, final_round_key, width);
		partial_key_idx = 0;
		for (i = 0; i < partial_preprocessed; i++)
		{
			previous_round_key = round_constants + (final_round - i - 1) * width;
			VecMulMatrix(acc, mds_inv, inverted, width);
			FrCopy(partial_keys + partial_key_idx, &inverted[0]);
			partial_key_idx += 1;

			//printf("[%d] acc:\n", i);
			//FrPrintArrEx(acc, width);

			//MyPrint("inverted:");
			//FrPrintArrEx(inverted, width);

			//MyPrint("previous_round_key:");
			//FrPrintArrEx(previous_round_key, width);

			FrZero(&inverted[0]);
			VecAddVec(previous_round_key, inverted, acc, width);
		}
		FrCopyArr(round_acc, acc, width);
		//MyPrint("round_acc:");
		//FrPrintArrEx(round_acc, width);

		// Debug
		if (partial_preprocessed == 1)
		{
			;
		}

		for (i = 1; i < uncompressed; i++)
		{
			round_key = round_constants + (hafl_full_rounds + i) * width;
			FrCopyArr(compressed_round_constants + compressed_idx, round_key, width);
			compressed_idx += width;
		}

		VecMulMatrix(round_acc, mds_inv, compressed_round_constants + compressed_idx, width);
		compressed_idx += width;

		//MyPrint("After adding uncompressed constant: res:");
		//FrPrintArrEx(compressed_round_constants, compressed_idx);

		// Add partial keys in reserve mode
		//FrCopyArr(compressed_round_constants + compressed_idx, partial_keys, partial_key_idx);
		//compressed_idx += partial_key_idx;
		for (i = 0; i < partial_key_idx; i++)
		{
			j = partial_key_idx - 1 - i;
			FrCopy(compressed_round_constants + compressed_idx, partial_keys + j);
			compressed_idx += 1;
		}

		//MyPrint("partial_keys:");
		//FrPrintArrEx(partial_keys, partial_key_idx);

		for (i = 1; i < hafl_full_rounds; i++)
		{
			nex_round = round_constants + (hafl_full_rounds + partial_rounds + i) * width;
			VecMulMatrix(nex_round, mds_inv, compressed_round_constants + compressed_idx, width);

			//MyPrint("Add one hafl_full_rounds: inverted:");
			//FrPrintArrEx(compressed_round_constants + compressed_idx, width);

			compressed_idx += width;
		}

		j = full_rounds * width + partial_rounds;
		if (compressed_idx != j)
		{
			//printf("Compress round constant failed with wrong compress length [%d], real result should be [%d].\n", compressed_idx, j);
			break;
		}

		bRet = true;

	} while (0);

	if (mds_inv)
	{
		FrMatrixFree(mds_inv);
		mds_inv = NULL;
	}
	if (round_acc)
	{
		FrArrFree(round_acc);
		round_acc = NULL;
	}
	if (acc)
	{
		FrArrFree(acc);
		acc = NULL;
	}
	if (partial_keys)
	{
		FrArrFree(partial_keys);
		partial_keys = NULL;
	}
	if (inverted)
	{
		FrArrFree(inverted);
		inverted = NULL;
	}

	return bRet;
}

