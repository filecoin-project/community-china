
#include "MatrixOp.h"

// Copy a matrix to another matrix
void MatrixCopy(Fr* dstM, const Fr* srcM, uint64_t width)
{
	uint64_t i = 0;
	Fr* rowSrc = NULL;
	Fr* rowDst = NULL;

	for (i = 0; i < width; i++)
	{
		rowSrc = FrGetMatrixRowOffset(srcM, i, width);
		rowDst = FrGetMatrixRowOffset(dstM, i, width);
		FrCopyArr(rowDst, rowSrc, width);
	}
}

// A row vector multiply a matrix to get a new row vector
// vector size of [width], matrix is a square matrix with row and column length is [width]
// ATTENTION: input [v] and output [res] should not point to the same buffer
bool VecMulMatrix(const Fr* v, const Fr* m, Fr* res, uint64_t width)
{
	bool bRet = false;
	Fr* row = NULL;
	uint64_t i = 0;
	uint64_t j = 0;
	Fr tmp = { 0 };
	Fr sum = { 0 };

	do
	{
		if (!v || !m || !res || width < 2)
		{
			break;
		}

		for (i = 0; i < width; i++)
		{
			FrZero(&sum);
			for (j = 0; j < width; j++)
			{
				// res[i] = sum(v[j] * m[j][i]),   0 <= j < width
				row = FrGetMatrixRowOffset(m, j, width);
				FrMulV2(v + j, row + i, &tmp);
				FrAdd(&sum, &tmp, &sum);
			}
			FrCopy(res + i, &sum);
		}

		bRet = true;

	} while (0);

	return bRet;
}

// A matrix multiply a column vector to get a new column vector
// vector size of [width], matrix is a square matrix with row and column length is [width]
// ATTENTION: input [v] and output [res] should not point to the same buffer
bool MatrixMulVec(const Fr* m, const Fr* v, Fr* res, uint64_t width)
{
	bool bRet = false;
	Fr* row = NULL;
	uint64_t i = 0;
	uint64_t j = 0;
	Fr tmp = { 0 };
	Fr sum = { 0 };

	do
	{
		if (!v || !m || !res || width < 2)
		{
			break;
		}

		for (i = 0; i < width; i++)
		{
			FrZero(&sum);
			row = FrGetMatrixRowOffset(m, i, width);
			for (j = 0; j < width; j++)
			{
				// res[i] = sum(v[j] * m[i][j]),   0 <= j < width
				FrMulV2(v + j, row + j, &tmp);
				FrAdd(&sum, &tmp, &sum);
			}
			FrCopy(res + i, &sum);
		}

		bRet = true;

	} while (0);

	return bRet;
}

// A row vector add another row vector to get a new row vector
bool VecAddVec(const Fr* v1, const Fr* v2, Fr* res, uint64_t width)
{
	bool bRet = false;
	uint64_t i = 0;
	uint64_t j = 0;
	Fr tmp = { 0 };
	Fr sum = { 0 };

	do
	{
		if (!v1 || !v2 || !res || width < 2)
		{
			break;
		}

		for (i = 0; i < width; i++)
		{
			FrAdd(v1 + i, v2 + i, res + i);
		}

		bRet = true;

	} while (0);

	return bRet;
}

// A scalar multiply a vector
bool ScalarMulVec(const Fr* scalar, const Fr* vec, uint64_t width, Fr* resVec)
{
	bool bRet = true;
	uint64_t i = 0;

	for (i = 0; i < width; i++)
	{
		FrMulV2(scalar, vec + i, resVec + i);
	}

	return bRet;
}

// A vector subtract a vector: resVec = vec1 - vec2
bool VecSubVec(const Fr* vec1, const Fr* vec2, uint64_t width, Fr* resVec)
{
	bool bRet = true;
	uint64_t i = 0;

	for (i = 0; i < width; i++)
	{
		FrSub(vec1 + i, vec2 + i, resVec + i);
	}

	return bRet;
}

// Diagonal elements are all set to 1, other elements are all set to 0
bool MakeIdentityMatrix(Fr* m, uint64_t width)
{
	bool bRet = true;
	uint64_t i = 0, j = 0;
	Fr* row = NULL;

	for (i = 0; i < width; i++)
	{
		row = FrGetMatrixRowOffset(m, i, width);
		for (j = 0; j < width; j++)
		{
			if (i == j)
			{
				FrCopy(row + j, &g_FrOne);
			}
			else
			{
				FrCopy(row + j, &g_FrZero);
			}
		}
	}

	return bRet;
}

