
#include "Poseidon.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void TestFrCopy()
{
	Fr t = { 0 };

	FrCopy(&t, &(g_ConstC[0][0]));

	MyPrint("Fr in limbs:");
	FrPrint(&t);

	MyPrint("Fr raw in hexadecimal:");
	HexPrintInRaw(&t, FR_SIZE);

	MyPrint("Fr big integer in hexadecimal:");
	HexPrintInBigNum(&t, FR_SIZE);

	puts("");
}

static void TestGetStringLength()
{
	uint64_t i = 0;
	const uint64_t N = 5;
	char s[5][100] = 
	{
		"",
		"d",
		"d ",
		"dfgdfghdf12345649846515616541ferg43w91244934549746996489-40",
	};
	uint64_t strLen1 = 0;
	uint64_t strLen2 = 0;


	for (i = 0; i < N; i++)
	{
		strLen1 = GetStringLength(s[i]);
		strLen2 = strlen(s[i]);
		printf("len1 = %d, len 2 = %d\n", strLen1, strLen2);
		if (strLen1 != strLen2)
		{
			puts("Get string length failed!\n");
		}
	}
	puts("");
}

static void TestConvertStringToFr()
{
	char* str = "0x29176100eaa962bdc1fe6c654d6a3c130e96a4d1168b33848b897dc502820133";
	char* str2 = "0x09c46e9ec68e9bd4fe1faaba294cba38a71aa177534cdd1b6c7dc0dbd0abd7a7";
	Fr dst = { 0 };
	bool bRet = false;

	printf("Source string: %s\n", str);
	bRet = FrFromHexStringInBigNum(&dst, str);
	if (bRet)
	{
		MyPrint("Convert result in Fr representation:");
		FrPrint(&dst);
	}

	printf("Source string: %s\n", str2);
	bRet = FrFromHexStringInBigNum(&dst, str2);
	if (bRet)
	{
		MyPrint("Convert result in Fr representation:");
		FrPrint(&dst);
	}
	puts("");
}

static void TestPoseidonHash()
{
	bool bRet = false;
	Fr src = { 0 };
	Fr dst = { 0 };
	FrEx dst2 = { 0 };
	Fr realRes = { 0 };
	char* realFr = "0x29176100eaa962bdc1fe6c654d6a3c130e96a4d1168b33848b897dc502820133";

	FrSet(&src, 1);
	//FrIntoMontg(&src, &src);
	bRet = FrFromHexStringInBigNum(&realRes, realFr);

	MyPrint("Input data:");
	FrPrint(&src);

	PoseidonHash(&src, 1, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);

	//FrFromMontg(&dst, &dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);

	//MyPrint("The current result (In residual domain):");
	//FrPrint(&dst);

	if (bRet)
	{
		MyPrint("Poseidon hash correct!");
	}
	else
	{
		MyPrint("Poseidon hash failed!");
	}

	puts("");
}

static void TestModulusAndGen()
{
	MyPrint("Poseidon modulus in limbs:");
	FrPrint(&g_FrM);

	MyPrint("Poseidon modulus in raw hexadecimal:");
	HexPrintInRaw(&g_FrM, FR_SIZE);

	MyPrint("Poseidon modulus big integer in hexadecimal:");
	HexPrintInBigNum(&g_FrM, FR_SIZE);

	MyPrint("Poseidon generator in limbs:");
	FrPrint(&g_FrG);

	MyPrint("Poseidon generator in raw hexadecimal:");
	HexPrintInRaw(&g_FrG, FR_SIZE);

	MyPrint("Poseidon generator big integer in hexadecimal:");
	HexPrintInBigNum(&g_FrG, FR_SIZE);

	puts("");
}

static void TestFrAdd()
{
	Fr a = { 0 };
	Fr b = { 0 };
	Fr c = { 0 };
	Fr real = { 0 };
	bool bRet = false;

	char *strA    = "0x2831cc8647d7df7601ba031deaee027164a5daf05cbc5b69e6889152a00625c0";
	char *strB    = "0x29145660eaa962bd16a11b1c654d48561566c161a666b6a6b66c6c666f661332";
	char *strReal = "0x522bb761d552c57ad89f8781b2b7846923fd6632bcf1ea2b41f5ea2b71e81465";

	bRet = FrFromHexStringInBigNum(&a, strA);
	bRet = FrFromHexStringInBigNum(&b, strB);
	bRet = FrFromHexStringInBigNum(&real, strReal);


	MyPrint("Modulus:");
	FrPrint(&g_FrM);
	HexPrintInBigNum(g_FrM.u8, FR_SIZE);

	MyPrint("A:");
	FrPrint(&a);

	MyPrint("B:");
	FrPrint(&b);

	MyPrint("real result:");
	FrPrint(&real);

	FrAdd(&a, &b, &c);

	MyPrint("Computed result:");
	FrPrint(&c);

	if (FrEqual(&c, &real))
	{
		MyPrint("FrAdd computed success!");
	}
	else
	{
		MyPrint("FrAdd computed failed!");
	}
}

static void TestFrAdd2()
{
	Fr a = { 0 };
	Fr b = { 0 };
	Fr c = { 0 };
	bool bRet = false;
	uint64_t i = 0;
	const uint64_t N = 100;

	MyPrint("Modulus:");
	FrPrint(&g_FrM);
	HexPrintInBigNum(g_FrM.u8, FR_SIZE);

	for (i = 0; i < N; i++)
	{
		printf("Test [%d]...\n", i);

		FrGenRand(&a);
		FrGenRand(&b);

		MyPrint("A:");
		FrPrint(&a);
		HexPrintInBigNum(a.u8, FR_SIZE);

		MyPrint("B:");
		FrPrint(&b);
		HexPrintInBigNum(b.u8, FR_SIZE);

		FrAdd(&a, &b, &c);
		MyPrint("Result of C = (A+B)%M :");
		FrPrint(&c);
		HexPrintInBigNum(c.u8, FR_SIZE);
	}
}

static void TestFrMul()
{
	Fr a = { { 0x8f165d68ab85d15d, 0x6eb3cfcbb78de1f8, 0x81e68cc8607bf73c, 0x1da780117e696564 } };
	Fr b = { { 0x30c76af2d56152c5, 0x9e5a9ebfe1d3ec63, 0xf9aed7a28decf7c7, 0x0363b976489de83d } };
	Fr c = { 0 };
	FrEx c2 = { 0 };
	Fr real = { 0 };
	bool bRet = false;

	char *strA = "0x2831cc8647d7df7601ba031deaee027164a5daf05cbc5b69e6889152a00625c0";
	char *strB = "0x29145660eaa962bd16a11b1c654d48561566c161a666b6a6b66c6c666f661332";
	char *strReal = "0x138ed87bad41014507cd0e666280f5911565a166de5ff72cdfa78776fa607966";
	// R = 0x1d94cbe409d8a6948af553587095b38dfa496289ca04aa755a1183e3c4e47c7d
	// M = 0x30644e72e131a029b85045b68181585d2833e84879b9709143e1f593f0000001

	//bRet = FrFromHexStringInBigNum(&a, strA);
	//bRet = FrFromHexStringInBigNum(&b, strB);
	bRet = FrFromHexStringInBigNum(&real, strReal);

	FrSimpleReduce(&a);
	FrSimpleReduce(&b);

	MyPrint("Modulus:");
	FrPrint(&g_FrM);
	HexPrintInBigNum(g_FrM.u8, FR_SIZE);

	MyPrint("A:");
	FrPrint(&a);
	HexPrintInBigNum(a.u8, FR_SIZE);

	MyPrint("B:");
	FrPrint(&b);
	HexPrintInBigNum(b.u8, FR_SIZE);

	MyPrint("real result:");
	FrPrint(&real);
	HexPrintInBigNum(real.u8, FR_SIZE);

	FrMul(&a, &b, &c);
	Fr2FrEx(&c2, &c);
	FrMontgReduce2(&c, &c2); // Convert from montgomary field to prime field

	MyPrint("Computed result:");
	FrPrint(&c);
	HexPrintInBigNum(c.u8, FR_SIZE);

	if (FrEqual(&c, &real))
	{
		MyPrint("FrMul computed success!");
	}
	else
	{
		MyPrint("FrMul computed failed!");
	}
}

static void TestFrMul2()
{
	uint64_t i = 0;
	uint64_t succ = 0;
	Fr a = { 0 };
	Fr b = { 0 };
	Fr c = { 0 };
	Fr real = { 0 };
	bool bRet = false;

	// M = 0x30644e72e131a029b85045b68181585d2833e84879b9709143e1f593f0000001

	static const uint64_t N = 10;
	Fr arrA[10] =
	{
		{ { 0xec8798acee3836b1, 0xf481e8a5dca59f38, 0x97157be7574c073d, 0x249dad69cda985ed } },
		{ { 0x22e5e90185accff1, 0x88a297efcbb1fe5a, 0x02d03e6650ff3076, 0x222c812d88fcc6e0 } },
		{ { 0x349facbcbeccde8e, 0xf3f23e0085deaac4, 0x391fc33de9d5a842, 0x2fefa441012ebd40 } },
		{ { 0xb0b790cf7af31f7f, 0x0bd000432eadbf85, 0x84eeba92cec91423, 0x01067a92253e512d } },
		{ { 0xfde3ce71e75615c2, 0x9e5cabb401d1cf8a, 0x4ade591021de532e, 0x2749764fb38f5660 } },
		{ { 0x7b7aa6f816212993, 0xa22f1d83423bf066, 0x65bde55d075139eb, 0x2807d5c6d0b50575 } },
		{ { 0x32cb758ab2a73bda, 0x579431034483354b, 0x5c66e4b95a16a528, 0x0177cc5378cfea68 } },
		{ { 0xd3d9e8e5ff6481bf, 0x4648789415bb9a5b, 0x081f66cf59d490ab, 0x0b5a918e0bb6ac5b } },
		{ { 0x5523ee59a0e95651, 0x644907f947ba75fe, 0x2cbb5a2fee969b1d, 0x1df040e040dc3f32 } },
		{ { 0xd5e41936967dc232, 0xcb589f81eff148a6, 0x609f82fe5a6aaf98, 0x0249d76c9cdd6411 } },
	};
	Fr arrB[10] =
	{
		{ { 0xbbf453bf7d71755c, 0xffa10ad45aed2816, 0x1580603275286802, 0x2a23f264eaa24a29 } },
		{ { 0x84781392f027dd58, 0x303147927da3c685, 0x624403ba775f10fe, 0x24cc9b07e8720301 } },
		{ { 0x16034069b8525223, 0x9a71b60b5becfbe6, 0x2733d5be70ad255c, 0x2ee4dcc0ae2fb8ed } },
		{ { 0x9e105e66875fc8c5, 0xff00b893f263e9f8, 0x9310eca40e58893d, 0x2e5a0c78aa5ffaa6 } },
		{ { 0xe5c4072a24dde12c, 0xfa6629df2e36216a, 0x6729ca0d6d2f2750, 0x0fe043efe98e5bbb } },
		{ { 0x5c00a427d857e1eb, 0x19bb8caf030195b9, 0x513559cec15a9873, 0x28f29dcb1b1ce3d5 } },
		{ { 0xb6f752b9f70fcc2c, 0xc5b25c1ed9608dcb, 0x969d4e052048419a, 0x0b8f7edd22c6e0c3 } },
		{ { 0x0a0349ec5b405f79, 0x5e56336474930b4c, 0x34ec0eefe41b5a70, 0x1417fb0b18bc65d1 } },
		{ { 0x0d02c6c0cc46ee13, 0x81ee2d66272e4a5a, 0x39dd1dd59badacae, 0x209a44d30e2176f4 } },
		{ { 0x3049b175bc07edbf, 0xfcc3ada95a05b8bb, 0xfdaa2004f706e0a2, 0x0b386bce9d7d16c1 } },
	};
	Fr arrC[10] =
	{
		{ { 0x1842ea0c7eaaba88, 0x535f48ab07582cf7, 0x9ebcf3bffebc10e9, 0x06690414405de81e } },
		{ { 0x08a265b576e5607a, 0xa5ef3ba46e380250, 0x7f7659cf4982f88e, 0x0fb85373d2e15933 } },
		{ { 0x80c65c62a25a7c6d, 0xfad11e02b3876128, 0x3746040a4c691071, 0x107798b5ca3b375c } },
		{ { 0xbc92b1ab9d441b85, 0x1a0d3819414f5465, 0xf3ae69c0830def8a, 0x26629d5a2ea0206d } },
		{ { 0x2b46fe42e34c6cf0, 0xdc4f2abf043ca4c5, 0x15d530f96d47bb3e, 0x1771199914e1e9ad } },
		{ { 0x3961b8f4b809cfbc, 0x104a266fd265a0f1, 0x769b3531f21f8129, 0x1567986188267597 } },
		{ { 0x5d746fa504f95640, 0x1e8222e7bb44d376, 0x6eeb753a12074efe, 0x05e787a14d57150d } },
		{ { 0x11b833ccdf5d7482, 0x4a739dc1f551cbe0, 0xb7f499855aa651c4, 0x247110466fbc1d18 } },
		{ { 0x8360b53a17d03184, 0x01d474b3fb3ad44a, 0x1a3da375b3b218f2, 0x0afd95fb814dfb4b } },
		{ { 0xefcaa8a6bc6061f8, 0xbb716fe7397933a5, 0x8f1aa751032e69fe, 0x01e980ac62afea1b } },
	};

	MyPrint("Modulus:");
	FrPrint(&g_FrM);
	HexPrintInBigNum(g_FrM.u8, FR_SIZE);

	for (i = 0; i < N; i++)
	{
		printf("Round [%d]:\n", i);

		// Convert from residual domain to montgomary domain
		FrIntoMontg(&a, &arrA[i]);
		FrIntoMontg(&b, &arrB[i]);

		MyPrint("A:");
		FrPrint(&a);
		HexPrintInBigNum(a.u8, FR_SIZE);

		MyPrint("B:");
		FrPrint(&b);
		HexPrintInBigNum(b.u8, FR_SIZE);

		MyPrint("Real result:");
		FrPrint(&arrC[i]);
		HexPrintInBigNum(arrC[i].u8, FR_SIZE);

		FrMul(&a, &b, &c);

		MyPrint("Unconverted computed result:");
		FrPrint(&c);
		HexPrintInBigNum(c.u8, FR_SIZE);

		// Convert from montgomary field to prime field
		FrFromMontg(&c, &c);

		MyPrint("Computed result:");
		FrPrint(&c);
		HexPrintInBigNum(c.u8, FR_SIZE);

		if (FrEqual(&c, &arrC[i]))
		{
			succ += 1;
			MyPrint("FrMul2 computed success!");
		}
		else
		{
			MyPrint("FrMul2 computed failed!");
		}
	}

	printf("Total count : [%d], success : [%d], failed : [%d]\n", N, succ, N-succ);
}

static void TestBnMul()
{
	Fr a = { 0 };
	Fr b = { 0 };
	FrEx c = { 0 };
	FrEx real = { 0 };
	bool bRet = false;

	const char *strA = "0x2831cc8647d7df7601ba031deaee027164a5daf05cbc5b69e6889152a00625c0";
	const char *strB = "0x29145660eaa962bd16a11b1c654d48561566c161a666b6a6b66c6c666f661332";
	const char *strReal = "0x06732b356e391b785472176c1cb60ed09cf4437737b0dd48bc6549a7dafa85654f805c449ce43517183c4850b9dcda2ecda770eaa0656694ab23fb5500809f80";

	bRet = FrFromHexStringInBigNum(&a, strA);
	bRet = FrFromHexStringInBigNum(&b, strB);
	bRet = FrExFromHexStringInBigNum(&real, strReal);

	MyPrint("A:");
	HexPrintInBigNum(a.u8, FR_SIZE);

	MyPrint("B:");
	HexPrintInBigNum(b.u8, FR_SIZE);

	MyPrint("real result:");
	HexPrintInBigNum(real.u8, FREX_SIZE);

	BnMul(a.u8, b.u8, c.u8);

	MyPrint("Computed result:");
	HexPrintInBigNum(c.u8, FREX_SIZE);

	if (BnEqualEx(c.u8, real.u8, FREX_LEN))
	{
		MyPrint("BnMul computed success!");
	}
	else
	{
		MyPrint("BnMul computed failed!");
	}
}

static void TestBnMul2()
{
	Fr a = { 0 };
	Fr b = { 0 };
	FrEx c = { 0 };
	FrEx c2 = { 0 };
	bool bRet = false;
	uint64_t i = 0;
	const uint64_t N = 20000;
	uint64_t seed = 1;

	GetRawRandom(&seed, sizeof(seed));
	init_rand(seed);

	for (i = 0; i <= N; i++)
	{
		printf("Test [%d]: ", i);

		FrGenRand(&a);
		FrGenRand(&b);

		BnMul(a.u8, b.u8, c.u8);
		
		BnMulEx(a.u8, b.u8, c2.u8);
		
		if (BnEqual(c.u8, c2.u8))
		{
			MyPrint("C1 == C2: Test success!");
		}
		else
		{
			MyPrint("C1 != C2: Test Failed!");

			MyPrint("A:");
			FrPrint(&a);
			HexPrintInBigNum(a.u8, FR_SIZE);

			MyPrint("B:");
			FrPrint(&b);
			HexPrintInBigNum(b.u8, FR_SIZE);

			MyPrint("Result of C = (A*B) :");
			FrExPrint(&c);
			HexPrintInBigNum(c.u8, FREX_SIZE);

			MyPrint("Result of C2 = (A*B) :");
			FrExPrint(&c2);
			HexPrintInBigNum(c2.u8, FREX_SIZE);
		}
	}
}

static void TestBnReduce()
{
	bool bRet = false;
	FrEx a = { 0 };
	Fr r = { 0 };
	Fr realR = { 0 };

	uint64_t tmpA[BN_LIMBS * 2] = 
	{
		0xAED66CE184BE2329, 0xEBE9BBF1F1499052, 0x993E0C873CDBA6B3, 0xDE47B7061C0D5E24,
		0xA68BBB43C84D12B3, 0x1F2538097D5A031F, 0x3B45F596FCCBD45D, 0x32AEDB1C0A890D13
	};

	const char *strRealR = "0x138ed87bad41014507cd0e666280f5911565a166de5ff72cdfa78776fa607966";
	const char *strA = "0x06732b356e391b785472176c1cb60ed09cf4437737b0dd48bc6549a7dafa85654f805c449ce43517183c4850b9dcda2ecda770eaa0656694ab23fb5500809f80";
	// M: 0x30644e72e131a029b85045b68181585d2833e84879b9709143e1f593f0000001

	bRet = FrExFromHexStringInBigNum(&a, strA);
	bRet = FrFromHexStringInBigNum(&realR, strRealR);

	BnCopy(a.u8, tmpA, BN_LIMBS * 2);

	MyPrint("A:");
	FrExPrint(&a);
	//FrExPrintAsBigNum(&a);
	HexPrintInBigNum(a.u8, FREX_SIZE);

	MyPrint("M:");
	HexPrintInBigNum(g_FrM.u8, FR_SIZE);

	MyPrint("Real reduce result:");
	HexPrintInBigNum(realR.u8, FR_SIZE);

	BnReduce(r.u8, a.u8, g_FrM.u8);

	MyPrint("Computed reduce result:");
	HexPrintInBigNum(r.u8, FR_SIZE);

	if (BnEqual(r.u8, realR.u8))
	{
		MyPrint("BnReduce computed success!");
	}
	else
	{
		MyPrint("BnReduce computed failed!");
	}
}

static void TestComplementCode()
{
	int a = 0xabc4545;
	int b = 0x9645845;
	int c1 = 0, c2 = 0;
	int bb = 0;

	c1 = a - b;
	
	bb = ~b;
	bb += 1;
	c2 = a + bb;

	printf("a = 0x%08x\n", a);
	printf("b = 0x%08x\n", b);
	printf("bb = (~b + 1) = 0x%08x\n", bb);
	printf("c1 = a - b = 0x%08x\n", c1);
	printf("c2 = a + (~b + 1) = 0x%08x\n", c2);

	if (c1 == c2)
	{
		printf("c1 == c2\n");
	}
	else
	{
		printf("c1 != c2\n");
	}
}

static void TestMontgReduce()
{
	bool bRet = false;
	FrEx a = { 0 };
	Fr r = { 0 };
	Fr realR = { 0 };

	uint64_t tmpA[BN_LIMBS * 2] =
	{
		0x22cbc95d40000096, 0x2805810351078005, 0xf2e75e056633dcdf, 0xbcc2eb1603d7e5b5,
		0x24f4c58fc4c0117f, 0x12b2889f61ebc2b8, 0x4dacfbe3925a66e1, 0x049ee1287ff6bbd5
	};

	const char *strRealR = "0x23da8016bafd9af2ae478ee651564cb821b6df39428b5e68c7a34315efffffe1";
	const char *strA = "0x049ee1287ff6bbd54dacfbe3925a66e112b2889f61ebc2b824f4c58fc4c0117fbcc2eb1603d7e5b5f2e75e056633dcdf280581035107800522cbc95d40000096";
	// M: 0x30644e72e131a029b85045b68181585d2833e84879b9709143e1f593f0000001

	bRet = FrExFromHexStringInBigNum(&a, strA);
	bRet = FrFromHexStringInBigNum(&realR, strRealR);

	BnCopy(a.u8, tmpA, BN_LIMBS * 2);

	MyPrint("A:");
	FrExPrint(&a);
	//FrExPrintAsBigNum(&a);
	HexPrintInBigNum(a.u8, FREX_SIZE);

	MyPrint("M:");
	HexPrintInBigNum(g_FrM.u8, FR_SIZE);

	MyPrint("INV:");
	FrPrint(&g_FrInv);
	HexPrintInBigNum(g_FrInv.u8, FR_SIZE);

	MyPrint("Real reduce result:");
	FrPrint(&realR);
	HexPrintInBigNum(realR.u8, FR_SIZE);

	FrMontgReduce(&r, &a);
	//FrMontgReduce2(&r, &a);

	MyPrint("Computed reduce result:");
	FrPrint(&r);
	HexPrintInBigNum(r.u8, FR_SIZE);

	if (BnEqual(r.u8, realR.u8))
	{
		MyPrint("FrMontgReduce computed success!");
	}
	else
	{
		MyPrint("FrMontgReduce computed failed!");
	}
}

static void TestFrRandGen()
{
	uint64_t i = 0;
	uint64_t N = 20;
	Fr a;

	for (i = 0; i < N; i++)
	{
		printf("Test [%d]...\n", i);

		FrGenRand(&a);
		MyPrint("A:");
		FrPrint(&a);
		HexPrintInBigNum(a.u8, FR_SIZE);
	}
}

static void TestFrSquare()
{
	Fr a = { { 0x6c7dc0dbd0abd7a7, 0xa71aa177534cdd1b, 0xfe1faaba294cba38, 0x09c46e9ec68e9bd4 } };
	Fr c = { 0 };
	Fr real = { 0xbe133dc574b71da5, 0x7714112beac1cc97, 0xa0412655c67e902c, 0x280168979d0214dd };
	bool bRet = false;

	char *strA = "0x09c46e9ec68e9bd4fe1faaba294cba38a71aa177534cdd1b6c7dc0dbd0abd7a7";
	char *strReal = "0x280168979d0214dda0412655c67e902c7714112beac1cc97be133dc574b71da5";

	// M = 0x30644e72e131a029b85045b68181585d2833e84879b9709143e1f593f0000001

	bRet = FrFromHexStringInBigNum(&a, strA);
	bRet = FrFromHexStringInBigNum(&real, strReal);
	

	MyPrint("Modulus:");
	FrPrint(&g_FrM);
	HexPrintInBigNum(g_FrM.u8, FR_SIZE);

	MyPrint("A (Before convert to montg field):");
	FrPrint(&a);
	HexPrintInBigNum(a.u8, FR_SIZE);
	FrIntoMontg(&a, &a);
	MyPrint("A (After convert to montg field):");
	FrPrint(&a);
	HexPrintInBigNum(a.u8, FR_SIZE);

	MyPrint("real result:");
	FrPrint(&real);
	HexPrintInBigNum(real.u8, FR_SIZE);

	FrSquare(&a, &c);

	MyPrint("Computed result (Before convert to normal field):");
	FrPrint(&c);
	HexPrintInBigNum(c.u8, FR_SIZE);

	FrFromMontg(&c, &c);// Convert from montgomary field to residual

	MyPrint("Computed result (After convert to normal field):");
	FrPrint(&c);
	HexPrintInBigNum(c.u8, FR_SIZE);

	if (FrEqual(&c, &real))
	{
		MyPrint("FrSquare computed success!");
	}
	else
	{
		MyPrint("FrSquare computed failed!");
	}
}

static void TestMontg()
{
	Fr a = { { 0x267927fead0699bd, 0xa3198e8684fc7561, 0x19d7c413aea8bcd5, 0x1f5ea6937614c33c } };
	Fr b = { 0 };
	Fr c = { 0 };
	Fr real = { 0xbe133dc574b71da5, 0x7714112beac1cc97, 0xa0412655c67e902c, 0x280168979d0214dd };

	MyPrint("A in montgomary field:");
	FrPrint(&a);
	HexPrintInBigNum(a.u8, FR_SIZE);

	FrFromMontg(&b, &a);

	MyPrint("A in residual field:");
	FrPrint(&b);
	HexPrintInBigNum(b.u8, FR_SIZE);

	FrIntoMontg(&c, &b);

	MyPrint("A into montgomary field again:");
	FrPrint(&c);
	HexPrintInBigNum(c.u8, FR_SIZE);
}

static void TestMontg2()
{
	Fr a = { { 0x1a580bd42cda0e77, 0x58d66e0c07b9cc00, 0x8be7bc457f2756d5, 0x2088ce9534577bf3 } };
	Fr b = { 0 };
	Fr c = { 0 };
	Fr real = { 0xccc8c7771a8a426a, 0x12881baf5b09dc22, 0x36bef279b36ae936, 0x20877252cb848cf7 };

	MyPrint("A in residual field:");
	FrPrint(&a);
	HexPrintInBigNum(a.u8, FR_SIZE);

	FrIntoMontg(&b, &a);

	MyPrint("A in montgomary field:");
	FrPrint(&b);
	HexPrintInBigNum(b.u8, FR_SIZE);

}

static void TestMontgReduce2()
{
	FrEx a = 
	{ { 
		0x5296e1d75d12b571, 0x4e5cb18167d62575, 0xb714911b688c8d0c, 0xf09a37a043af6fb7, 
		0xf72c5a8717cc5867, 0x8d887aaa5a80ceee, 0xfed75ac9083ecdc5, 0x000582ead020a39c 
	} };
	Fr b = { 0 };
	Fr real = { 0x267927fead0699bd, 0xa3198e8684fc7561, 0x19d7c413aea8bcd5, 0x1f5ea6937614c33c };

	MyPrint("A before reduce:");
	FrExPrint(&a);
	HexPrintInBigNum(a.u8, FREX_SIZE);

	FrMontgReduce2(&b, &a);

	MyPrint("A after reduce:");
	FrPrint(&b);
	HexPrintInBigNum(b.u8, FR_SIZE);

	if (FrEqual(&b, &real))
	{
		MyPrint("TestMontgReduce2 computed success!");
	}
	else
	{
		MyPrint("TestMontgReduce2 computed failed!");
	}
}

static void TestPoseidonHash2()
{
	bool bRet = false;
	Fr src = { 0 };
	Fr dst = { 0 };
	Fr realRes = { 0 };
	uint64_t len = 0;
	Fr arrSrc[7] =
	{
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 2, 0, 0, 0 },
		{ 3, 0, 0, 0 },
		{ 4, 0, 0, 0 },
		{ 5, 0, 0, 0 },
		{ 6, 0, 0, 0 },
	};
	Fr arrRes[7] =
	{
		{ 0x8b897dc502820133, 0x0e96a4d1168b3384, 0xc1fe6c654d6a3c13, 0x29176100eaa962bd },
		{ 0x9e19607a4417189a, 0x2a3617f274324551, 0x3df64c6b9662e9cf, 0x115cc0f5e7d69041 },
		{ 0x6148182319cee427, 0x69982807e9884c1c, 0xbac462b6fffe58fd, 0x024058dd1e168f34 },
		{ 0x5765b6c2550f42a1, 0xbf5279d8bf37d4e6, 0x65e97a44fe3c30f3, 0x21e82f465e00a159 },
		{ 0x526247747cc71214, 0x6d6a4145e596abe0, 0x66ef00f2a1b0e1d6, 0x0cd93f1bab9e8c91 },
		{ 0xe884398c6b22825a, 0x4b8d1b75a97fff58, 0x9bb445a7447eb969, 0x1b1caddfc5ea47e0 },
		{ 0x134a4cca2f6302e1, 0x38490a68b05f2239, 0x13c8ebf094dea475, 0x2d1a038500844428 },
	};

	Fr input[7] = { 0 };

	// Case 1:
	FrCopy(input + 0, arrSrc + 1);
	FrCopy(&realRes, arrRes + 0);
	len = 1;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);

	//FrFromMontg(&dst, &dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);

	//MyPrint("The current result (In residual domain):");
	//FrPrint(&dst);

	if (bRet)
	{
		MyPrint("Case 1: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 1: Poseidon hash failed!");
		return;
	}

	// Case 2:
	FrCopy(input + 0, arrSrc + 1);
	FrCopy(input + 1, arrSrc + 2);
	FrCopy(&realRes, arrRes + 1);
	len = 2;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 2: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 2: Poseidon hash failed!");
		return;
	}

	// Case 3:
	FrCopy(input + 0, arrSrc + 1);
	FrCopy(input + 1, arrSrc + 2);
	FrCopy(input + 2, arrSrc + 0);
	FrCopy(input + 3, arrSrc + 0);
	FrCopy(input + 4, arrSrc + 0);

	FrCopy(&realRes, arrRes + 2);
	len = 5;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 3: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 3: Poseidon hash failed!");
		return;
	}

	// Case 4:
	FrCopy(input + 0, arrSrc + 1);
	FrCopy(input + 1, arrSrc + 2);
	FrCopy(input + 2, arrSrc + 0);
	FrCopy(input + 3, arrSrc + 0);
	FrCopy(input + 4, arrSrc + 0);
	FrCopy(input + 5, arrSrc + 0);

	FrCopy(&realRes, arrRes + 3);
	len = 6;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 4: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 4: Poseidon hash failed!");
		return;
	}

	// Case 5:
	FrCopy(input + 0, arrSrc + 3);
	FrCopy(input + 1, arrSrc + 4);
	FrCopy(input + 2, arrSrc + 0);
	FrCopy(input + 3, arrSrc + 0);
	FrCopy(input + 4, arrSrc + 0);

	FrCopy(&realRes, arrRes + 4);
	len = 5;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 5: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 5: Poseidon hash failed!");
		return;
	}

	// Case 6:
	FrCopy(input + 0, arrSrc + 3);
	FrCopy(input + 1, arrSrc + 4);
	FrCopy(input + 2, arrSrc + 0);
	FrCopy(input + 3, arrSrc + 0);
	FrCopy(input + 4, arrSrc + 0);
	FrCopy(input + 5, arrSrc + 0);

	FrCopy(&realRes, arrRes + 5);
	len = 6;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 6: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 6: Poseidon hash failed!");
		return;
	}

	// Case 7:
	FrCopy(input + 0, arrSrc + 1);
	FrCopy(input + 1, arrSrc + 2);
	FrCopy(input + 2, arrSrc + 3);
	FrCopy(input + 3, arrSrc + 4);
	FrCopy(input + 4, arrSrc + 5);
	FrCopy(input + 5, arrSrc + 6);

	FrCopy(&realRes, arrRes + 6);
	len = 6;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 7: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 7: Poseidon hash failed!");
		return;
	}

	MyPrintLine();
	MyPrint("All test cases passed!\n");
	MyPrintLine();
}

