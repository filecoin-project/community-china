
#include "FieldOp.h"



// Global poseidon constant variables, saved in little endian mode
const Fr g_FrZero = { 0, 0, 0, 0 };
const Fr g_FrOne  = { 1, 0, 0, 0 };
const Fr g_FrTwo  = { 2, 0, 0, 0 };

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Parameters from [https://github.com/arnaucube/poseidon-rs]

//
// Poseidon hash modulur N:
// Decimal:     21888242871839275222246405745257275088548364400416034343698204186575808495617
// Hexadecimal: 0x30644e72e131a029b85045b68181585d2833e84879b9709143e1f593f0000001
// Fr:          0x43e1f593f0000001, 0x2833e84879b97091, 0xb85045b68181585d, 0x30644e72e131a029


// This is the modulus m of the prime field
const Fr g_FrM    = { 0x43e1f593f0000001, 0x2833e84879b97091, 0xb85045b68181585d, 0x30644e72e131a029 };
// Multiplicative generator of `MODULUS` - 1 order, also quadratic nonresidue
const Fr g_FrG    = { 0x3057819e4fffffdb, 0x307f6d866832bb01, 0x5c65ec9f484e3a89, 0x0180a96573d3d9f8 };
// -(m^{-1} mod m) mod m
const Fr g_FrInv  = { 0xc2e1f593efffffff, 0, 0, 0 };
// 2^s root of unity computed by GENERATOR^t
const Fr g_FrRoU  = { 0x9632c7c5b639feb8, 0x985ce3400d0ff299, 0xb2dd880001b0ecd8, 0x1d69070d6d98ce29 };
// 2^{limbs*64} mod m
const Fr g_FrR    = { 0xac96341c4ffffffb, 0x36fc76959f60cd29, 0x666ea36f7879462e, 0x0e0a77c19a07df2f };
// 2^{limbs*64*2} mod m   // R^2 % M
const Fr g_FrR2   = { 0x1bb8e645ae216da7, 0x53fe3ab1e35c59e3, 0x8c49833d53bb8085, 0x0216d0b17f4e44a5 };
// 2^s * t = MODULUS - 1 with t odd
const uint64_t g_S = 28;


// a = a % M
void FrSimpleReduce(Fr* a)
{
	bool bRet = false;

	while (1)
	{
		bRet = BnLower(a->u8, g_FrM.u8);
		if (bRet)
		{
			break;
		}
		BnSub(a->u8, g_FrM.u8, a->u8);
	}
}

// c = a + b % M
// a and b should be in the prime field, the result c is also in the finite field
void FrAdd(const Fr* a, const Fr* b, Fr* c)
{
	uint64_t i = 0;
	uint64_t carry = 0;

	carry = BnAdd(a->u8, b->u8, c->u8);
	if (BnLE(c->u8, g_FrM.u8))
	{
		// c = c - M
		carry = BnSub(c->u8, g_FrM.u8, c->u8);
	}
}

// c = a - b % M
// a and b should be in the prime field, the result c is also in the finite field
void FrSub(const Fr* a, const Fr* b, Fr* c)
{
	uint64_t i = 0;
	uint64_t carry = 0;
	Fr tmp;

	if (BnLE(a->u8, b->u8)) // a >= b ?
	{
		carry = BnSub(a->u8, b->u8, c->u8);
	}
	else
	{
		// c = a - b = a - b + M = M - b + a
		carry = BnSub(g_FrM.u8, b->u8, tmp.u8);
		carry = BnAdd(tmp.u8, a->u8, c->u8);
	}
}

// c = a * b % M
// Input and output are both in montgomery domain
void FrMul(const Fr* a, const Fr* b, Fr* c)
{
	FrEx res = { 0 };   // Save temp result

	//BnMul(a->u8, b->u8, res.u8);
	BnMulEx(a->u8, b->u8, res.u8);

	//BnReduce(c->u8, res.u8, g_FrM.u8);
	FrMontgReduce2(c, &res);
}

// c = a * b % M
// Input and output are both in residual domain
void FrMulV2(const Fr* a, const Fr* b, Fr* c)
{
	FrEx res = { 0 };   // Save temp result
	Fr t1 = { 0 };
	Fr t2 = { 0 };
	
	FrIntoMontg(&t1, a);
	FrIntoMontg(&t2, b);
	BnMulEx(t1.u8,t2.u8, res.u8);
	FrMontgReduce2(&t1, &res);
	FrFromMontg(c, &t1);
}

// c = a ^ 2 % M
void FrSquare(const Fr* a, Fr* c)
{
	//// Simple implementation, need to upgrade
	//FrMul(a, a, c);

	FrEx res = { 0 };   // Save temp result

	//BnMul(a->u8, b->u8, res.u8);
	BnSquareEx(a->u8, res.u8);

	FrMontgReduce2(c, &res);
}

// c = a ^ 2 % M
// Input and output are both in residual domain
void FrSquareV2(const Fr* a, Fr* c)
{
	FrEx res = { 0 };   // Save temp result
	Fr t = { 0 };

	FrIntoMontg(&t, a);
	BnSquareEx(t.u8, res.u8);
	FrMontgReduce2(&t, &res);
	FrFromMontg(c, &t);
}

// ret = a == b % M ? true : false
bool FrEqual(const Fr* a, const Fr* b)
{
	bool bRet = false;
	Fr ta, tb;

	FrCopy(&ta, a);
	FrCopy(&tb, b);

	FrSimpleReduce(&ta);
	FrSimpleReduce(&tb);

	bRet = BnEqual(ta.u8, tb.u8);

	return bRet;
}

// dst = src
void FrCopy(Fr* dst, const Fr* src)
{
	uint64_t i = 0;

	for (i = 0; i < FR_LEN; i++)
	{
		dst->u8[i] = src->u8[i];
	}
}

// Copy Fr array from [src] to [dst]
void FrCopyArr(Fr* dst, const Fr* src, uint64_t arrlen)
{
	uint64_t i = 0;

	for (i = 0; i < arrlen; i++)
	{
		FrCopy(dst + i, src + i);
	}
}

// Zero Fr
void FrZero(Fr* a)
{
	uint64_t i = 0;

	for (i = 0; i < FR_LEN; i++)
	{
		a->u8[i] = 0;
	}
}

// Print Fr element
void FrPrint(const Fr* a)
{
	uint64_t i = 0;
	uint64_t e = 0;

	for (i = 0; i < FR_LEN; i++)
	{
		e = a->u8[i];
		printf("0x%016llx, ", e);
	}
	puts("");
}

// Print Fr element in hex mode (Big number)
void FrPrintEx(const Fr* a)
{
	HexPrintInBigNum(a->u8, FR_SIZE);
}

// Print FrEx element
void FrExPrint(const FrEx* a)
{
	uint64_t i = 0;
	uint64_t e = 0;

	for (i = 0; i < FREX_LEN; i++)
	{
		e = a->u8[i];
		printf("0x%016llx, ", e);
	}
	puts("");
}

// Print Fr element as a big number in hex mode
void FrPrintAsBigNum(const Fr* a)
{
	int64_t i = 0;
	uint64_t e = 0;

	for (i = FR_LEN - 1; i >= 0 ; i--)
	{
		e = a->u8[i];
		printf("0x%016llx, ", e);
	}
	puts("");
}

// Print FrEx element as a big number in hex mode
void FrExPrintAsBigNum(const FrEx* a)
{
	int64_t i = 0;
	uint64_t e = 0;

	for (i = FREX_LEN - 1; i >= 0; i--)
	{
		e = a->u8[i];
		printf("0x%016llx, ", e);
	}
	puts("");
}

// dst = src
void FrSet(Fr* dst, uint64_t src)
{
	uint64_t i = 0;

	dst->u8[0] = src;
	for (i = 1; i < FR_LEN; i++)
	{
		dst->u8[i] = 0;
	}
}

// dst->u8[i] = src
bool FrSetWithIdx(Fr* dst, uint64_t src, uint64_t i)
{
	if (i > FR_LEN)
	{
		return false;
	}
	dst->u8[i] = src;
	return true;
}

// ret = a < M ? true : false
bool FrIsValid(const Fr* a)
{
	bool bRet = false;

	bRet = BnLower(a->u8, g_FrM.u8);

	return bRet;
}

// dst = src
void FrEx2Fr(Fr* dst, const FrEx* src)
{
	uint64_t i = 0;

	for (i = 0; i < FR_LEN; i++)
	{
		dst->u8[i] = src->u8[i];
	}
	//memcpy(dst, src, sizeof(Fr));
}

// dst = src
void Fr2FrEx(FrEx* dst, const Fr* src)
{
	uint64_t i = 0;

	for (i = 0; i < FR_LEN; i++)
	{
		dst->u8[i] = src->u8[i];
	}

	// Set high part to zero
	for (i = 0; i < FR_LEN; i++)
	{
		dst->u8[FR_LEN + i] = 0;
	}
}

// Generate a random Fr element in the prime field
void FrGenRand(Fr* dst)
{
	uint64_t i = 0;
	Fr tmp;

	get_rand_bytes(tmp.u8, FR_SIZE);

	FrSimpleReduce(&tmp);

	FrCopy(dst, &tmp);
}

// dst = src % M
// Copy from [ff_derive_const\src\const_field_element.rs]
void FrMontgReduce(Fr* dst, const FrEx* src)
{
	uint64_t i = 0;
	uint64_t j = 0;
	uint64_t t1 = 0;
	uint64_t t2 = 0;
	uint64_t k1 = 0;
	uint64_t k2 = 0;
	uint64_t lp = 0;
	uint64_t hp = 0;
	uint64_t carry = 0;
	uint64_t carry2 = 0;
	FrEx A = { 0 };
	Fr tmpFr = { 0 };

	BnCopy(A.u8, src->u8, FREX_LEN);

	//for (j = 0; j < FR_LEN; j++)
	//{
	//	k1 = U8Mul(A.u8[j], g_FrInv.u8[0], &k2); // Need to correct
	//	for (i = 0; i < FR_LEN; i++)
	//	{
	//		lp = U8Mul(k1, g_FrM.u8[i], &hp);
	//		t2 = U8Add(lp, A.u8[i + j], &t1, 0);
	//		carry = U8Add(t1, carry, &(A.u8[i + j]), 0);
	//		carry += hp + t2;
	//	}
	//	hp = U8Add(A.u8[FR_LEN + j], carry2, &lp, 0);
	//	t2 = U8Add(lp, carry, &t1, 0);
	//	t2 += U8Add(lp, t1, &(A.u8[FR_LEN + j]), 0);
	//	carry2 = t2;
	//	carry = 0;
	//}

	for (j = 0; j < FR_LEN; j++)
	{
		k1 = U8Mul(A.u8[j], g_FrInv.u8[0], &k2); // Need to correct, just use the [k1]?

		t1 = BnMulU8(g_FrM.u8, k1, tmpFr.u8);
		t2 = BnAdd(tmpFr.u8, A.u8 + j, A.u8 + j);

		carry2 += t1 + t2;
		carry2 = BnAddU8(A.u8 + FR_LEN + j, carry2, A.u8 + FR_LEN + j);
	}

	BnCopy(dst->u8, A.u8 + FR_LEN, FR_LEN);

	FrSimpleReduce(dst);
}

// dst = src % M, copy from [ff]
// Copy from [ff_derive\src\lib.rs]
void FrMontgReduce2(Fr* dst, const FrEx* src)
{
	uint64_t i = 0;
	uint64_t j = 0;
	uint64_t t1 = 0;
	uint64_t t2 = 0;
	uint64_t k = 0;
	uint64_t k2 = 0;
	uint64_t carry = 0;
	uint64_t carry2 = 0;
	FrEx A = { 0 };
	Fr tmpFr = { 0 };

	BnCopy(A.u8, src->u8, FREX_LEN);

	for (i = 0; i < FR_LEN; i++)
	{
		k = U8Mul(A.u8[i], g_FrInv.u8[0], &k2); // just use the [k]
		carry = 0;
		BnMulAddCarry(A.u8[i], k, g_FrM.u8[0], &carry);

		for (j = 1; j < FR_LEN; j++)
		{
			A.u8[i + j] = BnMulAddCarry(A.u8[i + j], k, g_FrM.u8[j], &carry);
		}
		if (i == 0)
		{
			A.u8[FR_LEN + i] = BnAddWithCarry(A.u8[FR_LEN + i], 0, &carry);
		}
		else
		{
			A.u8[FR_LEN + i] = BnAddWithCarry(A.u8[FR_LEN + i], carry2, &carry);
		}

		if (i != (FR_LEN - 1))
		{
			carry2 = carry;
		}
	}

	BnCopy(dst->u8, A.u8 + FR_LEN, FR_LEN);

	FrSimpleReduce(dst);
}

// Convert a element from residual domain into montgomary domain
void FrIntoMontg(Fr* dst, const Fr* src)
{
	FrMul(src, &g_FrR2, dst);
}

// Convert a element from montgomary domain into residual domain
void FrFromMontg(Fr* dst, const Fr* src)
{
	FrEx tmp;

	Fr2FrEx(&tmp, src);
	FrMontgReduce2(dst, &tmp);
}

// Print the array of arr[len]
void FrPrintArr(const Fr arr[], uint64_t len)
{
	uint64_t i = 0;

	for (i = 0; i < len; i++)
	{
		FrPrint(&arr[i]);
	}
}

// Print the array of arr[len] in hex mode
void FrPrintArrEx(const Fr arr[], uint64_t len)
{
	uint64_t i = 0;

	for (i = 0; i < len; i++)
	{
		HexPrintInBigNum(arr[i].u8, FR_SIZE);
	}
}

// Print the matrix m[width][width]
void FrPrintMatrix(const Fr* m, uint64_t width)
{
	uint64_t i = 0;
	uint64_t j = 0;
	const Fr* row = NULL;

	for (i = 0; i < width; i++)
	{
		printf("Row [%02d]:\n", i);
		row = FrGetMatrixRowOffset(m, i, width);
		for (j = 0; j < width; j++)
		{
			printf("Column [%02d]:", j);
			FrPrint(&row[j]);
		}
	}
}

// Print the matrix m[width][width] in hex mode
void FrPrintMatrixEx(const Fr* m, uint64_t width)
{
	uint64_t i = 0;
	uint64_t j = 0;
	const Fr* row = NULL;

	for (i = 0; i < width; i++)
	{
		printf("Row [%02d]:\n", i);
		row = FrGetMatrixRowOffset(m, i, width);
		for (j = 0; j < width; j++)
		{
			printf("Column [%02d]:", j);
			FrPrintEx(&row[j]);
			//HexPrintInBigNum(row[j].u8, FR_SIZE);
		}
	}
}

// Core part for calculate multiplicated inverse
static void FrInvCore(Fr* x, Fr* y)
{

	while (BnIsEven(x->u8))
	{
		BnDiv2(x->u8, x->u8);

		if (BnIsEven(y->u8))
		{
			BnDiv2(y->u8, y->u8);
		}
		else
		{
			//FrAdd(y, &g_FrM, y);
			BnAdd(y->u8, g_FrM.u8, y->u8);
			BnDiv2(y->u8, y->u8);
		}
	}
}

// Calculate multiplicated inverse in prime field Fp
// By Extended Euclidean Algorithm
bool FrInverse(Fr* dst, const Fr* src)
{
	bool bRet = false;
	Fr u, v, b, c;

	if (FrEqual(src, &g_FrZero))
	{
		return false;
	}

	// Guajardo Kumar Paar Pelzl
	// Efficient Software-Implementation of Finite Fields with Applications to Cryptography
	// Algorithm 16 (BEA for Inversion in Fp)

	FrCopy(&u, src);
	FrCopy(&v, &g_FrM);
	FrCopy(&b, &g_FrOne);  // Need to update
	//FrCopy(&b, &g_FrR2);
	FrCopy(&b, &g_FrR);    // What? Use R instead of R2 ????
	FrCopy(&c, &g_FrZero);

	//printf("Initial value for generating MDS:\n");
	//printf("u = ");
	//HexPrintInBigNum(u.u8, FR_SIZE);
	//printf("v = ");
	//HexPrintInBigNum(v.u8, FR_SIZE);
	//printf("b = ");
	//HexPrintInBigNum(b.u8, FR_SIZE);
	//printf("c = ");
	//HexPrintInBigNum(c.u8, FR_SIZE);

	while (true)
	{
		if (FrEqual(&u, &g_FrOne))
		{
			break;
		}
		if (FrEqual(&v, &g_FrOne))
		{
			break;
		}

		FrInvCore(&u, &b);

		//printf("Step1:\n");
		//printf("u = ");
		//HexPrintInBigNum(u.u8, FR_SIZE);
		//printf("b = ");
		//HexPrintInBigNum(b.u8, FR_SIZE);

		FrInvCore(&v, &c);

		//printf("Step2:\n");
		//printf("v = ");
		//HexPrintInBigNum(v.u8, FR_SIZE);
		//printf("c = ");
		//HexPrintInBigNum(c.u8, FR_SIZE);

		if (BnLower(v.u8, u.u8))
		{
			//FrSub(&u, &v, &u);
			BnSub(u.u8, v.u8, u.u8);
			FrSub(&b, &c, &b);

			//printf("Step3:\n");
			//printf("u = ");
			//HexPrintInBigNum(u.u8, FR_SIZE);
			//printf("b = ");
			//HexPrintInBigNum(b.u8, FR_SIZE);
		}
		else
		{
			//FrSub(&v, &u, &v);
			BnSub(v.u8, u.u8, v.u8);
			FrSub(&c, &b, &c);

			//printf("Step4:\n");
			//printf("v = ");
			//HexPrintInBigNum(v.u8, FR_SIZE);
			//printf("c = ");
			//HexPrintInBigNum(c.u8, FR_SIZE);
		}
	}

	// Copy result
	if (FrEqual(&u, &g_FrOne))
	{
		//printf("Result1:\n");
		//printf("b = ");
		//HexPrintInBigNum(b.u8, FR_SIZE);

		FrCopy(dst, &b);
	}
	else
	{
		//printf("Result2:\n");
		//printf("c = ");
		//HexPrintInBigNum(c.u8, FR_SIZE);

		FrCopy(dst, &c);
	}

	bRet = true;
	return bRet;
}

// Calculate multiplicated inverse in prime field Fp
// By Extended Euclidean Algorithm
bool FrInverseOld(Fr* dst, const Fr* src)
{
	if (FrEqual(src, &g_FrZero))
	{
		return false;
	}

	// Get multiplicated inverse by Extended Euclidean Algorithm
	BnInverse(dst->u8, src->u8, g_FrM.u8);

	return true;
}

// Calculate multiplicated inverse in prime field Fp
bool FrInverseV2(Fr* dst, const Fr* src)
{
	bool bRet = false;
	Fr a, b;

	if (FrEqual(src, &g_FrZero))
	{
		return false;
	}

	FrIntoMontg(&a, src);
	FrInverse(&b, &a);
	FrFromMontg(dst, &b);

	bRet = true;
	return bRet;
}

// Calculate the row offset of a matrix with each row vector has [row_len] elements
Fr* FrGetMatrixRowOffset(const Fr* base, uint64_t row_index, uint64_t row_len)
{
	Fr* ret = NULL;
	uint8_t* ptr = NULL;
	uint64_t offset = 0;

	ptr = (uint8_t*)base;  // Must be cast to byte pointer
	offset = row_index * row_len * FR_SIZE;
	ret = (Fr*)(ptr + offset);

	return ret;
}

// Read a Fr from byte buffer [src] with big endian
void FrReadFromBe(Fr* dst, uint8_t* src)
{
	int64_t i = 0, j = 0;
	uint8_t* ptrD = NULL;
	uint8_t* ptrS = NULL;
	int64_t limbLen = 0;

	limbLen = FR_SIZE / FR_LEN;  // sizeof(uint64_t)
	for (i = 0; i < FR_LEN; i++)
	{
		ptrD = (uint8_t*)&(dst->u8[FR_LEN - 1 - i]);
		ptrS = src + limbLen * i;
		for (j = 0; j < limbLen; j++)
		{
			ptrD[j] = ptrS[limbLen - 1 - j];
		}
	}
}

// Malloc memory for Fr array
// Success return the allocated memory pointer, else return NULL
Fr* FrArrMalloc(uint64_t arrlen)
{
	Fr* ret = NULL;

	ret = (Fr*)malloc(FR_SIZE * arrlen);

	return ret;
}

// Free memeory for Fr array
void FrArrFree(Fr* ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

// Malloc memory for Fr 2 dimension array
// Success return the allocated memory pointer, else return NULL
Fr** FrHignDimMalloc(uint64_t highDim, uint64_t lowDim)
{
	Fr** ret = NULL;
	uint64_t i = 0;
	uint64_t headerSize = 0;
	uint64_t bodySize = 0;
	uint64_t elemSize = 0;
	uint64_t totalSize = 0;
	uint8_t* buf = NULL;
	uint8_t* ptr = NULL;

	if (!highDim || !lowDim)
	{
		return ret;
	}

	// Memeory layout
	//    header                       body
	// [ptr1, ptr2, ptr3... ][   elem1, elem2, elem3...   ]
	// ptr1 -> elem1,
	// ptr2 -> elem2,
	// ...
	headerSize = sizeof(Fr*) * highDim;
	elemSize = sizeof(Fr) * lowDim;
	bodySize = elemSize * highDim;
	totalSize = headerSize + bodySize;
	buf = (uint8_t*)malloc(totalSize);
	if (!buf)
	{
		return NULL;
	}

	Memset(buf, 0, totalSize);
	ret = (Fr**)buf;
	for (i = 0; i < highDim; i++)
	{
		ptr = (buf + headerSize) + i * elemSize;
		ret[i] = (Fr*)ptr;
	}

	return ret;
}

// Free memeory for Fr 2 dimension array
void FrHignDimFree(Fr** ptr, uint64_t highDim)
{
	uint64_t i = 0;

	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

// Reset each element of the array to zero
void FrArrReset(Fr* arr, uint64_t arrlen)
{
	uint64_t i = 0;

	for (i = 0; i < arrlen; i++)
	{
		FrZero(arr + i);
	}
}

// Compare the Fr array
bool FrArrCompare(const Fr* a, const Fr* b, uint64_t len)
{
	uint64_t i = 0;

	for (i = 0; i < len; i++)
	{
		if (!FrEqual(a + i, b + i))
		{
			return false;
		}
	}

	return true;
}





// Convert big number in hex representation string to Fr
// Example:  "0x112233" -> Fr{0x112233, 0, 0, 0}
bool FrFromHexStringInBigNum(Fr* dst, const char* src)
{
	bool bRet = false;
	uint64_t i = 0;
	uint64_t ai = 0;
	uint64_t srcLen = 0;
	uint64_t rawFrLenInStr = 0;
	uint8_t* ptr = NULL;
	uint8_t hp = 0, lp = 0;  // high part and low part of a byte in hex

	rawFrLenInStr = FR_SIZE * 2;
	srcLen = GetStringLength(src);
	if (srcLen != (rawFrLenInStr) && srcLen != (rawFrLenInStr + 2))
	{
		return false;
	}

	if (!dst || !src)
	{
		return false;
	}

	ptr = (uint8_t*)src;

	// srcLen should be equal to 64 or 68(with prefix [0x])
	if (srcLen == (rawFrLenInStr + 2))
	{
		ptr += 2;
		srcLen -= 2;
	}

	bRet = GetRawDataFromHexStringInBigNumRepresentation((uint8_t*)dst, ptr, srcLen);
	FrSimpleReduce(dst);

	return bRet;
}

// Convert big number in hex representation string to FrEx
// Example:  "0x112233" -> FrEx{0x112233, 0, 0, 0, 0, 0, 0, 0 }
bool FrExFromHexStringInBigNum(FrEx* dst, const char* src)
{
	bool bRet = false;
	uint64_t i = 0;
	uint64_t ai = 0;
	uint64_t srcLen = 0;
	uint64_t rawFrExLenInStr = 0;
	uint8_t* ptr = NULL;
	uint8_t hp = 0, lp = 0;  // high part and low part of a byte in hex

	rawFrExLenInStr = FREX_SIZE * 2;
	srcLen = GetStringLength(src);
	if (srcLen != (rawFrExLenInStr) && srcLen != (rawFrExLenInStr + 2))
	{
		return false;
	}

	if (!dst || !src)
	{
		return false;
	}

	ptr = (uint8_t*)src;

	// srcLen should be equal to 128 or 130(with prefix [0x])
	if (srcLen == (rawFrExLenInStr + 2))
	{
		ptr += 2;
		srcLen -= 2;
	}

	bRet = GetRawDataFromHexStringInBigNumRepresentation((uint8_t*)dst, ptr, srcLen);
	//FrSimpleReduce(dst);

	return bRet;
}

