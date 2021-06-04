
#include "BinNumOp.h"


// c = a + b + carry
// Return the carry flag
uint8_t U8Add(uint64_t a, uint64_t b, uint64_t* c, uint8_t carry)
{
	// Ref: https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_addcarryx_u64

	uint8_t tmp = 0;

	tmp = _addcarryx_u64(carry, a, b, c);

	return tmp;
}

// c = a - b - carry
// Return the borrow flag
uint8_t U8Sub(uint64_t a, uint64_t b, uint64_t* c, uint8_t carry)
{
	// Ref: https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_subborrow_u64

	uint8_t tmp = 0;

	tmp = _subborrow_u64(carry, a, b, c);

	return tmp;
}

// [ret,c] = a * b
// Return the low part of the result in [ret], the high part was saved to [c]
uint64_t U8Mul(uint64_t a, uint64_t b, uint64_t* c)
{
	// Ref: https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mulx_u64

	uint64_t hp = 0, lp = 0;

	lp = _mulx_u64(a, b, &hp);

	*c = hp;    // Save high part to [c]
	return lp; // Return lower part
}



// c = a + b, return carry
uint8_t BnAdd(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS], uint64_t c[BN_LIMBS])
{
	uint64_t i = 0;
	uint8_t carry = 0;

	carry = U8Add(a[0], b[0], &(c[0]), carry);
	carry = U8Add(a[1], b[1], &(c[1]), carry);
	carry = U8Add(a[2], b[2], &(c[2]), carry);
	carry = U8Add(a[3], b[3], &(c[3]), carry);

	return carry;
}

// c = a - b, return borrow
uint8_t BnSub(const uint64_t a[BN_LIMBS], uint64_t const b[BN_LIMBS], uint64_t c[BN_LIMBS])
{
	uint64_t i = 0;
	uint8_t carry = 0;

	carry = U8Sub(a[0], b[0], &(c[0]), carry);
	carry = U8Sub(a[1], b[1], &(c[1]), carry);
	carry = U8Sub(a[2], b[2], &(c[2]), carry);
	carry = U8Sub(a[3], b[3], &(c[3]), carry);

	return carry;
}

// c = (a - b) % N
void BnSubModN(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS], uint64_t c[BN_LIMBS], const uint64_t N[BN_LIMBS])
{
	uint64_t i = 0;
	uint64_t carry = 0;
	uint64_t tA[BN_LIMBS] = { 0 };
	uint64_t tB[BN_LIMBS] = { 0 };
	uint64_t tC[BN_LIMBS] = { 0 };

	BnCopy(tA, a, BN_LIMBS);
	BnCopy(tB, b, BN_LIMBS);

	while (BnLE(tA, N))
	{
		BnSub(tA, N, tA);
	}
	while (BnLE(tB, N))
	{
		BnSub(tB, N, tB);
	}

	if (BnLE(tA, tB))
	{
		// a >= b
		BnSub(tA, tB, c);
	}
	else
	{
		// a < b
		BnSub(N, tB, tC);
		BnAdd(tA, tC, c);
	}
}

// c = a + b, return carry
uint8_t BnAddU8(const uint64_t a[BN_LIMBS], uint64_t b, uint64_t c[BN_LIMBS])
{
	uint64_t i = 0;
	uint8_t carry = 0;

	carry = U8Add(a[0], b, &(c[0]), carry);
	carry = U8Add(a[1], 0, &(c[1]), carry);
	carry = U8Add(a[2], 0, &(c[2]), carry);
	carry = U8Add(a[3], 0, &(c[3]), carry);

	return carry;
}

// c = a - b, return borrow
uint8_t BnSubU8(const uint64_t a[BN_LIMBS], uint64_t b, uint64_t c[BN_LIMBS])
{
	uint64_t i = 0;
	uint8_t carry = 0;

	carry = U8Sub(a[0], b, &(c[0]), carry);
	carry = U8Sub(a[1], 0, &(c[1]), carry);
	carry = U8Sub(a[2], 0, &(c[2]), carry);
	carry = U8Sub(a[3], 0, &(c[3]), carry);

	return carry;
}