// Rotate a matrx: set row vectors to column vectors
// The source matrxi and the destination matrix can be the same matrix
bool RotateMatrix(const Fr* srcM, Fr* dstM, uint64_t width)
{
	bool bRet = false;
	uint64_t i = 0, j = 0;
	Fr* rowSrc = NULL;
	Fr* rowDst = NULL;
	Fr* tmpM = NULL;

	do
	{
		tmpM = FrMatrixMalloc(width);
		if (!tmpM)
		{
			break;
		}

		// Dst[j][i] = Src[i][j]
		for (i = 0; i < width; i++)
		{
			rowSrc = FrGetMatrixRowOffset(srcM, i, width);
			for (j = 0; j < width; j++)
			{
				rowDst = FrGetMatrixRowOffset(tmpM, j, width);
				FrCopy(rowDst + i, rowSrc + j);
			}
		}

		// Copy tmp matrix to destination matrix
		for (i = 0; i < width; i++)
		{
			rowSrc = FrGetMatrixRowOffset(tmpM, i, width);
			rowDst = FrGetMatrixRowOffset(dstM, i, width);
			FrCopyArr(rowDst, rowSrc, width);
		}

		bRet = true;

	} while (0);
	
	if (tmpM)
	{
		FrMatrixFree(tmpM);
		tmpM = NULL;
	}

	return bRet;
}

// Check target matrix: Diagonal elements are all 1 and other elements are all 0?
// Yes return true, No return false
bool IsIdentityMatrix(Fr* m, uint64_t width)
{
	bool bRet = true;
	uint64_t i = 0, j = 0;
	Fr* row = NULL;

	for (i = 0; i < width; i++)
	{
		row = FrGetMatrixRowOffset(m, i, width);
		for (j = 0; j < width; j++)
		{
			if (i == j)
			{
				if (!FrEqual(row + j, &g_FrOne))
				{
					bRet = false;
					break;
				}
			}
			else
			{
				if (!FrEqual(row + j, &g_FrZero))
				{
					bRet = false;
					break;
				}
			}
		}
	}

	return bRet;
}

// Remove the [rowIdx]th row and the [colIdx]th column from [srcM] and save the result to [dstM]
// The [dstM] should only has [width-1] rows with each row has [width-1] column
bool GetMinorMatrix(const Fr* srcM, uint64_t rowIdx, uint64_t colIdx, uint64_t width, Fr* dstM)
{
	bool bRet = true;
	uint64_t i = 0, j = 0;
	uint64_t i2 = 0, j2 = 0;
	Fr* rowSrc = NULL;
	Fr* rowDst = NULL;

	for (i = 0, i2 = 0; i < width; i++)
	{
		if (i == rowIdx)
		{
			// Remove this row
			continue;
		}
		rowSrc = FrGetMatrixRowOffset(srcM, i, width);
		rowDst = FrGetMatrixRowOffset(dstM, i2, width - 1);
		i2++;
		for (j = 0, j2 = 0; j < width; j++)
		{
			if (j == colIdx)
			{
				// Remove this column
				continue;
			}
			
			FrCopy(rowDst + j2, rowSrc + j);
			j2++;
		}
	}

	return bRet;
}

// Remove one row of the matrix
void RemoveOneRowForMatrix(Fr* m, uint64_t rowIdx, uint64_t width)
{
	uint64_t i = 0, j = 0;
	Fr* rowSrc = NULL;
	Fr* rowDst = NULL;

	for (i = rowIdx, j = rowIdx + 1; j < width; i++, j++)
	{
		rowDst = FrGetMatrixRowOffset(m, i, width);
		rowSrc = FrGetMatrixRowOffset(m, j, width);
		FrCopyArr(rowDst, rowSrc, width);
	}

	// Reset the last row to zero
	rowDst = FrGetMatrixRowOffset(m, width - 1, width);
	for (i = 0; i < width; i++)
	{
		FrZero(rowDst + i);
	}
}

