
#include "GenMDSMatrix.h"


// Generata a MDS matrix for mix column of poseidon hash with t*t width
// Return the generated matrix in MDS[t][t]
bool GenMDSMatrix(uint64_t t, Fr* mds)
{
	bool bRet = false;
	Fr* xs = NULL;
	Fr* ys = NULL;
	Fr* pMi = NULL;
	Fr x = { 0 };
	Fr y = { 0 };
	uint64_t i = 0;
	uint64_t j = 0;

	do
	{
		if (!mds || t < 2)
		{
			break;
		}

		xs = FrArrMalloc(t);
		ys = FrArrMalloc(t);
		if (!xs || !ys)
		{
			break;
		}

		// Generate x and y values deterministically for the cauchy matrix
		// where x[i] != y[i] to allow the values to be inverted
		// and there are no duplicates in the x vector or y vector, so that the determinant is always non-zero
		// [a b]
		// [c d]
		// det(M) = (ad - bc) ; if a == b and c == d => det(M) =0
		// For an MDS matrix, every possible mxm submatrix, must have det(M) != 0

		for (i = 0; i < t; i++)
		{
			FrSet(xs + i, i);
			FrSet(ys + i, i + t);

			//printf("[%02d]:\n", i);
			//HexPrintInBigNum(xs[i].u8, FR_SIZE);
			//HexPrintInBigNum(ys[i].u8, FR_SIZE);

			FrIntoMontg(xs + i, xs + i);
			FrIntoMontg(ys + i, ys + i);
		}

		//puts("Generating xs and ys finished!");

		for (i = 0; i < t; i++)
		{
			//printf("Generating mds row [%02d]:\n", i);
			//printf("xs[i] = ");
			//HexPrintInBigNum(xs[i].u8, FR_SIZE);

			pMi = FrGetMatrixRowOffset(mds, i, t);
			for (j = 0; j < t; j++)
			{
				//printf("Generating mds column [%02d]:\n", j);

				// Generate the MDS matrix at location [i,j]
				FrAdd(xs + i, ys + j, &x);     // x = xi + yj

				//printf("ys[j] = ");
				//HexPrintInBigNum(ys[j].u8, FR_SIZE);
				//printf("xs[i] + ys[j] = ");
				//HexPrintInBigNum(x.u8, FR_SIZE);

				FrInverse(&y, &x);             // y = 1/x
				FrCopy(pMi + j, &y);           // mds[i,j] = y

				//printf("1/(xs[i] + ys[j]) = ");
				//HexPrintInBigNum(y.u8, FR_SIZE);

			}
		}

		bRet = true;

	} while (0);

	if (xs)
	{
		FrArrFree(xs);
		xs = NULL;
	}
	if (ys)
	{
		FrArrFree(ys);
		ys = NULL;
	}

	return bRet;
}

// Generata a inverse MDS matrix from the original mds matrix with the same size
// Return the generated matrix in MDS[t][t]
bool GenMDSInverseMatrix(const Fr* mds, Fr* mds_inv, uint64_t t)
{
	bool bRet = false;
	Fr* xs = NULL;
	Fr* ys = NULL;
	uint64_t i = 0;
	uint64_t j = 0;

	do
	{
		if (!mds || !mds_inv || t < 2)
		{
			break;
		}

		for (i = 0; i < t; i++)
		{
			xs = FrGetMatrixRowOffset(mds, i, t);
			ys = FrGetMatrixRowOffset(mds_inv, i, t);
			for (j = 0; j < t; j++)
			{
				FrInverseOld(ys + j, xs + j);
			}
		}

		bRet = true;

	} while (0);

	return bRet;
}

