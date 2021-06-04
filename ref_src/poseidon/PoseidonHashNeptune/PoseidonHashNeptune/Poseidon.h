#ifndef __POSEIDON_H__
#define __POSEIDON_H__


#include "Utilities.h"
#include "PoseidonConstant.h"
#include "GenRoundConstant.h"
#include "GenMDSMatrix.h"

// Ref: https://docs.rs/poseidon-rs/0.0.8/src/poseidon_rs/lib.rs.html#67-81
// https://github.com/arnaucube/poseidon-rs



typedef struct _POSEIDON_CTX
{
	uint64_t len;       // length of state
	uint64_t fullR;     // Full rounds
	uint64_t partialR;  // Partial rounds
	Fr state[PARTIAL_ROUND_LEN];

} POSEIDON_CTX;


typedef struct _POSEIDON_RUNTIME_CTX
{
	uint32_t arity;                   // 2, 4, 8, 16, 24, 36, 11
	uint32_t width;                   // arity + 1
	uint32_t fullRounds;              // Usually is 8
	uint32_t halfFullRounds;          // fullRounds / 2
	uint32_t partialRounds;
	uint32_t currRound;
	uint32_t crcRoundOffset;          // Offset for compressed round constant
	uint32_t roundConstSize;          // (fullRounds + partialRounds) * width
	uint32_t compRoundConstSize;      // fullRounds * width + partialRounds

	Fr* roundConstant;                // Fr[(fullRounds + partialRounds) * width]
	Fr* compressedRoundConst;         // Fr[fullRounds + partialRounds * width]
	Fr* preSparseMatrix;              // Fr[width][width]
	PSparseMatrices sparseMatrices;   // SparseMatrices[partialRounds]
	Fr* state;                        // State

	// No need to delete this buffer after release, because it was malloc with [state]
	Fr* stateTmp;                     // State backup, for temprory usage

	Fr poseidonTag;                   // Tag for poseidon
	MDSMatrices mds;

}POSEIDON_RUNTIME_CTX, *PPOSEIDON_RUNTIME_CTX;


// Input Fr[len], Output one Fr, len <= PARTIAL_ROUND_LEN
void PoseidonHash(Fr input[], uint64_t len, Fr* output);

// Generate constants for Poseidon hash
// Success return the context, failed return NULL
PPOSEIDON_RUNTIME_CTX GetPoseidonRuntimeCtx(uint32_t arity, Fr* tag);

// Delete Poseidon context
void DelPoseidonRuntimeCtx(PPOSEIDON_RUNTIME_CTX ctx);

// Reset Poseidon context for reuse this context with the same arity
void ResetPoseidonRuntimeCtx(PPOSEIDON_RUNTIME_CTX ctx);

// Input an initialized [ctx] and [input], Output one Fr [output]
// The input length is saved in [ctx->arity]
void PoseidonHashV2Ex(PPOSEIDON_RUNTIME_CTX ctx, Fr* input, Fr* output);

// Input Fr[len], Output one Fr,
// Currently supported input length is: 2, 4, 8, 16, 24, 36, 11
void PoseidonHashV2Wrapper(Fr* input, uint32_t len, Fr* output);

// Input an initialized [ctx] and [input], Output one Fr [output]
// The input length is saved in [ctx->arity]
// Reference from neptune:hash_correct()
void PoseidonHashV2NaiveWrapper(Fr* input, uint32_t len, Fr* output);




// [inFileName] save the reference input and output data
// [arity] specify the arity
void BenchPoseidon(char* inFileName, uint32_t arity);




// Generate round constants and save result to [out],
// If the input buffer [out] has no enough size, return the needed size in [outlen]
// And return false, otherwise, return ture
bool GenRoundConstantDemo(Fr out[], uint32_t* outlen);

// R[w] = M[w][w] * V[w]
// w: width of matrix
// M: w*w matrix
// V: column vector with w elements
// R: column vector with w elements
// V and R should not point to the same vector
bool ProductMatrix(const Fr* M, const Fr* V, Fr* R, uint64_t w);

// field       //  2 bits bi,  0  <= i <= 1,  //  field = 1 --> x^5
// sbox        //  4 bits bi,  2  <= i <= 5,  //  sbox  = 1 --> Gf(p)
// field_size  // 12 bits bi,  6  <= i <= 17
// t           // 12 bits bi,  18 <= i <= 29, // t=9 for 8-arity input
// r_f         // 10 bits bi,  30 <= i <= 39
// r_p         // 10 bits bi,  40 <= i <= 49
uint64_t GenRoundConstant(uint8_t field, uint8_t sbox, uint32_t field_size, uint32_t t, uint32_t r_f, uint32_t r_p, Fr out[], uint32_t* outlen);

// Compare to round constants [a] and [b],
// Return value equal to len if they are all equal
// Else return the ith unequal value
uint64_t RoundConstCmp(Fr a[], Fr b[], uint64_t len);

// Compare to MDS matrix [a] and [b],
// Return value equal to [t^2] if they are all equal
// Else return the ith unequal value
uint64_t MDSMatrixCmp(Fr* a, Fr* b, uint64_t t);

// Standard version of genrating tag
// [t] == [arity-1]
bool GeneratePoseidonTag(Fr* tag, uint32_t t);

// Input: width * (full_rounds + partial_rounds) elements of round_constants
// Output:width * (full_rounds) + partial_rounds elements of compressed round_constants
bool CompressRoundConstant(uint32_t width, uint32_t full_rounds, uint32_t partial_rounds, const Fr* round_constants,
	const Fr* mds_matrix, uint32_t partial_preprocessed, Fr* compressed_round_constants);




#endif // !__POSEIDON_H__