// ret = a < b ? true : false
bool BnLower(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS])
{
	bool bRet = false;
	int64_t i = 0;   // Must be signed integer
	uint64_t ai = 0;
	uint64_t bi = 0;

	for (i = BN_LIMBS - 1; i >= 0; i--)
	{
		ai = a[i];
		bi = b[i];
		if (ai < bi)
		{
			bRet = true;
			break;
		}
		else if (ai > bi)
		{
			break;
		}
	}

	// i == -1 -> a == b -> return false

	return bRet;
}

// ret = a > b ? true : false
bool BnLager(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS])
{
	bool bRet = false;
	int64_t i = 0;   // Must be signed integer
	uint64_t ai = 0;
	uint64_t bi = 0;

	for (i = BN_LIMBS - 1; i >= 0; i--)
	{
		ai = a[i];
		bi = b[i];
		if (ai > bi)
		{
			bRet = true;
			break;
		}
		else if (ai < bi)
		{
			break;
		}
	}

	// i == -1 -> a == b -> return false

	return bRet;
}

// ret = a >= b ? true : false
bool BnLE(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS])
{
	bool bRet = true;
	int64_t i = 0;   // Must be signed integer
	uint64_t ai = 0;
	uint64_t bi = 0;

	for (i = BN_LIMBS - 1; i >= 0; i--)
	{
		ai = a[i];
		bi = b[i];
		if (ai > bi)
		{
			break;
		}
		else if (ai < bi)
		{
			bRet = false;
			break;
		}
	}

	// i == -1 -> a == b -> return true

	return bRet;
}

// ret = a == b ? true : false
bool BnEqual(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS])
{
	bool bRet = true;
	int64_t i = 0;   // Must be signed integer
	uint64_t ai = 0;
	uint64_t bi = 0;

	for (i = BN_LIMBS - 1; i >= 0; i--)
	{
		ai = a[i];
		bi = b[i];
		if (ai != bi)
		{
			bRet = false;
			break;
		}
	}

	// i == -1 -> a == b -> return true

	return bRet;
}

// ret = a == b ? true : false
// Compare [len] limbs of [a] and [b]
bool BnEqualEx(const uint64_t* a, const uint64_t* b, uint64_t len)
{
	bool bRet = true;
	int64_t i = 0;   // Must be signed integer
	uint64_t ai = 0;
	uint64_t bi = 0;

	for (i = len - 1; i >= 0; i--)
	{
		ai = a[i];
		bi = b[i];
		if (ai != bi)
		{
			bRet = false;
			break;
		}
	}

	// i == -1 -> a == b -> return true

	return bRet;
}

// dst = src, copy [len] limbs from [src] to [dst]
bool BnCopy(uint64_t* dst, const uint64_t* src, uint64_t len)
{
	uint64_t i = 0;

	for (i = 0; i < len; i++)
	{
		dst[i] = src[i];
	}

	return true;
}

// c = a * b
// c[8] = a[4] * b[4]
void BnMul(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS], uint64_t c[BN_LIMBS*2])
{
	uint64_t i = 0;
	uint64_t carry = 0;
	uint64_t carry1 = 0;

	uint64_t res[BN_LIMBS * 3] = { 0 };
	uint64_t tmp[BN_LIMBS] = { 0 };

	Memset(res, 0, sizeof(res));
	for (i = 0; i < BN_LIMBS; i++)
	{
		carry = BnMulU8(b, a[i], tmp);
		carry1 = BnAdd(res + i, tmp, res + i);
		BnAddU8(res + BN_LIMBS + i, carry, res + BN_LIMBS + i);  // Should  not carry again
		BnAddU8(res + BN_LIMBS + i, carry1, res + BN_LIMBS + i);  // Should  not carry again
	}
	BnCopy(c, res, BN_LIMBS * 2);
}

