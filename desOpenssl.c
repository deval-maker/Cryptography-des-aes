#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/des.h>
#include <openssl/rand.h>
#define BUFSIZE 64

int main(void)
{
 unsigned char in[BUFSIZE], out[BUFSIZE], back[BUFSIZE];
 unsigned char *e = out;
 DES_cblock key;
 DES_cblock seed = {0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10};
 DES_key_schedule keysched;
 memset(in, 0, sizeof(in));
 memset(out, 0, sizeof(out));
 memset(back, 0, sizeof(back));
 RAND_seed(seed, sizeof(DES_cblock));
 DES_random_key(&amp;key);
 DES_set_key((C_Block *)key, &amp;keysched);
 /* 8 bytes of plaintext */
 strcpy(in, "HillTown");
 printf("Plaintext: [%s]\n", in);
 DES_ecb_encrypt((C_Block *)in,(C_Block *)out, &amp;keysched, DES_ENCRYPT);
 printf("Ciphertext:");
 while (*e) printf(" [%02x]", *e++);
 printf("\n");
 DES_ecb_encrypt((C_Block *)out,(C_Block *)back, &amp;keysched, DES_DECRYPT);
 printf("Decrypted Text: [%s]\n", back);
 return(0);
}