// Reverse the elements of a vector
bool ReverseVec(Fr* vec, uint64_t len)
{
	bool bRet = true;
	uint64_t i = 0;
	Fr tmp = { 0 };
	Fr* dst = NULL;

	for (i = 0; i < len; i++)
	{
		FrCopy(&tmp, vec + i);
		dst = vec + len - 1 - i;
		FrCopy(vec + i, dst);
		FrCopy(dst, &tmp);
	}

	return bRet;
}

// Reverse the rows of a matrix: exchange the row[i] and row[width - 1 - i]
bool ReverseRowOfMatrix(Fr* m, uint64_t width)
{
	bool bRet = false;
	uint64_t i = 0, dst = 0;
	Fr* tmpRow = NULL;
	Fr* srcRow = NULL;
	Fr* dstRow = NULL;

	do
	{
		tmpRow = FrArrMalloc(width);
		if (!tmpRow)
		{
			break;
		}

		for (i = 0; i < width / 2; i++)
		{
			dst = width - 1 - i;
			srcRow = FrGetMatrixRowOffset(m, i, width);
			dstRow = FrGetMatrixRowOffset(m, dst, width);

			FrCopyArr(tmpRow, srcRow, width);
			FrCopyArr(srcRow, dstRow, width);
			FrCopyArr(dstRow, tmpRow, width);
		}


		bRet = true;

	} while (0);
	
	if (tmpRow)
	{
		FrArrFree(tmpRow);
		tmpRow = NULL;
	}

	return bRet;
}

// Elimiate target row [colIdx] elements
bool ElimiateMatrixByColumn(const Fr* srcM, uint64_t colIdx, Fr* shadowM, uint64_t numRows, uint64_t width, Fr* dstM)
{
	bool bRet = true;
	uint64_t i = 0, j = 0;
	uint64_t pivotIdx = 0;
	Fr* row = NULL;
	Fr* pivotRow = NULL;
	Fr pivotValue = { 0 };
	Fr pivotInv = { 0 };
	Fr val = { 0 };
	Fr tmp = { 0 };
	Fr factor = { 0 };
	uint64_t resRowIdx = 0;
	Fr* dstRow = NULL;
	Fr* scaledPivotV = NULL;
	Fr* eliminatedV = NULL;
	Fr* shadowPivotV = NULL;
	Fr* shadowRow = NULL;
	Fr* scaledShadowPivotV = NULL;

	for (i = 0; i < numRows; i++)
	{
		row = FrGetMatrixRowOffset(srcM, i, width);
		if (!FrEqual(row + colIdx, &g_FrZero))
		{
			for (j = 0; j < colIdx; j++)
			{
				if (!FrEqual(row + j, &g_FrZero))
				{
					break;
				}
			}
			if (colIdx == 0 || j == colIdx)
			{
				pivotIdx = i;
				break;
			}
		}
	}
	if (i == numRows)
	{
		return false;
	}

	pivotRow = FrGetMatrixRowOffset(srcM, pivotIdx, width);
	FrCopy(&pivotValue, pivotRow + colIdx);
	//FrInverse(&pivotInv, &pivotValue);
	FrInverseOld(&pivotInv, &pivotValue);

	//// Debug
	//FrMulV2(&pivotInv, &pivotValue, &tmp);
	//if (!FrEqual(&tmp, &g_FrOne))
	//{
	//	MyPrint("Calculate inverse failed!");
	//}

	do
	{
		scaledPivotV = FrArrMalloc(width);
		eliminatedV = FrArrMalloc(width);
		scaledShadowPivotV = FrArrMalloc(width);
		if (!scaledPivotV || !eliminatedV || !scaledShadowPivotV)
		{
			break;
		}

		// Get the first row
		resRowIdx = 0;
		FrCopyArr(dstM, pivotRow, width);

		for (i = 0; i < numRows; i++)
		{
			if (i == pivotIdx)
			{
				continue;
			}

			row = FrGetMatrixRowOffset(srcM, i, width);
			FrCopy(&val, row + colIdx);

			resRowIdx++;
			dstRow = FrGetMatrixRowOffset(dstM, resRowIdx, width);

			if (FrEqual(&val, &g_FrZero))
			{
				FrCopyArr(dstRow, row, width);
			}
			else
			{
				// factor = val / pivot
				FrMulV2(&val, &pivotInv, &factor);
				
				//MyPrint("val:");
				//FrPrintEx(&val);
				//MyPrint("pivotValue:");
				//FrPrintEx(&pivotValue);
				//MyPrint("pivotInv:");
				//FrPrintEx(&pivotInv);
				//MyPrint("factor:");
				//FrPrintEx(&factor);

				//// Debug
				//FrMulV2(&factor, &pivotValue, &tmp);
				//MyPrint("tmp:");
				//FrPrintEx(&tmp);
				//if (!FrEqual(&tmp, &val))
				//{
				//	MyPrint("Calculate inverse failed!");
				//}

				ScalarMulVec(&factor, pivotRow, width, scaledPivotV);
				VecSubVec(row, scaledPivotV, width, eliminatedV);
				FrCopyArr(dstRow, eliminatedV, width);

				shadowPivotV = FrGetMatrixRowOffset(shadowM, pivotIdx, width);
				ScalarMulVec(&factor, shadowPivotV, width, scaledShadowPivotV);

				shadowRow = FrGetMatrixRowOffset(shadowM, i, width);
				VecSubVec(shadowRow, scaledShadowPivotV, width, shadowRow);
			}
		}

	} while (0);

	if (scaledPivotV)
	{
		FrArrFree(scaledPivotV);
		scaledPivotV = NULL;
	}

	if (eliminatedV)
	{
		FrArrFree(eliminatedV);
		eliminatedV = NULL;
	}

	if (scaledShadowPivotV)
	{
		FrArrFree(scaledShadowPivotV);
		scaledShadowPivotV = NULL;
	}

	return bRet;
}