static void TestPoseidonHash3()
{
	bool bRet = false;
	Fr src = { 0 };
	Fr dst = { 0 };
	Fr realRes = { 0 };
	uint64_t len = 0;
	Fr arrSrc[7] =
	{
		{ 0x8b897dc502820133, 0x0e96a4d1168b3384, 0xc1fe6c654d6a3c13, 0x29176100eaa962bd },
		{ 0x9e19607a4417189a, 0x2a3617f274324551, 0x3df64c6b9662e9cf, 0x115cc0f5e7d69041 },
		{ 0x6148182319cee427, 0x69982807e9884c1c, 0xbac462b6fffe58fd, 0x024058dd1e168f34 },
		{ 0x5765b6c2550f42a1, 0xbf5279d8bf37d4e6, 0x65e97a44fe3c30f3, 0x21e82f465e00a159 },
		{ 0x526247747cc71214, 0x6d6a4145e596abe0, 0x66ef00f2a1b0e1d6, 0x0cd93f1bab9e8c91 },
		{ 0xe884398c6b22825a, 0x4b8d1b75a97fff58, 0x9bb445a7447eb969, 0x1b1caddfc5ea47e0 },
		{ 0x134a4cca2f6302e1, 0x38490a68b05f2239, 0x13c8ebf094dea475, 0x2d1a038500844428 },
	};
	Fr arrRes[7] =
	{

		{ 0xdb504ca5a932a075, 0x04de7764145b78e1, 0xacd7ebe684ff40eb, 0x273aee8601ea0564 },
		{ 0x00716a9d068c9d7a, 0x5707d647d9516391, 0x2cc54afb87da0e3b, 0x2ee938764be7f9ac },
		{ 0x598e52f4061146f6, 0x63a88710526c2f27, 0xc8a028a4cf2a1aca, 0x10d368ec1e900824 },
		{ 0xa1beb5b97dd399df, 0xbd1c44c6562cff73, 0x10e76901fdaeb78b, 0x2d56c6b99b77c4de },
		{ 0xa59749395958e8d5, 0xc776b65d7be3313f, 0x953a3cd376631f82, 0x1de6f394fb7a6e8c },
		{ 0x03d1816f4339b431, 0xf8fa7a59c40ee5cb, 0x083d5b0e4bc8a821, 0x0ff256d9ffbc7e33 },
		{ 0xe9d093669e82b0bc, 0xc5473a10d32d4998, 0xe04b78d72c0573cd, 0x290b1be8fea78488 },
	};

	Fr input[7] = { 0 };  // At most input 6 elements

	// Case 1:
	FrCopy(input + 0, arrSrc + 0);
	FrCopy(&realRes, arrRes + 0);
	len = 1;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);

	//FrFromMontg(&dst, &dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);

	//MyPrint("The current result (In residual domain):");
	//FrPrint(&dst);

	if (bRet)
	{
		MyPrint("Case 1: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 1: Poseidon hash failed!");
		return;
	}

	// Case 2:
	FrCopy(input + 0, arrSrc + 0);
	FrCopy(input + 1, arrSrc + 1);
	FrCopy(&realRes, arrRes + 1);
	len = 2;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 2: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 2: Poseidon hash failed!");
		return;
	}

	// Case 3:
	FrCopy(input + 0, arrSrc + 2);
	FrCopy(input + 1, arrSrc + 4);
	FrCopy(input + 2, arrSrc + 6);

	FrCopy(&realRes, arrRes + 2);
	len = 3;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 3: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 3: Poseidon hash failed!");
		return;
	}

	// Case 4:
	FrCopy(input + 0, arrSrc + 1);
	FrCopy(input + 1, arrSrc + 3);
	FrCopy(input + 2, arrSrc + 5);
	FrCopy(input + 3, arrSrc + 6);

	FrCopy(&realRes, arrRes + 3);
	len = 4;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 4: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 4: Poseidon hash failed!");
		return;
	}

	// Case 5:
	FrCopy(input + 0, arrSrc + 6);
	FrCopy(input + 1, arrSrc + 0);
	FrCopy(input + 2, arrSrc + 2);
	FrCopy(input + 3, arrSrc + 2);
	FrCopy(input + 4, arrSrc + 6);

	FrCopy(&realRes, arrRes + 4);
	len = 5;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 5: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 5: Poseidon hash failed!");
		return;
	}

	// Case 6:
	FrCopy(input + 0, arrSrc + 5);
	FrCopy(input + 1, arrSrc + 5);
	FrCopy(input + 2, arrSrc + 2);
	FrCopy(input + 3, arrSrc + 5);
	FrCopy(input + 4, arrSrc + 1);
	FrCopy(input + 5, arrSrc + 4);

	FrCopy(&realRes, arrRes + 5);
	len = 6;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 6: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 6: Poseidon hash failed!");
		return;
	}

	// Case 7:
	FrCopy(input + 0, arrSrc + 6);
	FrCopy(input + 1, arrSrc + 6);
	FrCopy(input + 2, arrSrc + 6);
	FrCopy(input + 3, arrSrc + 6);
	FrCopy(input + 4, arrSrc + 6);
	FrCopy(input + 5, arrSrc + 6);

	FrCopy(&realRes, arrRes + 6);
	len = 6;
	MyPrint("Input data:");
	FrPrintArr(input, len);

	PoseidonHash(input, len, &dst);

	MyPrint("Output data (In montgomary domain):");
	FrPrint(&dst);
	bRet = FrEqual(&dst, &realRes);

	MyPrint("The real result:");
	FrPrint(&realRes);
	if (bRet)
	{
		MyPrint("Case 7: Poseidon hash correct!");
	}
	else
	{
		MyPrint("Case 7: Poseidon hash failed!");
		return;
	}

	MyPrintLine();
	MyPrint("All test cases passed!\n");
	MyPrintLine();
}

static void TestGenRoundConstDemo()
{
	uint32_t i = 0;
	bool bRet = false;
	static Fr c[1000];
	uint32_t clen = 1000;

	bRet = GenRoundConstantDemo(c, &clen);
	if (!bRet)
	{
		printf("No enough len : %d\n", clen);
	}
	else
	{
		for (i = 0; i < clen; i++)
		{
			printf("Round constant [%03d]: ", i);
			FrPrintAsBigNum(&c[i]);
		}
	}

}

