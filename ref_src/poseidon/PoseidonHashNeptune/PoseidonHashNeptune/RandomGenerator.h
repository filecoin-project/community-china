
#ifndef __RANDOM_GENERATOR_H__
#define __RANDOM_GENERATOR_H__

#include "Sha256.h"
#include "Utilities.h"


// Init the random generator with the [seed]
void init_rand(uint64_t seed);

// Return [len] bytes of random data and saved in [buf]
void get_rand_bytes(void* buf, const uint32_t len);



#endif // !__RANDOM_GENERATOR_H__