// Convert a matrix to upper triangular form: m[i][j] == 0, (i < j)
bool ConvertMatrixToUpperTriangluar(const Fr* srcM, Fr* shadowM, uint64_t width, Fr* dstM)
{
	bool bRet = true;
	uint64_t i = 0, j = 0;
	Fr* dstRow = NULL;
	Fr* shadowResultM = NULL;
	Fr* shadowResRow = NULL;
	Fr* currM = NULL;
	Fr* currTM = NULL;
	uint64_t colIdx = 0;
	uint64_t resRowIdx = 0;
	uint64_t numRows = 0;

	do
	{
		currM = FrMatrixMalloc(width);
		currTM = FrMatrixMalloc(width);
		shadowResultM = FrMatrixMalloc(width);
		if (!currM || !currTM || !shadowResultM)
		{
			break;
		}

		MatrixCopy(currM, srcM, width);
		colIdx = 0;
		numRows = width;
		while (numRows > 1)
		{
			//printf("numRows = %d\n", numRows);
			//MyPrint("currM:");
			//FrPrintMatrixEx(currM, width);

			//MyPrint("shadowM:");
			//FrPrintMatrixEx(shadowM, width);

			Memset(currTM, 0, FR_SIZE * width * width);
			ElimiateMatrixByColumn(currM, colIdx, shadowM, numRows, width, currTM);
			MatrixCopy(currM, currTM, width);
			numRows--;

			// Copy the first row of [currM] and [shadowM]
			dstRow = FrGetMatrixRowOffset(dstM, resRowIdx, width);
			FrCopyArr(dstRow, currM, width);
			shadowResRow = FrGetMatrixRowOffset(shadowResultM, resRowIdx, width);
			FrCopyArr(shadowResRow, shadowM, width);

			colIdx++;
			resRowIdx++;

			RemoveOneRowForMatrix(currM, 0, width);
			RemoveOneRowForMatrix(shadowM, 0, width);

		}

		// Copy the first row of [currM] and [shadowM]
		dstRow = FrGetMatrixRowOffset(dstM, resRowIdx, width);
		FrCopyArr(dstRow, currM, width);
		shadowResRow = FrGetMatrixRowOffset(shadowResultM, resRowIdx, width);
		FrCopyArr(shadowResRow, shadowM, width);
		
		MatrixCopy(shadowM, shadowResultM, width);

		bRet = true;

	} while (0);

	if (currM)
	{
		FrMatrixFree(currM);
		currM = NULL;
	}

	if (currTM)
	{
		FrMatrixFree(currTM);
		currTM = NULL;
	}

	if (shadowResultM)
	{
		FrMatrixFree(shadowResultM);
		shadowResultM = NULL;
	}

	return bRet;
}

