#ifndef __MATRIX_OP_H__
#define __MATRIX_OP_H__


#include "FieldOp.h"

// Copy a matrix to another matrix
void MatrixCopy(Fr* dstM, const Fr* srcM, uint64_t width);

// A row vector multiply a matrix to get a new row vector
// vector size of [width], matrix is a square matrix with row and column length is [width]
// ATTENTION: input [v] and output [res] should not point to the same buffer
bool VecMulMatrix(const Fr* v, const Fr* m, Fr* res, uint64_t width);

// A matrix multiply a column vector to get a new column vector
// vector size of [width], matrix is a square matrix with row and column length is [width]
// ATTENTION: input [v] and output [res] should not point to the same buffer
bool MatrixMulVec(const Fr* m, const Fr* v, Fr* res, uint64_t width);

// A row vector add another row vector to get a new row vector
bool VecAddVec(const Fr* v1, const Fr* v2, Fr* res, uint64_t width);

// A scalar multiply a vector
bool ScalarMulVec(const Fr* scalar, const Fr* vec, uint64_t width, Fr* resVec);

// A vector substract a vector: resVec = vec1 - vec2
bool VecSubVec(const Fr* vec1, const Fr* vec2, uint64_t width, Fr* resVec);

// Diagonal elements are all set to 1, other elements are all set to 0
bool MakeIdentityMatrix(Fr* m, uint64_t width);

// Rotate a matrx: set row vectors to column vectors
// The source matrxi and the destination matrix can be the same matrix
bool RotateMatrix(const Fr* srcM, Fr* dstM, uint64_t width);

// Check target matrix: Diagonal elements are all 1 and other elements are all 0?
// Yes return true, No return false
bool IsIdentityMatrix(Fr* m, uint64_t width);

// Remove the [rowIdx]th row and the [colIdx]th column from [srcM] and save the result to [dstM]
// The [dstM] should only has [width-1] rows with each row has [width-1] column
bool GetMinorMatrix(const Fr* srcM, uint64_t rowIdx, uint64_t colIdx, uint64_t width, Fr* dstM);

// Remove one row of the matrix
void RemoveOneRowForMatrix(Fr* m, uint64_t rowIdx, uint64_t width);

// Reverse the elements of a vector
bool ReverseVec(Fr* vec, uint64_t len);

// Reverse the rows of a matrix: exchange the row[i] and row[width - 1 - i]
bool ReverseRowOfMatrix(Fr* m, uint64_t width);

// Elimiate target row [colIdx] elements
bool ElimiateMatrixByColumn(const Fr* srcM, uint64_t colIdx, Fr* shadowM, uint64_t numRows, uint64_t width, Fr* dstM);

// Convert a matrix to upper triangular form: m[i][j] == 0, (i < j)
bool ConvertMatrixToUpperTriangluar(const Fr* srcM, Fr* shadowM, uint64_t width, Fr* dstM);

// Convert a matrix to identity form
bool ReduceMatrixToIdentity(const Fr* srcM, Fr* shadowM, uint64_t width, Fr* dstM);

// Convert a matrix to identity form
bool MatrixInverse(const Fr* srcM, uint64_t width, Fr* dstM);

// Malloc memory for Fr matrix with [width] rows and [width] columns
// Success return the allocated memory pointer, else return NULL
Fr* FrMatrixMalloc(uint64_t width);

// Free memeory for Fr matrix
void FrMatrixFree(Fr* ptr);

// Input: mA[nrowA][ncolA], mB[nrowB][ncolB], require: ncolA == nrowA
// Output: mC[nrowA][ncolB] = mA x mB
bool MatrixMulMatrix(const Fr* mA, uint64_t nrowA, uint64_t ncolA, const Fr* mB, uint64_t nrowB, uint64_t ncolB, Fr* mC);





#endif //!__MATRIX_OP_H__