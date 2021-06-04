#ifndef __GEN_MDS_MATRIX_H__
#define __GEN_MDS_MATRIX_H__

#include "Utilities.h"
#include "FieldOp.h"
#include "MatrixOp.h"


// A `SparseMatrix` is specifically one of the form of M''.
// This means its first row and column are each dense, and the interior matrix
// (minor to the element in both the row and column) is the identity.
// We will pluralize this compact structure `sparse_matrixes` to distinguish from `sparse_matrices` from which they are created.
typedef struct _SparseMatrices
{
	// `w_hat` is the first column of the M'' matrix. It will be directly multiplied (scalar product) with a row of state elements.
	// `v_rest` contains all but the first (already included in `w_hat`).
	Fr* w_hat;   // [width] vector 
	Fr* v_res;   // [width-1] vector 

}SparseMatrices, *PSparseMatrices;

//Fr pre_sparse_matrix[width][width];         // [width][width] matrix
//SparseMatrices sparse_matrices[width];      // [width] SparseMatrices


typedef struct _MDSMatrices
{
	Fr* m;                 // [width][width] matrix
	Fr* m_inv;             // [width][width] matrix
	Fr* m_hat;             // [width-1][width-1] matrix
	Fr* m_hat_inv;         // [width-1][width-1] matrix
	Fr* m_prime;           // [width][width] matrix
	Fr* m_double_prime;    // [width][width] matrix
	uint64_t width;        // Width of the square matrix

} MDSMatrices, *PMDSMatrices;


// Generata a MDS matrix for mix column of poseidon hash with t*t width
// Return the generated matrix in MDS[t][t]
bool GenMDSMatrix(uint64_t t, Fr* mds);

// Generata a inverse MDS matrix from the original mds matrix with the same size
// Return the generated matrix in MDS[t][t]
bool GenMDSInverseMatrix(const Fr* mds, Fr* mds_inv, uint64_t t);

bool MakePrime(const Fr* m, uint64_t width, Fr* resM);

bool MakeDoublePrime(const Fr* m, const Fr* hatInvM, uint64_t width, Fr* resM);

// Input:  m[width][width]
// Output: resV[width-1] and resW[width-1]
bool MakeVW(const Fr* m, uint64_t width, Fr* resV, Fr* resW);

// Derive mds matrices from [mdss->m]
bool DeriveMdsMatrices(PMDSMatrices mdss);

// The [mdss] and [mdss->width] must be initialized before calling this function
// Output [mdss]
bool CreateMdsMatrices(PMDSMatrices mdss);

// Allocate memory for [mdss]
// User must call the [MdssFree] to free memory before discard the [mdss]
bool MdssAlloc(uint64_t width, PMDSMatrices mdss);

// Free memory for [mdss]
bool MdssFree(PMDSMatrices mdss);

// Compare two matrices a[width][width] and b[width][width]
bool MatricesCompare(const Fr* a, const Fr* b, uint64_t width);

// Compare two MDSMatrices
bool MDSMatricesCompare(const PMDSMatrices m1, const PMDSMatrices m2);

// Malloc memory for sparse matrices
PSparseMatrices SparseMatricesMalloc(uint64_t width, uint64_t len);

// Free memory for sparse matrices
void SparseMatricesFree(PSparseMatrices sms, uint64_t len);

// Generate pre-sparse matrix and sparse matrice
bool FactorToSparseMatrix(const Fr* baseM, uint64_t width, uint64_t n, Fr* preSM, PSparseMatrices sparseMs);

// Reset each element of the matrix (m[nrow][ncol])to zero
void ResetMatrix(Fr* m, uint64_t nrow, uint64_t ncol);

// A row vector multiply a sparse matrix with two vectors: w_hat[width] and v_res[width-1]
bool VecMulSparseMatrix(const Fr* v, const PSparseMatrices sparseM, Fr* res, uint64_t width);





#endif // !__GEN_MDS_MATRIX_H__


