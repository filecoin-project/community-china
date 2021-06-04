#ifndef __POSEIDON_H__
#define __POSEIDON_H__


#include "Utilities.h"
#include "PoseidonConstant.h"

// Ref: https://docs.rs/poseidon-rs/0.0.8/src/poseidon_rs/lib.rs.html#67-81
// https://github.com/arnaucube/poseidon-rs



typedef struct _POSEIDON_CTX
{
	uint64_t len;       // length of state
	uint64_t fullR;     // Full rounds
	uint64_t partialR;  // Partial rounds
	Fr state[PARTIAL_ROUND_LEN];

} POSEIDON_CTX;



// Input Fr[len], Output one Fr, len <= PARTIAL_ROUND_LEN
void PoseidonHash(Fr input[], uint64_t len, Fr* output);




#endif // !__POSEIDON_H__
