
#include "Utilities.h"


// Print a message
void MyPrint(const char* msg)
{
	puts(msg);
}

// Print a line
void MyPrintLine()
{
	const char* msg = "====================================================================";
	puts(msg);
}

// Memory set [dst] by [c] for [len] bytes
void Memset(void* dst, uint8_t c, uint64_t len)
{
	uint64_t i = 0;
	uint8_t* ptr = NULL;

	ptr = (uint8_t*)dst;
	for (i = 0; i < len; i++)
	{
		ptr[i] = c;
	}
}

// Memory copy from [src] to [dst] with [len] bytes
void Memcpy(void* dst, const void* src, uint64_t len)
{
	uint64_t i = 0;
	uint8_t* ptr1 = NULL;
	uint8_t* ptr2 = NULL;

	ptr1 = (uint8_t*)dst;
	ptr2 = (uint8_t*)src;
	for (i = 0; i < len; i++)
	{
		ptr1[i] = ptr2[i];
	}
}

// Print raw data in hexadecimal mode 
void HexPrintInRaw(const void* dst, uint64_t len)
{
	uint64_t i = 0;
	uint8_t c = 0;
	uint8_t* ptr = NULL;

	ptr = (uint8_t*)dst;
	for (i = 0; i < len; i++)
	{
		c = ptr[i];
		printf("%02x", c);
	}
	puts("");
}

// Print big number data in hexadecimal mode 
void HexPrintInBigNum(const void* dst, uint64_t len)
{
	int64_t i = 0;  // Should be signed integer
	uint8_t c = 0;
	uint8_t* ptr = NULL;

	ptr = (uint8_t*)dst;
	printf("0x");
	for (i = len - 1; i >= 0; i--)
	{
		c = ptr[i];
		printf("%02x", c);
	}
	puts("");
}

// Get a ASCII string length with null-terminator,
// The return length is not including the null-terminator
uint64_t GetStringLength(const char* str)
{
	uint64_t strLen = 0;
	uint64_t i = 0;
	uint8_t c = 0;
	const uint64_t MAX_STR_LEN = 0xFFFFFFFF;  // String should not exceed this length
	
	for (i = 0; i < MAX_STR_LEN; i++)
	{
		c = str[i];
		if (c == 0)
		{
			break;
		}
	}

	strLen = i;

	return strLen;
}

// Convert a char to hex, example: 'b' -> 11 
uint8_t CharToHex(const char c)
{
	uint8_t ret = 0;

	if (c >= '0' && c <= '9')
	{
		ret = c - '0';
	}
	else if (c >= 'a' && c <= 'f')
	{
		ret = c - 'a' + 10;
	}
	else if (c >= 'A' && c <= 'F')
	{
		ret = c - 'A' + 10;
	}
	else
	{
		MyPrint("Convert char to hex failed!");
		// Exit
	}

	return ret;
}

// Convert a hex to char, example: 11 -> 'b'
char HexToChar(const uint8_t h)
{
	char ret = 0;

	if (h >= 0 && h <= 9)
	{
		ret = h + '0';
	}
	else if (h >= 10 && h <= 15)
	{
		ret = h - 10 + 'a';
	}
	else
	{
		MyPrint("Convert hex to char failed!");
		// Exit
	}

	return ret;
}

// Convert uint8_t hex to two chars, example: 5a -> "5a"
bool ByteHexToString(uint8_t* dst, const uint8_t src)
{
	bool ret = 0;
	uint8_t hi = 0, lo = 0;
	char c = 0;

	hi = src >> 4;
	lo = src & 0xF;

	c = HexToChar(hi);
	dst[0] = c;

	c = HexToChar(lo);
	dst[1] = c;

	return ret;
}

// Convert a string representation data in memory representation data
// Example:  "0x1122AABB" or "1122AABB" ->  mem:[BBAA2211]
bool GetRawDataFromHexStringInBigNumRepresentation(uint8_t* dst, const char* src, uint64_t len)
{
	bool bRet = false;
	uint64_t i = 0;
	uint8_t c = 0;
	uint8_t* ptr = NULL;
	uint8_t hp = 0, lp = 0;  // high part and low part of a byte in hex
	uint8_t* ptrDst = NULL;


	if ((len & 1) != 0 || !dst || !src)
	{
		// len should be a even number
		return false;
	}

	ptr = (uint8_t*)src;

	// Start with prefix [0x])
	if (len > 2 && (ptr[1] == 'x' || ptr[1] == 'X') )
	{
		ptr += 2;
		len -= 2;
		if (len < 2)
		{
			return false;
		}
	}

	ptrDst = dst + len / 2 - 1;
	for (i = 0; i < len; i += 2)
	{
		hp = CharToHex(ptr[i]);
		lp = CharToHex(ptr[i + 1]);
		c = hp * 16 + lp;
		*ptrDst = c;
		ptrDst--;
	}

	bRet = true;

	return bRet;
}

// Get raw random fake data, should not call this function directory
void GetRawRandom(void* buf, uint64_t len)
{
	uint64_t i = 0;
	uint8_t r = 0;
	uint8_t* ptr = NULL;

	srand((uint32_t)time(NULL));
	ptr = (uint8_t*)buf;
	for (i = 0; i < len; i++)
	{
		r = rand();
		ptr[i] = r;
	}
}