// c = a * b
// c[8] = a[4] * b[4]
// Copy from [ff_derive_const\src\const_field_element.rs]
void BnMulEx(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS], uint64_t c[BN_LIMBS * 2])
{
	uint64_t i = 0, j = 0;
	uint64_t carry = 0;
	uint64_t t = 0;
	
	for (i = 0; i < BN_LIMBS; i++)
	{
		carry = 0;
		for (j = 0; j < BN_LIMBS; j++)
		{
			if (i == 0)
			{
				c[i + j] = BnMulAddCarry(0, a[i], b[j], &carry);
			}
			else
			{
				c[i + j] = BnMulAddCarry(c[i + j], a[i], b[j], &carry);
			}
		}
		c[BN_LIMBS + i] = carry;
	}
}

// c = a * b
// c[4] = a[4] * b, return the carry flag
uint64_t BnMulU8(const uint64_t a[BN_LIMBS], uint64_t b, uint64_t c[BN_LIMBS])
{
	uint64_t i = 0, j = 0;
	uint64_t carry = 0;
	uint64_t tmpC[BN_LIMBS + 1] = { 0 };
	uint64_t hi[BN_LIMBS + 1] = { 0 };

	
	for (i = 0; i < BN_LIMBS; i++)
	{
		tmpC[i] = U8Mul(a[i], b, hi + i);
	}

	// Should not carry
	carry = BnAdd(hi, tmpC + 1, tmpC + 1);

	carry = tmpC[BN_LIMBS];
	BnCopy(c, tmpC, BN_LIMBS);

	// Return the carry flag
	return carry;
}

// c = a * a
// c[8] = a[4] * a[4]
// Copy from [ff_derive_const\src\const_field_element.rs]
void BnSquareEx(const uint64_t a[BN_LIMBS], uint64_t c[BN_LIMBS * 2])
{
	uint64_t i = 0, j = 0;
	uint64_t carry = 0;
	uint64_t t = 0;

	for (i = 0; i < (BN_LIMBS - 1); i++)
	{
		carry = 0;
		for (j = i + 1; j < BN_LIMBS; j++)
		{
			if (i == 0)
			{
				c[i + j] = BnMulAddCarry(0, a[i], a[j], &carry);
			}
			else
			{
				c[i + j] = BnMulAddCarry(c[i + j], a[i], a[j], &carry);
			}
		}
		c[BN_LIMBS + i] = carry;
	}

	//HexPrintInBigNum(c, BN_SIZE * 2);

	//if (BN_LIMBS != 1)
	{
		for (i = 1; i < (BN_LIMBS * 2); i++)
		{
			if (i == 1)
			{
				c[BN_LIMBS * 2 - i] = c[BN_LIMBS * 2 - i - 1] >> 63;
			}
			else if (i == (BN_LIMBS * 2 - 1))
			{
				c[BN_LIMBS * 2 - i] = c[BN_LIMBS * 2 - i] << 1;
			}
			else
			{
				c[BN_LIMBS * 2 - i] = (c[BN_LIMBS * 2 - i] << 1) | (c[BN_LIMBS * 2 - i - 1] >> 63);
			}
		}
	}

	//HexPrintInBigNum(c, BN_SIZE * 2);
	carry = 0;

	for (i = 0; i < BN_LIMBS; i++)
	{
		if (i == 0)
		{
			c[2 * i] = BnMulAddCarry(0, a[i], a[i], &carry);
		}
		else
		{
			c[2 * i] = BnMulAddCarry(c[2 * i], a[i], a[i], &carry);
		}
		c[2 * i + 1] = BnAddWithCarry(c[2 * i + 1], 0, &carry);
	}

	//HexPrintInBigNum(c, BN_SIZE * 2);
}

