
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

