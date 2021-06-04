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



#endif // !__POSEIDON_CONSTANT_H__
