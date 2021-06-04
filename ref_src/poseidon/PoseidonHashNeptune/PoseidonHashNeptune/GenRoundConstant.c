
#include "GenRoundConstant.h"




// Set bit value [bv] to [ctx] at location [loc]
static void SetBit(PROUND_STATE_CTX ctx, uint32_t loc, uint8_t bv)
{
	uint32_t nloc = loc % STATE_POOL_SIZE;
	uint32_t byteIdx = nloc / 8;
	uint32_t bitIdx  = nloc % 8;
	uint8_t* ptr = &(ctx->state[byteIdx]);
	uint8_t t = 1;

	t = t << (7-bitIdx);
	if (bv)
	{
		// Set target bit to 1
		ptr[0] |= t;
	}
	else
	{
		// Set target bit to 0
		t = ~t;
		ptr[0] &= t;
	}
}

// Get bit value at location [loc] from [ctx]
static uint8_t GetBit(PROUND_STATE_CTX ctx, uint32_t loc)
{
	uint32_t nloc = loc % STATE_POOL_SIZE;
	uint32_t byteIdx = nloc / 8;
	uint32_t bitIdx = nloc % 8;
	uint8_t* ptr = &(ctx->state[byteIdx]);
	uint8_t t = 0;
	uint8_t ret = 0;

	t = ptr[0] >> (7 - bitIdx);
	ret = t & 1;

	return ret;
}

// Append bit value [bv] to [ctx] at the end of [ctx]
static void AppendBit(PROUND_STATE_CTX ctx, uint8_t bv)
{
	//ctx->size += 1;
	SetBit(ctx, ctx->size, bv);
	ctx->size += 1;
}

// Append n bits [bv] to [ctx] at the end of [ctx]
// At most append 32 bits for each time
static void AppendNBit(PROUND_STATE_CTX ctx, uint32_t n, uint64_t bs)
{
	int32_t i = 0;
	uint8_t t = 1;
	uint8_t bv = 1;

	for (i = n - 1; i >= 0; i--)
	{
		t = (uint8_t)(bs >> i);
		bv = t & 1;
		AppendBit(ctx, bv);
	}
}

// Generate bit value [bv] and save to [ctx]
static uint8_t GenBit(PROUND_STATE_CTX ctx)
{
	uint8_t bv = 0;
	uint32_t idx = 0;
	uint8_t b[6] = { 0 };
	uint8_t ret = 0;

	idx = ctx->size - 80;

	b[0] = GetBit(ctx, idx + 0);
	b[1] = GetBit(ctx, idx + 13);
	b[2] = GetBit(ctx, idx + 23);
	b[3] = GetBit(ctx, idx + 38);
	b[4] = GetBit(ctx, idx + 51);
	b[5] = GetBit(ctx, idx + 62);

	//b[0] = GetBit(ctx, idx + 80 - 0);
	//b[1] = GetBit(ctx, idx + 80 - 13);
	//b[2] = GetBit(ctx, idx + 80 - 23);
	//b[3] = GetBit(ctx, idx + 80 - 38);
	//b[4] = GetBit(ctx, idx + 80 - 51);
	//b[5] = GetBit(ctx, idx + 80 - 62);

	bv = b[0] ^ b[1] ^ b[2] ^ b[3] ^ b[4] ^ b[5];
	ret = bv;

	AppendBit(ctx, bv);
	return ret;
}

// Generate a valid bit value [bv] and save to [ctx]
static uint8_t GenValidBit(PROUND_STATE_CTX ctx)
{
	uint8_t t = 0;
	uint8_t bv = 0;
	uint8_t ret = 0;

	t = GenBit(ctx);
	while (0 == t)
	{
		t = GenBit(ctx);  // Discard it for its previous bit is 0
		t = GenBit(ctx);
	}

	// Get the valid bit, due to its previous bit is 1
	ret = GenBit(ctx);

	return ret;
}

// Generate next byte value with [bitCnt] bits and return it
static uint8_t GenNextByte(PROUND_STATE_CTX ctx, uint8_t bitCnt)
{
	uint8_t bv = 0;
	uint32_t i = 0;
	uint8_t acc = 0;
	uint8_t ret = 0;

	for (i = 0; i < bitCnt; i++)
	{
		bv = GenValidBit(ctx);
		acc <<= 1;
		if (bv)
		{
			acc += 1;
		}
	}

	ret = acc;
	return ret;
}

// Generate next byte buffer with [byteCnt] bytes and return it in [buf]
static void GenNextByteBuf(PROUND_STATE_CTX ctx, uint8_t buf[], uint32_t byteCnt)
{
	uint8_t bv = 0;
	uint32_t i = 0;
	uint8_t acc = 0;
	uint8_t ret = 0;

	for (i = 0; i < byteCnt; i++)
	{
		bv = GenNextByte(ctx, 8);
		buf[i] = bv;
	}
}

