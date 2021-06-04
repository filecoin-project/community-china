

#ifndef __SHA256_H__
#define __SHA256_H__

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SHA256_DIGEST_LENGTH (32ull)            // SHA256 outputs a 32 uint8_t digest
#define SHA256_BLOCK_SIZE    (64ull)            // Message block size, 64 bytes

#define ROTLEFT(a,b)  (((a) << (b)) | ((a) >> (32-(b))))
#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

#define CH(x,y,z)  (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x)  & (z)) ^ ((y) & (z)))

#define EP0(x)  (ROTRIGHT(x,2)  ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x)  (ROTRIGHT(x,6)  ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))

#define SIG0(x) (ROTRIGHT(x,7)  ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))


typedef struct _SHA256_CTX 
{
	uint8_t   data[SHA256_BLOCK_SIZE];
	uint64_t  datalen;
	uint64_t  bitlen;
	uint32_t  state[8];

} SHA256_CTX;


void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const uint8_t* data, uint64_t len);
void sha256_final(SHA256_CTX *ctx, uint8_t dgst[SHA256_DIGEST_LENGTH]);
void sha256(const uint8_t* data, uint64_t len, uint8_t dgst[SHA256_DIGEST_LENGTH]);



#endif // !__SHA256_H__