bool MakePrime(const Fr* m, uint64_t width, Fr* resM)
{
	bool bRet = true;
	uint64_t i = 0, j = 0;
	Fr* rowSrc = NULL;
	Fr* rowDst = NULL;

	for (i = 0; i < width; i++)
	{
		rowSrc = FrGetMatrixRowOffset(m, i, width);
		rowDst = FrGetMatrixRowOffset(resM, i, width);
		if (0 == i)
		{
			FrCopy(rowDst + 0, &g_FrOne);
			for (j = 1; j < width; j++)
			{
				FrZero(rowDst + j);
			}
		}
		else
		{
			FrCopy(rowDst + 0, &g_FrZero);
			for (j = 1; j < width; j++)
			{
				FrCopy(rowDst + j, rowSrc + j);
			}
		}
	}

	return bRet;
}

bool MakeDoublePrime(const Fr* m, const Fr* hatInvM, uint64_t width, Fr* resM)
{
	bool bRet = false;
	uint64_t i = 0, j = 0;
	Fr* rowSrc = NULL;
	Fr* rowDst = NULL;
	Fr* V = NULL;  // A row vector with [width-1] elements, copy from the first row of [m], remove the first element
	Fr* W = NULL;  // A row vector with [width-1] elements, copy from the first column of [m], remove the first element
	Fr* wHat = NULL; // A row vector with [width-1] elements

	do
	{
		V = FrArrMalloc(width - 1);
		W = FrArrMalloc(width - 1);
		wHat = FrArrMalloc(width - 1);
		if (!V || !W || !wHat)
		{
			break;
		}

		// Get the first row and the first column of [m], both remove the first element
		MakeVW(m, width, V, W);

		VecMulMatrix(W, hatInvM, wHat, width - 1);

		for (i = 0; i < width; i++)
		{
			rowSrc = FrGetMatrixRowOffset(m, i, width);
			rowDst = FrGetMatrixRowOffset(resM, i, width);
			if (0 == i)
			{
				FrCopy(rowDst + 0, rowSrc + 0);
				FrCopyArr(rowDst + 1, V, width - 1);
			}
			else
			{
				FrCopy(rowDst + 0, wHat + i - 1);
				for (j = 1; j < width; j++)
				{
					FrCopy(rowDst + j, &g_FrZero);
				}
				FrCopy(rowDst + i, &g_FrOne);
			}
		}

		bRet = true;

	} while (0);
	
	if (V)
	{
		FrArrFree(V);
		V = NULL;
	}

	if (W)
	{
		FrArrFree(W);
		W = NULL;
	}

	if (wHat)
	{
		FrArrFree(wHat);
		wHat = NULL;
	}

	return bRet;
}

// Input:  m[width][width]
// Output: resV[width-1] and resW[width-1]
bool MakeVW(const Fr* m, uint64_t width, Fr* resV, Fr* resW)
{
	bool bRet = true;
	uint64_t i = 0, j = 0;
	const Fr* rowSrc = NULL;
	const Fr* rowDst = NULL;

	// Copy the first row to [resV] as a row vector, except the first element
	rowSrc = FrGetMatrixRowOffset(m, 0, width);
	FrCopyArr(resV, rowSrc + 1, width - 1);

	// Copy the first column to [resW] as a row vector, except the first element
	for (i = 1; i < width; i++)
	{
		rowSrc = FrGetMatrixRowOffset(m, i, width);
		FrCopy(resW + i - 1, rowSrc + 0);
	}

	return bRet;
}

// Derive mds matrices from [mdss->m]
bool DeriveMdsMatrices(PMDSMatrices mdss)
{
	bool bRet = false;
	const Fr* m = NULL;
	uint64_t w = 0;

	do
	{
		if (!mdss)
		{
			break;
		}

		m = mdss->m;
		w = mdss->width;

		//MyPrint("Original mds matrix:");
		//FrPrintMatrixEx(m, w);

		MatrixInverse(m, w, mdss->m_inv);

		GetMinorMatrix(m, 0, 0, w, mdss->m_hat);

		MatrixInverse(mdss->m_hat, w - 1, mdss->m_hat_inv);

		MakePrime(m, w, mdss->m_prime);

		MakeDoublePrime(m, mdss->m_hat_inv, w, mdss->m_double_prime);

		bRet = true;

	} while (0);

	return bRet;
}