// dst = src % M
// solinas_reduce
void BnReduce(uint64_t dst[BN_LIMBS], const uint64_t src[BN_LIMBS*2], const uint64_t M[BN_LIMBS])
{
	// fast reduction 512bit to 256bit
	// ref: http://cacr.uwaterloo.ca/techreports/1999/corr99-39.pdf 

	uint32_t * A = (uint32_t *)(src);
	uint64_t sumD[BN_LIMBS];
	uint32_t* ptr = (uint32_t*)sumD;
	uint64_t B[BN_LIMBS * 2] =
	{
		0, 
		0, 
		A[15],  // B[2] is temp
		(uint64_t)A[8]  + A[13], 
		(uint64_t)A[9]  + A[14], 
		(uint64_t)A[10] + A[15], 
		A[11], 
		A[15]
	};
	uint64_t S[BN_LIMBS] = { src[0], src[1], src[2], src[3] };
	uint64_t payload[BN_LIMBS] = { 0, 0, 0, 0 };
	uint64_t carry = 0;
	uint64_t carry2 = 0;

	B[2] += A[14]; B[1] += B[2]; B[6] += B[2];
	B[2] += A[13]; B[0] += B[2]; B[5] += B[2];
	B[2] += A[12]; B[4] += B[2]; B[7] += B[2];
	B[2] += A[11]; B[3] += B[2];
	B[2] += (uint64_t)A[9] + A[10]; B[1] += B[2];
	B[2] += A[8]; B[0] += B[2]; B[7] += B[2];

	ptr[0] = (uint32_t)B[0];
	B[1] += B[0] >> 32;
	ptr[1] = (uint32_t)B[1];
	ptr[2] = (uint32_t)(B[1] >> 32);
	ptr[3] = (uint32_t)B[3];
	B[4] += B[3] >> 32;
	ptr[4] = (uint32_t)B[4];
	B[5] += B[4] >> 32;
	ptr[5] = (uint32_t)B[5];
	B[6] += B[5] >> 32;
	ptr[6] = (uint32_t)B[6];
	B[7] += B[6] >> 32;
	ptr[7] = (uint32_t)B[7];
	carry = B[7] >> 32;

	carry += BnAdd(S, sumD, S);


	//carry = BnMulU8(M, carry, payload);
	//BnSub(S, payload, S);
	//while (BnLE(S, M))
	//{
	//	BnSub(S, M, S);
	//}

	//carry2 = 0;
	//BnCopy(payload, S, BN_LIMBS);
	//while (carry2 < carry)
	//{
	//	carry2 += BnSub(payload, M, payload);
	//}
	//while (BnLE(payload, M))
	//{
	//	BnSub(payload, M, payload);
	//}
	//BnCopy(S, payload, BN_LIMBS);

	dst[0] = 0;
	dst[1] = (uint64_t)A[8] + A[9] + A[13] + A[14];
	dst[2] = 0;
	dst[3] = 0;

	// dst = (S - dst) % M
	BnSubModN(S, dst, dst, M);
}

// Calculate a + (b * c) + carry, returning the least significant digit
// and setting carry to the most significant digit.
uint64_t BnMulAddCarry(uint64_t a, uint64_t b, uint64_t c, uint64_t* carry)
{
	uint64_t ret = 0;
	uint64_t t1 = 0, t2 = 0, t3 = 0;
	uint64_t c1 = 0, c2 = 0, c3 = 0;

	t1 = U8Mul(b, c, &t2);
	c3 = U8Add(a, *carry, &t3, 0);

	c1 = U8Add(t3, t1, &ret, 0);

	*carry = t2 + c3 + c1;

	return ret;
}

// Calculate a + b + carry, returning the sum and modifying the
// carry value.
uint64_t BnAddWithCarry(uint64_t a, uint64_t b, uint64_t* carry)
{
	uint64_t ret = 0;
	uint64_t t1 = 0, t2 = 0, t3 = 0;
	uint64_t c1 = 0, c2 = 0, c3 = 0;

	c1 = U8Add(a, b, &t1, 0);
	c2 = U8Add(t1, *carry, &ret, 0);

	*carry = c2 + c1;

	return ret;
}

