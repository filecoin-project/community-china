#ifndef __FIELD_OP_H__
#define __FIELD_OP_H__


#include "Utilities.h"
#include "BinNumOp.h"
#include "RandomGenerator.h"


#define FR_LEN (4)               // 4 limbs
#define FREX_LEN (FR_LEN * 2)    // 8 limbs

// Element representation in Prime Field,
// Littelendian storage: 
//    u8[0] is the least significant one, 
//    u8[3] is the most significant one
typedef struct _Fr
{
	uint64_t u8[FR_LEN];   // 4 limbs

} Fr;

//
// Example:
// Decimal: 4417881134626180770308697923359573201005643519861877412381846989312604493735
// Hex:     0x09c46e9ec68e9bd4fe1faaba294cba38a71aa177534cdd1b6c7dc0dbd0abd7a7
// Fr:      0x6c7dc0dbd0abd7a7, 0xa71aa177534cdd1b, 0xfe1faaba294cba38, 0x09c46e9ec68e9bd4,
// Memory:  a7d7abd0dbc07d6c1bdd4c5377a11aa738ba4c29baaa1ffed49b8ec69e6ec409

#define FR_SIZE            sizeof(Fr)  // 32 bytes
#define FR_MODULUS_BITS    (254)       // Number of bits of module N
#define FR_SHAVE_BITS      (2)         // Number of remaind bits over module N for FR (256 - 254)
#define S                  (28)        // 2^s * t = MODULUS - 1 with t odd


extern const Fr g_FrZero;  // 0
extern const Fr g_FrOne;   // 1
extern const Fr g_FrTwo;   // 2
extern const Fr g_FrM;     // This is the modulus m of the prime field
extern const Fr g_FrG;     // Multiplicative generator of `MODULUS` - 1 order, also quadratic nonresidue
extern const Fr g_FrInv;   // -(m^{-1} mod m) mod m
extern const Fr g_FrRoU;   // 2 ^ s root of unity computed by GENERATOR^t
extern const Fr g_FrR;     // 2^{limbs*64} mod m
extern const Fr g_FrR2;    // 2^{limbs*64*2} mod m


// FrEx is not the element that located in Prime Field
typedef struct _FrEx
{
	// Fr d[2];
	uint64_t u8[FREX_LEN];   // 8 limbs

} FrEx;

#define FREX_SIZE            sizeof(FrEx)  // 64 bytes

//#define FrGetMatrixRowOffset(_base, _row_index, _row_len) \
//	(Fr*)( (uint8_t*)_base + _row_index * (_row_len * FR_SIZE) )

// a = a % M
void FrSimpleReduce(Fr* a);

// c = a + b % M
// a and b should be in the prime field, the result c is also in the finite field
void FrAdd(const Fr* a, const Fr* b, Fr* c);

// c = a - b % M
// a and b should be in the prime field, the result c is also in the finite field
void FrSub(const Fr* a, const Fr* b, Fr* c);

// c = a * b % M
// Input and output are both in montgomery domain
void FrMul(const Fr* a, const Fr* b, Fr* c);

// c = a * b % M
// Input and output are both in residual domain
void FrMulV2(const Fr* a, const Fr* b, Fr* c);

// c = a ^ 2 % M
void FrSquare(const Fr* a, Fr* c);

// c = a ^ 2 % M
// Input and output are both in residual domain
void FrSquareV2(const Fr* a, Fr* c);

// ret = a == b % M ? true : false
bool FrEqual(const Fr* a, const Fr* b);

// dst = src
void FrCopy(Fr* dst, const Fr* src);

// Copy Fr array from [src] to [dst]
void FrCopyArr(Fr* dst, const Fr* src, uint64_t arrlen);

// Zero Fr
void FrZero(Fr* a);

// Print Fr element
void FrPrint(const Fr* a);

// Print Fr element in hex mode (Big number)
void FrPrintEx(const Fr* a);

// Print FrEx element
void FrExPrint(const FrEx* a);

// Print Fr element as a big number in hex mode
void FrPrintAsBigNum(const Fr* a);

// Print FrEx element as a big number in hex mode
void FrExPrintAsBigNum(const FrEx* a);

// dst = src
void FrSet(Fr* dst, uint64_t src);

// dst->u8[i] = src
bool FrSetWithIdx(Fr* dst, uint64_t src, uint64_t i);

// ret = a < M ? true : false
bool FrIsValid(const Fr* a);

// dst = src
void FrEx2Fr(Fr* dst, const FrEx* src);

// dst = src
void Fr2FrEx(FrEx* dst, const Fr* src);

// Generate a random Fr element in the prime field
void FrGenRand(Fr* dst);

// dst = src % M
void FrMontgReduce(Fr* dst, const FrEx* src);

// dst = src % M, copy from [ff]
void FrMontgReduce2(Fr* dst, const FrEx* src);

// Convert a element from residual domain into montgomary domain
void FrIntoMontg(Fr* dst, const Fr* src);

// Convert a element from montgomary domain into residual domain
void FrFromMontg(Fr* dst, const Fr* src);

// Print the array of arr[len]
void FrPrintArr(const Fr arr[], uint64_t len);

// Print the array of arr[len] in hex mode
void FrPrintArrEx(const Fr arr[], uint64_t len);

// Print the matrix m[width][width]
void FrPrintMatrix(const Fr* m, uint64_t width);

// Print the matrix m[width][width] in hex mode
void FrPrintMatrixEx(const Fr* m, uint64_t width);

// Calculate multiplicated inverse in prime field Fp
bool FrInverse(Fr* dst, const Fr* src);

// Calculate multiplicated inverse in prime field Fp
bool FrInverseV2(Fr* dst, const Fr* src);

// Calculate multiplicated inverse in prime field Fp
// By Extended Euclidean Algorithm
bool FrInverseOld(Fr* dst, const Fr* src);

// Calculate the row offset of a matrix with each row vector has [row_len] elements
Fr* FrGetMatrixRowOffset(const Fr* base, uint64_t row_index, uint64_t row_len);

// Read a Fr from byte buffer [src] with big endian
void FrReadFromBe(Fr* dst, uint8_t* src);

// Malloc memory for Fr array
// Success return the allocated memory pointer, else return NULL
Fr* FrArrMalloc(uint64_t arrlen);

// Free memeory for Fr array
void FrArrFree(Fr* ptr);

// Malloc memory for Fr 2 dimension array
// Success return the allocated memory pointer, else return NULL
Fr** FrHignDimMalloc(uint64_t highDim, uint64_t lowDim);

// Free memeory for Fr 2 dimension array
void FrHignDimFree(Fr** ptr, uint64_t highDim);

// Reset each element of the array to zero
void FrArrReset(Fr* arr, uint64_t arrlen);

// Compare the Fr array
bool FrArrCompare(const Fr* a, const Fr* b, uint64_t len);




// Convert big number in hex representation string to Fr
// Example:  "0x112233" -> Fr{0x112233, 0, 0, 0}
bool FrFromHexStringInBigNum(Fr* dst, const char* src);

// Convert big number in hex representation string to FrEx
// Example:  "0x112233" -> FrEx{0x112233, 0, 0, 0, 0, 0, 0, 0 }
bool FrExFromHexStringInBigNum(FrEx* dst, const char* src);





#endif // !__FIELD_OP_H__