// The [mdss] and [mdss->width] must be initialized before calling this function
// Output [mdss]
bool CreateMdsMatrices(PMDSMatrices mdss)
{
	bool bRet = false;

	do
	{
		if (!mdss)
		{
			break;
		}

		bRet = GenMDSMatrix(mdss->width, mdss->m);
		if (!bRet)
		{
			break;
		}

		bRet = DeriveMdsMatrices(mdss);
		if (!bRet)
		{
			break;
		}

		bRet = true;

	} while (0);

	return bRet;
}

// Allocate memory for [mdss]
// User must call the [MdssFree] to free memory before discard the [mdss]
bool MdssAlloc(uint64_t width, PMDSMatrices mdss)
{
	bool bRet = false;
	uint64_t w = 0;
	do
	{
		if (!mdss)
		{
			break;
		}

		Memset(mdss, 0, sizeof(MDSMatrices));

		mdss->width = width;
		w = width;
		if (0 == w)
		{
			break;
		}

		mdss->m = FrMatrixMalloc(w);
		if (!mdss->m)
		{
			break;
		}

		mdss->m_inv = FrMatrixMalloc(w);
		if (!mdss->m_inv)
		{
			break;
		}

		mdss->m_hat = FrMatrixMalloc(w-1);
		if (!mdss->m_hat)
		{
			break;
		}

		mdss->m_hat_inv = FrMatrixMalloc(w-1);
		if (!mdss->m_hat_inv)
		{
			break;
		}

		mdss->m_prime = FrMatrixMalloc(w);
		if (!mdss->m_prime)
		{
			break;
		}

		mdss->m_double_prime = FrMatrixMalloc(w);
		if (!mdss->m_double_prime)
		{
			break;
		}

		bRet = true;

	} while (0);

	return bRet;
}

// Free memory for [mdss]
bool MdssFree(PMDSMatrices mdss)
{
	bool bRet = false;

	do
	{
		if (!mdss)
		{
			break;
		}

		if (mdss->m)
		{
			FrMatrixFree(mdss->m);
			mdss->m = NULL;
		}

		if (mdss->m_inv)
		{
			FrMatrixFree(mdss->m_inv);
			mdss->m_inv = NULL;
		}

		if (mdss->m_hat)
		{
			FrMatrixFree(mdss->m_hat);
			mdss->m_hat = NULL;
		}

		if (mdss->m_hat_inv)
		{
			FrMatrixFree(mdss->m_hat_inv);
			mdss->m_hat_inv = NULL;
		}

		if (mdss->m_prime)
		{
			FrMatrixFree(mdss->m_prime);
			mdss->m_prime = NULL;
		}

		if (mdss->m_double_prime)
		{
			FrMatrixFree(mdss->m_double_prime);
			mdss->m_double_prime = NULL;
		}

		bRet = true;

	} while (0);

	return bRet;
}

// Compare two matrices a[width][width] and b[width][width]
bool MatricesCompare(const Fr* a, const Fr* b, uint64_t width)
{
	uint64_t i = 0;
	uint64_t j = 0;
	const Fr* rowA = NULL;
	const Fr* rowB = NULL;

	for (i = 0; i < width; i++)
	{
		rowA = FrGetMatrixRowOffset(a, i, width);
		rowB = FrGetMatrixRowOffset(b, i, width);
		for (j = 0; j < width; j++)
		{
			if (!FrEqual(rowA + j, rowB + j))
			{
				return false;
			}
		}
	}

	return true;
}

