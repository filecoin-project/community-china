#ifndef __BIG_NUM_OP_H__
#define __BIG_NUM_OP_H__

#include "Utilities.h"

#define BN_LIMBS (4)                             // 4 limbs for each Big number
#define BN_SIZE  (BN_LIMBS * sizeof(uint64_t))   // 4 limbs for each Big number, 32 bytes


// x86-64
#ifdef _WIN32
// for windows
#include <intrin.h>
#else
// for linux
#include <x86intrin.h>
#endif


// Ref: https://software.intel.com/sites/landingpage/IntrinsicsGuide/

// c = a + b + carry
// Return the carry flag
uint8_t U8Add(uint64_t a, uint64_t b, uint64_t* c, uint8_t carry);

// c = a - b - carry
// Return the borrow flag
uint8_t U8Sub(uint64_t a, uint64_t b, uint64_t* c, uint8_t carry);

// [ret,c] = a * b
// Return the low part of the result in [ret], the high part was saved to [c]
uint64_t U8Mul(uint64_t a, uint64_t b, uint64_t* c);



// c = a + b, return carry
uint8_t BnAdd(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS], uint64_t c[BN_LIMBS]);

// c = a - b
uint8_t BnSub(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS], uint64_t c[BN_LIMBS]);

// c = (a - b) % N
void BnSubModN(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS], uint64_t c[BN_LIMBS], const uint64_t N[BN_LIMBS]);

// c = a + b, return carry
uint8_t BnAddU8(const uint64_t a[BN_LIMBS], uint64_t b, uint64_t c[BN_LIMBS]);

// c = a - b, return borrow
uint8_t BnSubU8(const uint64_t a[BN_LIMBS], uint64_t b, uint64_t c[BN_LIMBS]);

// ret = a < b ? true : false
bool BnLower(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS]);

// ret = a > b ? true : false
bool BnLager(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS]);

// ret = a >= b ? true : false
bool BnLE(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS]);

// ret = a == b ? true : false
bool BnEqual(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS]);

// ret = a == b ? true : false
// Compare [len] limbs of [a] and [b]
bool BnEqualEx(const uint64_t* a, const uint64_t* b, uint64_t len);

// dst = src, copy [len] limbs from [src] to [dst]
bool BnCopy(uint64_t* dst, const uint64_t* src, uint64_t len);

// c = a * b
// c[8] = a[4] * b[4]
void BnMul(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS], uint64_t c[BN_LIMBS * 2]);

// c = a * b
// c[8] = a[4] * b[4]
// Copy from [ff_derive_const\src\const_field_element.rs]
void BnMulEx(const uint64_t a[BN_LIMBS], const uint64_t b[BN_LIMBS], uint64_t c[BN_LIMBS * 2]);

// c = a * b
// c[4] = a[4] * b, return the carry flag
uint64_t BnMulU8(const uint64_t a[BN_LIMBS], uint64_t b, uint64_t c[BN_LIMBS]);

// c = a * a
// c[8] = a[4] * a[4]
// Copy from [ff_derive_const\src\const_field_element.rs]
void BnSquareEx(const uint64_t a[BN_LIMBS], uint64_t c[BN_LIMBS * 2]);

// dst = src % M
void BnReduce(uint64_t dst[BN_LIMBS], const uint64_t src[BN_LIMBS * 2], const uint64_t M[BN_LIMBS]);

// Calculate a + (b * c) + carry, returning the least significant digit
// and setting carry to the most significant digit.
uint64_t BnMulAddCarry(uint64_t a, uint64_t b, uint64_t c, uint64_t* carry);

// Calculate a + b + carry, returning the sum and modifying the
// carry value.
uint64_t BnAddWithCarry(uint64_t a, uint64_t b, uint64_t* carry);

// Is target a even number?
// Example: 2, 4, 6, 8 etc.
bool BnIsEven(const uint64_t a[BN_LIMBS]);

// a == 0 ?
bool BnIsZero(const uint64_t a[BN_LIMBS]);

// a == 1 ?
bool BnIsOne(const uint64_t a[BN_LIMBS]);

// c = a / 2
void BnDiv2(const uint64_t a[BN_LIMBS], uint64_t c[BN_LIMBS]);

// a = a >> 1
void BnShr(uint64_t a[BN_LIMBS]);

// a = a % M
bool BnMod(uint64_t a[BN_LIMBS], const uint64_t M[BN_LIMBS]);

// 1 === dst * src % M
// Get invserse of [src] by Extended Euclidean Algorithm
// Success return true, else return false
bool BnInverse(uint64_t dst[BN_LIMBS], const uint64_t src[BN_LIMBS], const uint64_t M[BN_LIMBS]);




#endif // !__BIG_NUM_OP_H__