static void TestFrInv()
{
	#define _FR_INV_ARR_CASE (639)

	// Test data are from the variable : g_ConstC[7]
	static Fr arr[_FR_INV_ARR_CASE * 2 + 2] =
	{
		// Case [0]:
		{ 0x1a580bd42cda0e77, 0x58d66e0c07b9cc00, 0x8be7bc457f2756d5, 0x2088ce9534577bf3, }, // Residual field data
		{ 0x48bf2559a5483caf, 0x457c8c4e49f0fc81, 0x3c17c55def1b94e1, 0x012a481742e86ec6, },
		// Case [1]:
		{ 0x742a58e0ec356be1, 0xd21c9e37d73dfff9, 0xf43cec6810356c94, 0x1b86e63908c4b12a, },
		{ 0x64f895eecb20439e, 0x2f5b93cf43d138e5, 0xa4f868c989207d2b, 0x07cc4b8fbfb4bec2, },
		// Case [2]:
		{ 0x0d5d50d5a021a169, 0xa4ace33e16825f54, 0x0f755212e2edc9d0, 0x09ca022ba1142d17, },
		{ 0xcbc196c787907f38, 0xf3a3b500741cdee2, 0xe5fccf6e00806150, 0x2e5e8387d0cfd982, },
		// Case [3]:
		{ 0x38eaf613bc1aecd4, 0xe22c849c6d8ad8c9, 0x241f6aebe9449be6, 0x277e69d47a133804, },
		{ 0xfae3503c54856dd1, 0x0b61f2bc198d5282, 0xa913634c616f7c02, 0x1a99e8784b73c102, },
		// Case [4]:
		{ 0x94545a235db6b269, 0xac9ba5457a18cec5, 0xe0ef425aa2ad931a, 0x17b57ea03754e24a, },
		{ 0x1e43b99746fb7f57, 0x681843400119f895, 0xe7cd1b2a513fba75, 0x0530ff2192aa9217, },
		// Case [5]:
		{ 0xa77d5a1fd74abac6, 0x75c9077755eb1a37, 0xa026e2c7c9392363, 0x11c740983395e0f4, },
		{ 0x0623001a0a431295, 0x3ebba519fdefe231, 0x6636d9cfa6a2a531, 0x2f5ddd79818b384e, },
		// Case [6]:
		{ 0xefc5a81eb37bc5bd, 0x27556a479c59b822, 0xfb7ea403515bab57, 0x1cd85529010dd7e2, },
		{ 0x7a39299f5a42e3a0, 0xadda34f58dbdc700, 0x65dc221d5b79b0a0, 0x268065042faa0ebd, },
		// Case [7]:
		{ 0x5a1f96f87b12f292, 0x2ced83d197aa374b, 0xbfa985de34f43d70, 0x2cb9354002cec4bc, },
		{ 0xa8ed607e7d7658cb, 0xb41009d0fe6ba68e, 0x76c4dadfc474f2bf, 0x2b78ffcb5256bb50, },
		// Case [8]:
		{ 0x6544f9acd61aa32d, 0xac52f56fbbd87850, 0x23f27a3dad40c525, 0x1f7af98e08f68779, },
		{ 0xaf9211310564c265, 0x7f91f8a92d8b28bd, 0x39c7f90b6ed14ef1, 0x0fcff3d1cec433ae, },
		// Case [9]:
		{ 0xc0ff92c431d31dd5, 0x46b1075de58c7064, 0x5c9e99a7c4f26ad9, 0x2b15176925df33a4, },
		{ 0xc8413f44b092003a, 0x0e66f6c0e5e23b01, 0x2b60b7c33aeda455, 0x1b2a3ec06391d93a, },
		// Case [10]:
		{ 0x3fda940e988c1ca3, 0x061358493f3cb365, 0xa60a322d6b399b88, 0x22c89859b4d399d3, },
		{ 0x1793ed151566887f, 0xa7291ef6e6a2cae2, 0xef49bf450d45c9d5, 0x1c08797cf9a52672, },
		// Case [11]:
		{ 0xa67fc18e5b1938fe, 0x597039373af5055a, 0xf6dd98109363d405, 0x1a9f2730c80854d8, },
		{ 0xb30d6736f9dd9e41, 0x86e287ee0be5b26d, 0xcb5e08fb986f23b6, 0x032d7e373dbde2e0, },
		// Case [12]:
		{ 0x4a1a0a40575f0ed3, 0x2563ebbac58ff8fc, 0xce5e294998ea060e, 0x040bae2c57fc68e3, },
		{ 0xceed73a0693b1fcc, 0xb57387d9b8d010e9, 0x617400c81bf7a7cf, 0x0c6de6652c2d2772, },
		// Case [13]:
		{ 0x2dd8565c4faf8b7e, 0xbc4d885cb99699aa, 0xee9749cc380605d2, 0x16bf4f5622729467, },
		{ 0x2412d05b038f25f4, 0xda9a0734b7c25bdd, 0x2f0bbd5be938dc3a, 0x246b66d1f16cce88, },
		// Case [14]:
		{ 0xec7fcef61b11329a, 0xa3ea075001b21637, 0x1c3bf07ff4968390, 0x1045ecea044ba1cb, },
		{ 0xff44c186bbc3a615, 0x872122a73b61e4e9, 0x8d88a0936ad386ca, 0x03d9078b20d158b9, },
		// Case [15]:
		{ 0x6d3b6197a262fd09, 0x23492ece769f70f6, 0xdd6cea9587cfe3f5, 0x26a319fe6b7d6e08, },
		{ 0x68c1199f069124bb, 0x27ad8f744bf531de, 0x6cd2670fcb111fd1, 0x1d6b8a6345cc14e8, },
		// Case [16]:
		{ 0x6da84216ba81bd6e, 0x172ef1ed9c073868, 0x7eacb09c1571256d, 0x28a5629b4c208338, },
		{ 0x9225fdc481250358, 0x9ac08ec4a6fa5f66, 0x39bb923d7d857c8f, 0x28bf45f68a95ec65, },
		// Case [17]:
		{ 0x19de280532fa9726, 0xfc6d8897e32d6a0b, 0xcc8760dba63b119c, 0x186be22b6a063d18, },
		{ 0xb4d146e8f755d684, 0xbec7544a9aa51f23, 0xf933a0ad7a482525, 0x2a4d70797e7030a3, },
		// Case [18]:
		{ 0x8137cb8aa5c574e7, 0x15bd9b73218c6af8, 0x6c5595a1ced6b3dd, 0x2c41eaf9c0128c48, },
		{ 0x0890e7bcdee1c493, 0x5e43255995bc1db6, 0x4c0eb5a2cf883f73, 0x018a66470d7d880d, },
		// Case [19]:
		{ 0x3727fa2df7e3cd7a, 0x6ab7213321dbe068, 0xb4d2ceccd18dada4, 0x11864265d76e8873, },
		{ 0x51aa411dd0f80850, 0x41c734a874affb06, 0x74bd741727597ae2, 0x1fa8589515be6e31, },
		// Case [20]:
		{ 0x02cb60d8322467e4, 0x8166ede6fb6ac68b, 0x5f97461ff7956553, 0x1383e7371d7f3eb7, },
		{ 0x61b427bec9b34ee5, 0x775df95c56a929c5, 0x810a3ca991e4fb0e, 0x0eabc11cc7261969, },
		// Case [21]:
		{ 0x3602e138c59c7469, 0x1351de9642f39816, 0x73e3989f34c304ff, 0x1a005346e9edc595, },
		{ 0xa9e1c1c4fde4efef, 0xa844b1ea666a6220, 0x2b74574107e617b0, 0x2d3366d2ef9003bd, },
		// Case [22]:
		{ 0x0e36f3b4eb486052, 0xc6299c69a5d24b46, 0x9d649270ceed4b2d, 0x2b541345bc4fe158, },
		{ 0xc865a17c2fa85f54, 0x8bbe106b06f1eddd, 0xa21c5af27dd557ba, 0x0faf7d87bcc37253, },
		// Case [23]:
		{ 0x982881b4ea7eb58d, 0x90f87e8bd993310b, 0x8b420fdac7a62f3e, 0x213e74e3b8869206, },
		{ 0x83c42db0266a8c32, 0x71a4e19e0d3a2055, 0x6d9b91a9fb024afe, 0x2b7dbdae312c9ff0, },
		// Case [24]:
		{ 0x7e9e037d41ae2b84, 0x79c86cc6c9db77b4, 0xdf5d27b984e21d89, 0x0254370fdf60e319, },
		{ 0x7455a9ed60a14881, 0xb8dadc938ac91747, 0x8ff94ef1a7b7e63b, 0x21c192f0836daa73, },
		// Case [25]:
		{ 0xeee627f5a6369ecb, 0x19adaa660bb6a79c, 0xbd0c5ee3279cccb3, 0x083b7377987bed3f, },
		{ 0xe479c0a1fdfeec06, 0x65023269651732a0, 0x7b75ffd672f24f71, 0x147a250192a5349e, },
		// Case [26]:
		{ 0x70021cccd4fbce1c, 0x7bade4ecb0999e2a, 0xbc4c5b09b209d4a7, 0x0a2b26bbf2b84a55, },
		{ 0x235eb938b070b871, 0xc15b3212a847997d, 0x5c87b0b6d13ec1dd, 0x1aa38fbfa6e002a7, },
		// Case [27]:
		{ 0x53faef068533eb09, 0x4785c51889ac9ca0, 0x3cd72bdd881ace1a, 0x287090d407c4c529, },
		{ 0x21a10755b628d766, 0x97dfd7b53b35a044, 0x50856ff5f6391acd, 0x2e7fbee65b699701, },
		// Case [28]:
		{ 0x77ca4cdab62a8587, 0x476001ea6e329312, 0x2a473c04931dde66, 0x00a9fcc21a234bc2, },
		{ 0xbc8ab37e5d7c6248, 0x77803c71598e3461, 0x75378dd69a6527ec, 0x1462d6b4c4bdbdd0, },
		// Case [29]:
		{ 0x386b8cf06606d116, 0x3f9722c5d10d6411, 0x2d6ec0c096f3c062, 0x1d79fcc5066ff2a6, },
		{ 0xb4ef0b3b698c90bc, 0x7a735671848a1300, 0xd962743bef1fd83b, 0x1fc17d0ea136947c, },
		// Case [30]:
		{ 0x646814f38b7c9cc3, 0x022a82291934ae8d, 0x7d87a57c6a6f2c91, 0x1d2da676081b7b0a, },
		{ 0xa5e1c16994da1578, 0x5158e69be50adde1, 0xb77f9eb3530cd55d, 0x267cfcdf6fa129ba, },
		// Case [31]:
		{ 0xdac26f7a79d371ad, 0xe85ff4b3ceabb4ea, 0x2f3bba28737ea247, 0x0121189d7362dba9, },
		{ 0x5b7d45fcf5bae6cc, 0xfc42e97aa23e3aac, 0xc0958058c29e8d94, 0x0137bc3f08bc7885, },
		// Case [32]:
		{ 0x4362ee63bd6d6102, 0x5da5a7f472f49756, 0x3626831d5e82852a, 0x03ba01bdc7f31b4b, },
		{ 0x2d5f561ffd2cd485, 0xd4ae6701da15e555, 0x9a567e7633f166fd, 0x1efd81cfa7857610, },
		// Case [33]:
		{ 0x6a169bdec89a35cb, 0xa3312df5ed0b6e60, 0xd835b220c7f1e7b7, 0x216487ac4eea81e4, },
		{ 0x10a7a12b51fa30b0, 0x2b80a4353353559b, 0xa1b29665906131a8, 0x29a722c4a624f47e, },
		// Case [34]:
		{ 0x98c1d8f3069fc804, 0xc333b4d98e4cede6, 0x20779d6138a7296d, 0x0eb5eb424bc72e5b, },
		{ 0x0f39e109ea0a6d6e, 0x6866bf52cf2f40f7, 0x0455e0ee0015dad8, 0x00618360f897f45b, },
		// Case [35]:
		{ 0x31fa17811afc45f6, 0x71875fafec3aac68, 0x69d538de90f90bf2, 0x1476087ee68863fe, },
		{ 0x8ac895e6e220c17e, 0x12be1658d969f8fd, 0x607a9d5106fc7ffb, 0x27704ba75df4f5f1, },
		// Case [36]:
		{ 0xdfd8a5aaec009f32, 0x440e7adfb00da7e4, 0x925ce8050e6bdd0b, 0x25995ecf079f4f81, },
		{ 0x735704126ee678c0, 0xff01745c10858d4a, 0x87a02095d89f89de, 0x09ce53fdca500fbd, },
		// Case [37]:
		{ 0x95a8fc6b03dddb21, 0xeb378d3dc8585a81, 0x2ff0e8eccb97f057, 0x01b590ea145df615, },
		{ 0x338532fe1cca15d6, 0x46938d664bb4cbe9, 0x06d0d058d68c854b, 0x0968244e0dd9d3ff, },
		// Case [38]:
		{ 0x7dd42470e016bd52, 0xc85f07c3d055eb98, 0x7734d82fb7ab59eb, 0x0ebfed12777ad974, },
		{ 0xdeaaf55fb40193fc, 0x098f07910bbfec30, 0xa89dd507b506b7a4, 0x0b0121d161a1f92d, },
		// Case [39]:
		{ 0x6437c9990a3e232c, 0xc5c073355890f26d, 0xbad1ced25d02de18, 0x2e03b519ff070e31, },
		{ 0xd2000b56c401a868, 0x656a3124a46a28dd, 0x87392cc1cd131a04, 0x1888a7e4e05565c6, },
		// Case [40]:
		{ 0x22663117c3038109, 0x30ff6f7bffeda93a, 0xa157c0bc80373478, 0x028ed48befb70534, },
		{ 0x825642303daa31f3, 0x1180fde6dc50b76f, 0x0f619bfed2dcee54, 0x05a04a9595374d79, },
		// Case [41]:
		{ 0x69d109945aa879cc, 0x6645d78783397921, 0x7627083f5c6ff580, 0x21d5480ef2288cf3, },
		{ 0x45a7a6b69fa55e87, 0xd436a630926df3b4, 0x49a569ca6fe7a5ed, 0x07b3a763dd98a1e7, },
		// Case [42]:
		{ 0x92513679ff531866, 0x22666a268eed190c, 0x9d616fc3b74f426a, 0x2a017f4ca62717fe, },
		{ 0xa5e125a8c433227b, 0x66e7e372aa3308c7, 0x7120072894f99c68, 0x10eb89ae55a02f81, },
		// Case [43]:
		{ 0xe13102dca258a182, 0x3e0a9db664958560, 0x0b2b34cf06cf6f89, 0x085cf123084d6b4b, },
		{ 0x1098ad93c1135380, 0x398165f41b51485d, 0x52caf6c75510802d, 0x0bbb89491ff0427a, },
		// Case [44]:
		{ 0x26bc3f2f24fc30ab, 0xd063cf8ea6ecb3a3, 0x4f1b1f0f4cf71073, 0x01cab1eb61ae5a9c, },
		{ 0xbb9fa78abbe16bef, 0xb09124f84c69b750, 0x15f094ec318cc1f8, 0x2747cc8665f6a465, },
		// Case [45]:
		{ 0x495f0305e89bb96f, 0xee94369715042367, 0x98c51de07438e7fa, 0x08b659a737c0a7e1, },
		{ 0xba6dbcc061c18fa1, 0x098993006d59f9e2, 0xf896b96272548ffd, 0x1eb085e1db71357e, },
		// Case [46]:
		{ 0x744e7b5b2c307df6, 0xa9c895a81386e769, 0xa949e044a68115b0, 0x02b3adfef956007b, },
		{ 0x24abefe460731ebb, 0x4cbcde2df3d4fd39, 0xebab1abd276c0264, 0x193877c5a38efd7d, },
		// Case [47]:
		{ 0x2b057b4fc00cafa6, 0x9b04c40af2fecc17, 0x9b24a7b451cf439d, 0x1a502a7b0883deaf, },
		{ 0x0cc1c359d0a6a96c, 0xb6b201c4cb3592e1, 0x555661e19891609e, 0x2eeb3e8433ac4839, },
		// Case [48]:
		{ 0x6a2cce33a42ce949, 0xb19c46c00e407251, 0x1a0fa596752c83ed, 0x3048a536a2a75af4, },
		{ 0xdbe4fa4bf828f10d, 0x9cb1932a94ff91cf, 0x3c491e3694398638, 0x14dd512a18ce0a08, },
		// Case [49]:
		{ 0x5e75b3e9c66ab22c, 0xe69a7595a3d2e872, 0x36b9f2c8eaf18d2a, 0x01d008216832f777, },
		{ 0x235dbe89474c7300, 0xa0869188fafcbb8f, 0x0775d9aa79d2d45f, 0x0b5ba93f21aa81e5, },
		// Case [50]:
		{ 0x96c1b15ee85c0c20, 0x4f1b7d54e69e1d18, 0x493424576d30d625, 0x067389fa6719bb9e, },
		{ 0xdb1e3345eb6fb207, 0x6dfc9eb48ecfdefc, 0x164913847c88a7f2, 0x0db9f50f7f1c4c81, },
		// Case [51]:
		{ 0x52705699bcdcabf4, 0x7e08d6b196503594, 0x88a4dee60dacec40, 0x17da04cb50608615, },
		{ 0x82693a30d6788aad, 0x6bd84eb53c3b8d41, 0x1a495fc6113dcf07, 0x22f77f01a370d718, },
		// Case [52]:
		{ 0xff0104ce6de14af0, 0x903a08d3a7658e05, 0x48a04b71f91f834d, 0x1e110b24526cf194, },
		{ 0x08ddf5ec4fe4f0e6, 0x20ebef2389b863f5, 0xf8e2fe65a4d4656b, 0x28a45f58fb0b5f81, },
		// Case [53]:
		{ 0x6160e2352a820e34, 0xc4406708f1a7bec2, 0x242231c7384d9b96, 0x0b0a28b67269dcfb, },
		{ 0x428dc7d78a5055cd, 0x1ef0923e64f734bb, 0x291ee1811740d702, 0x2031493e0feb6a36, },
		// Case [54]:
		{ 0xbd7391ad0dca0c61, 0xad1d4b29b81ae33c, 0x1bca604a2f55b324, 0x0226ba223bf5cc83, },
		{ 0xe0b67fb6d645703f, 0x75317fe42fbd96fd, 0x744915a05b347fe9, 0x0afe597aaee3e584, },
		// Case [55]:
		{ 0x7093bfce2f3f5cfc, 0xaccac5f7cff14594, 0xb6a04dba21eb6224, 0x1fa506fae71f617d, },
		{ 0x3fbb28ac0b3b4bd6, 0x235edf7387ea9bd6, 0xabfa3ac96ea4c5a6, 0x0fe7d3482f1b1eaf, },
		// Case [56]:
		{ 0x6d596f48844f0394, 0x9e7e0467a5b4b5a1, 0xc4e53fb981f27358, 0x29724cc2973b5b34, },
		{ 0xc7f8134c85610fd5, 0x4fda48f72a8afc83, 0x8f34dbd2bd1b267b, 0x2b5eb2477023d880, },
		// Case [57]:
		{ 0x41a181a7cd90cac4, 0xdb44fada44534a9e, 0xd769b1e7b3a42369, 0x20185815e6d5bd43, },
		{ 0x03337d218012a75b, 0xd275eeb326b28a4d, 0x6c6c96b5cce65eb8, 0x2c0a01b4dda5aa84, },
		// Case [58]:
		{ 0xb614af6d89376612, 0xd8649d73a9f53133, 0x9986b565545493d5, 0x2cb5ecab94a2faf8, },
		{ 0x03af952d910f714d, 0x43e95f5967a4e7b3, 0x4db48e894c96ee55, 0x0fd04c915d9ddb84, },
		// Case [59]:
		{ 0xd879bc27ee2134bf, 0x5c5986fbdbce0a3f, 0xf2f186272db82513, 0x06772704a6a6c396, },
		{ 0xbcf59865f3a2c412, 0x227e005806bd7b02, 0x25729fea8c4b61eb, 0x0c88d03370886fea, },
		// Case [60]:
		{ 0xeeb6e64d30591851, 0x1e168efe6c37fd0b, 0x77440e744d7fc619, 0x0112bff4736679a4, },
		{ 0xafb075cece3aab5a, 0xe507903dc2094a92, 0x3857edf04560e19e, 0x2cace482083254a7, },
		// Case [61]:
		{ 0x07ac0e268e391a57, 0xea8d00be172832ad, 0x7dc50b013be9c4b2, 0x2faacc248d2f742b, },
		{ 0xe519763e6485de4c, 0x8d2139654bc1730c, 0x29108ec6f644cc44, 0x1a145a244cb5bf04, },
		// Case [62]:
		{ 0x3800136498df40aa, 0x6d08af6e8fe7e42a, 0xd6b9a71b4f3437e7, 0x115ea053915c9231, },
		{ 0x2b53d1d7f4fb81b5, 0x6a75a3af257e5a05, 0x0dbfdcffb36f07ac, 0x0ff98d8c14c784f6, },
		// Case [63]:
		{ 0x27621b5a22181235, 0x06164d10dbaf7561, 0xc53f58394e2dbaca, 0x0353e2c2845c0fdf, },
		{ 0x26b4193caafa4055, 0x118dadb433e1c07f, 0xceb88aa172c0d1a7, 0x0f06541ece46eea2, },
		// Case [64]:
		{ 0x10e2afeac748710e, 0xcae2c52c7ede3ec0, 0x10363ae0cdec5f61, 0x29b3685900bbaca9, },
		{ 0x8edf6ca405e9b155, 0x2dfd042afcf59c7b, 0x848a5024db7ef693, 0x2340d1ff16363287, },
		// Case [65]:
		{ 0xa9f1c2fa89fac1a4, 0xd9227b21bfd8e8a3, 0xd0a9f310920791fa, 0x1a73ba985b824209, },
		{ 0x1a21b15ba1785b35, 0xc477d25c0165b71c, 0x24fec9bc35f29613, 0x1ce75a0ff9817e98, },
		// Case [66]:
		{ 0xb83be943309a305f, 0x5b9b5e845c8c9dce, 0xb5ea22e0558b145f, 0x274682d63a1d6a9e, },
		{ 0x6605960008ec4602, 0xac07c2c3c711207e, 0xf39f01d4a6eb4107, 0x202cf8af011e5d02, },
		// Case [67]:
		{ 0xc892ccf949fcafcd, 0x398f38e6089d92e2, 0xddc122e02aac0d79, 0x249de663dfdf6682, },
		{ 0xc8f724277890baa2, 0x048282e2ba000d01, 0x238530d96e4f25e2, 0x08cc4843c07c0683, },
		// Case [68]:
		{ 0xcbb677ea4376d4e2, 0xafd4992f0d7d4023, 0x18229d2faf87b6b5, 0x076346a494ca4999, },
		{ 0x471998c751b7e71c, 0x1b6a31db6588da81, 0xdfbb87372c87be11, 0x0fa4ba959e030943, },
		// Case [69]:
		{ 0x4741e64e9926b50e, 0xe220daf6931b8446, 0x8bdd94e29ad85939, 0x0712154eb43b0a3e, },
		{ 0x31ef09e108a8a4c0, 0xbe84a5d90c43b7d0, 0xc40edebdd6ed0347, 0x1e8ca17437870c0b, },
		// Case [70]:
		{ 0xafdedd89befc6c32, 0xe249ddf327fc6c92, 0x642692a92d864960, 0x15bb7e127b9fc937, },
		{ 0x16e16453795cb5d0, 0xc950e08cad61905f, 0x1d755a7f9f74af08, 0x07e079c6e2af2b84, },
		// Case [71]:
		{ 0x80d80076800d8e11, 0x8ae05c60052c10ab, 0x06a80584015eaf7a, 0x0d438d885c3fce5b, },
		{ 0xcda74babef6f3864, 0xf72eb2497d1b3683, 0xd6e7452fae62c827, 0x25b190440f9b52d3, },
		// Case [72]:
		{ 0xdc383c8aa34a9e0c, 0xdcf7a5fd881894b7, 0xb2e362d6195c8013, 0x2bffb873c9b04762, },
		{ 0x2856e444d34f9aca, 0xf54bf3f682c18c84, 0x19bd2bc01d6e4003, 0x0fa4b96de6628aa4, },
		// Case [73]:
		{ 0xa45b76652707d6c0, 0xf8552b9564e5ba2d, 0x8e8b1016663fdaa3, 0x24ea42c76f7350d0, },
		{ 0x2a9fa3dec875a3bb, 0x9fa1a428d93e5d1e, 0xa0e3d410f4629543, 0x2c91a179aaa8fd29, },
		// Case [74]:
		{ 0x0da34523c481dfbc, 0x05b1193b579ecece, 0x0b808b9d838b4ef2, 0x2a62ea21a0ade474, },
		{ 0x242b87536114abe3, 0xf5fd27408aa388d2, 0x9c8d1ef2c2193f7f, 0x04abdcbc0e1f4b62, },
		// Case [75]:
		{ 0x44b1ab89edf475e9, 0xa8ca864c6d32f2c6, 0x468cea0f32211cc9, 0x0c49774a68f5274b, },
		{ 0x0249d3da0473bb5f, 0x7c188f60c27c9bc9, 0xf19f007cda1f854e, 0x2701bb34906736b5, },
		// Case [76]:
		{ 0x51fead13246073cc, 0xffd61cbffaec9571, 0xc24d4e052dc3072c, 0x0a9b4d3d32564d83, },
		{ 0x3f18a9993b76cb9e, 0x7c780952ecf3ea3c, 0x5c0568d2a9865e2d, 0x2174cc0d805502cd, },
		// Case [77]:
		{ 0x0fc64bd4d201c3a1, 0xf000dcfce572ac31, 0xbaa0de8e19ad399c, 0x221179d848ae3c29, },
		{ 0x5ab65177a9577c8e, 0x41a91ca97510c395, 0x367359feb7b1502a, 0x0362946027dc6640, },
		// Case [78]:
		{ 0xe2340692f7f5e0a0, 0xa70a45de25203435, 0xd19da15dee1fdcb2, 0x1702294352579a43, },
		{ 0x0a6b038ebacdc01f, 0x9834e69ee6ab9dcc, 0xd9e1e9c5c05b426c, 0x12ebb4392266820d, },
		// Case [79]:
		{ 0x63a7ef5019d4d8e0, 0xbceb1aefe37f7796, 0x5cf6de04f87ca9db, 0x059ab78827360068, },
		{ 0x51ea66f22604ed74, 0x08034b538da1166c, 0x593556a4ef7c0755, 0x116dd4b6d5d8c234, },
		// Case [80]:
		{ 0x5f12c1b21b41f599, 0x6a034029a109ce43, 0x35af1999691398ad, 0x23af64b1622be077, },
		{ 0x48cacac4afae7f94, 0x2824dccc136636c9, 0x124100bd20207e4b, 0x0186637b32dfadd1, },
		// Case [81]:
		{ 0xd8f49b2038594516, 0x5e8132433e5fba6e, 0x94a0c6ca6ed942ef, 0x109ed21e2456ad7f, },
		{ 0x30ff622dc1c899d8, 0x138889b673fccd49, 0xa86542edbf72135c, 0x064aba6388ce39aa, },
		// Case [82]:
		{ 0x67f70c39e0893326, 0x37872271d891f19f, 0x6927a58958338d60, 0x26d9ccfa5379d3fd, },
		{ 0x50c1b910626ed520, 0xe3274541ecf6fe81, 0xe68f87beea49227c, 0x0ad6193e421b5f2f, },
		// Case [83]:
		{ 0xfb00a6ccd991d0fe, 0x647207816ae5a901, 0xcf7dcd7d0e46979a, 0x24ea9e2db358c1be, },
		{ 0xfea4994e593f0ffe, 0xad0bc578e5deec99, 0x9f535c526e8a3dd9, 0x04c165b03f43b57c, },
		// Case [84]:
		{ 0xcf502bfb20c71bbc, 0x98eeca1d27735974, 0xae3971d193a430be, 0x0015a9b8c33fce93, },
		{ 0xd8659cceebd9bc21, 0x0edda64075066fb2, 0x896a8a8bfb7fcbc5, 0x24fbf005fa0cfa4f, },
		// Case [85]:
		{ 0x550bf351f296dc1c, 0x826bd3a85347e559, 0x138d79a96ab5cd14, 0x2bbb366f79bc3baa, },
		{ 0xfc115aa7f9658933, 0x2e51794d93590070, 0xaec85fddadff3b47, 0x271697e0e508101e, },
		// Case [86]:
		{ 0x54af052686b70e29, 0x1d9e7b29eb14d076, 0xeaa1bf4aadc95679, 0x0a1c76641eded157, },
		{ 0x1b119b97fe605470, 0xac916451b99e967a, 0x4f01da3e06430e96, 0x13a866c008fb0a74, },
		// Case [87]:
		{ 0x103abcb48ab21fc2, 0xce2ca16c07bc747d, 0x0b5cd84217af26fd, 0x0a8a9f9ee8ecf8ad, },
		{ 0xf064968587866c17, 0xe43b8edefef7895a, 0x47df20dbed8be953, 0x1cad36c2b31e49f8, },
		// Case [88]:
		{ 0x01ba6de2011dead6, 0x2b77d8e566fe3b39, 0x29c46824d00b4444, 0x26d6852b5917f4e2, },
		{ 0x3b81f46812fb1de3, 0x808ee3c28dbee1cd, 0x40e185bf65ed76a1, 0x06a32be98f53f6cb, },
		// Case [89]:
		{ 0x096e5f01fbae6885, 0x1ed67e0f3c1fcec7, 0x4ee4a323b35f2c17, 0x19601734c30cb2a4, },
		{ 0x50165fc45a91e3af, 0xd770df258a8880be, 0x90152a2771d2112e, 0x21421f23e67653e5, },
		// Case [90]:
		{ 0x1070bc17cc87d044, 0x02505587f386cbb7, 0xf17e359b0ee926d4, 0x07895f7f029f84c3, },
		{ 0xec0544320d0601ae, 0x1b0087b29364183c, 0x4df47ebcd2cf7809, 0x3054ffba2486bc1a, },
		// Case [91]:
		{ 0xb0f35a939e0ef483, 0x8eb4d9503bf25cc2, 0xb87130586c786822, 0x05807e0a2b2473f3, },
		{ 0x627c0bfe19c37381, 0xc1aab6b81aa94471, 0x0421aa9a426392fc, 0x2300e27daf300a37, },
		// Case [92]:
		{ 0x828be3e5099d2fde, 0x2aa490a355e07982, 0xa79886aa8c7dbd36, 0x1ac9ba8eb9e2fde0, },
		{ 0x8020536a588591e9, 0xf7c352a89ea326c5, 0x46894bf858f111d6, 0x117075de7c8a4467, },
		// Case [93]:
		{ 0x8af5638e3b321b40, 0xcd00e7a07346e258, 0x28672afc5bbb6463, 0x231c7595f76fea58, },
		{ 0xa2dad4b8546a9b5f, 0x14312d08e7262b3d, 0x87bd5cc43063adc9, 0x02cb15e6f95827d7, },
		// Case [94]:
		{ 0x581ca78f0068672d, 0x946e2eff2b80d17f, 0x5fcc58f4039532ff, 0x2e3d1677310217ce, },
		{ 0xd0708711e3187f60, 0x7edc72a97460b52f, 0x3f9a56e96f008c52, 0x1385604c71690a67, },
		// Case [95]:
		{ 0x7830c5980464000e, 0x17b2bdce7b7eb02c, 0xa33b4093f922d7df, 0x0974163441712975, },
		{ 0xc8e6219d1d16da37, 0xddaddc47bc6db020, 0xdf10672ad2002eb1, 0x089eaa666ab67db5, },
		// Case [96]:
		{ 0x39bb51671b9919b2, 0xedb87977e98ee291, 0x9deecb82a64baab4, 0x1cf5c1a4280822a5, },
		{ 0x832c41eaeb238882, 0x46849c82b1fc519a, 0x17807c81fff601a8, 0x0bc753af570bd70f, },
		// Case [97]:
		{ 0xf78ed7e94cc81289, 0x84bfd5f23de46f1d, 0xf57933aa9476ec91, 0x11ad46e13792150c, },
		{ 0xb3e01da855664850, 0x0935f82353811f9a, 0xfd16155717c6e29e, 0x157d8b38c3e345d5, },
		// Case [98]:
		{ 0x41e7a1bb8e63dae7, 0xed792a9c3cc4002b, 0x0c0f3d5af2fe5796, 0x0828fbfc0951c1ea, },
		{ 0x8a62db3af9793798, 0x4a6394c4adda2ca5, 0x359de2891a0599d3, 0x27530f9fe54013f2, },
		// Case [99]:
		{ 0x2e30e99e8500fcf6, 0x854535c4ff404fe8, 0x305304ecf3a00f99, 0x02c720a8486e7122, },
		{ 0x5c84c2a9b0725a39, 0x6a607e15e86fd9e5, 0xfc7db6842cab321d, 0x068ae3525a2f1045, },
		// Case [100]:
		{ 0xf1cd3a7fc3ef72c2, 0x360d2881aa425028, 0xc0a38d6f525f9176, 0x09bdfc942fba8824, },
		{ 0x71a5b4108dda5197, 0xb09abf94e6cc1db0, 0x35a49e62270c0b73, 0x16ed93287c874f2d, },
		// Case [101]:
		{ 0xdcc4a1b2ca82e2bb, 0x2a943dde51e262e7, 0x81c6b897fbd72f4f, 0x1d954a0f93250e55, },
		{ 0xa414fef709fef561, 0x09e21de1a251b0da, 0x6ea053fc22767a55, 0x0c0b5ab51090c5e3, },
		// Case [102]:
		{ 0xf92f14c98aed56eb, 0x35edf37e7ab0e1a7, 0x06e74f9fe702f696, 0x2b829352e297ab21, },
		{ 0x6c0fce1e03cb5fd4, 0x66a26f2cc3422bb3, 0x9e1f5c721d483d7c, 0x1f5d91a1ae0f9971, },
		// Case [103]:
		{ 0xf1c33368734a904e, 0x23dfac75482e108a, 0xe1babaa341d1dac9, 0x12d3b917e58f1f44, },
		{ 0x4fe5b39821d41aae, 0x344aa16dc28373eb, 0x51eba73d535ce345, 0x070b85eefb3a0c20, },
		// Case [104]:
		{ 0xd5015077afe4bbfb, 0x509305f85326062a, 0xa47795bde9b177b5, 0x28a9e6c65d06ed6e, },
		{ 0x96a056b8b83bfe67, 0x7dab022af4c8feb0, 0x9a4949b98ecc20de, 0x272ad09e2b5db8e2, },
		// Case [105]:
		{ 0xdc535fa593221ca8, 0x0c311fc8d232fbc2, 0xd4ad82508b76df89, 0x2bd3c33ae311c2f8, },
		{ 0x2135df77ac4b0b5d, 0xe09437a8099c1be9, 0x90a11b27605c430f, 0x227a93b2bd1694c0, },
		// Case [106]:
		{ 0x3d84da23767d6873, 0xf3a0923bf9059bae, 0xbb624f1dd774edc8, 0x272d00d7a8fb1463, },
		{ 0x287e10f2ff369716, 0x3cfe59e9b1f8762a, 0x19a01114cb202bce, 0x24c1b05696304907, },
		// Case [107]:
		{ 0xe0acf2a4d07d03bd, 0x068f5070440552ee, 0x3b81dfae32101a13, 0x1355a796abdfaa90, },
		{ 0x2c3e79e0ab2c9a21, 0x35df54bf95624cc3, 0x25b824516a2d5229, 0x17ff50efff7cf0ff, },
		// Case [108]:
		{ 0x2cd16afe2a033728, 0x02cc7d74ca8ef159, 0x6d4a6689b9b94f2b, 0x0734bcbce4180ae1, },
		{ 0x4e739dea48d05889, 0x8d389f315ff2997d, 0x6be4a27797b031d4, 0x1c85d91eff6d66f1, },
		// Case [109]:
		{ 0x6d3d15dbd4799d54, 0x627464b620d91e7b, 0x28199d989a9052e2, 0x0778d4a614c2f76e, },
		{ 0x17c32c394b06d697, 0x0ab5bfd34e1263c7, 0xad7e78381a15a306, 0x2b5403213be9417b, },
		// Case [110]:
		{ 0x4cb8574fe8bf869c, 0x27db377ae144ff63, 0x434d087c501859d1, 0x16bbc980a67b2a65, },
		{ 0xf23d0bfad0f7715b, 0x363a97206da50ece, 0xf2214369ac697275, 0x2ddb1b614e0d311e, },
		// Case [111]:
		{ 0xd59e4bac10d633cf, 0x326db7c7aaf2c1c0, 0x6894366245bed65e, 0x12a3e7e197b0504c, },
		{ 0x6abaab803b7eb2db, 0x1fa7c23c1aa71c24, 0x54f9ecfc6df94fee, 0x1ffcc20c3095a8a5, },
		// Case [112]:
		{ 0x1f4b8fea7dd5d33f, 0x99160fa9f7e20d81, 0xf42d9d07334fd67f, 0x1f35f8c4431fb0db, },
		{ 0xdfd06ec6ef8d654b, 0xf92565593a79f698, 0xe353f2d88b02c5ad, 0x214c7d1d09e5c6f7, },
		// Case [113]:
		{ 0x71e8bdf349bfdfbc, 0x2ff1556e77fbcc6d, 0x41cf55e7c85b8f23, 0x25d5bf1a863a0a64, },
		{ 0x09415263c719cae5, 0xd5b50e666c45f233, 0xc82166a1bcc32573, 0x108f2d55ed3e19bb, },
		// Case [114]:
		{ 0x19587a23332320aa, 0x87ee4ce30cc24cad, 0x3638216ae471176e, 0x15e6b8d9ab7e063a, },
		{ 0xb64d55954bf2e844, 0xbf9a6e82b9d8eea8, 0x8f6971de9bf6eef0, 0x16914f3811ec0d52, },
		// Case [115]:
		{ 0xcba7b708a534c9ca, 0x41eb2641bfba35a9, 0x7ebd0d1a40f9ec4d, 0x01929ef47c7322b7, },
		{ 0x0c0dccdf9757e8b5, 0xb33bc311318abac7, 0x94b8efcc7e9c41a3, 0x0d91bf70449ad6b6, },
		// Case [116]:
		{ 0x708ac65c51e3bb79, 0xb0e864d7a8f678c7, 0xea7911151247bad4, 0x184f51e791edaa2d, },
		{ 0xb94d39f91ac10d8f, 0x4732d182b3ad3806, 0xf21dbe7e15b6767d, 0x2342899e093ca7ee, },
		// Case [117]:
		{ 0xc535a410597cd866, 0x71eee0595ce1422a, 0xffb284df1ec0d4e3, 0x2605adf5562d5055, },
		{ 0x6f3385ca30168e1e, 0xd2b802efe45a1666, 0x316c515c179198f5, 0x207ca1d963b2553d, },
		// Case [118]:
		{ 0x3d2a4925c239ad51, 0x85bc9eae1612b8bc, 0xe007e1bccc814425, 0x06e6d41feb832c2f, },
		{ 0x4aa13664dc6c5d77, 0x921fc6820bfa3e6d, 0x77ee808bb36e9dd6, 0x2220f7eeef7ca052, },
		// Case [119]:
		{ 0x0fde4345ac9c954d, 0xe1c0d633cdd113bf, 0xe28db6ae5e780b7a, 0x137eb7da068955cd, },
		{ 0x86d1511a05cb8a61, 0x0393ef69382a9580, 0xed73c5f04245d039, 0x2b9fbca87d9df2d9, },
		// Case [120]:
		{ 0x4bf9e70eba6e9bb6, 0x64d7d187023ce2de, 0x3ba27b25879753fe, 0x2e97930eb419f735, },
		{ 0x1e10e0a969eb3970, 0x73e49c99350ff50f, 0xf61891da700f976b, 0x2f514f45e2a4070e, },
		// Case [121]:
		{ 0x9321736a1d812413, 0x07405bf9c75a9efd, 0xe62d6860fdab1592, 0x13af409362087866, },
		{ 0x469b45fe140d5d98, 0xafeec4114a22bf2b, 0xf0afd69340ab808f, 0x090fda6d50ccc346, },
		// Case [122]:
		{ 0xff2fd19259d47d62, 0x4966264560ebafb3, 0x46d57c8050737572, 0x0fd2f95404a9e92f, },
		{ 0x63f4b9106ea5cb00, 0x8155d592faaed173, 0x35e4daa2ced85d48, 0x09297dddb40a45b0, },
		// Case [123]:
		{ 0xdf3ce70e47d38116, 0x4384add521d98135, 0x826fc3012fc8fff1, 0x0bdd93ac21aedf31, },
		{ 0x917e0ac1ddf5bc3f, 0x412c56e13f7ac4d0, 0x58fe4aa6cb129b4c, 0x03a6ca5fc56ca5e3, },
		// Case [124]:
		{ 0xfefd5521f7d99f03, 0x811a6137788bb873, 0x9b601906befbef23, 0x083ea678d5a53e8a, },
		{ 0x84f0fb81d34cd029, 0xcd19de0cfdf9ec93, 0x1c8fa5cca1994b61, 0x0646eda052fd4092, },
		// Case [125]:
		{ 0xed6986d61f16af29, 0x2df6c6ccff6364c2, 0xcbf1b94f090df2d0, 0x08a9906be6e9ab93, },
		{ 0x5bc8981f82640f4f, 0x0463c73cdb0fe563, 0x78b743f9d4ac98c9, 0x0e5daac6bc0ad556, },
		// Case [126]:
		{ 0xb0333d8d535eaa47, 0xed19c604e65fb768, 0x49337cfa77f618e3, 0x187b1c82cfaf8804, },
		{ 0x7d31489da627368e, 0x8085735522efc1fb, 0x444d464b5e0ef294, 0x1794fab820ea141f, },
		// Case [127]:
		{ 0x1b8f3e90d7fec4f3, 0xc173f0ca4ea2a81b, 0x751143117f5e27d5, 0x245005f814e38250, },
		{ 0x1c0e663e7cda1bbe, 0x0938d07c02ddcb07, 0xcc425974530b4053, 0x11fffe4afd470ca1, },
		// Case [128]:
		{ 0xada71deaf1614db2, 0xfab69a61274fb36e, 0xf47fb1cf8ea8c757, 0x25aa5a53ec5e71f3, },
		{ 0x07acc1a108fbf78e, 0x1c2b420665f77bd6, 0x0cde24d8437ecc47, 0x2f26dd1ee7aba404, },
		// Case [129]:
		{ 0x4492c2cc4b0c8bb9, 0xd91b14cd9b6578b6, 0x3b39ec6b775f07ca, 0x01c244a2ed192275, },
		{ 0x2aa3bf107bf1c1aa, 0xda700768980e7b74, 0x6bd43ace413c6d4e, 0x0f7b47ac349e2163, },
		// Case [130]:
		{ 0x7daaa853d46c382e, 0x0f3e59eae24fcd7e, 0xcb10cf3a3bd51afa, 0x01664e5c861216c4, },
		{ 0x3bfd9296bc6db9dd, 0x5331a2fc85ab23a5, 0x8bfe239f8566558c, 0x295dfb7e561d4282, },
		// Case [131]:
		{ 0xd2e0f0a00e424074, 0x4da2beada0449ea1, 0x1e327ad212ed3023, 0x2af001a296c111e4, },
		{ 0xbc9df034604060dc, 0x6f92bb68d2beadde, 0xa3294c09f90324b2, 0x05a2b9c5911bc6d9, },
		// Case [132]:
		{ 0x066e45039aed813b, 0x5433b270f28c24e6, 0x5f661a287dfe2391, 0x16022bdd67d2ade1, },
		{ 0xa9e360ece001704f, 0xa8b77c8d4323c801, 0x36f75e6fb6d94ff9, 0x12d3dc410af49a03, },
		// Case [133]:
		{ 0x2c74a749a26826f6, 0xdf36916384a54b81, 0x864268ad723e8780, 0x132d7ca5f935f3e8, },
		{ 0x074bc0755806f7c3, 0xa3d35fd45872d6f5, 0xa983d32bc9958a20, 0x273f2f76d6058c80, },
		// Case [134]:
		{ 0xc5db95fd184c4f37, 0x4a273808807ade4e, 0xa99d0e8b0d69b79a, 0x20bdab9829e48c89, },
		{ 0x208fe7cb89493c5a, 0x1dadf5ad9edf026a, 0xf1b573bdfa8166d9, 0x1f2c85523d4ca68d, },
		// Case [135]:
		{ 0x161e61772258a951, 0xc2afe87bc1afe556, 0xab52d719ea05f98d, 0x28db494350ae9c81, },
		{ 0xdb38e11a2dd6d88f, 0xe3b119e32b93dd87, 0xb6f661b614abb78a, 0x13bff0139cce17e7, },
		// Case [136]:
		{ 0xb24d9cb9f3fb3ed0, 0x0ab9f6041e0e51d1, 0x3af3427b77ea74e8, 0x19fc92f1d2c1dc04, },
		{ 0x8bee1cec613da662, 0x2333633dca1cd1d5, 0xf369825d4b37d442, 0x252d5b3435c410c2, },
		// Case [137]:
		{ 0x1dd733c3cb884705, 0xb90c7e5fd02bbdba, 0xb6c86afca80b606c, 0x16bea7126b8f072a, },
		{ 0x9174ffb668845304, 0xddb55314418c5d1c, 0x4dcf576f47c201fd, 0x2d88228d256cfc4e, },
		// Case [138]:
		{ 0x0a126f5833f1fd5d, 0x28fd09e0dff88955, 0x15a417ebb4bf5beb, 0x1fc57b168a5badca, },
		{ 0xa783e1dfc6ac80e5, 0x0fea2041cb421b8c, 0x46f71c6ac80d1982, 0x2b3ecdcfc61e3a86, },
		// Case [139]:
		{ 0x7d23dcbc65bd9afd, 0x7d56699cf37dd7b9, 0x334be4ba911dec95, 0x1ad20d1a3ee559b6, },
		{ 0xcd083c6ff0e5043c, 0xc66e4c95cd7e08fc, 0x1d7b11051560f4b2, 0x10a197a7ed4bad3e, },
		// Case [140]:
		{ 0xe0fcd7bebcd88885, 0x59a3e5bcd20895ad, 0x027393a443b6e25e, 0x2173430a6842061f, },
		{ 0x8e6b229c591255ec, 0x55727250e008f687, 0x5d26ac28c2b36dcc, 0x0c24434f8f08c991, },
		// Case [141]:
		{ 0xe1534b183fe27cd8, 0x7a23d7f3003680f3, 0x7361db05a0b06714, 0x11673173043e1513, },
		{ 0x3bafe17bd2aa5b4d, 0xe1e5c4057d6d4c94, 0x29f06cdf42a92224, 0x018d8623f2a1329d, },
		// Case [142]:
		{ 0x56eff65129259ff2, 0x84493eb998add055, 0x22181f3e77388069, 0x037c80af5ed51c1c, },
		{ 0x015322b3521af3ad, 0x312970de5092a619, 0x526f02ab45de1086, 0x08348866d9b65d13, },
		// Case [143]:
		{ 0xc36f6b44e9b9ff5f, 0xb63fbd25f3038285, 0xcacd8c0954040548, 0x1d70b961246d2262, },
		{ 0xefdcf0e48369ce54, 0xeed518501d004b5d, 0xd398ae060ebbd1ed, 0x27fdc52f433d6ee3, },
		// Case [144]:
		{ 0x2c63252186b6c44b, 0x9635e4610c25864b, 0x6dbe3de73f383a90, 0x2184448a7bb80d17, },
		{ 0xd843c471b19cb1d9, 0xcdb0bf3655bacce6, 0xb1407a5c70fcd0d0, 0x1b5c2fc67683765d, },
		// Case [145]:
		{ 0x13f36521a5dba7d0, 0x6c7d3c96c1bf7d50, 0x9e7b317190ebbb9f, 0x03bdca6b22fb80cf, },
		{ 0xdbe1d41f790122e9, 0xf52ce6da3245c9e0, 0xb8ddf5ffa7a371ee, 0x1fb39f7242df2c46, },
		// Case [146]:
		{ 0x0d1af952eb64b247, 0x436f4eea91a100ec, 0x44d510dcb3f55048, 0x2b65873313d5bffa, },
		{ 0x4f74821676d23c4e, 0xd19a2d200b9dc461, 0x92ebaf258bddb444, 0x0789b61a9b6a8269, },
		// Case [147]:
		{ 0x39b53778ca274616, 0xf06f37ea10e7e3f5, 0xdc03c9cbe82e857c, 0x2a7fd02ef10db1c9, },
		{ 0x6057ba97fca83eca, 0xbfffb63c97b26942, 0xb5d251152ebd834a, 0x070579a494f58368, },
		// Case [148]:
		{ 0x5fbc2196fb8b569f, 0x72da23b3d2142d26, 0x65713565ee4255ce, 0x1cb880cea1921538, },
		{ 0x3db237344b789aca, 0x32d58051bffe3423, 0x0788d6d736c200b7, 0x09f47f6a3a2600d3, },
		// Case [149]:
		{ 0xd47cdfa548a91a56, 0x27484f594a7e3ba8, 0xc1d60029a69c843d, 0x16628b6f83fc36bb, },
		{ 0x59353832c3135f86, 0x12b6b3e9d2a64c3b, 0x97bdd935afc10930, 0x2728e1bdb28a2ea4, },
		// Case [150]:
		{ 0x2e4b8dbe0080f16e, 0xb760d4919bed798e, 0x9e76e037104f8886, 0x26fa9b84e855f106, },
		{ 0x2358d021dc2aa49d, 0x74f97b3314665791, 0x5b8ff88f2425b8e1, 0x03f4d21c4b3e1d42, },
		// Case [151]:
		{ 0x1b9ecd80da9e9687, 0xf05b9161856d658c, 0x26e36a6c4ac9fc9b, 0x0ee86c87bdf0ecd5, },
		{ 0x10006fb3281c5cb6, 0x263745cd7e376b0a, 0x359b9ad48ef7ed03, 0x17be9c992016449b, },
		// Case [152]:
		{ 0x6734ffa85267191f, 0x84c63cd115ffed3a, 0x05527cb82b6f6199, 0x08a5179993a80564, },
		{ 0x04673346b12f4bac, 0xd23e5885da66245e, 0x47baeb7e52373268, 0x1ca34a631bb2de88, },
		// Case [153]:
		{ 0x875f45df7eeb5437, 0xbcc2ad3949dcf96e, 0xc4e0a2f291e62124, 0x047aa61e4bf0721a, },
		{ 0x0481e34424094570, 0x88ecebc2f4887436, 0xe4867ff4ad8cf216, 0x18438fcae04e74dd, },
		// Case [154]:
		{ 0x2eb1ef5bc4f21148, 0xf5d1fec21ea8bbfe, 0xc6d282b52712a09b, 0x263a511f033e1fbd, },
		{ 0x6d8f44a09fa553f1, 0xdbec9e60d6a56b81, 0xfdae5a88d4e9d0fd, 0x2da81322262c0c28, },
		// Case [155]:
		{ 0x7386c9b1f993f34e, 0x31b86432a2c100dd, 0xd8c859b449bbda76, 0x226520bf730486e2, },
		{ 0xe1304cf898ce341a, 0x642c5f4045c5af46, 0x2d5a1eeca7e50d63, 0x2e04e04b9cfb84ab, },
		// Case [156]:
		{ 0x157b386a7d356357, 0xf0d18d38b893cbb1, 0x788f0c5a940f5a4d, 0x2baef27107a52854, },
		{ 0x721061b19ae77ee5, 0x8103c30ee186d5b2, 0xba45bbbdd7cd2fd2, 0x268c609a1c3f7961, },
		// Case [157]:
		{ 0xa60cf70c8da5fc52, 0xd9c92122f7de5651, 0xd54e60e300b5c949, 0x18022cca17f26818, },
		{ 0x580411b94216a470, 0x5e1158b2707c729e, 0xbbc284462dfd429e, 0x2c540bc098998288, },
		// Case [158]:
		{ 0xd94dd67de6717d25, 0x785caef8565777fe, 0x1e6ed10f52abf1bd, 0x07baad301d58460d, },
		{ 0x1729dbc4b0e67159, 0xfc17c4610c125b59, 0xa9ed1d97cced13e6, 0x128127d5d53d6126, },
		// Case [159]:
		{ 0x2f4b01047e248a6a, 0x1a7f71b4135be366, 0x3a5aac6e110df2cc, 0x1e476106c4bce390, },
		{ 0x88b407736dd4263b, 0xd27e7df62e2df1d7, 0x0d567b523ce7b78a, 0x0bbf519a8039568d, },
		// Case [160]:
		{ 0x5c7e9d1bb6e77a98, 0xc3fc1ebdedccb804, 0x2df063c210466a88, 0x1e019dea5028d23b, },
		{ 0xfb77b9db00d0dcc1, 0x2eda50184aedf107, 0xcb9b040eb230d537, 0x0d20de39146cae34, },
		// Case [161]:
		{ 0x5f9a9908186308e2, 0x7174c6b6067e730a, 0x47b254d29a73f5ea, 0x0dd55f006559bb67, },
		{ 0xe53add8da7666760, 0x53bd45a5aef04c83, 0xa857de19f4a28761, 0x0746d083a1ea9136, },
		// Case [162]:
		{ 0x38a48a952c029189, 0xebc81be408cb96fe, 0xe0c9059d3b919fb2, 0x0993085a8024a598, },
		{ 0x365b3ed770da4527, 0x5a3c7338b8ee8e73, 0x4462b744bcc94339, 0x2a0c0990e7466be7, },
		// Case [163]:
		{ 0x9f165869ec7fb9b7, 0x7893787bfcfb13b3, 0xb2115493ee06e26c, 0x143f3cbf98e40971, },
		{ 0xedab20f27514ca05, 0xf9d6bf0ea095713d, 0xd913cf1a4b4a37c5, 0x2acbaa911aaf67a3, },
		// Case [164]:
		{ 0xaafd008524eda07d, 0xa030d497312cc17c, 0x8d033b021395754f, 0x0525ff28fa24291b, },
		{ 0x2868e97b81964c59, 0x0cc38f37a87b8d99, 0x47574ac83d230068, 0x1264bddcc3b17077, },
		// Case [165]:
		{ 0x911f708eb05cd852, 0x025095182d5f40d5, 0xf449142017909392, 0x2d9fdc18cd2586b9, },
		{ 0x5d15ed4da99796eb, 0x56aad7b4c054024d, 0x216d6f426435b357, 0x211261ff2b0a16c1, },
		// Case [166]:
		{ 0xe6dfb400efb43f45, 0x8e3621d613fe0e78, 0x1e1bf1e59a9d0118, 0x230997202fcd6f05, },
		{ 0xbc231a6717043166, 0x2955c7f0f3722703, 0xbeb0a3bfab5c507a, 0x2c8658043be2152f, },
		// Case [167]:
		{ 0x80aef7ed69e7171f, 0x0d11981a767e507b, 0x0c0f075e20f390d3, 0x044b56469ffbbc9d, },
		{ 0x1cd11d15679b27ff, 0x3959f535fb323892, 0x8280ef23d0110e6d, 0x20639e4eb1d0aa8c, },
		// Case [168]:
		{ 0x3eaf7a23736150b7, 0xaa71672e00245039, 0x23a94555d1e4d379, 0x1507d88bbe10b21c, },
		{ 0x045d5eae01e4bd61, 0x1e027cda3022473b, 0xaab025a4a0fe1237, 0x0aff41559c17b3af, },
		// Case [169]:
		{ 0x3c6840594824e9b6, 0x151b3cf6a9ea1be9, 0x26377ec798404f71, 0x104d6752a761b500, },
		{ 0xb41b22c2ab0edc72, 0xe27608c8bfd678f4, 0xa9a3a5eb04e6520b, 0x14f6c24f4f4dbcfc, },
		// Case [170]:
		{ 0x44bbff12b1e0ec23, 0x46a9fd2226aa604d, 0x6558de60da729414, 0x25276305cdeae4c1, },
		{ 0xe721859dcde1b69b, 0x105cf5386b1c2bf5, 0xd5b350f3f3b8912a, 0x25ba225ee7cdbfd4, },
		// Case [171]:
		{ 0xd0c30cbd9812051c, 0xdca683dad8cc35a6, 0xd7dc4c7cabd97940, 0x10f3cefb054d630b, },
		{ 0x06c77fb567377c8c, 0xa568d2907bfafad7, 0x00dbe6600b7aed06, 0x1dc027d89a61fb6c, },
		// Case [172]:
		{ 0xcc7cccec809df03d, 0x1baff0585afc4fce, 0x4ed043ff3cb1d689, 0x0e406cbfa384c6b2, },
		{ 0x1b2e9a374d216845, 0x628d3b5c70853a29, 0x7d3058116f4de82d, 0x1ac0f526be6a5359, },
		// Case [173]:
		{ 0x3534cfda40aeaf0d, 0x863efdb8966db7ed, 0xda0c12616b00b611, 0x18f36033fcf64f1b, },
		{ 0xb5be8ec075811366, 0x5becc898005b387a, 0xc0bd4e95c3565f65, 0x042fbd37acc0f80e, },
		// Case [174]:
		{ 0x06dc56ca6c937c52, 0xba2a6db07572dba1, 0x3255723635a51a35, 0x165d022a34cf10ad, },
		{ 0xa7ef9ced88ea5c0c, 0x60099022942fb995, 0x78ed7041b9c8c836, 0x0067bc9c791dad49, },
		// Case [175]:
		{ 0x27a539c47819424f, 0xc4b10e58baa13658, 0x18265b56ecb7a4cf, 0x223c8c9aed305b3d, },
		{ 0x8804f60ee9d208e8, 0xddb5aa16edf0e52d, 0x900fc07dcc3a9330, 0x0cb2e611b1dda3e0, },
		// Case [176]:
		{ 0xd7b28c8984fde6d6, 0x511a2b5268f1ac96, 0x1aa185a1f8221ee4, 0x2103fee94674840b, },
		{ 0x98fe7af20c4d678d, 0x51244c4308279afc, 0x1b99e9f17e8cc1bd, 0x2231e69f1424f08f, },
		// Case [177]:
		{ 0xa92806f78ef9d384, 0x23ec5cd55297a387, 0xa02abf2390973c17, 0x1c1396433bb9eac9, },
		{ 0xaebe782df557b86f, 0xad03c4d31d7f738d, 0x8fa45cf7e53827ee, 0x2a5488d394b6c4fe, },
		// Case [178]:
		{ 0x0cb4decf109f1b92, 0x06996fd32fecb72b, 0xc9ae9226169e8981, 0x1befee24005a88d2, },
		{ 0x16d547b16b5e0b34, 0xa8d240202ff4f356, 0x9b9fc35641566647, 0x119d3e7e1585fba1, },
		// Case [179]:
		{ 0x50c8ac41350f5184, 0xc2fc742c806f0d59, 0x727a64e98675ea0a, 0x1adc49f1f1b405df, },
		{ 0x184a7808f497e30f, 0xdb1d1c0fc65a592f, 0x57fd05cddbce074c, 0x1bfd5a4d56792bce, },
		// Case [180]:
		{ 0x03eae240c9c847cb, 0x4ef739173cfaab2d, 0xa00799dab1f2e4a7, 0x10a0e0cab76db0b6, },
		{ 0x66d636628277d02a, 0xc4459b84833a829f, 0x35fd0a8183608049, 0x15634b35c6360466, },
		// Case [181]:
		{ 0x0d2933af1af3f997, 0x1e047c0b27ef49b1, 0xed0eb91b6c4f974c, 0x1a9aff62d6c66fdf, },
		{ 0xa02d54d8c48b51a1, 0x92f64d8032ac4005, 0xb476d36198885b64, 0x0a66d7e43cf6fc83, },
		// Case [182]:
		{ 0xd191873985f95cb4, 0x725f95e21fc36c8e, 0xf7411034526eb5ac, 0x261967f6840995da, },
		{ 0x8ece15ec549aefa4, 0x9f92460ef6d55b90, 0x9803c3172638a09a, 0x1e84594ab03f663a, },
		// Case [183]:
		{ 0xd183c89ed5286098, 0xe1af2f88fe7dbe29, 0xe09eb016f4254086, 0x1338030f85fcd2fa, },
		{ 0x639900fd61950852, 0x35904dfdfc6cbaba, 0x98b90b34085fba99, 0x139187275864b2de, },
		// Case [184]:
		{ 0x2bdf1649c7911ada, 0x50c1134914cbb4d5, 0x99ff109e777727e7, 0x02c53745d1f0e664, },
		{ 0x99032d00f6fa0231, 0xac6eca2712ab5bf7, 0x9a166250f7bc547a, 0x285f263f73adbf60, },
		// Case [185]:
		{ 0x276ea7d9f62a05d0, 0x0e88d8b0b82d10c1, 0xd94eb857a1c5df1c, 0x2740100354406de4, },
		{ 0xfce911abb56770db, 0x3b5beed73c235296, 0x33caac430e2f054f, 0x293664c07a53efd5, },
		// Case [186]:
		{ 0x05a6226887c9bcef, 0x3e4f150d1c32ac89, 0xa9f7dc08f24d7086, 0x0b8a9153d3d643f0, },
		{ 0x60d820e0b114e59f, 0x859cae7e9ac9896e, 0xee91459dbbef032e, 0x26b620b6cd19bacb, },
		// Case [187]:
		{ 0xeb72cf548b2eea1d, 0x3801ed1aa4059d94, 0x9c1ff69b0b86a0ed, 0x25dd73d81ea8918c, },
		{ 0x5e8ab5262c44a1f8, 0xd23af82aaf622e40, 0x4d160279de37bd9f, 0x058ba4208ceeaf43, },
		// Case [188]:
		{ 0x9dcd12891ad1526f, 0x277b4d0312a5888a, 0xc7d6622bdb9faaff, 0x253d813cf05f2ff1, },
		{ 0x389b6562c43136e2, 0x84c971e2d61c16c9, 0x4faf1615bfacbd3f, 0x07b5a7a3f879ee20, },
		// Case [189]:
		{ 0x0eb2c15ed830f5f6, 0xd2c8e62e3af51e02, 0x54c944b57752bdd8, 0x2523322d2d2a78cc, },
		{ 0x819a7b491ab1660a, 0xcc321ce81377742b, 0xf9bdcf7a2a9033a6, 0x0995e15f19758908, },
		// Case [190]:
		{ 0x2ae3e4f83b0071b4, 0x2377f3b4ac98e10e, 0xe8dfd47499cdbd4f, 0x2ac9c2d60d456848, },
		{ 0x635c7424db50e82b, 0xe1cf748b226ecea5, 0x1fbee5a6bc357f94, 0x056009067b0ab278, },
		// Case [191]:
		{ 0x30d94f9bc4386bcf, 0x8a9716174f47fb08, 0xf9ccb8c75523b1ac, 0x2a4e35f1df833442, },
		{ 0xac85a339202c30a9, 0xdbcd9f0888e98f00, 0xdedefe5d718fb679, 0x06018fcdb609e086, },
		// Case [192]:
		{ 0x0522dccb096f9fdb, 0xb676d174acb65b73, 0x926147cbf79a7330, 0x270e7f6b15f2c0e0, },
		{ 0x54bfae2639949836, 0xfccfe82d92c15414, 0xce8d1c19373ebef6, 0x2e6199bf0e97256e, },
		// Case [193]:
		{ 0xaebb2ca2ef52ced2, 0xe899f15214f0b8fe, 0x274634e1f5a4e50c, 0x1933ef75d4b862f2, },
		{ 0x45ffb4e1902ea605, 0x9c8247850192e219, 0x26fc56cb885e359a, 0x24dd2ec65163e77b, },
		// Case [194]:
		{ 0xb1b0fa7aa5175dc5, 0x4108d364bbdc6acb, 0x84278a31841109da, 0x165130ddf77a82db, },
		{ 0xe0b09494c5baeb55, 0x5ec8377dca75c370, 0xd959137bcaa7be10, 0x0c42867f3db9b771, },
		// Case [195]:
		{ 0x19895b9f6fceda6c, 0x5505e965b7e7dc4c, 0xd5d8b1340d0d37df, 0x2fc1fe031dcd4538, },
		{ 0xc677a8b37f0a698f, 0xc30b3be018757275, 0xa0e0a4e64c949c98, 0x2e92bd18905f10a4, },
		// Case [196]:
		{ 0x0a1e4bcc0f62f16f, 0x5d546422e7730e36, 0xd903eaeb6e02a7c8, 0x0e1ead2be6f64559, },
		{ 0x6e2b0e353e21aab2, 0x1b53ee05465f7b34, 0x67c528f5e669f8cd, 0x1e645a3f0a131bec, },
		// Case [197]:
		{ 0x067d278e21c8e54c, 0x4f161fda3d05b1a5, 0x5df30a2e4b22535a, 0x0a983360bf32392d, },
		{ 0xdf0f40306be85558, 0xeedeff3b40f2b77e, 0x667ae78df1b919a7, 0x02f8e176eca26260, },
		// Case [198]:
		{ 0xb86d6a79d729f4ce, 0xaeef782e879c5230, 0xc17eff9bb1e5ed0b, 0x2e27e61828693607, },
		{ 0xa7c52e5885178b7a, 0xe21f7102bcfc79c1, 0x9d26f1fa508ee779, 0x0c38174213e4422d, },
		// Case [199]:
		{ 0x38c1acd006ffa53f, 0xce7b105cbd04e7c8, 0x22ace505e837caa2, 0x0d1cea26a08207e5, },
		{ 0x0b724f6cfd2415e2, 0x743ec48bc089861d, 0x8bcb1717d1b06db4, 0x012fe2ac3c78780e, },
		// Case [200]:
		{ 0xccde4c38cb2a1944, 0x396a03568376fb44, 0xe9e4cef89abc82e3, 0x0b958dabc9a8066d, },
		{ 0x631ed9ae97967fae, 0x2ffb2f4d38d36231, 0xc777d2dbdeb80b6c, 0x0d3145c928b7ab58, },
		// Case [201]:
		{ 0x6cf2034a9b88bbe8, 0xb1cdce307261dec8, 0x87ffff796bcf8175, 0x16f5b42d88f8d4f7, },
		{ 0xdc8db9b1fc0b5cdf, 0xc1017b073bd635c6, 0x4a26ff0e68fb4206, 0x254b5ef08b425e76, },
		// Case [202]:
		{ 0x7435a288c2b6c63a, 0xdbcf7546ef27f47d, 0xa61f0fd4b976b00d, 0x12b68aec2db262e0, },
		{ 0xae85a28f32d35869, 0xf495d203c423873b, 0xd0e9050246e8a852, 0x2d026757a549ed34, },
		// Case [203]:
		{ 0xc87b77628ab6d84d, 0xf3f81ef863300944, 0x39d06ca5870e3503, 0x1d2238d8d9768dc6, },
		{ 0xb1966d095692d0c1, 0x58ec12c35a981b86, 0x615218e56cf98cb1, 0x06789bec137d217a, },
		// Case [204]:
		{ 0xe382bdc6b790d91a, 0x95e75d4833ae232a, 0xda3ae332a831cc9a, 0x0d164e32fca3c3c8, },
		{ 0x9b3e17ad08b9c124, 0x275d8b8ec14aa60b, 0x6f0dd848e284a324, 0x17fe35bd37fa1d99, },
		// Case [205]:
		{ 0x62000d7f6ca8ef3b, 0xb762a5c47b57739a, 0x2fa19234fb157661, 0x02fcdde6d6eabd7f, },
		{ 0x4bae57e37c06f59c, 0x3dbdf2157d24e4ac, 0x4f6076872014e062, 0x2ce92d1f0e3676f7, },
		// Case [206]:
		{ 0xf9c8c21908efbe37, 0xc802a1590df5e5b8, 0x84574647812ca377, 0x0f133b8b1e54f434, },
		{ 0x172f1374f0cc560b, 0x7b2347c920adab85, 0x575dad0a6e13bbbc, 0x0b8bd6f6f1bb0746, },
		// Case [207]:
		{ 0xb472d9dd29c42bde, 0xe60afd13ba4e90af, 0xd1a4bad8241e14f1, 0x03057ea8932e9bf7, },
		{ 0xe21a66d7f262c0ee, 0x6ca8e4d67a1cb7ee, 0xfc3c347131b9d809, 0x226e8a2d541886e2, },
		// Case [208]:
		{ 0xe45c88b0088a9f18, 0x1bc93f33645825d0, 0x0debdc825f776457, 0x23dbcb6ecb480774, },
		{ 0x1cbb82d4f60d9fa7, 0x5893095b16f3e59b, 0x25df84519d5b3770, 0x24b8b64a205fcffd, },
		// Case [209]:
		{ 0x79927ecdf63edac9, 0x9423bc3a76f82895, 0xcdb64ab45e24c2e2, 0x01b90754a2058217, },
		{ 0xac60fd50e4c2f8d4, 0xa177404c78999082, 0x816d17c0f5e81cf1, 0x1f5978dc8b04ced6, },
		// Case [210]:
		{ 0xbb9514a0f038fa91, 0xf9d0271c74d957c6, 0xc8e107e198aeaabb, 0x28db800ae16d7033, },
		{ 0xa52d14b8c21de72a, 0x418346988ac04197, 0x22bb7385f276a973, 0x1eb0f4f0c1ae31e6, },
		// Case [211]:
		{ 0x73cbe477c3fab178, 0xe58eaf37b5b94394, 0x4cbdbdc36e5ef374, 0x02f97a36ef93a790, },
		{ 0x598b971cf5712c6f, 0x0afbb16622ab5e3d, 0xd57fd0451cc66a50, 0x302ac3249050ddbb, },
		// Case [212]:
		{ 0xa130743e03ed3caf, 0x5b9e8089d1697445, 0xb5cbd19ba7b955a4, 0x1bad1d9637a6ad6d, },
		{ 0xe7f1dc87426f9598, 0xd60817484b44a475, 0x778dfdbec17dff90, 0x06a63bb4f93154ff, },
		// Case [213]:
		{ 0x179753f740edae80, 0x5b9c43220b0a3279, 0x878b28bf96d28185, 0x2b96f520dda8251a, },
		{ 0xb589f750ee9331c7, 0x237d2810f0c8d85f, 0xe561d7d560a8b1f7, 0x1c922e190c29bf4a, },
		// Case [214]:
		{ 0x78ae12843212909d, 0x0999e0e0e40c6543, 0x0fdf7974bf922b7a, 0x041f97f76c60b28e, },
		{ 0xc0a8bcf8e1aeeb9f, 0xf9761b0bf647ee5f, 0x92b0ce34a6d9dc94, 0x22e0f292306b2131, },
		// Case [215]:
		{ 0x95616c2aed5588e0, 0x3aef9726cbd9835b, 0xf5fb6d0809312397, 0x13b5cf57475057a2, },
		{ 0x81b7d3ede46cb347, 0x7cee90a7afdc06ab, 0xcf9b99e15844ba99, 0x04c2d551634c33cc, },
		// Case [216]:
		{ 0xf7491fa2df12deee, 0xf84d44f3d2e398b5, 0x8c9be92a15e7ad0a, 0x2ca43aed5aea162e, },
		{ 0x1a00e6705b4f8290, 0x82c2def1b7cc1ea8, 0xd9f122d13666f288, 0x11cd7648a1c11051, },
		// Case [217]:
		{ 0xab0c5d9adb5c3df0, 0xf0f2f96ea11df270, 0xe6ea69b9649520a6, 0x089f6b1ec8b51cd1, },
		{ 0xc6da52bf057e0cd1, 0xfea214e4481b2f32, 0x9606ed7e2a290589, 0x17ee2df63897408c, },
		// Case [218]:
		{ 0x3711d1300b4d1275, 0x6041772627793a0f, 0x0babb8ed7c50c34c, 0x04f510cfc7e52837, },
		{ 0x0096f1acf62f8d01, 0xc01b7830df44a966, 0x2d540dd94a5ec1ef, 0x247681a07beb772d, },
		// Case [219]:
		{ 0x5f8164d0f13d1059, 0xbad5b7af4ee037ea, 0x63affcdd5c2862f4, 0x260e12c47d0ab525, },
		{ 0xdade0a46f3c43279, 0x475b587aeac47610, 0x0959c464baa94f15, 0x0ac56b30625d49c3, },
		// Case [220]:
		{ 0x7bb35b12dec772b7, 0x6cc0d60f8dce451f, 0x8aedd8515b3111e1, 0x1a656424760e7546, },
		{ 0x39a56ee0a802ebc1, 0xb67673b38de35d83, 0xf2be8598dde91f5b, 0x184ecf77b3821103, },
		// Case [221]:
		{ 0x879e9bdfbc6711a9, 0xa6c70cf72f222b80, 0xed20058b6769fc27, 0x00cc850e959c567b, },
		{ 0xc76be3e8c5741d1f, 0x939aced678e24bbd, 0xb7375fff3917ecbd, 0x09345358a3a3ee56, },
		// Case [222]:
		{ 0xa0b699bc60f18cac, 0x0e19d0bbe875a7f3, 0xbd8688695c64ac02, 0x088947910eb3b43e, },
		{ 0xa530f1d0618b86c8, 0x5d7e7e1a207acd0b, 0x565b8ea5b323be32, 0x1a8ebb4e24ed35c0, },
		// Case [223]:
		{ 0xe790dc4babdc86be, 0xace9f3f9afb09071, 0x45fde5b178105655, 0x2c25c236bb48035f, },
		{ 0x1471d82db761deff, 0x0639b54453c58252, 0x0190818b2deb0dd8, 0x1a2265ac895ed06c, },
		// Case [224]:
		{ 0x1704904b2905da68, 0xf2bde0d79ddbdda2, 0x9ba65865769c9e47, 0x12dfe1bc28654f5c, },
		{ 0xbefa2ec865f2c40e, 0xc2463e2459e7400a, 0xccde35fc9d445b50, 0x217aaf9dde1a62da, },
		// Case [225]:
		{ 0x2a986a6cfb2fd8fb, 0xab5b0442f0b8efaa, 0xf08f745e1413bd83, 0x05645b68f99a564f, },
		{ 0xa2499095f46f73b6, 0x52a7ffa0a1654b8d, 0xd881b3f8ffc6bcaa, 0x0e405c8b614e9971, },
		// Case [226]:
		{ 0xfa4b110e43864c75, 0x2e9c259126bf6310, 0xad640d912e41b4c7, 0x17cf3ec9831b4d6e, },
		{ 0xa243b2b0ad46f694, 0x7112bb1ad7c683d8, 0xaadbc43f57af5a20, 0x0781d5bc287c9f5f, },
		// Case [227]:
		{ 0x72fbbd5689a66f61, 0x7dd721ab44af286e, 0xa519ab9cc67a78c5, 0x12b15f28fefe5d6f, },
		{ 0x1f1e1352065ad2ef, 0x3608c823fa6eda25, 0x01b2b90c14b53fcd, 0x0bedf5496119daf9, },
		// Case [228]:
		{ 0x7ffaf8e59842a00b, 0xedda8eedb6fe6d03, 0xcbdacfaab2e1ef01, 0x2da44f7210520779, },
		{ 0x1337d4e9db706a42, 0x3ea7ac8cd67d9a1f, 0x9c3e85f9c18dc915, 0x078ebe2d80733bc2, },
		// Case [229]:
		{ 0x2f7da2e5d9a894cc, 0x3bd393d5c9a961cd, 0x2afa165f11588b40, 0x137ff7323fe757f3, },
		{ 0x9400103920c35225, 0x3a2d6ab122ab1917, 0x5ac44dfac1e78f1d, 0x01f61efa615b42e2, },
		// Case [230]:
		{ 0x95de945c8cf78aff, 0xb91ee0bf27b44511, 0xf04ef48679c73d46, 0x1318105fa9fe1549, },
		{ 0xa96dae6d75f41290, 0x43d4efc076e15546, 0x37eb34a3e9d5fad6, 0x1e1f210e10ac3c7b, },
		// Case [231]:
		{ 0x8d1f843c3ba3438d, 0x121708c312e635ef, 0x1775936b2c2d476a, 0x1408a4259df52a49, },
		{ 0x0643e7dd7ddc141c, 0x69e7a8abd2935f41, 0x6886cba6f4ab51b0, 0x1156945646a80ca1, },
		// Case [232]:
		{ 0x5193eb7571585d07, 0xc4f447f20cac98c9, 0x80dec5be44ae2ddc, 0x10cf20dd5734c188, },
		{ 0xc4ad25bbdebb97d6, 0xd10a69b8dfd28f7a, 0x125a151f32b30e9c, 0x207ef888d2eb2058, },
		// Case [233]:
		{ 0x4ea74d6010b7d08e, 0xfeb1e37fbc3a9c8a, 0xe0c8b5a471974ac1, 0x2787fe4623bd3264, },
		{ 0x86b6d5bcf346e0e8, 0x96dd1622e9bcbc89, 0x1fa9070bcb5ab994, 0x20789c57b8ff71c0, },
		// Case [234]:
		{ 0x33db582d45ab172e, 0x1f703258bc03707e, 0xc1dec3c59dbf2a6b, 0x1b90e21074907545, },
		{ 0x0c50d8eaebc34da7, 0x6d23b9def3e8fb84, 0xaa796bf01f1ce52f, 0x1372f71a9f4597df, },
		// Case [235]:
		{ 0x5022fdbc40636cfb, 0xdfd9429a7b3632bb, 0xb779a0801b90863e, 0x0b8e912a5ec5a0bf, },
		{ 0x9be076b438885a73, 0xf9938c0283458d1e, 0xd84b2bf0be9374d0, 0x0401532b32232245, },
		// Case [236]:
		{ 0x547a3993044188db, 0x3ee6b0d8abf31f1f, 0x0bb7a555c34df318, 0x0d9982378cd9a837, },
		{ 0xd05c4f1c2edf2248, 0x0ad85bdf4c23bf61, 0xadd5018b08c48740, 0x126ea3c76d8b8795, },
		// Case [237]:
		{ 0x6f6940221d248af4, 0x29a468d1cd3ecde5, 0xd630b0afbf6d376f, 0x1e497bcfd5c95cdf, },
		{ 0x89ec1cc640d6457a, 0x4657f67be76af1c8, 0x1b948aabcf2dadf2, 0x2d72a2ef43e44f3e, },
		// Case [238]:
		{ 0xcff9a15076585b7a, 0x9a5a4acbc935686c, 0xff3dd552e271eec2, 0x2d602401cabbc69d, },
		{ 0x47fd97be65f42bae, 0x38175578f8094c70, 0xf4b6fe50fc4a977c, 0x07789d2fac9ecebe, },
		// Case [239]:
		{ 0x784951f2abefa707, 0x803c0d355f3e10a5, 0x330671ad2a361f2c, 0x170a5f4518f58544, },
		{ 0xf5ca7153274b19ab, 0xa40c79e5a70c1575, 0xdb2459fafd4cafb4, 0x0233bab186696518, },
		// Case [240]:
		{ 0xc784956acf98865e, 0x38776af671edfe44, 0x1c08502eca497be9, 0x21b3a23c3a553d40, },
		{ 0x6b4e3e9842fb0902, 0x282b02fbf6e7ef23, 0x95e7ab43c39bc0df, 0x2874115d1ab600cb, },
		// Case [241]:
		{ 0x88c2b1166e8e479a, 0x7490e824a14204ed, 0xb9c48c9ac3cee530, 0x224dd497bf3a4247, },
		{ 0xca0d76b2a9b20718, 0x9e58021153bf392b, 0xb61364ea26b51d15, 0x14e49c235e586d65, },
		// Case [242]:
		{ 0x00624a375302e0ef, 0xbaaf0f68d42664e3, 0x22fb54e676ac8401, 0x2654965a3bf3c924, },
		{ 0xeae7237e82c3a4fe, 0xa7cdc98522ef4490, 0x46efdf57eb4cce8d, 0x1722ee94e5d5ac50, },
		// Case [243]:
		{ 0xe299677820839f32, 0x726e95be160ee1a3, 0xc006828670e7785b, 0x1d525f4105f51b69, },
		{ 0x2fa90b0a7d8c81b2, 0x35c2ab766d49d262, 0xedbecdccf7990e12, 0x15e09ad4cf54f29f, },
		// Case [244]:
		{ 0xc52db74479b4b323, 0x50ec41a1ede53612, 0xbfe697270fc0f34f, 0x28f88d089f421ca2, },
		{ 0x8994d9112713b30f, 0x86974e57bb789c83, 0x9f75fa16d78cc2ef, 0x061c74a59eec620c, },
		// Case [245]:
		{ 0xdb24d1c8e6f07a9c, 0x560ef9af0fa0f948, 0x4e9fb7ff3d123fc9, 0x082e621153ee3432, },
		{ 0xb9edce86f10de25d, 0x3be85259e22c24b3, 0x117ca22062a6814f, 0x1c9a84d18fd4ec4d, },
		// Case [246]:
		{ 0x8752e12a4d5805f7, 0x9c0d7d5bcde4f19d, 0xb1d9403e9ca61ad9, 0x07f8578337523867, },
		{ 0xd366d5cb6cbc9ed8, 0x0ee938c58a16530e, 0x4cd0bc88b9b9fceb, 0x0c4ba9b8ee461541, },
		// Case [247]:
		{ 0xb5bda8e35d69819a, 0x2ba1cf2eb8d59208, 0xb7d7e85255849b06, 0x2e52f30dd05931ad, },
		{ 0x8c5010e7be16c886, 0x9feabe1d39c7796a, 0x5ffc59a4cb3d294e, 0x15ff7fbc6b9a746a, },
		// Case [248]:
		{ 0x3f83f72ef4c8f345, 0x1caf26f7c233bb18, 0x5ba04261a8b11779, 0x14cb3e56b2b8c660, },
		{ 0x0dc0f532660b8c93, 0xb93682a85e503748, 0xd1cfd507b5ba1339, 0x149d84b9eccc113e, },
		// Case [249]:
		{ 0xd36c8d325c9bd7ac, 0x45eab305be627df4, 0xda21414dd8712de8, 0x2fd6b4e6c892609f, },
		{ 0x9b31679b14501ed2, 0xff206775490911cd, 0xb3280a32135ef2aa, 0x03a04fbd45a7e948, },
		// Case [250]:
		{ 0xfd996a4a96157bf8, 0xdb0c9940a69e9191, 0x32ebd73f53df3b1a, 0x0325898c8434f7ca, },
		{ 0x571dc33d9fbd1694, 0x756e42fe2b0f72ef, 0xd155d843e7eba4c6, 0x2f5af1a8666439f9, },
		// Case [251]:
		{ 0xf99fc4644d6d5d48, 0xb8a7ec4dcf5ec066, 0xb85d6a16a0d3dff6, 0x08f50a7b584dc022, },
		{ 0x862db1f637e13272, 0x35060f42773958d4, 0xa9987c1113f54f37, 0x2ca345b85d57c3d7, },
		// Case [252]:
		{ 0xf2bbf4c9bae9e11f, 0xd9ceb8a19ff3c970, 0x85ca30a43cfd7141, 0x29c5bbb8eb214fb2, },
		{ 0x0c9f8365896210a9, 0x412c38b4b0954daf, 0x1f440968ccc51a17, 0x0ae5fcf7794be2a7, },
		// Case [253]:
		{ 0x99e1997307e7432c, 0x088f1eb7eaf59349, 0x211e2856a78901e4, 0x1264cbd9ec001175, },
		{ 0x0a2de9c5212a4a6c, 0x01b7b3ae91387557, 0xdf71b9605218ed7f, 0x12f2f7fbff494c73, },
		// Case [254]:
		{ 0x7cb97fd177688504, 0x51dc9416533ae33f, 0x9cf2bdabf64fadbd, 0x28a0e7819aa0251e, },
		{ 0x4ddad60a9d1c205c, 0x663547f6b1729546, 0xecdecf6671d17ee6, 0x0489319ce8555b67, },
		// Case [255]:
		{ 0x48f6af307ec621d6, 0x4c52fc23e51ade9c, 0xc800848477cbb67e, 0x1a9be651c412fee6, },
		{ 0x6df6c6691efed5d1, 0x9ff3c00857068aa1, 0xd00521331efd4d1a, 0x106be1d01e5349af, },
		// Case [256]:
		{ 0xc11296e5b0c75f6d, 0x03c33005cbe7f34a, 0x6fdde6f556b3ed4b, 0x1bf70a24fe7fc894, },
		{ 0x57b8f5693e469dd5, 0xc0689bf60a58200c, 0x3f5cf8e7f711a559, 0x0a5583895e9e56a6, },
		// Case [257]:
		{ 0x5c5138e0c6ac83c2, 0xcad0719e932a3619, 0xcf4921abd33b1590, 0x2f56c8c0387e5e44, },
		{ 0x6af48a74afbe591e, 0x53227c11e1670246, 0x588cdeddac3fe114, 0x0f2f82bd2f54b8fe, },
		// Case [258]:
		{ 0xe3a7c943b293fede, 0xf5f211920eb8d638, 0x27b2afeeff00608a, 0x1109db87b7684f49, },
		{ 0x9fbbcdccaacdaf42, 0xadda7d85b1d7f092, 0x8156e20743853332, 0x1b5ec084980832f7, },
		// Case [259]:
		{ 0x32ca89222bc75787, 0xa51d13032cd576d3, 0x9c69c80891035590, 0x1851c29804025b6f, },
		{ 0xddc035ee389b305e, 0xc5f61543209cd1de, 0x9d12f5d2b1c3d111, 0x256a2b2886c27c3f, },
		// Case [260]:
		{ 0x6c9f66fd5dfadfba, 0x5c7137e1d5ac9a98, 0xdf4898106b5c40f2, 0x0909e4cdc0bc47f2, },
		{ 0x8c6671c2d2dc0a77, 0xa04de4dde0614315, 0x5a51911e12c69158, 0x28011692fc341a9f, },
		// Case [261]:
		{ 0x28e16af9f010e07e, 0x233659701b319aa2, 0xd5913d4dd1e71d4f, 0x2ae3e90e2650e286, },
		{ 0x7e3d00fbb21e30b0, 0xd804776802fcc33c, 0xbbfcc7f41cd77802, 0x126c8a7c0ec2b943, },
		// Case [262]:
		{ 0xdd81ec557235d530, 0xb60fbc4dc72fdab7, 0x1f7a40d4f1bde04e, 0x06a6c015f9517344, },
		{ 0xa713e22fcb3edb48, 0x6118c0f37c251377, 0xcd4e0bc7824d5cec, 0x17d61794350473b1, },
		// Case [263]:
		{ 0x3d484c97f8d2446c, 0xff30d6c46816a3bd, 0x366da257c8596fa6, 0x2f6ab5d35ccfe9ea, },
		{ 0xd09420927affc2ab, 0x0ba00b8a299698db, 0xe1b0f7cc8d7252b9, 0x0bcc56f41a8125b1, },
		// Case [264]:
		{ 0x9bf6426f7ab57cdd, 0x8745d9c912705089, 0xd4a83f9272bc220a, 0x01f9c60308182eb6, },
		{ 0x733a66a33841d71e, 0x22252e0106978191, 0x920ab7a588dafe5e, 0x06ee73bfa4b5d517, },
		// Case [265]:
		{ 0x7ded35bc01d799d8, 0x4c4b29609d3ea561, 0xe6798e4c3cb13d5e, 0x2f514c412bfd9754, },
		{ 0x3f38a28d9d19170e, 0x1a6216c9763149be, 0xdbe0aa64cd17c6e0, 0x1a714948e2ccaa6b, },
		// Case [266]:
		{ 0x7afcb3e08abcd9cc, 0x5d28294d092cb891, 0x7941b1f133bb1822, 0x14c4162b9c9eefb9, },
		{ 0xf0e3e95b2f873c0d, 0xe46d01d4e1c6ef51, 0xeb955b8a36c0877c, 0x01e84fda0e6ce94a, },
		// Case [267]:
		{ 0x8884b00354085b32, 0x3cb650e1e72b3fc9, 0x7ecd8af3d6ff0e0a, 0x19921fd625c66ec6, },
		{ 0x98d5fdb6d8eee9db, 0xeb683fc9ccfc7897, 0x90a0e9ec3eb5e880, 0x2f53a8c0cbc3c5ff, },
		// Case [268]:
		{ 0xf93b8debf37eb6ca, 0xd21de3436c816f75, 0xe1268739ac15d2c6, 0x1c852aefc9296753, },
		{ 0xed474a1e0305d32d, 0xa10fd0d190667bc9, 0xe30cec0719a5de3b, 0x1e485c4c930ca63e, },
		// Case [269]:
		{ 0xeb88ad9d02745fb8, 0xf559e8167edddac1, 0x4afaa1dd1bf60de1, 0x04bf4a69b1aa4f30, },
		{ 0x6c71e1c14e3c2252, 0xf92111b42bcdc491, 0xadcd82bee2737296, 0x1fb33a3daa44d739, },
		// Case [270]:
		{ 0x5830165e4d123753, 0x9fe3fe72e7183d8e, 0x5d9aae80f341cb56, 0x240a791f3b8bb62d, },
		{ 0x84a979180b6e9994, 0xc5f1ee32befdc29f, 0x6a76e3b78cc56183, 0x2c8ac59351e35c42, },
		// Case [271]:
		{ 0x663ee4f28ff5e764, 0xc8551654186d62cc, 0x9fef7bc5ef40f1e3, 0x151b295b4242e0c0, },
		{ 0x10434912a6f8525d, 0xee95db44d865f9e0, 0xcafb150c48162d79, 0x0517d3a2a3c782db, },
		// Case [272]:
		{ 0xb0cbf7676165f23d, 0x497c93cf7e657954, 0x64a074a09739dc8c, 0x086eb3d30bc4d806, },
		{ 0x36951006dcbf19d0, 0xb46b4574180b15f2, 0x611705763b60233b, 0x0e60a3eebe42ad18, },
		// Case [273]:
		{ 0xebe0dd62622c21c4, 0x2a292a7121ab0ebb, 0xde7eacd95a8e8938, 0x17aa8992d7b901ea, },
		{ 0xc1e7ea26d8a9eb24, 0xb2605b3f5ae8c424, 0x31873d8c70ddce42, 0x012905620e23658f, },
		// Case [274]:
		{ 0x2008570f96eb8de8, 0x32f489b23a3c4396, 0x663657607b5c7ff8, 0x1a5b3345a4c0d875, },
		{ 0x2f7128dad1c5dfe4, 0x5cb98e370593872f, 0x1b0e3437d7ab608f, 0x19cefe6c4cac52bd, },
		// Case [275]:
		{ 0xb2a7964b01e6347c, 0xe3f31d1364f03345, 0xf8f4cf2cf710e48c, 0x2f03b46d9eeedcd7, },
		{ 0x128bffd541d1978b, 0x7ee34e36c95ea66d, 0x67b9b2a02f72ef7c, 0x2d4b5466db3ec7aa, },
		// Case [276]:
		{ 0x35259e0a40050d45, 0x70a0291723aa354a, 0xeba879f7bd602418, 0x0fef583e7e8e102f, },
		{ 0x422842c9cb2d3998, 0x4b11926af8036bb6, 0x302476f3b59e3fb4, 0x115bf8b8e58bd528, },
		// Case [277]:
		{ 0x86a36288b969fa6a, 0x0fa5e523abbd8950, 0x4d9baffacd02d7d8, 0x2e07b5d70ca583cf, },
		{ 0x7a11abb07b909f95, 0x46ca5e9599c13212, 0x58c9a514c61cc6bc, 0x25e8d6b39cb6254a, },
		// Case [278]:
		{ 0x517baedbf2f176df, 0x394b858af8e904c0, 0x14d585248cf23ca1, 0x24599dbfa1dd1f47, },
		{ 0x67018c4c116fb0ad, 0x05b55b845ad72be7, 0xd3761dd5de439a9a, 0x257419fdd5ad5c85, },
		// Case [279]:
		{ 0x07b500fb5291f8ee, 0xe61377388d8727e4, 0x5b66189e8d986777, 0x00a826afd370bcb6, },
		{ 0xe6f9c204ab43e272, 0xa4bff66502d5f7f1, 0xd9798c43476dbdcd, 0x28a7ef719675f374, },
		// Case [280]:
		{ 0xcad03de907081e3b, 0x0a2bf23e905e7d33, 0x8adbc5f4bc03415f, 0x28745950870bc184, },
		{ 0x5a1fd906342036af, 0x62e35a367b88ce01, 0xa11674154878e12d, 0x0e6a5c6391a755b5, },
		// Case [281]:
		{ 0x1be4081714cace58, 0x8b5747b46dd9914d, 0xd405673d2cb4710f, 0x219e6dcda590fc88, },
		{ 0x6a1c1aa6b7cec724, 0xf44ce6fdb14d6b04, 0x7080c82d758b3091, 0x0f9a51eeeb763f46, },
		// Case [282]:
		{ 0xf41747c6f27dbe6a, 0xd95185ff7253d9d1, 0x399f17ba71ffeded, 0x296692077b42e972, },
		{ 0x1de33580734ea642, 0xce81a0c70e09102a, 0x63a5f5b8cf6ccb34, 0x16ed37cfa5c4d882, },
		// Case [283]:
		{ 0x5078de859f9cbceb, 0x9fb5d826a6a483dd, 0x841862f32f806282, 0x2ccc5f0e2049d426, },
		{ 0x85140f2eb79a4987, 0xf9792c2af2e91796, 0x16073ad970681d96, 0x0a3a0f17bc78c6c1, },
		// Case [284]:
		{ 0x07fa90a70feffda2, 0x367700bbb9bc061d, 0x08a615dd89fa207d, 0x04f915a4fabc8ab2, },
		{ 0xfd29ca4cce498904, 0x4abc8415b8fb211d, 0xae1f6f7094285d52, 0x0f4b56171ef536ae, },
		// Case [285]:
		{ 0xe59ea9eba8794708, 0xccea4ed5928a34f4, 0xe5e4fbb5cd7b6e60, 0x2e04b7c1aa853f9e, },
		{ 0xb4424e5db51f7d9b, 0xaf65b3ed9b0dda1a, 0x147516fb2d2ff17b, 0x14f129e1bf6b013f, },
		// Case [286]:
		{ 0x08036391b4b6db3a, 0xec69b04a2e1b8651, 0x0ef2bed12bd78340, 0x08700df51138b36c, },
		{ 0x2ad9ca067d72ea5e, 0x965a7bd378f003a3, 0xc8cf934d6077da07, 0x0e2ef385ff98e4e6, },
		// Case [287]:
		{ 0xec41bb7062c24782, 0x710416fd63d7aadc, 0xea8d4929db1dd0b3, 0x2503336398f165bd, },
		{ 0xd41450cea302d531, 0x3f536b513fd7e915, 0xf3616101d223aaa4, 0x0bfd6ab967e74982, },
		// Case [288]:
		{ 0x2996a47a527bdaed, 0xcc2df072ed8eab9a, 0x573ab10d893341a0, 0x05633785a50a9c77, },
		{ 0xac9849f4b4a17148, 0x0d792f026c48a671, 0x88510a07c172ce0e, 0x14dbea87af71b761, },
		// Case [289]:
		{ 0xcb2c3be2d3901e1c, 0x4622513b7c96e9fc, 0x12a4c982dc0d8a0d, 0x0ba4084e44c50e14, },
		{ 0x1f925a10422b429f, 0x9a497e20c50feeaa, 0x4773048cc1ec1f63, 0x05944f63ddc368c6, },
		// Case [290]:
		{ 0x6cc9cccd8f307c86, 0x106dc4519c61c399, 0xa9e03d7ff8a43bae, 0x2d6f32cb761406df, },
		{ 0x11f00e237fe71d1d, 0x606f3565baef32e7, 0x6f36e5adf1fc1dd5, 0x0770be7b6cd5fb74, },
		// Case [291]:
		{ 0x73491244f8373687, 0x3c8e6bae3aea2edb, 0x395846373b1f7d00, 0x2f959c830737e631, },
		{ 0x79a60a5433d23365, 0xb86331e1448543ad, 0x78203ad1339c1ce1, 0x055c6241a16bcb47, },
		// Case [292]:
		{ 0x8db27aed54fbaa38, 0x498d999250cc0a85, 0xbb40901664349217, 0x14863af59792adb1, },
		{ 0xad45fa6c96141eb3, 0x92e27e2de1ec4c0f, 0xeb8f8464fc00985f, 0x23ade6ba20178c8f, },
		// Case [293]:
		{ 0x6df8d986937cdc82, 0xe7552826e4d6b58d, 0x99f9c5783e1fdbb1, 0x27623d101b1f9228, },
		{ 0x002035c9e93b5f81, 0xe02552096fbee96f, 0xa1159651c2f6e0cd, 0x0f1f1f9bb02bc316, },
		// Case [294]:
		{ 0x411c0798602a6268, 0x5c21f09305301bf1, 0x3e37ea72cc5d1c89, 0x247328a4d9ce8160, },
		{ 0x1f56dce9bf37a83b, 0x75f96e7cedb53b37, 0xb6119d252161a8d3, 0x0990b4f157cb613c, },
		// Case [295]:
		{ 0xa12af4ce324c6081, 0xd93a25a5496cafac, 0x8a6cfbed6c1056e3, 0x1921909aaad03cc7, },
		{ 0xd9077c99ff0fce3b, 0x38c8dfc9f91bb205, 0xf8929320aeffff4f, 0x16ab5f63e4933e71, },
		// Case [296]:
		{ 0xe29cf101aed00d80, 0x92df154f649b7213, 0x7d14d42feafbdd43, 0x0a85c0358cf388b4, },
		{ 0x7fd52f437875e15c, 0x959e356b93c579fb, 0x9287f8a09faa60cb, 0x2b8665fe588739a2, },
		// Case [297]:
		{ 0x3860f7077537512e, 0x621beb56f902ca48, 0x65d67aaee04165de, 0x01bac04734a5920d, },
		{ 0xdd1c516da843fc2f, 0x2df3f22778bfe81a, 0x7b9ed7c6fd80a1e6, 0x079da43709069ac4, },
		// Case [298]:
		{ 0x93d8c70ab3eed999, 0x6dee5454f784134b, 0xb00b08d6b8bac6c7, 0x1dd1720966b3231b, },
		{ 0x8533d18d9dc3d407, 0x1da544baafe0f99f, 0x869241344621de20, 0x24f4c6224e45bae8, },
		// Case [299]:
		{ 0x9ccfbbe92e86c08e, 0xd37ad696535d82d3, 0x36bee1e7f42ed4b0, 0x22897debc6eb2a7f, },
		{ 0x2bd84259c5d1c82a, 0x4b2ce5d93bb0f341, 0xf0febe2264a21816, 0x278baba2bc58fcc4, },
		// Case [300]:
		{ 0x8ee73065b387e175, 0x1e94dc85512bc516, 0xb3b91ad88c69a33c, 0x2ad01bb42b95d113, },
		{ 0xec6580a12553ba05, 0xd4e1a4a2ef08595d, 0xa7fdee771be86f08, 0x213a0835d938d42d, },
		// Case [301]:
		{ 0x697eaa177c6000b0, 0x1529a57f8360a2cd, 0xf9aa947df5f13179, 0x2e82bd0a053ce03a, },
		{ 0xd2043fc6b8afa124, 0x41523377714191e2, 0x338f6fb7609b1c1b, 0x034b60f92c7c444c, },
		// Case [302]:
		{ 0x2f08ae3e44e1f4bb, 0x91c3bc4efbfc8e7c, 0xd8b6529f00c4c6d6, 0x2d2daeaeaa93a5f9, },
		{ 0x34de98de56b8dcfd, 0xcf8ec71a1736aa1a, 0xd3180be5f23b0f78, 0x24ef859b81e96b63, },
		// Case [303]:
		{ 0x716cc305727a0f72, 0xc1a9c1e58c76ef2e, 0x7983bace0b327f98, 0x0ab08914b2de5739, },
		{ 0x6ce89ef3a2db1862, 0x4bda20cf42c793ab, 0x327b718066bd624f, 0x2c4e9e045dcf8375, },
		// Case [304]:
		{ 0xcca107cb2bc91998, 0x2ffa1bc884c3cd1c, 0x0c433c4f1b6b19d4, 0x2758796cd1c178ed, },
		{ 0x7b521cf19bbf6b71, 0x0eb6f0b1c29ad681, 0x111855d8c0b327bb, 0x0a441e868ded67c7, },
		// Case [305]:
		{ 0x3a824992311e30f4, 0x4a30fc4f1b59fb71, 0xbda4741ec898c74e, 0x063df5b0349016e7, },
		{ 0x16a6826fdce1a8f6, 0xe8470823d5f03892, 0x22eb5bdbfe66945d, 0x051d75b2786e1aeb, },
		// Case [306]:
		{ 0xd0641cedc5fc6728, 0x4344b7c05838048e, 0x3d41abd69e6fb91e, 0x2371301655554675, },
		{ 0x5aa9b7069f097332, 0x0f2af9898913e82e, 0xac968fa0d746259e, 0x19d478112d84e342, },
		// Case [307]:
		{ 0x53fe8b5adb74c075, 0xa86ab57eb031b96b, 0x93b7e2059d6a528a, 0x26bdfc0a894998e6, },
		{ 0x8bedcfe021a273f3, 0x57488ffbd01469b8, 0xaf859b09b5c09995, 0x16ba8a397dd1b4fb, },
		// Case [308]:
		{ 0x1bb734f53985286a, 0x407a1de135b63254, 0x115dac581b9553cb, 0x08897118f75cc8e9, },
		{ 0x183c4bca4563ab72, 0x8fb5348f7fbbbac3, 0x6da29e1b09bdf2d5, 0x15a6e5e2e80aa868, },
		// Case [309]:
		{ 0x46ea6f6d4960c346, 0xfa9b3a5557abe811, 0x57691ecb1e15a40a, 0x02ef8eb2c7b26f7a, },
		{ 0xf5d7f4aee7178746, 0x359dca6a5bc5a1f8, 0x3766f219f8f2a2b7, 0x3058b0999d594ff4, },
		// Case [310]:
		{ 0xb25910f63cf08b01, 0x586bcaaf12603658, 0x48fd7a2c9f4a5a0b, 0x254e8e5fc11b9923, },
		{ 0x1edf0a51f90bda2f, 0x078e34164f8f3596, 0xc140898cd2f5f434, 0x1b9077a53a3b2e5e, },
		// Case [311]:
		{ 0x03d3a32b89c57b7c, 0x77301da5fbbd59db, 0xb510dca16e7b4b42, 0x02f41c21b73dd4e7, },
		{ 0x84823b796d57f89c, 0x21d4ad568a1b7a9e, 0x7adfd4313fd8fe93, 0x02bd85ca5eb3d751, },
		// Case [312]:
		{ 0x303db99618e1d0a0, 0x2871e5fc67bff13e, 0xeae98ba1b29806bc, 0x253f09ce9ecfd2ae, },
		{ 0x24f7d10905af47b4, 0xd396b828d8889f3d, 0xe43ca2b0248700ec, 0x2bdaeba93ec64a59, },
		// Case [313]:
		{ 0x226b04b0e795bfc9, 0xaaf7c63ceffbbea9, 0xf25775e66ae67be0, 0x04395eb655582d03, },
		{ 0x5d9e5e57036daf0f, 0x1e92784d23079308, 0x0b43c496550772f1, 0x159af2a68d27c9a9, },
		// Case [314]:
		{ 0xc999e6e6126e402c, 0xfa2e796e26b72e05, 0x49e3e41bd048a32b, 0x13711235c3d21dd7, },
		{ 0x66829e704f343082, 0xdc7dd7eb04159790, 0x4e8723a94941a583, 0x212f4cb264375b5f, },
		// Case [315]:
		{ 0xdd9ea42add7a175b, 0xf33590ddcc297e3c, 0x43b5513963fbd0f9, 0x083c75117510a37d, },
		{ 0xca2936510fd00ed9, 0x7f61dd872041344f, 0x9a39ad6bbcd1c9c0, 0x1d096c5f1333675f, },
		// Case [316]:
		{ 0xf21d4d0d823dcea9, 0x4c6525ddcd7488cf, 0x6582d35d8fdbda94, 0x26cc9b5718d84e60, },
		{ 0xcea93de63fa72133, 0x178d6f892d933939, 0x9e7426467ccbcd2c, 0x19514ef63298f51e, },
		// Case [317]:
		{ 0x4504ed8a344d56e4, 0x20b9a46d0b1187d5, 0x94601499634a8da0, 0x0e8978f047929b1a, },
		{ 0x984a55d47363d2a5, 0x16b52817e7e80ef0, 0xd76188a8289881e0, 0x0f4c82f676787adc, },
		// Case [318]:
		{ 0x006247688f6fa805, 0x9a6d41234acabed2, 0xbe397439b5ca50aa, 0x2b11423af39a5d15, },
		{ 0x01b26aeafb7220c2, 0x56f0243e655af7b2, 0x92a68808bfde8ae1, 0x1a81336339893804, },
		// Case [319]:
		{ 0xc430382573b402b6, 0x92685625e5aa77bb, 0xda5a31a5aa275ce6, 0x21a56381040c702d, },
		{ 0xd8b88516a8cad022, 0xb820e386bd3405bc, 0xb99efe92a371e979, 0x01c28ad27f35d614, },
		// Case [320]:
		{ 0x4aad8e9346af07f6, 0x14c800945ba49db7, 0x5016feca2cb82a2f, 0x19a869e15b3f9b96, },
		{ 0xd751f476262cece4, 0xa07b5e22a525d4f9, 0x9276be4e34ce91d0, 0x1faf1592371815d6, },
		// Case [321]:
		{ 0xb76f24afa6be50d5, 0xbf3ae097aa930771, 0x69d4670098466f05, 0x2b01c5a2baa16f95, },
		{ 0xbccefefe8f7b240f, 0xdeb44aa83c4ed836, 0xaf5b77c44a41b285, 0x2e132af0a2576319, },
		// Case [322]:
		{ 0xd64eaea532582124, 0x4a71b3fc67a35448, 0x17f94602fd6c86ad, 0x0586148573b6b566, },
		{ 0xeaa2818114a47dad, 0x2829a8fde6307a85, 0x6d7355cfab413237, 0x15e61759fa0c7b6e, },
		// Case [323]:
		{ 0x3e7704411894f98a, 0x07872e0599a3127a, 0xbc7a2c549bc19cb0, 0x040352e19809dd93, },
		{ 0xaa1e9f57b72da630, 0x96433107fd56c645, 0x164bd552aba45566, 0x29370bc012bb22c1, },
		// Case [324]:
		{ 0x6561e1346c5a893a, 0x36974e842e1fef87, 0xa86cf044e8950ffa, 0x2d6486b8e7b9549e, },
		{ 0x75cd8070f648427d, 0x3e834bda80013a8a, 0xf5b8458f1343137b, 0x0b43a996c77cbd45, },
		// Case [325]:
		{ 0xc1b5872c74e5a49f, 0xc9debe589044f305, 0x3895565840e25843, 0x2ea9d2e1b7d07c9a, },
		{ 0x3cc851344959d641, 0x576470da74143dad, 0xeb11a64b1bb92e9b, 0x1a4cead59fd2e6cc, },
		// Case [326]:
		{ 0xf062270413a8087a, 0xaeb8f6d00ecf84b4, 0x2b7cea0bd76da34a, 0x12e0dc4105acd869, },
		{ 0xab16da66bf339bd3, 0xf378ca034df33b5a, 0x327260974af2f624, 0x1631aea480c80759, },
		// Case [327]:
		{ 0xa491f24b6368290f, 0x3db4df8307599a33, 0x3ce7c980a70c9d79, 0x0da9c10656e6f42c, },
		{ 0x72a7464f76e79fec, 0xc3d4edf1da065a85, 0x95711df9f4fe9dc3, 0x1622e2cfd2f864d2, },
		// Case [328]:
		{ 0x8ac76af21b11a850, 0x9360d9b89aec23c1, 0xda629c96633d5cc9, 0x02f3551c6a648387, },
		{ 0xc0d7038c16b35b41, 0x331c67cdeee6643b, 0x4c03dd683050d5f1, 0x242d18fae258c3cf, },
		// Case [329]:
		{ 0xda46e134731dde14, 0x093386c8a553d3a3, 0x8aeea34af1ed5c74, 0x202de33a6fce9dfe, },
		{ 0xacba45db6407e994, 0xc5dda1d9060ae8ad, 0xa8fd2128bb2d5a1c, 0x0ca5953c785c9b0b, },
		// Case [330]:
		{ 0x768a5a52482b1b7c, 0x3f043575f3427e35, 0x9e3e91f902d57a21, 0x07372d41054dbc00, },
		{ 0xb1ce4ba8afc1ca1b, 0xcc025c3d526b6583, 0xd9200e7f81da2463, 0x009524948839fae6, },
		// Case [331]:
		{ 0xa9edbc716e2454fa, 0xe8e938cd999cd911, 0x949a819262943c97, 0x02f7e35a4bbe9699, },
		{ 0x274040c394c201dc, 0x6297e4d43030b833, 0x3cd0d8fd83a41f25, 0x20c06e8234f6fcda, },
		// Case [332]:
		{ 0x24b6123036d73ff1, 0x11606c819b4baa68, 0x8cc73bf54bf535b0, 0x2a27b84a7422e29b, },
		{ 0xab0381f22a5782cf, 0x0e1d3c43913209e8, 0xcb2219ee0123c3d1, 0x21bf822b434929b4, },
		// Case [333]:
		{ 0xfa0c63aff7161a3e, 0xf5d8e5f98e74b312, 0xd2638c863499839f, 0x19527e9093b313d5, },
		{ 0x80af634899f8d154, 0xb3f4b66624c12990, 0x48f79a6b08608d85, 0x015980f9727b6282, },
		// Case [334]:
		{ 0x8562ba033147f025, 0x231d1e355d93894c, 0x299666231e3c49ed, 0x08571a6b8b730363, },
		{ 0xa3118eb9351bac1c, 0xa5437bd0a208a867, 0x360947b678e27a7d, 0x1589d9cd406e9ac6, },
		// Case [335]:
		{ 0xe3f213a5d2a1b9ed, 0xd4fb64caea2cc2d4, 0xd912961c81d88e98, 0x2c0f32778edfe932, },
		{ 0x6c89e3bb7a1b7e1c, 0xd5e51b91b9a1cdb4, 0xf2cda3cbe129926e, 0x2d15e1b14807febc, },
		// Case [336]:
		{ 0xc58191b2b1453ea0, 0x7f84a4577610b19c, 0x15da09e69bc24c56, 0x2710a63e84f8bf3b, },
		{ 0x5f060356f64455f0, 0x8928d8372c65582b, 0xacb65a1128d03c70, 0x26e8b9c148f45262, },
		// Case [337]:
		{ 0x525ebc258a953dd7, 0xb0fb3f148e4ee77b, 0xd84c3e393f75bdc0, 0x2d4b8440f168745e, },
		{ 0xe9024c740e3c9d0d, 0xe92e59d70dbddde1, 0x48ba835b62be357d, 0x2e2c467a0d264b20, },
		// Case [338]:
		{ 0xb6b796895917684f, 0x9aea7c808ca9ee79, 0x4f629bf6e96eaf37, 0x234901ff3ec65e0a, },
		{ 0x39053860de6b1f0c, 0xa3ce636911ac07ad, 0xac77d9055c46d29e, 0x120dc52e094008b6, },
		// Case [339]:
		{ 0x7865c36be526e5e6, 0x7720b450975339e8, 0xba1bb3372072518c, 0x28a529a627cfc689, },
		{ 0x14ceddbbcdbf9569, 0xce06972a8ed58694, 0x82725d19374ed980, 0x09be919ac5f34a00, },
		// Case [340]:
		{ 0xd554af11c6cef5eb, 0xc6e83d73b5c5c0fe, 0x9a6a466ddc1855fd, 0x1a1af260473d8348, },
		{ 0xcaecd871eb290dd2, 0x5926e863f95c9d59, 0xb666cb315196678a, 0x1251243de7acf1dd, },
		// Case [341]:
		{ 0x8f02ab7270952924, 0x088264cc16a8119e, 0x0123f3af16c9289d, 0x2fd594dc14997e8e, },
		{ 0xd550a633caf6d651, 0xe3ff755bf31a0be8, 0xfa7b6b64ed779d2d, 0x17c6d04672f3c068, },
		// Case [342]:
		{ 0x7fa3a5dc23eec833, 0x9658234bc4db5914, 0x02d8f8278b0d2f81, 0x0d3564e44716de8c, },
		{ 0xc64cb5a5a91fce7c, 0x2ebca44b3b48b33a, 0x6cb84745c7499853, 0x177d2beece0170a9, },
		// Case [343]:
		{ 0x38266aada3cfaa0d, 0x5e886e0f8e43f01b, 0x377dd8b02d5ae569, 0x293e9ac448bada42, },
		{ 0x759fdfc8dc462286, 0x5faab0baa76a1e22, 0x72f7d5aa72044eaa, 0x17052efce342dc5c, },
		// Case [344]:
		{ 0x0b2381296daecdb8, 0xcfb1ee1288aefb7e, 0xd7b667d35e95f354, 0x2186e961df0728bc, },
		{ 0xc9c6469856a0b77c, 0x47d5d0d5d7e16e1f, 0x329cb3a622748a5f, 0x2f21a959b732fa91, },
		// Case [345]:
		{ 0xe1e3b8c8a7f49e74, 0xdce44bf8368a0c43, 0x27219cdeab7acdb5, 0x1b4972ee03b2787a, },
		{ 0xff1444d5586b6549, 0x08888a2daad74500, 0xa6b295062498c317, 0x0f0276d985c923bd, },
		// Case [346]:
		{ 0xa905ce1c3279522a, 0x0f05738fce996b2f, 0x52e817c32d86a3b1, 0x01105ad26651d5ac, },
		{ 0x26a3986ae0c1a5a0, 0xab30894c3cec1166, 0xf1ab01e3630ec5c8, 0x28da5f5a814d192c, },
		// Case [347]:
		{ 0x72e45358569ef30c, 0x5cf521ba7c91478d, 0xac30d03f5d247759, 0x072b770a70dab242, },
		{ 0x3dc0119da89a0553, 0xf9b79a53f019508e, 0xf511c78efe6526b8, 0x0925fab3883be189, },
		// Case [348]:
		{ 0x7f5a93021b70d275, 0x837195bb93620699, 0x079e9d61ec97ff8c, 0x1e399a42196a8061, },
		{ 0xb7c663d4276121a1, 0xd868ce2d2918ef53, 0x183d6cbb5d1e2702, 0x13d835b1b6c4291b, },
		// Case [349]:
		{ 0xfadb6218aefb7d6a, 0xa3c59735dd3303bc, 0x2cba453ec40a8796, 0x24f50ccc3a68ab3e, },
		{ 0xf5ddcb3e2ea4a676, 0xde6b9fa70ac4615d, 0x40d8868107744281, 0x2b8e90e502b6c068, },
		// Case [350]:
		{ 0x118f75616714bd3c, 0xbc119f01dfe708b9, 0xf23f8a5a0a7a2f50, 0x14fe92dc9227b42d, },
		{ 0xb370603c85784b6a, 0x4dcc548aa33aeec6, 0x5f3032b9af19fb26, 0x2f147a67c5645ea3, },
		// Case [351]:
		{ 0x6b12696a7065916f, 0x82271958c98fd42d, 0x7b66941c007d1702, 0x24713d85951736c7, },
		{ 0x673de437da52d0d3, 0xe33cdbd449cd4c00, 0x82d22a4df1e2477b, 0x0dc32b04f9ecca75, },
		// Case [352]:
		{ 0xa97b263cce815ceb, 0xd1b698dede7feea9, 0x238f63258c8dfce0, 0x05cf2ad05c75de38, },
		{ 0xd96d43989e3a0b3a, 0x78f648a952389f6f, 0x088db090fb00b273, 0x0a09339d38f49b2a, },
		// Case [353]:
		{ 0xe1580dc48218aa26, 0xffaaea6e6bfce85a, 0x0c874b40395a695f, 0x2d62695c7008a11d, },
		{ 0x386e34dd2cdee423, 0xf7f63c4903199d48, 0x8e187417d890351f, 0x02286a62b70c1bd0, },
		// Case [354]:
		{ 0xd0830b3ef5d775a0, 0xea6f348565c3aada, 0x126770fa5ba61405, 0x19e47227e74d5563, },
		{ 0x0fa8cd610079987d, 0x296797a0d4a708ab, 0x9bbafd1451a73b87, 0x1f260a6f3ab29bcf, },
		// Case [355]:
		{ 0x5ed8c15e5ca1084a, 0x594537f98565f2d6, 0xe2074a6b2fd50c74, 0x20e43ff580378baf, },
		{ 0x84be9e17941db786, 0x723aa6c66869d9ca, 0x950a89dd2bd02992, 0x0bbc49710ae83ff7, },
		// Case [356]:
		{ 0x91bf1c1bf5c1273e, 0x37406d50d2849c70, 0xe92ddd9cb4d973e2, 0x264e4841309ac1aa, },
		{ 0xea7a52d7b6aaa6e9, 0x073567031be9248b, 0xd9e96578c2e12622, 0x1986e72487112ba0, },
		// Case [357]:
		{ 0xe1b4c0b2f710e604, 0xf4289680658fb26a, 0x35b578af1c30c077, 0x1238beacedd4f53b, },
		{ 0xe7e8098f7dd4c799, 0xa5cae25ff8931804, 0xfc67efb9b6c97409, 0x288b107a518e26a3, },
		// Case [358]:
		{ 0xfc7c137cce05fe35, 0xade903de9bc02fa5, 0x13f37459d4f2055d, 0x0d90474c262aac19, },
		{ 0x4b8781d92c15770c, 0xc5a687df1375c919, 0x0d5446227d18844c, 0x1604e39573453f07, },
		// Case [359]:
		{ 0x3b95cae4f653ad82, 0xebf3388383e69257, 0x00235ebd1cd1b9f6, 0x0f5aaf4827d5f40e, },
		{ 0x0b7365cc45b3f3a2, 0xafc9c82e5311000d, 0x10bd24cd92decc14, 0x1b8a44ff553c7f61, },
		// Case [360]:
		{ 0x4d0cee4008834893, 0x967c28d62d0c45c3, 0x73cd823df37097ee, 0x2cdda4350f353347, },
		{ 0xcc348b5731a43bd7, 0x1ec4bf90e3b6c6e7, 0x39f04e4063a138ee, 0x24b3f7601e225555, },
		// Case [361]:
		{ 0x6a2d5d0911b7d768, 0x5bc2c78832a618bb, 0x4dc46755a7e07279, 0x1c0c8c2ebb6860e6, },
		{ 0x9064b19c52901ac2, 0xc06792c88db26319, 0x60451fe54516dae5, 0x02d01719f235d5e7, },
		// Case [362]:
		{ 0x8d7240b8e8c03276, 0xb85642d4f243d5e6, 0xcb705bc3584c0150, 0x269fa26069db1cf0, },
		{ 0xd0d0cb2e84fbeb1c, 0x56113f679c846bf9, 0xe9d5398dcd775762, 0x2f038e7c60cc66ef, },
		// Case [363]:
		{ 0x258881d994fa91c8, 0xc7b6226341ac8389, 0xb9a6d3f003609fa7, 0x09b443b0a7676575, },
		{ 0xd2808c31bfa19c4f, 0x5fc8f59addb413ea, 0xb237732754d4dd07, 0x0349e3328ccfa015, },
		// Case [364]:
		{ 0x86f22bd33e7bddbc, 0x3fb6998e9131e99a, 0x80f81b25743fe13f, 0x191b4697a8e295ab, },
		{ 0x30f74525b69216f2, 0x3f3a767a759a57d6, 0x1a729990cad22e6d, 0x257e2d174be7ba54, },
		// Case [365]:
		{ 0x4bb9d91775645730, 0x8577e8f906a971ad, 0xc324f04288ad865c, 0x0b488b6a875f238b, },
		{ 0xe32aa80f5403d21f, 0x9dc947e4b1ce136d, 0xe0dc311e120b97d2, 0x1f1744ac54301881, },
		// Case [366]:
		{ 0xde1db83287f5f5e6, 0xbb0cd31c36cd172b, 0x95c01b18a5d30081, 0x275928b25e503c9c, },
		{ 0xe4a6fb5e18b6c212, 0xeb190cfdc84afb37, 0xd79527896ec2fde8, 0x047aa7c112138680, },
		// Case [367]:
		{ 0xe65d70f65c3b026f, 0x9f60e4afc39cfdcd, 0xe14f0f2e7b7461b4, 0x1fde053dd87291d7, },
		{ 0xaf60f15e4d4f02d1, 0xe333b4455c329125, 0xf2ae2cd0ff96f60f, 0x187af890debbc046, },
		// Case [368]:
		{ 0x58dc231aa1dd3e0b, 0xff88ac29199a1813, 0x76100e8fb9543329, 0x29b2c386816e9d3f, },
		{ 0x84f5c04f3b10b4e4, 0x746b3d2acda3c002, 0xa4c35e6d7e17682b, 0x0449f4f2bb4e4c68, },
		// Case [369]:
		{ 0xa26f425cd19767c5, 0xfe1ce9c2aa7d7c54, 0xec3c10421005e133, 0x04987de3e3121811, },
		{ 0x8e1595fd9ced57c8, 0x539b81510ef267cb, 0xc014515af12232cf, 0x0a080cd031ff8cf4, },
		// Case [370]:
		{ 0x32d409942fb6e16b, 0x0628665eb496ed87, 0x1b757e35aa355905, 0x19a23ba97426bfa8, },
		{ 0x1e7b02612eae8777, 0x017101048dc70eff, 0x0372ce23192c60bc, 0x082897fbcf6b385f, },
		// Case [371]:
		{ 0x861fdc26c1b7f767, 0x04d001d2b393791a, 0x0b5e2f9d96561b2c, 0x12333e97d1f0e328, },
		{ 0x0cf616117a71c323, 0x797084a0bc714517, 0x513d73d4a0f62ddc, 0x29152aae8e23580d, },
		// Case [372]:
		{ 0x4917ca03baff3227, 0xd25c95a7672f3a1f, 0x95d06928a181d75a, 0x23e48a5b646d3538, },
		{ 0x454af7b884cd7761, 0xad14914ca47ae7e2, 0x10949d1822440787, 0x031de94c7f868453, },
		// Case [373]:
		{ 0xedcd94587d596382, 0x93b8f2bb0a52245c, 0x721965972823ca2e, 0x1b6bff423317d2c2, },
		{ 0x88fe1f39a497196a, 0xebb80e12e05ce5a1, 0xe2af7b0559941c07, 0x165d125fdeb6a8b0, },
		// Case [374]:
		{ 0xa4f7c4df4b088b07, 0xf378b3524680aafd, 0x0ba6d176df30701f, 0x16af0f387b9ba94c, },
		{ 0x18ae42ceef5949de, 0x0bb16021500edff4, 0x3ffaf457b2f81e2d, 0x2a50b3c6ecc8bba8, },
		// Case [375]:
		{ 0x2cb75b92797a2103, 0xe908c098b28bbe71, 0x97c51ac7dc2d80f2, 0x1bfad9c1a92234ed, },
		{ 0x4f78887d6b0e8b2c, 0xb9aaf9abede66e3f, 0xf0d83d07b7471e21, 0x1103f2668d111fa3, },
		// Case [376]:
		{ 0x88442ca4d95e6256, 0x07d90ea8962530f3, 0xaec7bfd94d48fe22, 0x29bb5064073e9a6a, },
		{ 0x2f8c31030cdec551, 0x3b471d5fd6c3b5e2, 0x5c9e8cd2defa0165, 0x07c0fe8c3161d156, },
		// Case [377]:
		{ 0x489264f5e34033e5, 0x647edc3e765f4de7, 0x9e10fea36509acc3, 0x1cbe456ec3f8d884, },
		{ 0xbfb2eb91c121bc03, 0xe64800b677972a6b, 0x0dcc6f7d36614e1e, 0x21ffea84cb459880, },
		// Case [378]:
		{ 0x81495a62aae42424, 0x12749781f03b39b1, 0x636f76cef6fab3b4, 0x0087a35062dbd735, },
		{ 0x2c6e4d9b9fe54971, 0x12de7edc4dcba7ff, 0x68fca032051487af, 0x0423d57d8657a806, },
		// Case [379]:
		{ 0xf9495174d228bcc3, 0x7f9a6a5f3dea9a9b, 0xd9645e347879a734, 0x1f1219145ff0bf15, },
		{ 0x33f8c17f4eef9464, 0x191152ee587255b7, 0xdce50f12423b6ebc, 0x2ca77c543ce2adcf, },
		// Case [380]:
		{ 0xafa13d76ce02f88c, 0x7cef14ad2b907702, 0xe1b42b92d527b2ce, 0x07f93fb41605d3ca, },
		{ 0xa72c68679f522b8d, 0xf64677acc715e29a, 0xd65ce36f5cf1ed87, 0x15f588fe85ddc7b8, },
		// Case [381]:
		{ 0x5ebd26c1c7d34299, 0xbf32115679d2629a, 0xb62767e92f3c19ef, 0x0ae3de8a6edd589a, },
		{ 0x60d07f3b7560de1a, 0x2cfa23c0532d58b9, 0x6240bb118f9d37a9, 0x13b02d8e161be389, },
		// Case [382]:
		{ 0xebcc188c23888dcb, 0x5eb8844423c71a98, 0x1ce08fb17695347b, 0x15b6688e877724b4, },
		{ 0x2d5ae2df29ece7af, 0xf71cbe0f15aa19cd, 0x12a2d48281e0180c, 0x10621a9644f657cb, },
		// Case [383]:
		{ 0x76d6f9f6ad26bb13, 0xec8b176c1ca5584d, 0x8cd6cb1b15344b6f, 0x131cdc252f00cfe4, },
		{ 0xa14723c2a12bda83, 0xa2bd37ee099eafb3, 0x7c634a3e5f3068fb, 0x264dafa44cdd8fc6, },
		// Case [384]:
		{ 0x09ec789ff11e8eed, 0xd898444d0e70d649, 0x616ca32bf55e0b3f, 0x1bd570cf878b3dc1, },
		{ 0x077dec141ce25f6f, 0xe624cc1d4196b668, 0x78f69721835d42c6, 0x15578fee506d63d8, },
		// Case [385]:
		{ 0xb8e508d1e11f03cb, 0x2c3b43d1d6960094, 0xbf717c01dd99b726, 0x1e5a54e71ef7b9ea, },
		{ 0xd7dd8c023600510a, 0xe367c8808b2ee5eb, 0xb011d1737a8f8690, 0x23a6bd6e8d186cd6, },
		// Case [386]:
		{ 0x1e9f0f35c9e7fccd, 0x94856233dfbccbdd, 0xfb641014feceacee, 0x21c88de360b36a24, },
		{ 0x3847fab784662c23, 0xbd3a3593c3f02855, 0x61b3621798e903fd, 0x205b78abdebb8aec, },
		// Case [387]:
		{ 0x45ecb3ae21e23ac3, 0xe1f91820b61ab86f, 0x898b8afc9aa54a3b, 0x2ef387dc1012ae94, },
		{ 0xbd2d9b552d16c7f4, 0x7cb42335075a3ce4, 0xa42c90456ff3d1ae, 0x0cc0a4ce0533ce45, },
		// Case [388]:
		{ 0xbfc1c0c55cc6d5f4, 0xc2873fc3c1543afd, 0x9936af1157c536d9, 0x283914da97f03634, },
		{ 0x05b45ce42edde65d, 0x98f058349c661c0d, 0x8f9f10a320783a42, 0x271156654a943b4c, },
		// Case [389]:
		{ 0x79f1189066dd42c0, 0x5a14246a6e7d76ea, 0x4db2292c7ff704d1, 0x276ad4f7ba33971e, },
		{ 0x2105a5e695b734bb, 0x33d0786ee90c6af5, 0x88f151110ea017e0, 0x295bb7b5090288b7, },
		// Case [390]:
		{ 0x1cd4f63e9e2c63d8, 0x64f5e6892d48e4a7, 0x21a624bf07950e8f, 0x24ca7fd6a2014d98, },
		{ 0x571797d3b9bc326c, 0xcc3ab7f7cab67fed, 0xa106b0f8535aef3b, 0x17b1e6cffa017899, },
		// Case [391]:
		{ 0xe22dc2276364afd5, 0xf666673ecae78bd7, 0x4dec0fae5919d8f4, 0x0fe8f370d24968de, },
		{ 0xa23cca3db8dad5d6, 0xc7b6043929d27d38, 0x843de3b6ce108940, 0x1bbdc088a0a400a0, },
		// Case [392]:
		{ 0xdcc1223aafbf2586, 0x78775ace589d4657, 0x2df348122df4b917, 0x2f0bbec7f6a25551, },
		{ 0xa28ef25ae7c37c8a, 0x4e306300e496e64d, 0x15229469c8111c59, 0x292105c2f2e19a78, },
		// Case [393]:
		{ 0xa72d5955678703d1, 0x80013cc671d68c69, 0x4866158f54f4d8b9, 0x180732ee6d3ae2aa, },
		{ 0xe3617cbcbda54901, 0x498f8cc04218874b, 0x80d0d7bd99b145d4, 0x18be61c5fad3da7b, },
		// Case [394]:
		{ 0x07bec6b153590703, 0x974a7033a69be304, 0x1dbe2c92f9121284, 0x05a0b0ba16b7b063, },
		{ 0xb10880e1679a1597, 0x5eb16dc1b43f061b, 0xb29395d805429c8b, 0x12c1b72a2eb22123, },
		// Case [395]:
		{ 0x1a57ac77290193db, 0x4b664edaeba4106e, 0x4f6565e561bbfe9a, 0x2908a5a3204a9a14, },
		{ 0xa3d108de3b31d2d1, 0x863c6ca934d1617a, 0x0f6c789443047710, 0x15680019d8e7b2ee, },
		// Case [396]:
		{ 0x8cd7f2d8a7029c0f, 0xc66cb5979908a8ca, 0x944a1075e804c32e, 0x18c860a5d2537a84, },
		{ 0x0213b05b0ed4bd16, 0x8d1538dc3e5e8641, 0x92b10364c48eb1f3, 0x242b4de2c46c1c21, },
		// Case [397]:
		{ 0xddb9ab292afc0e91, 0x90c364e37f7a1f07, 0xde5361dc2fb16cfb, 0x1ef80617b025bd54, },
		{ 0x1008732c70e6139c, 0xd987f9290e4fd5d0, 0x73b65fccc9345e65, 0x29a8df0ebea96a9d, },
		// Case [398]:
		{ 0xeae561be3d62c2c5, 0x429464e7788a229f, 0x98510f6d5dbfdac1, 0x2ab495215ccdfda4, },
		{ 0xefa3d6a230d874ee, 0x4d3afc48ad0cbdd7, 0xb5c36eceb42e6108, 0x10215a7dbc2be13a, },
		// Case [399]:
		{ 0x80aea6c19952a7ec, 0xcb2c38e67d64eac6, 0x06bea25560e1be3c, 0x251dc073bf23010a, },
		{ 0x62fbd3dff1b40c5f, 0xcddc382662a6f0bc, 0x0eaeedfe34a368db, 0x0a10cbe09f9243d1, },
		// Case [400]:
		{ 0x0943a8af3f106847, 0xf50772e8c150bcec, 0xa511e2555643567d, 0x02201c3662a59685, },
		{ 0x3a800ada5e741faf, 0xa9f0b6277c4ec717, 0x4619e8937190d606, 0x1e9eb2248749a9b1, },
		// Case [401]:
		{ 0x65e5e67a22f465f9, 0x72a842f97627a820, 0x54300da09101d24c, 0x2bb9277b8021c5d3, },
		{ 0x9d2aeca3f4c04fca, 0x0482fc97deba91cb, 0x75d5523b487e118c, 0x2121fa1693332a25, },
		// Case [402]:
		{ 0xd61339cca435e348, 0xd62a2017b6d2f30e, 0x85b3ded3fa8b9b7f, 0x14f5ee46878e6055, },
		{ 0x538b21f5b3764b74, 0x4757ea8b73e36ef9, 0x56327537c461f12d, 0x304ec3f58965f699, },
		// Case [403]:
		{ 0xf5e0486047bf3fc4, 0xabd855f3fba503d5, 0xc7d794abcd2497ba, 0x114578668b59522f, },
		{ 0x51e314f44ee53dd8, 0xf92d0c4cccdf7fab, 0xa702fa10ba8bf384, 0x12641beb7f07c846, },
		// Case [404]:
		{ 0xcd33eab3773a1146, 0x228017055096ee68, 0x07d0dd0a9da6987f, 0x20bc06a35fe07cd5, },
		{ 0x3cb31685d90a3e13, 0x2926ac9a56f8673d, 0x470dd22a3b41de1e, 0x14e9a80984308e24, },
		// Case [405]:
		{ 0x237670051d5fac5f, 0xc983d1cd94cada67, 0x32b94fb0612baa4e, 0x184801f655e82f8d, },
		{ 0x2e5a9679af14e1a2, 0xaee5efd6aa6a9674, 0x1bf8f4028e396611, 0x141d114276dc6a03, },
		// Case [406]:
		{ 0x25d3906ab5b3490f, 0x892147a64bfee54b, 0x778158fb2d303364, 0x1404d5fc7a2e8940, },
		{ 0x6945e6ae56aa71a1, 0xc13bfbb9cd231d09, 0x098ece39e5980008, 0x047bda9330ddb529, },
		// Case [407]:
		{ 0xb0560b0c1ee79e0f, 0x09d71cb59d6e303d, 0xbbae73beb8cb57b8, 0x251df4335e5164fc, },
		{ 0xc03441b698add89e, 0x223791cf0e61e77c, 0x6aae94ecff52a44f, 0x1121fa60e536ead4, },
		// Case [408]:
		{ 0x103eac7190faad57, 0x82486d3f8777eba4, 0x87b58d749c78c690, 0x09a45be49f35c4f9, },
		{ 0xbffbb5efd8af0230, 0xa12162edc666cf8e, 0xc8351d7bbb053113, 0x21f0e1e3880c3608, },
		// Case [409]:
		{ 0x8fb907df00e51177, 0x02c0051f1f203c78, 0xd5e1e6ea260a87f9, 0x2ede228b9b96b21d, },
		{ 0x6b5bb36144b1925d, 0xcb7115635787f683, 0x2859f8529f2eff29, 0x113c39cc19e0e0df, },
		// Case [410]:
		{ 0xa99cd14e45d6f209, 0x07e96de582c2c923, 0x00e6aab0e4e6b10f, 0x100a3118e3248ac4, },
		{ 0x7d82d877ea8ba6e1, 0x4cd9f23b39bdf37d, 0xf25a605c9f1416cd, 0x09e4868389c2d8b5, },
		// Case [411]:
		{ 0xf27adce084894e10, 0xd92ff71b6a6a2b32, 0x1faeac076b57513a, 0x15872dba1f1047ac, },
		{ 0x5780a6ce58b20746, 0x80c77749bca85355, 0xe42ef9aa06068287, 0x1c8e8763df136531, },
		// Case [412]:
		{ 0x737e4a6843283fa9, 0x039da22e42959520, 0xa573076ccd7946a4, 0x1f68a35d81c05733, },
		{ 0x475a0cb7dca7e23e, 0x9843d58f9f1acc43, 0x487ee603a8fa7823, 0x0cb44082e41ca156, },
		// Case [413]:
		{ 0x3683a8919e99a282, 0xb1515db27ea710af, 0xfa4e581d7cb567d9, 0x2a165a1a2b018ab2, },
		{ 0x2e5f87dcc2e4d4bd, 0x884ac8efda939f0e, 0x20fd26b9ec5ccf57, 0x1a41d0ed2f7f6582, },
		// Case [414]:
		{ 0x526f719fb40c6759, 0xd2ef854c66f917ae, 0xa924e943ca627fcb, 0x064ff94b98a0588a, },
		{ 0xe77a39358a2850c6, 0xa713ab40ebc1de2a, 0x9670eaa6dd7e957d, 0x29fe1590da85f5e0, },
		// Case [415]:
		{ 0x9f9691e08283d5ef, 0x4b673b72d673aaa3, 0xfe6db936c53bd356, 0x1c8349f898cbf2d1, },
		{ 0x9aed2c23622fb3bb, 0x337b5b881e7cbff5, 0xb1561483bde76431, 0x1d9f3658415608df, },
		// Case [416]:
		{ 0x0158f156db6e7c5a, 0x0576739c07050bcb, 0x4a32f10e0a95e92d, 0x2e4628a8655d2fc8, },
		{ 0x44d334122b106cda, 0x963109e9cc023033, 0x0088275a4a8b65cb, 0x20e0657c59c07296, },
		// Case [417]:
		{ 0xc510755a4a1ec152, 0x517e7ea1e4800a22, 0x213380a8757b3a9d, 0x0068316de71fed80, },
		{ 0xf8d4e066bb025bf6, 0x6e07f4155be16c01, 0x9c2c48163bc42bc4, 0x10b86307c21d9408, },
		// Case [418]:
		{ 0x95ec5b8289a54289, 0x5b9f5f1e8b4ebbd9, 0xddac8bacca9ec0a8, 0x229e32cdf952fd49, },
		{ 0x42c8883143a8c80a, 0x70c95d552150661d, 0xd6bf0a828e4bcca7, 0x079aa4c9c139608a, },
		// Case [419]:
		{ 0xa7383f01b9b5b892, 0x14cfafb05ad000af, 0x335cdfdf33ce102a, 0x26c9af69ab4a7e08, },
		{ 0x70ecec85230954da, 0x979fb62718d58b16, 0x5e1ba0c62dd1e9f2, 0x26b1d78c0d351445, },
		// Case [420]:
		{ 0x8e17af4db8f232d4, 0xe5e48678f97c1bb5, 0x8f20d51498ca60f6, 0x14bc514056691551, },
		{ 0x8e6cc4ab1bd2b370, 0xada16a11ba565cb9, 0x2bc986b52ce9ec77, 0x1d2a0ed13ba5bb8d, },
		// Case [421]:
		{ 0xbd0cdb308734339c, 0x1291bacee5c5226f, 0xb4a8bf2cc8c47e35, 0x22fe06bbaccc5b18, },
		{ 0xa7df657bcb5206b5, 0xa87b27abf296b394, 0x02cc341d34f19180, 0x13b57ff27cef4d51, },
		// Case [422]:
		{ 0x80f53d75d247af04, 0xa81902626de0d81d, 0x4b083aa9b9768db5, 0x1dca140377358114, },
		{ 0xda596e261443af5c, 0x48dee30e2ac6a8f2, 0x9d7b40fd4ec48bc2, 0x2f9e59ad7ccea66d, },
		// Case [423]:
		{ 0x5f420c45c56a1f52, 0x4b7e3025a592d462, 0xa4503613f3472ee9, 0x04152e8ca329e892, },
		{ 0x5b11515adc69786d, 0x18808492ba165e31, 0x2b6ed26336134eb2, 0x1e9ca89bd8ede76c, },
		// Case [424]:
		{ 0xd556cc5ad7914e36, 0x261f379f1fbb48a8, 0xd533026150f2bb6d, 0x13ce7edc9f1c7d2e, },
		{ 0x01fc5875d44213d6, 0x0eb57a3cbcd9043e, 0x28d21c46f1ee63ff, 0x248d1b22d819f919, },
		// Case [425]:
		{ 0x544a631f4e1cb1de, 0x81ec03c394fb2eec, 0x0bbe57854d48399d, 0x24f4fa36a48be01d, },
		{ 0xcbccd0eca1f3fe11, 0x519fcaaf3b98d542, 0x9387c1799bae84c1, 0x1510ac9fa55c15b1, },
		// Case [426]:
		{ 0xa0b3c29a01e559ec, 0xf9ccefc47bd5c487, 0xcc352710f1433d9d, 0x26e0659af8c838aa, },
		{ 0x872b4c1729d5a583, 0xc0cee7d0f6dfdbca, 0xa25e0f15a74069f2, 0x1dabfa968e2fc0f1, },
		// Case [427]:
		{ 0x72476c4f73e7818d, 0x46724707601b7a4a, 0xc8ca585c067b5ce9, 0x222f80f3327ff730, },
		{ 0xef728603470850ce, 0xbe4ceb891bbfb9cd, 0xd4b5d92bb9037be5, 0x1c4815949fc70638, },
		// Case [428]:
		{ 0xe5ebed3049ab2f87, 0x9c58d993ee168cea, 0x433f64e4f9f3e2ad, 0x19cd3a66216e859e, },
		{ 0x2ea1fd4719f9fc0f, 0xd34eeff8e71033c9, 0xac02598903d7861f, 0x2b80f18ad6c221b0, },
		// Case [429]:
		{ 0x44d8680e8a76188e, 0x101fc0ef222e3c2b, 0xcb695543c8499803, 0x0d01aa823ee846c2, },
		{ 0xe2588694d8aea533, 0x9a4a9eddc64733e0, 0xabfe7bfc10b1ba3f, 0x2c0137e3ac53e596, },
		// Case [430]:
		{ 0x26ebcc45c76488b3, 0x7c7207924e177d08, 0xad9ac0d387757aa7, 0x2e17901918cb6f4f, },
		{ 0x3b579a75ac9b6df6, 0x335191f8e94f26d0, 0xd867f19394fae93a, 0x2a40cccffd7f38a5, },
		// Case [431]:
		{ 0x30a9fa75bf484ad4, 0x15ce5f34d17c0164, 0x101cb479c7281e87, 0x2e30cc49639069e2, },
		{ 0x1232f9b8c44a7090, 0x9afe2a66b5f52dde, 0xfeca6e71f2a7537d, 0x0d8d54bb12f14dbd, },
		// Case [432]:
		{ 0x404683b2f00dee5c, 0x2b70249db92a74e1, 0x6c38ac70d1344c6d, 0x18694d18fe6758b3, },
		{ 0x29ff9d9e823d2e81, 0x6af3d16b026a3bae, 0x54395b9b8297468a, 0x0111c57a811081ca, },
		// Case [433]:
		{ 0xbe529996b56bffbc, 0x38b4c52af4e55fb5, 0x0c8bd40b4a786817, 0x2597efc11329ee3e, },
		{ 0xfe0c9860dea85fe9, 0x4c07a7d3a2620521, 0x372888438964df90, 0x1548cd828e76d3d5, },
		// Case [434]:
		{ 0x45dfc91edbbd1c94, 0x640893186e6ff6c0, 0x5aea9ff5443d25ee, 0x003ead8cba0d2471, },
		{ 0x5696dc19cf04714f, 0x3bf6d1967e8f72ec, 0x37439f6305619f35, 0x07f8be7aeabd7736, },
		// Case [435]:
		{ 0x7f3bbe071cf1ca2c, 0xc7b7c04cc2afaabd, 0xe7234d41915f2fa3, 0x1e17e4583d68f0e1, },
		{ 0x995fa9d8d9117226, 0xdcebb39ffb1660fc, 0x8093da0f5199dc5b, 0x0aa208472820ff9b, },
		// Case [436]:
		{ 0x5527168ee9f9d5c0, 0x97b7547bdfa1433a, 0xe8758837f5c973ec, 0x2d05098ef2828d71, },
		{ 0x7290df3751adbfb7, 0xc07d597bee4d7296, 0x8150a7592ef78778, 0x0e3eac18c979f0a6, },
		// Case [437]:
		{ 0xe8e1f0d436051a7e, 0xb7c1b837ade64a37, 0x1b2f2971627d1a74, 0x09220ca57e2ddf5a, },
		{ 0xadbcb6cc43088e5f, 0xde3afe209e60febb, 0x3df1a2a20c687379, 0x2db1a98bea5389b9, },
		// Case [438]:
		{ 0x68b3f5fba518e03f, 0x868adc52b4fccfdb, 0xa428f8afc999eb09, 0x22ee5c6d36a980b7, },
		{ 0xf067b708dcede4ad, 0xc0491e6ddaf1328e, 0x95efc7a0a95bc4ec, 0x28638f4241d4ccdc, },
		// Case [439]:
		{ 0x8a4b4aac270842c1, 0x77bc0ca8bef907ae, 0xcf4411203db1c19c, 0x1b70154b6e76cf9b, },
		{ 0xcfafe42833e521cb, 0x990d6bcde2984af9, 0x88b97d501995a148, 0x2a0c4ca99e5ec5c6, },
		// Case [440]:
		{ 0xf6b7a25baa7dfb88, 0x00f58c8605fd112e, 0xc0d5bac3b7e94531, 0x1a2ad9a834a4d41b, },
		{ 0xe4fa6255257d8bc7, 0xb81d0d9e1e4b3913, 0x39ade59f1fc239bd, 0x0a62e8c2d3335f0c, },
		// Case [441]:
		{ 0x6f6473ffda38380d, 0xfa28844595b1f2b3, 0x3cf8ee196e8577e5, 0x075aa06f43a27343, },
		{ 0xfd145d9b94d66814, 0x1f3cfe584cfec294, 0x6e74d6eebe9e0d8d, 0x2de4db92c379cf5f, },
		// Case [442]:
		{ 0x20f11ee8bcedf82a, 0x008f994efa4f5565, 0x75fb09ce934c8733, 0x070f884d5d0093ff, },
		{ 0x4733710915eb7379, 0xfd653cdfa9671831, 0x4808229f2738f0e2, 0x1c41e0009fdcd7fc, },
		// Case [443]:
		{ 0xf7b9df6f9225ddf9, 0x12d33a73be02f078, 0xa56d9dee45f8480b, 0x07d5a9301209de0f, },
		{ 0x9a19bdd35dc0ca6a, 0xf67417c2c42e5470, 0x37fd41284d6eff43, 0x12ef49a36c286b8f, },
		// Case [444]:
		{ 0xf615995a0f2466ea, 0x018853218ce565a8, 0xfd800d28af04254a, 0x0100dd4a2833b127, },
		{ 0x9b6608707d000183, 0xf47a0caf58ba1276, 0xd2a0d5eb06b8e646, 0x057b8c1a1c4da01a, },
		// Case [445]:
		{ 0xafc5f0e627e0d836, 0x9397bcb0089ce03b, 0x3bcfb8105c5c1082, 0x164c79e2906202e7, },
		{ 0x310ea181bde3c2d7, 0xb039e3376592e709, 0x3ad075c98f9a7d84, 0x080f7e1909ed9c6f, },
		// Case [446]:
		{ 0x163d741923f8fdac, 0xbad1d849fad58d34, 0xa1bc9158dc1d3d1e, 0x29dec9bfa2a12f2f, },
		{ 0xa842846487bfd012, 0xdb85cffd0a6cc9a5, 0x05bc45cbdf63c92d, 0x2f0ce952335c9b08, },
		// Case [447]:
		{ 0x5e07978096257f88, 0x645f33c7b0ce03d5, 0xd43e3c40f7579dde, 0x27d590c95d3dddcd, },
		{ 0xdaa6fe5cb5b608be, 0xa574ae9a18d94987, 0x27ab6c4cead26e9f, 0x02347c917354683e, },
		// Case [448]:
		{ 0x1e6a66157dfb965c, 0xc4e962e75955401c, 0x2d8abcb8ab2c6a3d, 0x0c32e71be02fa830, },
		{ 0x6cf02eb431f22c57, 0xafc423480dab8507, 0xca3677a218a0c201, 0x2547476fb947460c, },
		// Case [449]:
		{ 0x47710d298c31e9d3, 0x60a3126433bf9b9e, 0x0c7d3edf52f4f93d, 0x0cecd591ea4f3cfe, },
		{ 0xa54f92d1bff3f0ce, 0xc03377bfd0279709, 0xa611e3cbea37fcd7, 0x20af754c6cac9d0e, },
		// Case [450]:
		{ 0xf75aa227335f264e, 0x4d44f1a06184aa81, 0x4216f5f24789b3f5, 0x070627a0421fde84, },
		{ 0x29a595824fbdfc78, 0x43f3883a18573829, 0x42ad5b73188acf7a, 0x106256c31791d629, },
		// Case [451]:
		{ 0x33f1206f449d1de6, 0x7fe285811ec2cfd7, 0xa8b9f1a3ac86bfa9, 0x116f5232abcabac8, },
		{ 0x1007cabf4444cfab, 0xed026d65455a7c5d, 0x903e5608fe88ee82, 0x0146b17deb198ec8, },
		// Case [452]:
		{ 0xa35cfb4a6d7dbec1, 0xa2ba7d3bae30aad7, 0xd03fa2f1a7904cf3, 0x2a8ecaecf1355850, },
		{ 0x4cb2b90b2b715633, 0xf952313e63255491, 0x1d0ed551dc115b05, 0x2874a9a1535846fd, },
		// Case [453]:
		{ 0x1f95918d3d39b911, 0x24e491ddd3719521, 0x5c060600b3f6e19f, 0x252ee8a2dfbaab26, },
		{ 0xc9230231b90f4df3, 0xd516c46c3ead0a01, 0x986e70611e5d70ad, 0x1da3b2939b4ca407, },
		// Case [454]:
		{ 0xc89054d5218258e8, 0xd3c120aa31e2f1b4, 0x5afe948fdef2b6e0, 0x23ed5e73a4223df8, },
		{ 0x5c559d7fc68ba4e4, 0xfc8070204ae4c114, 0x510ce801483a6c24, 0x2cb373ebf8aba29c, },
		// Case [455]:
		{ 0xb86ba4c62a0600fe, 0xbb9fb86173625037, 0xe4331ddba93aa688, 0x0ddef510d2c7ba32, },
		{ 0xf634afb2bf28f426, 0x9acefc1283f84ff7, 0x49c0597ad0355bdc, 0x00309c8268081f15, },
		// Case [456]:
		{ 0x2d38d317f0febe8d, 0x5a65bf8ad06c38a8, 0xdafb5073bd988be1, 0x2339cd5cb769acf2, },
		{ 0x4eb9acd07a0970ee, 0xf141c7da0853a051, 0x302203e9b49cdd59, 0x13ff3fe3468bd6b8, },
		// Case [457]:
		{ 0xb37afbfdf076ab49, 0x762b585c422bf8dc, 0xcc999150483d44aa, 0x26fb4a101c97c06a, },
		{ 0xcc671e20ce869570, 0xed70800acbf8ff90, 0x1db1c983356e81bf, 0x0167be2e4cac6188, },
		// Case [458]:
		{ 0xab5cb833b09d1858, 0xfb8ed9e0acada998, 0x0cb02f280c5fdf78, 0x077d5874dba21d26, },
		{ 0x9eb384a81f0fd1ee, 0xea89a964fe6b2000, 0xd7a69c36cf2ae48a, 0x2c5c7d189611ba47, },
		// Case [459]:
		{ 0x812b69aeb6113220, 0x28511313b40b4a9e, 0x46f8522d73267023, 0x22ddb2bebc8cd1c9, },
		{ 0x6699ba4eef5bc11a, 0xf1805838e18e5c1e, 0x5eaae015b1a53abf, 0x0f7014396e7512df, },
		// Case [460]:
		{ 0x698e2c0ddadc93b5, 0x2a3da64be2c3f381, 0xf682c05c571f6aa6, 0x2e7c43c6222e6323, },
		{ 0xd334cd7dc0548b96, 0xfd2392a664800744, 0x894446982b6c6636, 0x1d07cdd4cba86e17, },
		// Case [461]:
		{ 0x7c94a50c9c682de5, 0x2acdbbfa0a9eab7a, 0x95371c667ce85077, 0x19ee0e60fc2da7a2, },
		{ 0x4e8ecf8bcf8b917d, 0x634599e627ada3ec, 0x161cf3fc4a09c0ef, 0x1a88646b3d690314, },
		// Case [462]:
		{ 0x7a82e780f1fa79b9, 0x38c0e199ce5968e5, 0x258ef2c525659b81, 0x04d46d32c131ca79, },
		{ 0xa89f2fc703d0aa5d, 0xc152362dca07c5ef, 0xbc48eb77eeea6fbe, 0x23a2091ff050c74a, },
		// Case [463]:
		{ 0x89a5e8faca46bd82, 0x2635a6dc7ea3cf38, 0x86a030f4bcc1d438, 0x2ddd25bd37dea233, },
		{ 0x799b3226b57ed550, 0x71b8407006aa65d2, 0x75d268ee5568c35a, 0x232ec3580a7a427a, },
		// Case [464]:
		{ 0x312fd5ec3d2726ad, 0x8549347b44526893, 0xe3d01a92fc168de7, 0x0be3e9d472b8118c, },
		{ 0x9d7c3d836f58e9bf, 0xf0c22a6ebebae766, 0xabb7c770233c978f, 0x0adc235e0be22dce, },
		// Case [465]:
		{ 0x43b48ff528e49b8e, 0x9594798707b477f3, 0x909a2f31896dc8de, 0x27fa8f235db616a5, },
		{ 0x65d042f345f19745, 0x8285554cf0397eee, 0xd9586020fbfbb53f, 0x0630c9fb821c9799, },
		// Case [466]:
		{ 0xce8b96f8c87aea21, 0x6a4dd6495e29ca47, 0x23eeda0b84833381, 0x17226412ab2fab62, },
		{ 0x34112267b66fcdb9, 0x5eddccb67c227215, 0x629c62f79684f25b, 0x01ad3f1a0785b6c3, },
		// Case [467]:
		{ 0x918277a21d03d4a8, 0x9bdce68646a435a6, 0x086eed8a710a3546, 0x008a2aca609e6344, },
		{ 0x4970fb2ce25a9a71, 0x8feeec217b597ec1, 0xf61e7d48606718ba, 0x167e39bd1ec30b1d, },
		// Case [468]:
		{ 0x58232ac25093e35a, 0xaecf7bc84098dc1c, 0x1b7ce9c318df7edf, 0x27a10619eec3b521, },
		{ 0xd235c401d9bc4ae1, 0xc492831a9e48a8fc, 0x50744d29fa7c8c78, 0x033e1e7f353339a1, },
		// Case [469]:
		{ 0x499755f25497fc46, 0x81897fe0f1adc5c0, 0x99865393563ec8bc, 0x06def2df638eab98, },
		{ 0x7b1e995b2ff9ad0c, 0xae91e33e5de90954, 0xbcc1b9b0b2c2248f, 0x010abe4e90e31ef7, },
		// Case [470]:
		{ 0x9d0ec7be8c50c098, 0x538a7faa110a438b, 0x563b7ad1b362a058, 0x0c86bd5b00467b98, },
		{ 0x1cfe448f04decb1b, 0x062691531b910b06, 0x559f203e7f460eb4, 0x0b79110efd5e758f, },
		// Case [471]:
		{ 0xfb3f2e7f30d90214, 0x8be8845df471e4d4, 0xc9daf086524707a7, 0x02237c3870ca51c0, },
		{ 0x3baf6cc90a5d7f67, 0x6a792685ceb3f50e, 0xc4060b9f10230778, 0x1325fea99f72d297, },
		// Case [472]:
		{ 0x70494cfd3c2982cf, 0xd00530e01e2a704d, 0xe1afa9f2c5f1ede8, 0x2aef4c14a514a36c, },
		{ 0x51559cbca2d7791b, 0x990a4853e1f1771e, 0xd69b65543ceabe14, 0x01ca685fe3736f6e, },
		// Case [473]:
		{ 0xeea75b55833b328f, 0xcea281735a913d24, 0x6f01fcf0d5ef108a, 0x0f425f81861ada85, },
		{ 0x5360fa36d3fa366a, 0x33ecacebca91a68c, 0xe7e54704e14b1eaf, 0x1bffe6cd312c0ac1, },
		// Case [474]:
		{ 0x8999d5baa0b4630f, 0xaec9c66e6cc8fda1, 0x21eeaf564fb19f57, 0x1e562f2a3a83be13, },
		{ 0x5a146b0a777dccb2, 0x9feb3d327d6d9312, 0xcbcf471dcfaa4c97, 0x0d0e730a801f8d11, },
		// Case [475]:
		{ 0x5b79e8e1e748c705, 0xa814a756782e2cd8, 0xc5e1eb617598954a, 0x0627d8f4c1a8c8f8, },
		{ 0x3ed2dc7570272f14, 0x85dc2f39b3280e2a, 0x513b12d8a3bf81fc, 0x24478859d910dd2f, },
		// Case [476]:
		{ 0x670fd3c317b0ea5b, 0x380c25992e5cd14c, 0x3a41f67782388cca, 0x15e5ad36f719cca8, },
		{ 0xa98685463d90739f, 0x5f1b5383c4241a5f, 0x9992abb9173cc827, 0x03bfe499744ce493, },
		// Case [477]:
		{ 0x0b18d16c5e757ce2, 0xe500e3529cdefd4f, 0x62697b7791da960b, 0x0cc8d138d0854f9b, },
		{ 0xc694cc7028792920, 0x87351d8fd4151726, 0xfd01e235c2d740ea, 0x0e01f56035fb8e0e, },
		// Case [478]:
		{ 0x5086f975d24c1e8b, 0xe9de247d2cf8d817, 0xb3c46c80946df519, 0x17ff555b52d28be1, },
		{ 0xffff38441559281d, 0x636de5f7ce507cf8, 0x5887b61337f3b8fe, 0x06f835c9b904b69d, },
		// Case [479]:
		{ 0xdee8bd404e6c79e6, 0x0a02693252b74f7f, 0x6671978d2fd289aa, 0x0fd5dd57c2cede87, },
		{ 0x14419912569ea3e6, 0x67d7d5ab885d3bf4, 0x4e9a87812c58c73b, 0x0a5ae3cfc60d99a2, },
		// Case [480]:
		{ 0x0c6733bd72f06f69, 0x93a1da1fb9e22b7d, 0xfcaff39b141def7e, 0x203144a77c72ea89, },
		{ 0x7747d10989f3e059, 0x95cf24c545009d6f, 0x1aae621fd33db984, 0x002cf79f39c80503, },
		// Case [481]:
		{ 0x755bed7daaf721d4, 0x1e1c855b5704d8bf, 0xa8ef35eebbcf6f62, 0x1979320524dfa45a, },
		{ 0x3a0bcfb4eccb301a, 0xae677a21d93f0623, 0x17f9ba4123554647, 0x1d0a6ead52e93814, },
		// Case [482]:
		{ 0xcade4e736ea28998, 0xf8b894d7f8bbcb95, 0xbab0f1092ca04880, 0x089b6683b1f849db, },
		{ 0x198f55c05daa4ed8, 0xd00edeef134b6b3d, 0xf4619bbd43731e25, 0x252344831e0606a3, },
		// Case [483]:
		{ 0xd51109517fa28162, 0x25c908396b5c3f2b, 0x784aa08bb9661fbe, 0x2c2dd8e6610a0495, },
		{ 0xe795a5417df8a88f, 0x3a3dcfb75f6c8cec, 0x8672ebd992151ea5, 0x0ada71d2ebf2c41d, },
		// Case [484]:
		{ 0x6dc3607b17e42477, 0xb3a33249be5cc6b5, 0x306886e1ff4003ae, 0x2b9627b579ec4019, },
		{ 0x1e5c33bf3eb17853, 0xbb6d6e8365f98ffb, 0xfb19a3e2858cdd62, 0x0ab8e9c350c9bd21, },
		// Case [485]:
		{ 0x19344ddd931174f5, 0x049f8c9889366965, 0x5bf4ca79b2d6da47, 0x178f70a99501a6e0, },
		{ 0xd5c0122ac5de41b9, 0xa9bd06d931c66031, 0x2da33520ce74f5cd, 0x011a4300556eeb9a, },
		// Case [486]:
		{ 0x3a3f156c04083abe, 0xa01b523548ea0ca2, 0x0c7d718e99cf3b6b, 0x224ffa0f9d0d57eb, },
		{ 0x49dda77740be04d7, 0x976694aebec18bd5, 0x68f54092c8222b0e, 0x1d3215c8da4efa60, },
		// Case [487]:
		{ 0xf67a799759c39ed4, 0x7d304d88cdee555e, 0xcd8aef1dbfc82699, 0x00f2ee1e2be1ece2, },
		{ 0x04235f18b1e693a8, 0xc59d23e09d6bcd7e, 0xf4c04a7989f3c1f8, 0x2fe0a9591511eb58, },
		// Case [488]:
		{ 0x0dd1ba2cbf7de236, 0xb1a3d21d3cbed193, 0x745a76000e24328e, 0x25757740ab14ca93, },
		{ 0x7dc9988a01a8ae2d, 0xfcf05fd8b41f64cd, 0x175b7794566259fc, 0x2589f14d764b4122, },
		// Case [489]:
		{ 0x7f280eae6496f16f, 0x1b4675edf79ee79a, 0x0510b3ca6e1ae62c, 0x0fa6b963bc65bd93, },
		{ 0xd5db691f415b3ea8, 0x624e41ffaa9546f4, 0x95237e8d4ce61669, 0x0edf4086e4ebdc02, },
		// Case [490]:
		{ 0xcaef37beced0e32d, 0x3f4eb1f1117d14c1, 0x2a9cba5f859fb3cc, 0x0ccb794ddf870bb9, },
		{ 0x86e0fbdd5c06ae97, 0xa2a6ebd05e3a8817, 0x3987df78b53f884e, 0x207aba602608c6d6, },
		// Case [491]:
		{ 0xc6b68c7f6ba50005, 0xca00fc23ea9447a7, 0x5a4309d4fe6e0cc1, 0x123fc6d306f17fcd, },
		{ 0x25fabfbb2aff6f3d, 0x24059a9749f27a88, 0x32ec223953e575d9, 0x1dcc7846fc89a634, },
		// Case [492]:
		{ 0xfc72cf90f0a29961, 0x2a09814a9557bcb9, 0x0aa1ee7baea48621, 0x22162170a1f845eb, },
		{ 0x51eb947b2b4edd0b, 0x967fed3c25bb3754, 0xc5067c25cc28a70f, 0x035dc46539b6af05, },
		// Case [493]:
		{ 0x257242484e497e3a, 0x422c9ee861c43036, 0x78dc7740e927ce8d, 0x13e385a5cd2fbda9, },
		{ 0x697da2c83cc2603a, 0x86267efc954a6210, 0x8b56dbdfb152df65, 0x30072e9e2f77928f, },
		// Case [494]:
		{ 0x7bb4be69410a7803, 0x10cecf47f9f57e23, 0x017d8e3eb84c2698, 0x13bebd80c2022724, },
		{ 0x9154f31c236cfea6, 0x2c0c124ed258cff9, 0xcb0bc64e0650b880, 0x20a6a4e974d193b4, },
		// Case [495]:
		{ 0x246c1de057d8ff1c, 0x158a6fc84f4ba6f0, 0x33b4c4607245156a, 0x13ed291502566a70, },
		{ 0xcc9a33db84a199b8, 0xbae76e97887a57e8, 0x563f604970c1b66d, 0x0f5e97428c568f2f, },
		// Case [496]:
		{ 0x7095a6e54f743247, 0x6c54114274217921, 0xc7ac3b7714f204e2, 0x2ffa06928536af91, },
		{ 0xdade37afda957b5a, 0x83885a83c875e5fb, 0xd0e659537f10fe22, 0x0ddaff9ea88c0a46, },
		// Case [497]:
		{ 0x8b5e528d4313183e, 0x10fd55a368624c14, 0x029749aaa7c9a40a, 0x2a6df655e926c4aa, },
		{ 0x3974e6b67eeecbb1, 0xc8f7ef30ae60eba5, 0x05470876bedc6f54, 0x23ee063ab5f69daf, },
		// Case [498]:
		{ 0x8651f1bf6b9b0238, 0x0db502a580b8a4cf, 0xca74db524323fc10, 0x27d8531ec6121a3e, },
		{ 0x44f55149a4cab4da, 0x7ebc5a95e9ff70d9, 0x42a846b8043ff661, 0x2b13b1f5eede5391, },
		// Case [499]:
		{ 0x2b4aa12a3b0e747d, 0x06693422b3846b3a, 0xbc1ccfd4626cea0c, 0x1ea104a44d82fbe1, },
		{ 0x09526b1580774a43, 0x8b5bc226239b90df, 0x18d70f3f5ae39476, 0x20c76ea1dbab3191, },
		// Case [500]:
		{ 0x0da5915412ac5ff4, 0x5989114a4667251b, 0x58034d954dea602e, 0x1d69a3852720a887, },
		{ 0x975b777527157343, 0x234375a83e117ac5, 0x362c910c4caa30c6, 0x2a2fbc736c6e9ad0, },
		// Case [501]:
		{ 0xb5e10337d7f3d7e5, 0x2e647f6926da913c, 0xeff9c1086d49cd8d, 0x1b8e232710f6c1ce, },
		{ 0x2fa0b3165b1b8223, 0xddd6c908d908f116, 0xfd466d1a3d0cb136, 0x2531f401ccb28927, },
		// Case [502]:
		{ 0x210f7da599c4fb3d, 0x169f88067574ffc9, 0x6014c69630dbfdf3, 0x2d40d3f8e6f9e3aa, },
		{ 0x445b83959e53d96f, 0x2bef1f17cdf159c5, 0x14203f66a2a08b16, 0x2573fc698a621fe0, },
		// Case [503]:
		{ 0x6df54a6fb6f0508b, 0x02f00cc696df64f7, 0x01770cefc4334a8c, 0x24e1c2f60b1cd361, },
		{ 0x0336afccf32861c3, 0x9c99079398938779, 0x521ce3e3ed1ba69f, 0x0a07f6d984cb7332, },
		// Case [504]:
		{ 0x54017abb3db8c04d, 0xac0c9cb5cbcb4b40, 0xcadbff81c9a44913, 0x2408f2eb6b1e958c, },
		{ 0x7c20d8c17eadb543, 0x11258f9ecc32229d, 0x15ab57a6d0502d22, 0x090c3ddb623ec85b, },
		// Case [505]:
		{ 0xd14e5ea33ff8ecde, 0xb07c1353dad96e87, 0x6aa37dacd2abc38e, 0x0e3c6ecd281ba2e1, },
		{ 0xe2d6039066c68a9d, 0xf52919b944d4748c, 0xc629a9c656069234, 0x1a30ccb6b5663a2e, },
		// Case [506]:
		{ 0x90f0006d9ec543e8, 0x6cd0f6e3212e2540, 0x19bfc755eb9e9a30, 0x248c7cfb7ba2e718, },
		{ 0x39b2e6a3e4c5fbbc, 0xe2080f3d44f5c701, 0x0fad4591326bfe9a, 0x2b739f4d6d296ef2, },
		// Case [507]:
		{ 0xb4ae4f39d21721ed, 0x1226d8ce39574d72, 0x9e79f68632217df5, 0x267fdcdeecf69d79, },
		{ 0x95358ff83dd2b985, 0xe21ac9151d1a59d7, 0xdf0481fbc8919f1c, 0x030292a5ff4157ac, },
		// Case [508]:
		{ 0xad831de9fa34bab9, 0xb261603c2c9afcf4, 0x911ebf78dd15342e, 0x2bd9173ef276b7d4, },
		{ 0x403e029124d0bd0f, 0xde80efc607598140, 0x86981921218df932, 0x1a4acc9065e5c3cc, },
		// Case [509]:
		{ 0xc1d8582f4dc65f14, 0x0fabad8fa3ddb365, 0xadda334672300625, 0x1cc0af33d07e50b2, },
		{ 0x5678d4f2e5d1a04b, 0xbefd9fe4fc05104b, 0xc3f7149928cd1e78, 0x1afe56dc7012f1e6, },
		// Case [510]:
		{ 0xc59c11447caecebc, 0xb05440c20dd9754b, 0x5f9ca9ce8fdeaefc, 0x221f2bc4b7dce919, },
		{ 0x2189f4fecb8a9a4b, 0xea125da76384d6ee, 0x1d57e60f7dd4c423, 0x2785e9dabc55da1a, },
		// Case [511]:
		{ 0x9f3c2499ecf92b07, 0x8dbf1996bcd1b348, 0x45d238fd0cab5dec, 0x18ebd5c63b0bf20f, },
		{ 0x947bfb6af4c96846, 0x07047811ebede971, 0x3eb275b8a8d1163a, 0x086f56ef5280bfa9, },
		// Case [512]:
		{ 0xbe47a5e77e9f5a4b, 0xe58a5efa19ddc891, 0x4af3beb92aa92ce8, 0x2f338bc5a586f277, },
		{ 0xc10fda36789acd71, 0x7cf5571aaf2b5f76, 0x31934f7fc2dc3739, 0x032e788fbdde29d8, },
		// Case [513]:
		{ 0x492939bfe4e9fb1e, 0x9da5907f8c7118ae, 0x4f2ff6e0c88f4198, 0x0556b9c3784145eb, },
		{ 0x3ac167638040581d, 0x03130be70fba5fac, 0x4b4f1bb4672e1a17, 0x24562cd3c04337bb, },
		// Case [514]:
		{ 0xa3294cbde38b2284, 0x51238a3637e47022, 0x38bc6956805ed370, 0x1ec100367f656845, },
		{ 0xccf443e8330936c2, 0x711d1a3216c9e354, 0x1c1be8e9c4ee93a1, 0x0accda4d2676a368, },
		// Case [515]:
		{ 0xe26c215bf448f84f, 0x073c8baac6e5db87, 0x1a4b798c7096e832, 0x1645a29dd4527ab9, },
		{ 0xf828f5a8c5847318, 0xa091134b366da302, 0x507effaf59dedcbb, 0x26d7b5ea75b911c6, },
		// Case [516]:
		{ 0x09a95ad105ac9350, 0xddd375e9b3bfb424, 0x743ed52ef2737bbb, 0x22a78abf7d5b362a, },
		{ 0xa089199a5d3d3dc1, 0x45f08cd959aa96f3, 0x692ce54edf3cb137, 0x072f9c7577dab8bf, },
		// Case [517]:
		{ 0x40830bb18686eb37, 0x1a49d5f181e80365, 0xafb3ac9f3f35acb6, 0x1a9921dead26c55a, },
		{ 0x47b98bdb40851a34, 0x68ad61671ba33223, 0xfbfd6c81a105207e, 0x1f79bc303ce62acb, },
		// Case [518]:
		{ 0x5fcc6c3262191aa9, 0xa588272465d319e1, 0x3927d4643574c0b1, 0x0eb8645b0d2b8f0c, },
		{ 0xf371f137853e3f84, 0xe44bc3c8f5f9f1bf, 0xaf8f1fd4e1b0773f, 0x2dee3c0ffb656a4a, },
		// Case [519]:
		{ 0x9077d60e5e7ea655, 0xa47c31b5592c4afa, 0xdeb825a34ca48904, 0x0e48af0cb275af55, },
		{ 0x1148b2f3698e961d, 0xe90cfb3d8a73db5c, 0x085a22bfe732968c, 0x18cba3a87ee42dee, },
		// Case [520]:
		{ 0x26a62e85a3ea4b66, 0x1b5bc894ee6b62e6, 0xf967cfef597a6da1, 0x17dfbac5a26f06ff, },
		{ 0x6a4774cfc9e601cf, 0x65f8b4cba7861ed7, 0xb3494fa7ef0edc64, 0x26a6f745e49e1967, },
		// Case [521]:
		{ 0xb3631027c866aaa1, 0x6f78917d7fbdbbc1, 0x5226a83edbdb3c5a, 0x0dffbd016ffd2b79, },
		{ 0x39c16a3098801883, 0x8ccb547622c78203, 0xb568e61ce4eb080a, 0x159df04786330208, },
		// Case [522]:
		{ 0xe2c2d13825094310, 0xe7ebfc750e16ebd1, 0x23a4338d244f6ba7, 0x2f948d5f70856b5f, },
		{ 0x7149d6ffa44b2b74, 0x8f20ee6c8126933d, 0xf05119f2a84e17f2, 0x0471b3b383e098d9, },
		// Case [523]:
		{ 0xd80435301511713c, 0x9dca60fe174ea321, 0xa0f885c59e420bb8, 0x194c9f7615cbe3ea, },
		{ 0x2aebe0157f62afd8, 0x8cf365607d1e04de, 0x8fe7ed47b6623d48, 0x0f23435a7425167a, },
		// Case [524]:
		{ 0x240cbfbb4b17b3cf, 0x663d621562fb3701, 0xe662c7ae726051ec, 0x16e81a0540143cbb, },
		{ 0x2f4f07e4e5d5d0e3, 0x0a555e1e9bd196de, 0x5f91e9d89fcd9c73, 0x0f1e0c5db97ffd60, },
		// Case [525]:
		{ 0x8eaa42927ea6eee2, 0xec78decdbeed34bc, 0x5e47e9a4953f789f, 0x11ef0c2d88131f71, },
		{ 0x9eaf77d203fa91e8, 0x243786a159fb39d3, 0x0b7045bd95439645, 0x250e0467babe18a5, },
		// Case [526]:
		{ 0xb7d548400f668535, 0x1d1d5c3e1414308d, 0xbfc620a55951802a, 0x0876e45a4f862901, },
		{ 0xaa27f7f119619030, 0x0f1b3e7c177aaa62, 0x252993b78c7fcf30, 0x250cc90141a6f5b1, },
		// Case [527]:
		{ 0x317dcc98017e6c75, 0xa8676363bfcf3165, 0xa4ddaee1192c055a, 0x2e78d35e1dd86776, },
		{ 0x5f5f2298370ef4d4, 0x1b73f59f87b187fd, 0xa431fa84cf2c6d56, 0x087328cbd6c0405d, },
		// Case [528]:
		{ 0x89009a2cd7d15a6e, 0xa444da42164b6ef2, 0xc36adae4bc034fb9, 0x19f6e589ba384db3, },
		{ 0xdcb86c11be8b454d, 0xa166031548fb8c62, 0x1e609543c278d158, 0x1a16ac61456c5787, },
		// Case [529]:
		{ 0x35dc9f6ab14404fe, 0x7acceadace687aa7, 0x6739bdb1b4b50895, 0x09fed90b1f10f84f, },
		{ 0xd2ef10d4615079dc, 0x1b3c4f4b617629fa, 0xa9817bfbd3a84040, 0x1a7ac7e4c7b43884, },
		// Case [530]:
		{ 0x21714137221f4831, 0xd5192adcd70dc337, 0x7a3603222e09005d, 0x055e35bbef7ce5ee, },
		{ 0x694b1dbe00b93358, 0xc3001b0499187358, 0x795642468f90ca72, 0x14d8e62679a503f7, },
		// Case [531]:
		{ 0x2a96e7cac65a9828, 0xf9bb736e0d47cec2, 0xb6990fd928ecf056, 0x05e8dc359ee98d3b, },
		{ 0x2ca58b37be7eea95, 0x382d1afa1e832081, 0x8eeefe6f136c502d, 0x16af22b9a810770f, },
		// Case [532]:
		{ 0xe038bcd2315d290f, 0x752a7bd3943c7b97, 0xfac76944ee969930, 0x0c732297f8b0c272, },
		{ 0x8749a00f7e2bf126, 0xdfe354b1d84bdb53, 0xf1ea2fad12da55ee, 0x1e00ae77502de665, },
		// Case [533]:
		{ 0x3cfd13fb6c2a10ba, 0x34de248310887dc1, 0xe315d5b62aa1bf78, 0x16703fb8b02c94ad, },
		{ 0x740b7df6d6996c9b, 0xe44e6eb007c06063, 0x9a02f82e758a32c6, 0x0aedfb12e4241e42, },
		// Case [534]:
		{ 0x0f3f1e059d7f7f4e, 0x0059635d01fd6fe4, 0x2af4e39e43bf9ac8, 0x28715ac5265d7a81, },
		{ 0x26c4a8503a50035a, 0x781217af32598615, 0x3d9d5fcc1104abcb, 0x07653e5745277195, },
		// Case [535]:
		{ 0x1593ce6f837bcaf8, 0x227b480a6aca67ab, 0x5e71eec8475730fe, 0x2f683b0027994e09, },
		{ 0x581ae9f77f4ebf07, 0xe2431d15952af9f2, 0xbc2529cca73ee1c6, 0x12bbfecb985567b4, },
		// Case [536]:
		{ 0x595b9a08da85b323, 0x3c5aa6140a858f21, 0x2f198590decd4394, 0x0854d9c3be72187a, },
		{ 0x40a4d142586e6540, 0x81e1777a7bea82d2, 0xe61622af33f5904d, 0x16c315c4dd660b7b, },
		// Case [537]:
		{ 0x01a0d379497deadd, 0xb9101a3cce55c668, 0x5b2104acc1d8db8c, 0x1e3d592b71a473c8, },
		{ 0x0fd7c33e6467436f, 0x89a6e72eccb34b38, 0xc1666115f300912c, 0x097f2325615e4446, },
		// Case [538]:
		{ 0x069dee8b95a9a70a, 0xbc1d7ce047e83d0e, 0x67a71e697725c195, 0x1eb27377cfa38a39, },
		{ 0x74fa24799be578c0, 0x4d17bb33ac8e1eff, 0x6923e0a1b0a4ff4a, 0x2a9f854870316eaa, },
		// Case [539]:
		{ 0xe3ea30a659bdd9be, 0xbc2d657c47b122f4, 0x01232c7aaafb5e73, 0x0045b9fd1e0f1158, },
		{ 0xa8f2f3be42906c25, 0x7ed21005be844cfa, 0xdd9c2f92bbdd5162, 0x02dc3f0b379f70d0, },
		// Case [540]:
		{ 0xf1e1de65a87dba6a, 0xd68295910dd39245, 0x94b61a804dfe2231, 0x027aefe3d1130e93, },
		{ 0xfc3374735634d74d, 0xa095b2b1bb80ef05, 0xaf5a5ee5e7e6ec96, 0x23f0e982f789e41b, },
		// Case [541]:
		{ 0x4df0482a9b1df4eb, 0x625e4c169415487d, 0x56fc50dd7fca7b48, 0x2e4c5fa1a42064e5, },
		{ 0x486d71b7a2e4b775, 0xa7671913525be3c5, 0x5ce72d629d0d690e, 0x115a21fea47942a0, },
		// Case [542]:
		{ 0xc7b9b9f74dd3315d, 0x2e82441be0b90523, 0x9627a19196a7e467, 0x05767cb28f1019a3, },
		{ 0xceadf7f5dc3acd51, 0xdb2e1d551dc61372, 0x61749d65309638d6, 0x19747767eef026aa, },
		// Case [543]:
		{ 0x02c5439c807fb4dd, 0xeb3f945e99a68095, 0x09d3e038d1364b24, 0x17e443e32ab352d2, },
		{ 0xe2d2e362abe3aa8e, 0x9c9e3c77ee52b07c, 0x0ebc1a45fa714f00, 0x15a1ebbb0dd11353, },
		// Case [544]:
		{ 0x35bce42793513e43, 0x4acef4a2cdcfd8c3, 0xfb70978edec1bf3c, 0x017a0c0d83cead8f, },
		{ 0xb41b7e8f6e0c6e51, 0x92c3a5b2c13b69dd, 0xa31ccaa30d4d655a, 0x0f2cbf8369acab4e, },
		// Case [545]:
		{ 0x9bf1030008a252b3, 0x20738a481a7a76a1, 0x665e38f3c49b767f, 0x28b749b2a9becb34, },
		{ 0x096fb9d8c6f9f750, 0xfae8301acbd6b2aa, 0xab025b5baec9457f, 0x187d82093b525b1e, },
		// Case [546]:
		{ 0x36c3f1ffca690356, 0xe0acee47da26c404, 0x0f2fc1b5ec5ea0a0, 0x1f5252eb629922c7, },
		{ 0xc0c7fbc82c91c66c, 0x80366e4e873a78ee, 0xd6159d50acc47ff3, 0x12db463b4ec7317c, },
		// Case [547]:
		{ 0x56cc26b73358aa0e, 0xa7724da53ccedb3e, 0x33a056c3fa8f44d6, 0x29324c40ee7bc85d, },
		{ 0xa461f7d4b626a128, 0x2ef378ea949a2ed4, 0x1c051eaedbe428a8, 0x1a81d494f5c7ad32, },
		// Case [548]:
		{ 0x054fb3ecf7860cde, 0xf8bec6c9abede582, 0xd75b376a9a1af17b, 0x00567e9bd8a2b947, },
		{ 0x3d44a437a84e9723, 0x82fe24f06fc85528, 0xb06829e3b82144ed, 0x143a0c13e2f24620, },
		// Case [549]:
		{ 0x55c3176d5c11e8d6, 0x2fc9988485f61843, 0x0f2621c0adad747c, 0x1e96bab6ed6f4555, },
		{ 0x0b1ffa8c4a8546c1, 0x6af5e557e6929240, 0x41d5922c3f93ec5b, 0x067abbf6022d67cb, },
		// Case [550]:
		{ 0x0836f599e995a399, 0x48f6cd7c1f61874a, 0x992c9eddc91259a7, 0x08d47dc23b1ff527, },
		{ 0x6b3b107b7dbe3334, 0x03a2da42339535e3, 0xbabfda5fd8abdc06, 0x2f6284fe57575df7, },
		// Case [551]:
		{ 0xaf671050cf6736a2, 0x0809a0b888c85743, 0x0d89d1ac142f2675, 0x22733cdd318150f4, },
		{ 0x2bbb1836882383f9, 0x837d3df0d1918e2b, 0x83b6161c11fc0303, 0x25fab52d7dd0d543, },
		// Case [552]:
		{ 0x25864c5ca1927347, 0x1de6bff4a3778030, 0xee87441174a24fd4, 0x2168174bb9c45be2, },
		{ 0xa9db27721c0d135f, 0x038ee74105fae43c, 0x1e47b418a91cf1a6, 0x15aee13751d4649d, },
		// Case [553]:
		{ 0x83e7b8726043a1e0, 0x65af4a9267b5d620, 0x8d0495ba63e8713b, 0x0b48fdaba88524ef, },
		{ 0xc5a77a82331b2f3a, 0x07d38243df7b8208, 0x83b84204eb2c1442, 0x08188e4d8e0fc470, },
		// Case [554]:
		{ 0x17a866e50b3ec8a9, 0x35a4ce8d7b733a9b, 0x520c0fa02dce2329, 0x18658643fcb63644, },
		{ 0x596e162dac108532, 0xc8232bda50a44546, 0xa9144427b7b4a501, 0x141af398e019cd92, },
		// Case [555]:
		{ 0x834865fd4974bc21, 0xed0df05f6c6b28a3, 0x5871bca97960b299, 0x2fc94cda5238fc78, },
		{ 0x32e99588bfbd66a4, 0xd1508bfdb074ed5e, 0xaf233ee26127f1fa, 0x08abb3b12d4030b1, },
		// Case [556]:
		{ 0x13d65c6d5994ab6f, 0x244fcf42c38db355, 0xe87530303c12ef76, 0x1a54a91a89dd7e0c, },
		{ 0xe2b51bcb02681829, 0x9dd175f34545640a, 0x68947c50a1edd0d6, 0x16b4ec01a869e616, },
		// Case [557]:
		{ 0xb72510c5c4c3da22, 0xb2d13f04d4673537, 0x2f4170eaf42a27cf, 0x15610d8d64ba0295, },
		{ 0xe7181cab237d9141, 0xd9d74bf6d6ed633f, 0xbbaa34b6c7389a21, 0x040fa09f58412f7d, },
		// Case [558]:
		{ 0xcf66ea44a6661212, 0x42b277467d8a0436, 0x7ee42087cf8b5890, 0x13597b4707657f43, },
		{ 0xf6a746897389a95b, 0xebf37bde22a85604, 0xfd460fdb19ff8872, 0x137c2aced1de7adb, },
		// Case [559]:
		{ 0x845d5e961a87837f, 0x7e3871d3f16ad0c3, 0x28bc5edf58b2e9fc, 0x2dbb95e5114e7400, },
		{ 0x80b96e30a3bd5897, 0x890a4e30a82a183d, 0xabb3b5f8b1fb5729, 0x09c038fceef2b4a4, },
		// Case [560]:
		{ 0x3ec71e11f86c52f9, 0xafb43cb6492b2c36, 0x596eab92d772f6b8, 0x2cb3a3e7ce16cad9, },
		{ 0x031ecf1a05d23451, 0x455f448cdc3a6a1c, 0xbb8061e1edc2fb82, 0x2264dd8729e5b1e0, },
		// Case [561]:
		{ 0xedffeca5d70020a4, 0xec27de7147ce50b8, 0x2dad5d90ef65d28d, 0x286e8b9468bd2d39, },
		{ 0xc1c95472ec2ae113, 0x61d0e531014a1d34, 0x40d963bb261f7486, 0x1fdedc4e3871f857, },
		// Case [562]:
		{ 0x9f6bbfcce9989317, 0x226237b077cb76ed, 0x1d753737d7d908ef, 0x166e762a73b51900, },
		{ 0x38e7ab621bfaede2, 0x8ca7a93d342b957b, 0xb0523a4bb4daae66, 0x1b90190216ce5da0, },
		// Case [563]:
		{ 0xeaf4be54ab844f61, 0x78a57fad3845e7c9, 0x79fa2f33ba9adce8, 0x1dc5bee6477d7e78, },
		{ 0x78936e62f4b52f93, 0x8cd7c8f0e9318642, 0x4287a66b264bf2e4, 0x1f88431b3cdac3f3, },
		// Case [564]:
		{ 0x5174b40d3877155c, 0x41d614abc7b34bb4, 0x3e064c86b508afec, 0x1f16f7f1cd61d956, },
		{ 0xdc2f1e50f4ad07de, 0xf0fbb95298b747cf, 0x45cbfe1e388fe613, 0x136783baadb45b08, },
		// Case [565]:
		{ 0x9f8751af58c8eb15, 0xadf9691e4ea5f620, 0x6fbf044e631ab11f, 0x28df04cdd7f79cb0, },
		{ 0xeed6b4aa591a9dcb, 0xf168e5c98309230b, 0x581b4ee9e3cc95bf, 0x1d94b511e1ae8910, },
		// Case [566]:
		{ 0xba95646526588fb6, 0x61b7075d38a7c0b2, 0x05dc1e60f4487624, 0x18aa6490047ab521, },
		{ 0xf4659d31f2c102e8, 0x09c467f38f26e3db, 0x204e822d63e8381d, 0x00029f1fca340861, },
		// Case [567]:
		{ 0x57bc6bd9400ab99b, 0xbddf4f65388cae83, 0x2147c6a6465c9a83, 0x0076ab8143a29079, },
		{ 0x61f143c3dd844fcd, 0xf5b68215162bb415, 0xced119d557746c04, 0x0929a740da878e74, },
		// Case [568]:
		{ 0x26f821bcb6f1f8de, 0xbd2e344b403bbd8a, 0x3cef3b234cc11acb, 0x2616217a94f40705, },
		{ 0xc46c1401ebfb2b9b, 0xbbb6dfc40f712419, 0x278c0789c66c9a82, 0x00f0b00847ce5e87, },
		// Case [569]:
		{ 0xbd4e260d81675684, 0xbfe1bc4e0301ec1c, 0xa34d3a11080d6ed5, 0x2296862cb9a14424, },
		{ 0x003aa7e666c23f05, 0xed0831cfcd7c6107, 0xff1eea9c53a1d6e6, 0x2a16a9f649fcabf9, },
		// Case [570]:
		{ 0x834e513f3ef97c53, 0x0fda227a3e7a40a4, 0x3406314c159732bc, 0x0828428022a29990, },
		{ 0xedf6ba70ca36d6d6, 0x7a7e6a0e632d0fb1, 0xd78a75f06fca9569, 0x0d2acd16fb2b6294, },
		// Case [571]:
		{ 0x75b394f38279c77b, 0x1780a0719b3f5901, 0xa6f20cf1841e702c, 0x0771ff9f397469dd, },
		{ 0x776af36b7d9452e2, 0x5a4adca8647304e2, 0x2153cf30e7f624c3, 0x2b0354f7b159d595, },
		// Case [572]:
		{ 0x444965a749567975, 0x228d06dd4567fce1, 0x04925eb9439a4f44, 0x0dc489dcf61aba11, },
		{ 0x89702fd41f03f7da, 0xa9077fffda76f0ac, 0xe859cc06fd13bd32, 0x1348b6b4896350ab, },
		// Case [573]:
		{ 0x3bdb912d43865fa1, 0x3b6ff11b2ebb64a6, 0xdafa39eabdf7eaa2, 0x104470f92923d3b9, },
		{ 0x584c19bb1b7d6ab1, 0x08d6bdc6afb425a5, 0x13dc05a7b7dafa64, 0x25d43965725579e4, },
		// Case [574]:
		{ 0xd4f78efbec993a6d, 0x35aa6586b27cc9cc, 0x5ad223e2f3971861, 0x14a490ce09c92950, },
		{ 0xb93cebea3f3c8939, 0xdb3112bf466610de, 0x92a8b64f10a39aa1, 0x19d2db53108a098c, },
		// Case [575]:
		{ 0xc9563fed9a7853ea, 0x4cf330835825fb8a, 0x4461fb24a2f72eae, 0x206893bb747ca250, },
		{ 0xf9b4d22b7f95a17b, 0x3da6b78e6fb333e5, 0xa07bebd877c4f22c, 0x1d4107d9596b3421, },
		// Case [576]:
		{ 0x618c800acf626546, 0x3fbd4f37c80ba508, 0x068c6ac8171244c2, 0x03c2a738e753f35b, },
		{ 0x99c90d4d5a98be5f, 0xb9bc21e4049dba23, 0x51d658fb38377f2d, 0x277d06190330c33f, },
		// Case [577]:
		{ 0xf3646b52cfb06e16, 0xf1308100d34a569e, 0x80efc7400212cd7a, 0x129edb7a013029be, },
		{ 0x2239c76ca0ec56b8, 0x180f4dab1e6ec590, 0x2579ac5efbadea85, 0x056f4509081558fd, },
		// Case [578]:
		{ 0x6f4d1524a1ddc158, 0xc7ece1ec2e262f22, 0xddac89e7b562f917, 0x0874b0edfee05d8c, },
		{ 0xec874212709d9ee5, 0x0fa8660a4bd17cfe, 0xd215f9b64a74b28d, 0x097c344cfb4720e7, },
		// Case [579]:
		{ 0xcdf30ad2517b2aae, 0x8078841896f7be41, 0x537c696bb1ffaf89, 0x10a0bab2786cda30, },
		{ 0x2e655f292d5df632, 0x59498ccfbbe169a7, 0x17b6bb8fe2fd4b2d, 0x2825210733fb2594, },
		// Case [580]:
		{ 0x7a6c72a47e13fc2b, 0xed928364cac984e1, 0x221f435ba90520bc, 0x0bab661c2a17fbe0, },
		{ 0xe8cef74c4dfdb70c, 0xddc9d96443ec0bfb, 0x92d7a607d2d14e9d, 0x27927d334175a97b, },
		// Case [581]:
		{ 0x05e1380c54f843b2, 0xad8dd02ac7d46630, 0x57a28aa2ae13c981, 0x2042016e686c9840, },
		{ 0x620523a6db523582, 0x4a6747c21199c52b, 0x1b598e1fb47e5320, 0x056de9386ff3443c, },
		// Case [582]:
		{ 0xff5d6e0710cf4a42, 0xa887739d7cee663f, 0xa81d087f967f16a3, 0x1fc295ac71911a59, },
		{ 0x42517a3990fcadbd, 0xe4f7aa4e53d30f59, 0x0e816f992e52b50b, 0x2eb60449c3685036, },
		// Case [583]:
		{ 0x1dd32c19cb1a8777, 0xaf4fa291de888e9b, 0xcc3bb0d9d345cade, 0x05922697b04ae608, },
		{ 0x93d5fa7c480cfffa, 0x9031acaf7aa80de3, 0xf4a68d50f3f2cb7a, 0x26362f7e9ce77711, },
		// Case [584]:
		{ 0x51144bb3b0e4b9db, 0x23bc90b469cee37b, 0xd864b9cd030729e5, 0x271b87d8b895c6e1, },
		{ 0x0f6385246ac5d934, 0x0f16369f5e03cd9c, 0xe5955a4bc8cb86ca, 0x2984a3ca1a888af5, },
		// Case [585]:
		{ 0xc674edb9d7bba552, 0x9d0c0ffab8f55c21, 0x22900fee892cca26, 0x24aa401343e4705f, },
		{ 0xe643574ebf649e4c, 0x0d50ec103bd22a59, 0x51327850144fe10f, 0x047fb406a4049ebf, },
		// Case [586]:
		{ 0x71c617004f05922d, 0xef0268d5d2b76d72, 0xb5e00f7037c9ac37, 0x1b07068cafe17b55, },
		{ 0xc6173549dadee177, 0x1739b635233f09f3, 0xc95ed28cdc532478, 0x01a457ab2507629a, },
		// Case [587]:
		{ 0xa6ee30c90097cb33, 0x84a2b74aaf3e5b13, 0x6a2094f2a1bf2d19, 0x1e35bad319a036cc, },
		{ 0x355586f89b319a1a, 0xcd600cf2e4e444d3, 0xa5b43e1fa928e891, 0x251f6adf0a563ba1, },
		// Case [588]:
		{ 0x5eff2d5e754fc219, 0x03945e039c4ddbe0, 0xbea68f4fb5b1fa09, 0x2ab91b9a85ce69e7, },
		{ 0x3948031477f13318, 0xeda8d2fef47a0c45, 0xeeeba16f99eb0a4e, 0x16b41196d4fa8003, },
		// Case [589]:
		{ 0xaab14b547858f666, 0x5edb8e28fa7ec307, 0x365ec70b5b3e0ddc, 0x21e979fa3a2594d2, },
		{ 0xa302d1f10554f415, 0xe3fba4dcd367e536, 0x1bb852976d1a404a, 0x29ceb27d80fcaf0c, },
		// Case [590]:
		{ 0x96fdd68469d1ad0e, 0x15e73784ac6b15c5, 0x95523ebe065c9c21, 0x187cffd76c5fb297, },
		{ 0xa9a16253f3b42683, 0xb823721c4f6957b4, 0x489451f3502f3bb5, 0x1a0d2a240de09d48, },
		// Case [591]:
		{ 0xef6af2180a007392, 0xd11d9f91c0f7fde9, 0xa8c068f88c3d23f9, 0x18d2ff882c52b396, },
		{ 0x50c9efe581604105, 0x3e7b387fb1a221d2, 0x01673ac3901f1b45, 0x2f3bbba23829be54, },
		// Case [592]:
		{ 0x5adc1d9fb91b31f3, 0x5c1ac114e599c24e, 0xc3d430f11f326b78, 0x0a878a77de615e83, },
		{ 0x391fd8c73ce1039b, 0xdb8bf98ad8446656, 0x28ec3eeb0970f947, 0x19f2ec31b50b3737, },
		// Case [593]:
		{ 0x0b9af2609d39afcc, 0x957a615576d7620a, 0xbcc75d020ea09c45, 0x286b9c6381700288, },
		{ 0xb7eee778bd0e56ae, 0xdd3d093e95e730b1, 0x99c91cfc26009103, 0x2258a7c8e168da31, },
		// Case [594]:
		{ 0xb6c422d9080c3f12, 0x89a1ac5031c35ee1, 0x059ae2da709879d4, 0x1c4e5ed7db96db52, },
		{ 0x4817ac3a6075b648, 0x19a997815df572d5, 0xd3437bec2537aa61, 0x07de921833ade188, },
		// Case [595]:
		{ 0xc04912092a4d2abd, 0xd59457b96630e0a5, 0x93b880784ff5fbc5, 0x27141679bb9260a6, },
		{ 0xb22a23959b86bcf4, 0xf62cff0d0b73acc2, 0xea75c346b25f94bf, 0x1af9ca043ea826fc, },
		// Case [596]:
		{ 0x8b49eba02bf085fe, 0xb5d019ce7dd4144a, 0x6a74fdbe7cdd1901, 0x15e337c65fa58edb, },
		{ 0xd78b27fcf3bdf739, 0x50827b7e9d572a54, 0x8f6a2ab89ececbbb, 0x1d29eae7aa04e668, },
		// Case [597]:
		{ 0x56fd2dc90cae3631, 0x91d88a557c69b2a9, 0xeca89f5114f1e7f0, 0x08256792218c8227, },
		{ 0x012ba29f99234f56, 0xfd3176122fb3b173, 0x26359287121cd8df, 0x1139b58e2f1e223f, },
		// Case [598]:
		{ 0x9ee7ed1bca5185da, 0x5e83367204ee6720, 0xacd3928ffb5a57de, 0x0c08d19af9c30a31, },
		{ 0xffc45a4b5bb402e4, 0x01c85eba71f27cc2, 0x1d31737ca83c6377, 0x23f6f1f8cf55e9ff, },
		// Case [599]:
		{ 0xd0f9d2b60709b6fa, 0xac29246f93c24a1b, 0x70f237d2a0aa98ef, 0x1919839ad91604c3, },
		{ 0x37f352fa481206a7, 0x7e456703743011e9, 0x72f7e182c230dfd1, 0x1bc91f276c1d3757, },
		// Case [600]:
		{ 0x44c77ff6c3561a41, 0xf49375acb5958bf9, 0x9f0ea893ddbb0572, 0x15bf65b02b92f40b, },
		{ 0xe62612d532cfa5fb, 0x2c62158780a76035, 0x233b65961df2a21c, 0x237d10e7b8b53096, },
		// Case [601]:
		{ 0x32e3a7c75ef033b5, 0x202d335af7bd2cf0, 0xb22def001acc797b, 0x122e02f2e0169809, },
		{ 0xbdd5754ed4cfeb41, 0x4e58b8366ae9d076, 0x52c8fd33db00f083, 0x046d9862e10601af, },
		// Case [602]:
		{ 0xfb39977305182469, 0x6a21f5176d380141, 0x654e718605211f7f, 0x12075100dddb8098, },
		{ 0x8de7671c20130631, 0x12927f944054d499, 0x3899c28af1105507, 0x2ac6c54c0d0fbf0b, },
		// Case [603]:
		{ 0x8d00b72d8adf0878, 0x1bbef018a63f50f6, 0xf01f73d0cc60b15f, 0x2dadbbb8fecf5ccd, },
		{ 0xa825c9772f26197e, 0xec78e10381663ee9, 0x867e3babd754bd88, 0x247b276520987a6c, },
		// Case [604]:
		{ 0x3009edcd62ea8b71, 0x8092ec0cee24c9fa, 0x375e7cfe7b89fa0d, 0x14334ece05a631ab, },
		{ 0xa018aea1905d5ae9, 0xb41f91991f6b7b97, 0xa7c4f8920b0fb3df, 0x013c4c0e857997af, },
		// Case [605]:
		{ 0x0f6de08b34e3942c, 0x5ba5479d8714a09f, 0xf7d44aca57b17436, 0x09a51856d49ec654, },
		{ 0xeca292b492afcb53, 0x5cce9cc21d8b1b76, 0xd4a71989e28dc23d, 0x0ff9267e5ec35858, },
		// Case [606]:
		{ 0xac1f685bb8f6715b, 0x5ce9de018f4a4647, 0x8dbc63cd3d811ed0, 0x048e8feea9b82852, },
		{ 0xf0c096c477f70cb1, 0x17ce1344cad4d4db, 0xccbb0dc875917741, 0x14705bafc4e091fd, },
		// Case [607]:
		{ 0x730a76253c9b07f6, 0xa8fa4c13e7fa4e89, 0xff10980957022eca, 0x204ba6f18193f747, },
		{ 0xa2cda61da604591d, 0xfcd21b86f492a268, 0xa3b0c81a5b9f1c3f, 0x2064f5be8168aba4, },
		// Case [608]:
		{ 0xd0c9a0d174df130e, 0x9bff4fa82b79fde5, 0x742e4f811ea2c037, 0x0079e1be1622edc5, },
		{ 0x968a41e13b2817d9, 0x9f9b4f09e8e153c8, 0x06d918100f3465da, 0x1971c273c1b1e650, },
		// Case [609]:
		{ 0x1ffae4d7683f637a, 0x4e8d4dbf4360c81d, 0x305ab720ee4c7f41, 0x27e48eabb0ef3b22, },
		{ 0x190bf82b027b6f8f, 0xcb2affdbabab2575, 0x131bb2060806b196, 0x1ca6db6b13881431, },
		// Case [610]:
		{ 0x354372d999881d5a, 0x4767215f659c91ba, 0x45ae416a6b357627, 0x15571becc7f5454e, },
		{ 0xe99f915e309702b7, 0xc3af5163079a8fd8, 0xf7f180820b59e65b, 0x0d22e8117a09658d, },
		// Case [611]:
		{ 0x01f7f8cdd316655e, 0xedddbd2ac1df4f51, 0x4af91ca7192eec4a, 0x2e6a4545ebf7c2e4, },
		{ 0xef2ac52b3658402d, 0x304dbacf42ad39ac, 0xa4a079eac3332c5e, 0x1e46f9989e7a4fb9, },
		// Case [612]:
		{ 0x57492867f8f6bca5, 0x08606cbf8a075244, 0xb1932cdf6f9e9592, 0x2de19fcc78800027, },
		{ 0x53d268e1db4983ed, 0x4bcab4cfe7d9568b, 0x1919dc09d8f09c44, 0x1a780c74431c6b9f, },
		// Case [613]:
		{ 0x86b113f3209d55f2, 0xf3c4bdd53d6382ca, 0x9fc2d62cb14446e8, 0x2e1ca8efd1876e20, },
		{ 0xd5c69307e193c011, 0x331032e7a8ba6b24, 0x35a62cc69651af5c, 0x290285b258860667, },
		// Case [614]:
		{ 0xc6177ac00ebad368, 0xf03cf8f23befc4d7, 0x718e733ca2ca7c8a, 0x154b3f85eaed8b65, },
		{ 0xe2ba500f195a2761, 0xd2d46be39b380d2a, 0x0f3034639cafa26a, 0x19c1fe9a401174e4, },
		// Case [615]:
		{ 0xcd0ba2a2cf6373bd, 0xa5a50503860d20c5, 0x7bac3df18d8eaeb2, 0x29e58f39555d9dde, },
		{ 0x2dbc786f25012c85, 0x84a7cdb40a0e2f10, 0x977d5d3e22b5399f, 0x0614bc05ef8173d9, },
		// Case [616]:
		{ 0x37ff518e57b4c3f0, 0x504cd2d86a12c7d9, 0xd798fb36ef7c0681, 0x032d32032e52103a, },
		{ 0xaa6f0477c1d00525, 0xf11e6807d7cfba68, 0xb3754777f47b718b, 0x034054e1f9d0d3ad, },
		// Case [617]:
		{ 0x2cec650e1a245a3a, 0x5dc7ff12d20888d0, 0x105e39dc174015d6, 0x281de0191d30af73, },
		{ 0x566c6082873eb889, 0x593aa8ec7f5e466d, 0x974bf509a38ad2d1, 0x077516e78e0052ba, },
		// Case [618]:
		{ 0x33e1ffdcf70c808f, 0xbb062bf0afe14191, 0x4281645d290607ea, 0x0f7e76af800ebab1, },
		{ 0x0cf27d564abe8e37, 0xe1af377e21c98eb4, 0xcdb98262c8240fa9, 0x1e7034f81738642a, },
		// Case [619]:
		{ 0x5c014d46283f75b3, 0x47501f6f77a588a7, 0x4dd338a2bca98195, 0x27ea405bdfc6557a, },
		{ 0x2add9d2037c30ded, 0x3be2a4245a229834, 0x8c6f70f694c19382, 0x13e5d44c7be47017, },
		// Case [620]:
		{ 0x0c825c621c7ac22b, 0xd395ac82381491a8, 0xdab63fb05d31edca, 0x0570af543efefdfd, },
		{ 0x8b5bfdde8c95253e, 0x2dcf47762e532dc1, 0x6b02c6c54c013f4a, 0x15334d82a16f9e39, },
		// Case [621]:
		{ 0x6ebaec4c46692bfe, 0x894b0a229c8e89f5, 0x78a413cede7a45cd, 0x027a797e00143024, },
		{ 0x341ff3d13498ffdf, 0xe5578093f0dcb4fc, 0xbd4899378f8b513e, 0x174788fc493aebcd, },
		// Case [622]:
		{ 0x1719b36bace81516, 0x43554a8d3c7e41d9, 0x4966a517687fc532, 0x1dd0e283a8ef7d0f, },
		{ 0xcb6832dc33bd67ea, 0x58cf251c84abcd9b, 0xa70f84d544c46299, 0x13d9d6b2ebce6a8d, },
		// Case [623]:
		{ 0xc2d8be6c59979242, 0xb73ee5bccbb43a05, 0x869df6dcde2673e5, 0x2006444695987560, },
		{ 0xd8a2f37513ff879e, 0x6b29e74b1b2399a9, 0xac4dfebee81b978e, 0x2984f01d3a52296b, },
		// Case [624]:
		{ 0x08831d24bb1b6cb6, 0xff3f6d83ee713940, 0x437afe2c2969bea4, 0x271926392e5f1c94, },
		{ 0xd3fa40ce637d62b0, 0x8ceb1042c65181f7, 0x6c9f3ed62448952f, 0x2a7dd93a7a267895, },
		// Case [625]:
		{ 0x76935a8b54cabf8e, 0x8d6e1f00cc82f001, 0x9a8c20ea26b33b47, 0x1b607ed2f130580d, },
		{ 0x6ebb7f0e3524ef9c, 0xadbc8d2f3bfb1965, 0xf1c1aeaa3223c7a0, 0x29176963e194ab64, },
		// Case [626]:
		{ 0x4b0487e63df03e0a, 0x95c10d62b8b98178, 0x9e55c23871cfdfe4, 0x0b7a6e33808d217a, },
		{ 0x3e21b64b151aeb4a, 0x22f3e6fa40a9996e, 0x8e61e001aa7393f7, 0x037b3c4fb666722d, },
		// Case [627]:
		{ 0x236ecb1ef872cbc9, 0x599b79edef17cf70, 0xab80cd1670403943, 0x28ac790d462bb345, },
		{ 0x2506be53fbd10c56, 0x5e6cc07bd8eee235, 0x2ec28bd4530564f4, 0x28a0588c37e76061, },
		// Case [628]:
		{ 0x6c3077231226bb94, 0xc498be314210180c, 0x2f932f7913095515, 0x2f8d745b1b4750fd, },
		{ 0x9db0aae98327ce90, 0xac2e42859cb0170b, 0x25076d99ca0f799f, 0x00ddb8080fdac4c4, },
		// Case [629]:
		{ 0x2eecb7a7d56d71be, 0x9523956d8bc68409, 0xd2f3b82eef613507, 0x2a3ef20e60142f17, },
		{ 0x2f3fa5956aaf4319, 0x74679badf2576f1c, 0x6dbacfef011953fd, 0x1381fd2294de53ae, },
		// Case [630]:
		{ 0xb988cb638c71a0f0, 0x772d067489d42672, 0xb224697c2c6536cf, 0x08119b14b83922e4, },
		{ 0x1c895eaeb18ced55, 0x1d9a3b0dca796dd5, 0xbd817738f4829546, 0x06e9017d3c80c987, },
		// Case [631]:
		{ 0x614a52d84ce73205, 0xc83d91e7ddfd5110, 0x2739a275bc722c8c, 0x1a4bae6c9cf73ea2, },
		{ 0x7ef202af969ac673, 0x88446d77b5c2bd4e, 0x9920fcfda96598b7, 0x05e2811cc1edb29f, },
		// Case [632]:
		{ 0x2d8d94cdb384d1be, 0x250046c09d532631, 0x8be3a7d7f23e362c, 0x1d659aebe4b37b88, },
		{ 0x6fd847385bb20ce1, 0xe207e18068fa899e, 0x7cb718a1486c5894, 0x12b03af11f01a8ba, },
		// Case [633]:
		{ 0x2406af4c03969f8f, 0x564458d95f732aae, 0xb96730479f170760, 0x28e2fb92bf6da4e6, },
		{ 0x15e54ec2c7bab02e, 0xa490aaa034b991fc, 0xcff35fbbacc3324b, 0x148aad92ac8603f8, },
		// Case [634]:
		{ 0x6311d47b8778aa68, 0x786ede8e6e14b7c6, 0x87729990456c9685, 0x10f4ec3ad6f3ed33, },
		{ 0x638d10c54284c96e, 0x9c64a499dadb4237, 0x32ad7921eb9514fd, 0x11e36a835b7e39e5, },
		// Case [635]:
		{ 0x05272ae1bcddc2d8, 0x3c595de6e0aa51c8, 0x66504d4d34346e0a, 0x2ad366d904191078, },
		{ 0x93a3ba4890059f56, 0xbe1af57d49d74f28, 0xbfd28d15bd53e9d7, 0x0c6f6f75cd60685a, },
		// Case [636]:
		{ 0x3ca02ad24c6dac81, 0x0cd8f80351724d31, 0xe43d3379db0f2e8f, 0x02f1dc29a06c64c9, },
		{ 0x58a9a659eae1044e, 0x314a0a383069dad8, 0xd4086962c4ee6ba2, 0x0c4f96fef3b3918f, },
		// Case [637]:
		{ 0x47b7f020652da64e, 0x74f173f37d0e4a17, 0xcb37cfb64ddab080, 0x20086a672c397e65, },
		{ 0x40a6183d357125e7, 0x7346182b6501f5a3, 0x46473e83a7e795f8, 0x1675bada1a25fced, },
		// Case [638]:
		{ 0x1f36110ca2ee9076, 0x458c3cd8f90c825c, 0xec74ba22c0b7af9d, 0x0ef2861f4ec9ba5f, },
		{ 0x68f25368fac5c845, 0x090fd6654aa3b254, 0x8de9d0d3c05c1739, 0x0295bfd58fa469f4, },
	};

	uint64_t i = 0, j = 0;
	Fr* x = NULL;
	Fr* y = NULL;
	Fr t = { 0 };
	Fr t2 = { 0 };
	bool bRet = false;


	for (i = 0; i < _FR_INV_ARR_CASE; i++, j++)
	{
		printf("Calculating case [%02d]: ", j);
		x = arr + i * 2;
		y = arr + i * 2 + 1;
		FrIntoMontg(&t, x);  // Convert to montgomary field
		bRet = FrInverse(&t2, &t);
		if (!bRet)
		{
			printf("Failed 1!\n");
		}
		else
		{
			FrFromMontg(&t, &t2);  // Convert from montgomary field
			bRet = FrEqual(&t, y);
			if (!bRet)
			{
				printf("Failed 2!\n");
			}
			else
			{
				printf("Success!\n");
			}
		}
	}
}