// Compare two MDSMatrices
bool MDSMatricesCompare(const PMDSMatrices m1, const PMDSMatrices m2)
{
	uint64_t i = 0;

	if (m1->width != m2->width)
	{
		MyPrint("Two MDSMatrices have different width, compare failed!");
		return false;
	}

	if (!MatricesCompare(m1->m, m2->m, m1->width))
	{
		MyPrint("Two MDSMatrices have different [m], compare failed!");
		return false;
	}

	if (!MatricesCompare(m1->m_inv, m2->m_inv, m1->width))
	{
		MyPrint("Two MDSMatrices have different [m_inv], compare failed!");
		return false;
	}

	if (!MatricesCompare(m1->m_hat, m2->m_hat, m1->width - 1))
	{
		MyPrint("Two MDSMatrices have different [m_hat], compare failed!");
		return false;
	}

	if (!MatricesCompare(m1->m_hat_inv, m2->m_hat_inv, m1->width - 1))
	{
		MyPrint("Two MDSMatrices have different [m_hat_inv], compare failed!");
		return false;
	}

	if (!MatricesCompare(m1->m_prime, m2->m_prime, m1->width))
	{
		MyPrint("Two MDSMatrices have different [m_prime], compare failed!");
		return false;
	}

	if (!MatricesCompare(m1->m_double_prime, m2->m_double_prime, m1->width))
	{
		MyPrint("Two MDSMatrices have different [m_double_prime], compare failed!");
		return false;
	}

	return true;
}

// Malloc memory for sparse matrices
PSparseMatrices SparseMatricesMalloc(uint64_t width, uint64_t len)
{
	bool bRet = false;
	PSparseMatrices smRet = NULL;
	uint64_t i = 0;
	uint64_t mSize = 0;
	Fr* w = NULL;
	Fr* v = NULL;


	do
	{
		mSize = sizeof(SparseMatrices) * len;
		smRet = (PSparseMatrices)malloc(mSize);
		if (!smRet)
		{
			break;
		}
		Memset(smRet, 0, mSize);

		for (i = 0; i < len; i++)
		{
			w = FrArrMalloc(width);
			v = FrArrMalloc(width);
			smRet[i].w_hat = w;
			smRet[i].v_res = v;
			if (!w || !v)
			{
				break;
			}
		}

		if (i < width)
		{
			break;
		}

		bRet = true;

	} while (0);

	if (!bRet)
	{
		// Free allocate memory
		SparseMatricesFree(smRet, width);
	}

	return smRet;
}

// Free memory for sparse matrices
void SparseMatricesFree(PSparseMatrices sms, uint64_t len)
{
	uint64_t i = 0;

	if (sms)
	{
		for (i = 0; i < len; i++)
		{
			if (sms[i].w_hat)
			{
				FrArrFree(sms[i].w_hat);
				sms[i].w_hat = NULL;
			}
			if (sms[i].v_res)
			{
				FrArrFree(sms[i].v_res);
				sms[i].v_res = NULL;
			}
		}
		free(sms);
		sms = NULL;
	}
}

// Reset each element of the matrix (m[nrow][ncol])to zero
void ResetMatrix(Fr* m, uint64_t nrow, uint64_t ncol)
{
	uint64_t i = 0, j = 0;
	Fr* row = NULL;

	for (i = 0; i < nrow; i++)
	{
		row = FrGetMatrixRowOffset(m, i, ncol);
		for (j = 0; j < ncol; j++)
		{
			FrZero(row + j);
		}
	}
}

