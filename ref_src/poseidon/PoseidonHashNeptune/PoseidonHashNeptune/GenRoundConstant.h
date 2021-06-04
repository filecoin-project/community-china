
#ifndef __GEN_ROUND_CONSTANT_H__
#define __GEN_ROUND_CONSTANT_H__


#include "Utilities.h"
//#include "Poseidon.h"


#define BITS_TO_RESERVED (80)         // Reserved 80 initial bits
#define BITS_TO_DISCARD  (160)        // Discard first 160 generated bits
#define BITS_TO_BUFFER   (100 * 8)    // Buffer bits

// 160 bits are the initialize value and they should be discard when geneerating round constant
#define STATE_POOL_SIZE (BITS_TO_RESERVED + BITS_TO_DISCARD + BITS_TO_BUFFER)  // State pool size in bits

typedef struct _ROUND_STATE_CTX
{
	uint32_t size;                     // Size of [state] in bits
	uint8_t state[STATE_POOL_SIZE / 8];

} ROUND_STATE_CTX, *PROUND_STATE_CTX;

#define MAX_FIELD_ELEM_BYTES (1000)



void TestGenRoundConstantMain();

// Generate one field element with [field_size] bits and return it in [buf]
void GenNextByteBufEx(PROUND_STATE_CTX ctx, uint8_t buf[], uint32_t field_size);

// Initialize the [ctx] with 160 bits initianlize value
void InitGenRoundConstantCtx(PROUND_STATE_CTX ctx,
	uint8_t   field,        // bi,  0  <= i <= 1
	uint8_t   sbox,         // bi,  2  <= i <= 5
	uint32_t  field_size,   // bi,  6  <= i <= 17
	uint32_t  t,            // bi,  18 <= i <= 29
	uint32_t  r_f,          // bi,  30 <= i <= 39
	uint32_t  r_p           // bi,  40 <= i <= 49
);

// Get full round number and partial round number from [arity]
bool GetRoundNumberForArity(uint32_t arity, uint32_t* r_f, uint32_t* r_p);






#endif  // !__GEN_ROUND_CONSTANT_H__
