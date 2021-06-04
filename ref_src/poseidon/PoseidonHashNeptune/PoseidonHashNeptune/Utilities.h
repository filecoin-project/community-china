#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Print a message
void MyPrint(const char* msg);

// Print a line
void MyPrintLine();

// Memory set [dst] by [c] for [len] bytes
void Memset(void* dst, uint8_t c, uint64_t len);

// Memory copy from [src] to [dst] with [len] bytes
void Memcpy(void* dst, const void* src, uint64_t len);

// Print raw data in hexadecimal mode 
void HexPrintInRaw(const void* dst, uint64_t len);

// Print big number data in hexadecimal mode 
void HexPrintInBigNum(const void* dst, uint64_t len);

// Get a ASCII string length with null-terminator,
// The return length is not including the null-terminator
uint64_t GetStringLength(const char* str);

// Convert a char to hex, example: 'b' -> 11 
uint8_t CharToHex(const char c);

// Convert a hex to char, example: 11 -> 'b'
char HexToChar(const uint8_t h);

// Convert uint8_t hex to two chars, example: 5a -> "5a"
bool ByteHexToString(uint8_t* dst, const uint8_t src);

// Convert a string representation data in memory representation data
// Example:  "0x1122AABB" or "1122AABB" ->  mem:[BBAA2211]
bool GetRawDataFromHexStringInBigNumRepresentation(uint8_t* dst, const char* src, uint64_t len);

// Get raw random fake data, should not call this function directory
void GetRawRandom(void* buf, uint64_t len);



#endif // !__UTILITIES_H__