// Generate one field element with [field_size] bits and return it in [buf]
void GenNextByteBufEx(PROUND_STATE_CTX ctx, uint8_t buf[], uint32_t field_size)
{
	uint8_t bv = 0;
	uint32_t i = 0;
	uint8_t acc = 0;
	uint8_t ret = 0;
	uint32_t byteCnt = 0;
	uint32_t bitCnt = 0;
	uint32_t off = 0;

	byteCnt = field_size / 8;
	bitCnt = field_size % 8;

	if (bitCnt > 0)
	{
		bv = GenNextByte(ctx, bitCnt);
		buf[0] = bv;
		//printf("Got one byte (first): %d\n", bv);
		off = 1;
	}
	for (i = 0; i < byteCnt; i++)
	{
		bv = GenNextByte(ctx, 8);
		buf[i + off] = bv;
		//printf("Got one byte: %d\n", bv);
	}
}

// Initialize the [ctx] with 160 bits initianlize value
void InitGenRoundConstantCtx(PROUND_STATE_CTX ctx, 
	uint8_t   field,        // bi,  0  <= i <= 1
	uint8_t   sbox,         // bi,  2  <= i <= 5
	uint32_t  field_size,   // bi,  6  <= i <= 17
	uint32_t  t,            // bi,  18 <= i <= 29
	uint32_t  r_f,          // bi,  30 <= i <= 39
	uint32_t  r_p           // bi,  40 <= i <= 49
)
{
	
	uint8_t bv = 0;
	uint32_t i = 0;
	uint32_t idx = 0;
	uint32_t m1 = 0xFFFFFFFF; // All one in bit
	uint32_t numConst = (r_f + r_p) * t;
	uint32_t elemBytes = field_size / 8 + (field_size % 8) > 0;
	static uint8_t buf[MAX_FIELD_ELEM_BYTES + 2];  // MAX number of bytes for each element in the field

	if (elemBytes >= MAX_FIELD_ELEM_BYTES)
	{
		MyPrint("Elemet size in byte exceed the max element size!");
		return;
	}

	Memset(ctx, 0, sizeof(ROUND_STATE_CTX));
	ctx->size = 0;
	AppendNBit(ctx, 2,  field);
	AppendNBit(ctx, 4,  sbox);
	AppendNBit(ctx, 12, field_size);
	AppendNBit(ctx, 12, t);
	AppendNBit(ctx, 10, r_f);
	AppendNBit(ctx, 10, r_p);
	AppendNBit(ctx, 30, m1);  // bi,  50 <= i <= 79  are set to 1

	for (i = 0; i < 80; i++)
	{
		bv = GetBit(ctx, i);
		//printf("[%02d]: %d\n", i, bv);
	}

	for (i = 0; i < BITS_TO_DISCARD; i++)
	{
		bv = GenBit(ctx);
		//printf("[%02d]: %d\n", i, bv);
	}
}

// Get full round number and partial round number from [arity]
bool GetRoundNumberForArity(uint32_t arity, uint32_t* r_f, uint32_t* r_p)
{
	uint32_t t = arity + 1;
	bool bRet = false;
	if (!r_f || !r_p)
	{
		return false;
	}

	switch(t)
	{
		case 2:
		case 3:
		{
			*r_p = 55;
			bRet = true;
			break;
		}
		case 4:
		case 5:
		case 6:
		case 7:
		{
			*r_p = 56;
			bRet = true;
			break;
		}
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		{
			*r_p = 57;
			bRet = true;
			break;
		}
		case 16:
		case 17:
		case 25:
		{
			*r_p = 59;
			bRet = true;
			break;
		}
		case 37:
		{
			*r_p = 60;
			bRet = true;
			break;
		}
		case 65:
		{
			*r_p = 61;
			bRet = true;
			break;
		}
		default:
		{
			*r_p = 0;
			break;
		}
	};

	if (bRet)
	{
		*r_f = 8;
	}
	return bRet;
}






static void TestBit()
{
	int i = 0;
	uint8_t b = 0;
	ROUND_STATE_CTX ctx = { 0 };

	for (i = 0; i < 100; i++)
	{
		SetBit(&ctx, i, 1);
		b = GetBit(&ctx, i);
		printf("Bit [%d] = %d\n", i, b);
	}
	for (i = 0; i < 100; i++)
	{
		SetBit(&ctx, i, 0);
		b = GetBit(&ctx, i);
		printf("Bit [%d] = %d\n", i, b);
	}

}

static void TestAppendBit()
{
	int i = 0;
	uint8_t b = 0;
	ROUND_STATE_CTX ctx = { 0 };

	for (i = 0; i < 100; i++)
	{
		SetBit(&ctx, i, 1);
		b = GetBit(&ctx, i);
		printf("Bit [%d] = %d\n", i, b);
	}
}

static void TestGenBit()
{
	int i = 0;
	uint8_t b = 0;
	ROUND_STATE_CTX ctx = { 0 };


	InitGenRoundConstantCtx(&ctx, 1, 1, 255, 9, 8, 57);

	for (i = 0; i < 160; i++)
	{
		b = GetBit(&ctx, i);
		printf("Bit [%d] = %d\n", i, b);
	}
}

static void TestEndian()
{
	int i = 0;
	uint8_t b = 1;
	

	// Little endian, the byte [1] is save in menory 0b[1000 0000], instead of 0b[0000 0001]
	// The byte order and the bit order are the same in the same machine
	printf("Bit [%d] = %d\n", i, b);
	
}


void TestGenRoundConstantMain()
{
	//TestBit();
	TestGenBit();
	//TestEndian();
}