// Convert a matrix to identity form
bool ReduceMatrixToIdentity(const Fr* srcM, Fr* shadowM, uint64_t width, Fr* dstM)
{
	bool bRet = true;
	uint64_t i = 0, j = 0;
	uint64_t idx = 0, idx2 = 0;
	Fr* srcRow = NULL;
	Fr* shadowRow = NULL;
	Fr* resultM = NULL;
	Fr* resRow = NULL;
	Fr* shadowResultM = NULL;
	Fr* shadowResRow = NULL;
	Fr* normalizedV = NULL;
	Fr* shadowNormalizedV = NULL;
	Fr* subtractedV = NULL;
	Fr* resSubtractedV = NULL;
	uint64_t colIdx = 0;
	uint64_t resRowIdx = 0;
	uint64_t currWidth = 0;
	Fr val, inv;

	//MyPrint("Enter function [ReduceMatrixToIdentity]:");

	do
	{
		normalizedV = FrArrMalloc(width);
		shadowNormalizedV = FrArrMalloc(width);
		subtractedV = FrArrMalloc(width);
		resSubtractedV = FrArrMalloc(width);
		resultM = FrMatrixMalloc(width);
		shadowResultM = FrMatrixMalloc(width);
		if (!normalizedV || !shadowNormalizedV || !subtractedV || !resSubtractedV || !resultM || !shadowResultM)
		{
			break;
		}

		for (i = 0; i < width; i++)
		{
			idx = width - 1 - i;
			srcRow = FrGetMatrixRowOffset(srcM, idx, width);
			shadowRow = FrGetMatrixRowOffset(shadowM, idx, width);

			FrCopy(&val, srcRow + idx);
			FrInverseOld(&inv, &val);

			ScalarMulVec(&inv, srcRow, width, normalizedV);
			ScalarMulVec(&inv, shadowRow, width, shadowNormalizedV);

			//printf("i = %d\n", i);
			//printf("idx = %d\n", idx);
			//MyPrint("val:");
			//FrPrintEx(&val);
			//MyPrint("inv:");
			//FrPrintEx(&inv);

			//MyPrint("normalizedV:");
			//FrPrintArrEx(normalizedV, width);
			//MyPrint("shadowNormalizedV:");
			//FrPrintArrEx(shadowNormalizedV, width);

			for (j = 0; j < i; j++)
			{
				idx2 = width - j - 1;
				FrCopy(&val, normalizedV + idx2);

				resRow = FrGetMatrixRowOffset(resultM, j, width);
				shadowResRow = FrGetMatrixRowOffset(shadowResultM, j, width);
				ScalarMulVec(&val, resRow, width, subtractedV);
				ScalarMulVec(&val, shadowResRow, width, resSubtractedV);

				VecSubVec(normalizedV, subtractedV, width, normalizedV);
				VecSubVec(shadowNormalizedV, resSubtractedV, width, shadowNormalizedV);

				//printf("j = %d\n", j);
				//printf("idx2 = %d\n", idx2);
				//MyPrint("val:");
				//FrPrintEx(&val);

				//MyPrint("resRow:");
				//FrPrintArrEx(resRow, width);
				//MyPrint("shadowResRow:");
				//FrPrintArrEx(shadowResRow, width);

				//MyPrint("subtractedV:");
				//FrPrintArrEx(subtractedV, width);
				//MyPrint("resSubtractedV:");
				//FrPrintArrEx(resSubtractedV, width);

				//MyPrint("normalizedV:");
				//FrPrintArrEx(normalizedV, width);
				//MyPrint("shadowNormalizedV:");
				//FrPrintArrEx(shadowNormalizedV, width);
			}

			resRow = FrGetMatrixRowOffset(resultM, i, width);
			FrCopyArr(resRow, normalizedV, width);
			shadowResRow = FrGetMatrixRowOffset(shadowResultM, i, width);
			FrCopyArr(shadowResRow, shadowNormalizedV, width);
		}

		// Reverse the row of matrix and save the result
		ReverseRowOfMatrix(resultM, width);
		ReverseRowOfMatrix(shadowResultM, width);
		MatrixCopy(dstM, resultM, width);
		MatrixCopy(shadowM, shadowResultM, width);

		bRet = true;

	} while (0);

	if (normalizedV)
	{
		FrArrFree(normalizedV);
		normalizedV = NULL;
	}

	if (shadowNormalizedV)
	{
		FrArrFree(shadowNormalizedV);
		shadowNormalizedV = NULL;
	}

	if (subtractedV)
	{
		FrArrFree(subtractedV);
		subtractedV = NULL;
	}

	if (resSubtractedV)
	{
		FrArrFree(resSubtractedV);
		resSubtractedV = NULL;
	}

	if (resultM)
	{
		FrMatrixFree(resultM);
		resultM = NULL;
	}

	if (shadowResultM)
	{
		FrMatrixFree(shadowResultM);
		shadowResultM = NULL;
	}

	return bRet;
}

