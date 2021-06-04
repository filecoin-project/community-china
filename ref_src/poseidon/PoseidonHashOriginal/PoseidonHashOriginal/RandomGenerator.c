
#include "RandomGenerator.h"



// Each time. we generate 64KB random data
#define RANDOM_POOL_SIZE (64 * 1024) //  64KB

static uint64_t m_ctr;
static uint64_t m_seed;
static uint32_t m_rand_idx;
static uint8_t  m_pre_dgst[SHA256_DIGEST_LENGTH];
static uint8_t  m_rand_pool[RANDOM_POOL_SIZE];
static bool     m_is_rand_init = false;


// Generate a random data pool
static void populate_pool()
{
	uint32_t i = 0;

	for (i = 0; i < RANDOM_POOL_SIZE; i += SHA256_DIGEST_LENGTH)
	{
		m_ctr += 1;

		// We then hash the counter
		sha256(m_pre_dgst, SHA256_DIGEST_LENGTH, m_pre_dgst);

		// Save the ctx value as random data
		Memcpy(m_rand_pool + i, m_pre_dgst, SHA256_DIGEST_LENGTH);
	}

	// Reinitializing the index of the first
	// available pseudo-random byte
	m_rand_idx = 0;
}

static bool prng_seed(uint64_t seed)
{
	bool ret = false;
	uint32_t i = 0;
	uint8_t rand = 0;
	uint8_t tmp_seed[4] = { 0 };


	if (!seed)
	{
		// Strongly recommanded that user should use the specify seed to init this instead of a rand seed

		// Using random seed in range 0 ~ 0x7FFFFFFF
		GetRawRandom(tmp_seed, 4);
		m_seed = *((uint32_t*)tmp_seed);
		m_seed &= 0x7FFFFFFF;
	}
	else
	{
		m_seed = seed;
		ret = true;
	}

	// ctr is initialized to all-zeroes
	m_ctr = 0;

	// Generate first dgst as a new seed
	sha256((const uint8_t*)&m_seed, sizeof(m_seed), m_pre_dgst);

	// We are now ready to fill the pool with
	// cryptographically secure pseudo-random
	// values.
	populate_pool();

	return ret;
}

// Init the random generator with the [seed]
void init_rand(uint64_t seed)
{
	m_is_rand_init = true;
	Memset(m_pre_dgst, 0, SHA256_DIGEST_LENGTH);
	prng_seed(seed);
}

// Return [len] bytes of random data and saved in [buf]
void get_rand_bytes(void* buf, const uint32_t len)
{
	uint32_t sofar = 0, available = 0;
	uint32_t tmpR = 1;
	uint8_t *buffer = NULL;

	if (!buf || !len)
	{
		return;
	}

	buffer = (uint8_t*)buf;
	if (!m_is_rand_init)
	{
		MyPrint("Random utils is not initialized, please initialize it first!");
		
		// We just use a fake rand
		GetRawRandom(&tmpR, sizeof(tmpR));
		init_rand(tmpR);
	}

	do
	{
		if (m_rand_idx + (len - sofar) >= RANDOM_POOL_SIZE)
		{
			// We don't have enough bytes ready in the pool,
			// so let's use the available ones and repopulate !
			available = RANDOM_POOL_SIZE - m_rand_idx;
			Memcpy(buffer + sofar, m_rand_pool + m_rand_idx, available);
			sofar += available;
			populate_pool();
		}
		else
		{
			available = len - sofar;
			Memcpy(buffer + sofar, m_rand_pool + m_rand_idx, available);
			m_rand_idx += available;
			// This will trigger a loop exit
			sofar = len;
		}

	} while (sofar < len);
}

