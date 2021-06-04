#ifndef __POSEIDON_CONSTANT_H__
#define __POSEIDON_CONSTANT_H__

#include "Utilities.h"
#include "FieldOp.h"

// Ref: 
// https://github.com/arnaucube/poseidon-rs
// https://github.com/matter-labs/ff


#define ROUND_FULL (8)
#define HALF_ROUND_FULL (ROUND_FULL / 2)
#define PARTIAL_ROUND_LEN (8)


//extern const uint64_t ROUND_FULL;
//extern const uint64_t HALF_ROUND_FULL;
extern const uint8_t g_RoundPartial[8];
extern const Fr g_ConstC[8][700];
extern const Fr g_ConstM[8][9][9];


// Use in lotus project
#define RC_A2_LEN (189)  // (full_round + partial_round) * t
#define MDS_A2_T (3)
#define RC_A4_LEN (320)
#define MDS_A4_T (5)
#define RC_A8_LEN (585)
#define MDS_A8_T (9)
#define RC_A16_LEN (1139)
#define MDS_A16_T (17)
#define RC_A24_LEN (1675)
#define MDS_A24_T (25)
#define RC_A36_LEN (2516)
#define MDS_A36_T (37)
#define RC_A11_LEN (780)
#define MDS_A11_T (12)

// Compressed round constant length
#define CRC_A2_LEN  (79)  // full_round * t + partial_round = 8*3+55
#define CRC_A11_LEN (153) // full_round * t + partial_round = 8*12+57

extern const Fr g_RC_A2[RC_A2_LEN];
extern const Fr g_CRC_A2[CRC_A2_LEN];
extern const Fr g_MDS_A2[MDS_A2_T][MDS_A2_T];
extern const Fr g_RC_A4[RC_A4_LEN];
extern const Fr g_MDS_A4[MDS_A4_T][MDS_A4_T];
extern const Fr g_RC_A8[RC_A8_LEN];
extern const Fr g_MDS_A8[MDS_A8_T][MDS_A8_T];
extern const Fr g_RC_A16[RC_A16_LEN];
extern const Fr g_MDS_A16[MDS_A16_T][MDS_A16_T];
extern const Fr g_RC_A24[RC_A24_LEN];
extern const Fr g_MDS_A24[MDS_A24_T][MDS_A24_T];
extern const Fr g_RC_A36[RC_A36_LEN];
extern const Fr g_MDS_A36[MDS_A36_T][MDS_A36_T];
extern const Fr g_RC_A11[RC_A11_LEN];
extern const Fr g_MDS_A11[MDS_A11_T][MDS_A11_T];
extern const Fr g_CRC_A11[CRC_A11_LEN];

// Tag for the first element of poseidon hash
extern const Fr g_Tag_A2;
extern const Fr g_Tag_A4;
extern const Fr g_Tag_A8;
extern const Fr g_Tag_A16;
extern const Fr g_Tag_A24;
extern const Fr g_Tag_A36;
extern const Fr g_Tag_A11;







///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Only for test sparse matrix generation of 2 arity ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct _TEST_SPARSE_MATRIX_FORARITY2
{
	Fr w_hat[3];
	Fr v_rest[2];

}TEST_SPARSE_MATRIX_FORARITY2;

extern const Fr g_testPreSparse[3][3];
extern const TEST_SPARSE_MATRIX_FORARITY2 g_testSparseMatrix[55];


#endif // !__POSEIDON_CONSTANT_H__