// Generate pre-sparse matrix and sparse matrice
bool FactorToSparseMatrix(const Fr* baseM, uint64_t width, uint64_t n, Fr* preSM, PSparseMatrices sparseMs)
{
	bool bRet = false;
	bool bRes = false;
	uint64_t i = 0, j = 0;
	Fr* currM = NULL;
	MDSMatrices derivedMDS = { 0 };
	Fr* rowAcc = NULL;
	Fr** accMs = NULL;  // accMs[n][width*width]
	Fr* accM = NULL;  // accMs[width*width]
	//Fr* doublePrime = NULL;
	//Fr* doublePrimeRow = NULL;
	PSparseMatrices sm = NULL;

	do
	{
		currM = FrMatrixMalloc(width);
		if (!currM)
		{
			break;
		}

		bRes = MdssAlloc(width, &derivedMDS);
		if (!bRes)
		{
			break;
		}

		// Allocae memory for 2 dimension array: accMs[n][width*width]
		accMs = FrHignDimMalloc(n, width*width);
		if (!accMs)
		{
			break;
		}
	
		// Prepare for [currM] and [accMs]
		MatrixCopy(currM, baseM, width);
		for (i = 0; i < n; i++)
		{
			//printf("Round [%d]\n", i);
			derivedMDS.width = width;
			MatrixCopy(derivedMDS.m, currM, width);
			bRes = DeriveMdsMatrices(&derivedMDS);
			if (!bRes)
			{
				break;
			}

			//MyPrint("current matrix:");
			//FrPrintMatrixEx(currM, width);

			//MyPrint("derivedMDS.m_prime:");
			//FrPrintMatrixEx(derivedMDS.m_prime, width);

			//MyPrint("derivedMDS.m_double_prime:");
			//FrPrintMatrixEx(derivedMDS.m_double_prime, width);

			// Copy the generated matrix
			//accM = FrGetMatrixRowOffset(accMs, i, width*width);
			accM = accMs[i];
			MatrixCopy(accM, derivedMDS.m_double_prime, width);
			
			// Reset matrix [currM]
			ResetMatrix(currM, width, width);

			// Mul the [baseM] with [m_prime]
			bRes = MatrixMulMatrix(baseM, width, width, derivedMDS.m_prime, width, width, currM);
			if (!bRes)
			{
				break;
			}
		}
		if (i < n)
		{
			break;
		}

		// Save result
		MatrixCopy(preSM, currM, width);
		for (i = 0; i < n; i++)
		{
			j = n - 1 - i;
			accM = accMs[j];
			sm = sparseMs + i;

			//printf("Middle sparse matrix [%d]\n", i);
			//FrPrintMatrixEx(accM, width);

			// Get the  first column of the [doublePrime]
			for (j = 0; j < width; j++)
			{
				rowAcc = FrGetMatrixRowOffset(accM, j, width);
				FrCopy(sm->w_hat + j, rowAcc + 0);
			}
			// Get the first row of the [doublePrime] except the first element
			rowAcc = FrGetMatrixRowOffset(accM, 0, width);
			FrCopyArr(sm->v_res, rowAcc + 1, width - 1);
		}

		bRet = true;

	} while (0);

	if (currM)
	{
		FrMatrixFree(currM);
		currM = NULL;
	}

	FrHignDimFree(accMs, n);

	MdssFree(&derivedMDS);

	return bRet;
}

// A row vector multiply a sparse matrix with two vectors: w_hat[width] and v_res[width-1]
bool VecMulSparseMatrix(const Fr* v, const PSparseMatrices sparseM, Fr* res, uint64_t width)
{
	bool bRet = false;
	Fr tmp = { 0 };
	Fr* tmpV = NULL;
	uint64_t i = 0;

	do
	{
		if (!v || !sparseM || !res)
		{
			break;
		}

		tmpV = FrArrMalloc(width);
		if (!tmpV)
		{
			break;
		}

		for (i = 0; i < width; i++)
		{
			FrZero(tmpV + i);
		}

		for (i = 0; i < width; i++)
		{
			FrMulV2(sparseM->w_hat + i, v + i, &tmp);
			FrAdd(tmpV + 0, &tmp, tmpV + 0);
		}

		for (i = 1; i < width; i++)
		{
			FrMulV2(sparseM->v_res + i - 1, v + 0, &tmp);
			FrAdd(v + i, &tmp, tmpV + i);
		}

		FrCopyArr(res, tmpV, width);

	} while (0);

	if (tmpV)
	{
		FrArrFree(tmpV);
		tmpV = NULL;
	}

	return bRet;
}