// Is target a even number?
// Example: 2, 4, 6, 8 etc.
bool BnIsEven(const uint64_t a[BN_LIMBS])
{
	bool bRet = false;
	uint64_t leastLimb = 0;  // Least signifficant limb

	leastLimb = a[0];
	if (0 == (leastLimb & 1))
	{
		bRet = true;
	}

	return bRet;
}

// a == 0 ?
bool BnIsZero(const uint64_t a[BN_LIMBS])
{
	bool bRet = false;
	static const uint64_t zero[BN_LIMBS] = { 0, 0, 0, 0 };  // 0

	if (BnEqual(a, zero))
	{
		bRet = true;
	}

	return bRet;
}

// a == 1 ?
bool BnIsOne(const uint64_t a[BN_LIMBS])
{
	bool bRet = false;
	static const uint64_t one[BN_LIMBS] = { 1, 0, 0, 0 };  // 1

	if (BnEqual(a, one))
	{
		bRet = true;
	}

	return bRet;
}

// c = a / 2
void BnDiv2(const uint64_t a[BN_LIMBS], uint64_t c[BN_LIMBS])
{
	uint64_t i = 0;

	for (i = 0; i < (BN_LIMBS - 1); i++)
	{
		c[i] = (a[i] >> 1) | (a[i + 1] << 63);
	}
	c[BN_LIMBS - 1] = a[BN_LIMBS - 1] >> 1;
}

// a = a >> 1
void BnShr(uint64_t a[BN_LIMBS])
{
	uint64_t t[BN_LIMBS] = { 0 };
	BnDiv2(a, t);
	BnCopy(a, t, BN_LIMBS);
}

// a = a % M
bool BnMod(uint64_t a[BN_LIMBS], const uint64_t M[BN_LIMBS])
{
	bool bRet = false;
	while (BnLE(a, M))
	{
		bRet = true;
		BnSub(a, M, a);
	}
	return bRet;
}

// Core part of inverse
static void BnInverseCore(uint64_t x[BN_LIMBS], uint64_t y[BN_LIMBS], const uint64_t M[BN_LIMBS])
{
	uint8_t carry = 0;

	while (BnIsEven(x))
	{
		BnShr(x);
		if (BnIsEven(y))
		{
			BnShr(y);
		}
		else
		{
			carry = BnAdd(y, M, y);
			BnShr(y);
			if (carry)
			{
				y[BN_LIMBS - 1] |= 0x8000000000000000;
			}
		}
	}
}

// 1 === dst * src % M
// Get invserse of [src] by Extended Euclidean Algorithm
// Success return true, else return false
bool BnInverse(uint64_t dst[BN_LIMBS], const uint64_t src[BN_LIMBS], const uint64_t M[BN_LIMBS])
{
	bool bRet = false;
	uint8_t carry = false;
	uint64_t u[BN_LIMBS] = { 0 };
	uint64_t v[BN_LIMBS] = { 0 };
	uint64_t a[BN_LIMBS] = { 1, 0, 0, 0 };  // Set to 1
	uint64_t b[BN_LIMBS] = { 0, 0, 0, 0 };  // Set to 0
	uint64_t t[BN_LIMBS] = { 0, 0, 0, 0 };  // Set to 0

	BnCopy(u, src, BN_LIMBS);
	BnCopy(v, M, BN_LIMBS);

	if (BnIsZero(src))
	{
		return false;
	}

	while (true)
	{
		if (BnIsOne(u)) break;
		if (BnIsOne(v)) break;

		BnInverseCore(u, a, M);
		BnInverseCore(v, b, M);

		if (BnLE(u, v))
		{
			BnSubModN(u, v, u, M);
			BnSubModN(a, b, a, M);
		}
		else
		{
			BnSubModN(v, u, v, M);
			BnSubModN(b, a, b, M);
		}
	}

	if (BnIsOne(u))
	{
		BnMod(a, M);
		BnCopy(dst, a, BN_LIMBS);
	}
	else
	{
		BnMod(b, M);
		BnCopy(dst, b, BN_LIMBS);
	}

	return true;
}