// Convert a matrix to identity form
bool MatrixInverse(const Fr* srcM, uint64_t width, Fr* dstM)
{
	bool bRet = true;
	Fr* upperTriangularM = NULL;
	Fr* shadowM = NULL;
	Fr* tmpM = NULL;


	do
	{
		upperTriangularM = FrMatrixMalloc(width);
		shadowM = FrMatrixMalloc(width);
		tmpM = FrMatrixMalloc(width);
		if (!upperTriangularM || !shadowM || !tmpM)
		{
			break;
		}

		MakeIdentityMatrix(shadowM, width);

		//MyPrint("Shadow matrix:");
		//FrPrintMatrixEx(shadowM, width);

		ConvertMatrixToUpperTriangluar(srcM, shadowM, width, upperTriangularM);

		//MyPrint("Shadow matrix:");
		//FrPrintMatrixEx(shadowM, width);

		//MyPrint("Upper triangular matrix:");
		//FrPrintMatrixEx(upperTriangularM, width);

		ReduceMatrixToIdentity(upperTriangularM, shadowM, width, tmpM);

		//MyPrint("Reduce to identity matrix:");
		//FrPrintMatrixEx(upperTriangularM, width);

		MatrixCopy(dstM, shadowM, width);

		bRet = true;

	} while (0);

	if (upperTriangularM)
	{
		FrMatrixFree(upperTriangularM);
		upperTriangularM = NULL;
	}

	if (shadowM)
	{
		FrMatrixFree(shadowM);
		shadowM = NULL;
	}

	if (tmpM)
	{
		FrMatrixFree(tmpM);
		tmpM = NULL;
	}

	return bRet;
}

// Malloc memory for Fr matrix with [width] rows and [width] columns
// Success return the allocated memory pointer, else return NULL
Fr* FrMatrixMalloc(uint64_t width)
{
	Fr* ret = NULL;

	ret = (Fr*)malloc(FR_SIZE * width * width);

	return ret;
}

// Free memeory for Fr matrix
void FrMatrixFree(Fr* ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

// Input: mA[nrowA][ncolA], mB[nrowB][ncolB], require: ncolA == nrowA
// Output: mC[nrowA][ncolB] = mA x mB
bool MatrixMulMatrix(const Fr* mA, uint64_t nrowA, uint64_t ncolA, const Fr* mB, uint64_t nrowB, uint64_t ncolB, Fr* mC)
{
	bool bRet = false;
	Fr* rowA = NULL;
	Fr* rowB = NULL;
	Fr* rowC = NULL;
	uint64_t i = 0, j = 0, k = 0;
	Fr tmp = { 0 };
	Fr sum = { 0 };

	do
	{
		if (!mA || !mB || !mC || ncolA != nrowB)
		{
			break;
		}

		for (i = 0; i < nrowA; i++)
		{
			rowA = FrGetMatrixRowOffset(mA, i, ncolA);
			rowC = FrGetMatrixRowOffset(mC, i, ncolB);
			for (j = 0; j < ncolB; j++)
			{
				FrZero(&sum);
				// ncolA == nrowB
				for (k = 0; k < ncolA; k++)
				{
					rowB = FrGetMatrixRowOffset(mB, k, ncolB);
					FrMulV2(rowA + k, rowB + j, &tmp);
					FrAdd(&sum, &tmp, &sum);
				}

				// C[i][j] = A[i][k] * B[k][j], k from 0 to [ncolA]
				FrCopy(rowC + j, &sum);
			}
		}

		bRet = true;

	} while (0);

	return bRet;
}