static void TestFrFromBe()
{
	uint8_t byte = 0;
	uint8_t bytes[FR_SIZE] = { 0 };
	uint8_t i = 0;
	Fr elem = { 0 };
	uint8_t* ptr = NULL;
	bool bFlag = false;

	for (i = 0; i < FR_SIZE; i++)
	{
		bytes[i] = i;
	}
	puts("Original data:");
	for (i = 0; i < FR_SIZE; i++)
	{
		printf("%02x", bytes[i]);
	}
	puts("");

	FrReadFromBe(&elem, bytes);

	puts("Converted to Fr:");
	//FrPrintAsBigNum(&elem);

	// This one should be equal to original data
	HexPrintInBigNum(elem.u8, FR_SIZE);

	ptr = (uint8_t*)(elem.u8);
	for (i = 0; i < FR_SIZE; i++)
	{
		byte = ptr[FR_SIZE - 1 - i];
		if (bytes[i] != byte)
		{
			printf("Not equal at index [%d]!\n", i);
			bFlag = true;
			break;
		}
	}
	if (!bFlag)
	{
		puts("Convert success!");
	}
}

static void TestFrInv2()
{
	uint64_t i = 0, j = 0;
	const Fr* x = NULL;
	Fr* y = NULL;
	Fr t = { 0 };
	Fr t2 = { 0 };
	bool bRet = false;


	for (i = 0; i < 2; i++)
	{
		printf("Calculating case [%02d]: ", i);
		
		x = &g_ConstM[0][0][i];
		FrInverse(&t, x);

		FrPrint(&t);
	}
}

int main()
{
	MyPrint("Begin test...\n");

	//TestFrCopy();
	//TestGetStringLength();
	//TestConvertStringToFr();
	//TestPoseidonHash();
	//TestModulusAndGen();
	//TestFrAdd();
	//TestFrAdd2();
	//TestFrMul();
	//TestBnMul();
	//TestBnMul2();
	//TestBnReduce();
	//TestComplementCode();
	//TestMontgReduce();
	//TestFrRandGen();
	//TestFrMul2();
	//TestFrSquare();
	//TestMontg();
	//TestMontgReduce2();
	TestPoseidonHash2();
	TestPoseidonHash3();
	//TestGenRoundConstantMain();
	//TestGenRoundConstDemo();
	//TestFrInv();
	//TestMontg2();
	//TestFrFromBe();
	//TestFrInv2();

	MyPrint("Finished test!\n");

	return 0;
}

