#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#define USAGE   "Usage: aes <input file> <encryption file> <decryption file> <key length [only 128 or 192 or 256!]> \n"

int main(int argc, char **argv)
{
    int keylength,i;
    FILE *in,*out,*encr,*decr;
    char ch;
    
    if (argc != 5) {
        printf(USAGE);
        return(1);
    }

    keylength = atoi(argv[4]);
    /* generate a key with a given length */
    unsigned char aes_key[keylength/8];
    memset(aes_key, 0, keylength/8);
    if (!RAND_bytes(aes_key, keylength/8))
        exit(-1);

    // buffers for encryption and decryption
    
    size_t inputslength = 0;
    in = fopen(argv[1], "rb");
    if (!in) {
        printf("File not found %s\n", argv[2]);
        return(1);
    }
    fseek(in, 0L, SEEK_END);
    inputslength = ftell(in);
    rewind( in );

    const size_t encslength = (((inputslength + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE );
    
    unsigned char enc_out[encslength];
    unsigned char dec_out[encslength];
    unsigned char aes_input[encslength];
    memset(enc_out, '\0', sizeof(enc_out));  // NULL character paddings
    memset(dec_out, '\0', sizeof(dec_out));
    memset(aes_input, '\0', sizeof(aes_input));
    
    // Get Input 
    for (i=0; i<inputslength;i++) {
        aes_input[i] = fgetc(in);
    }

    unsigned char iv_enc[AES_BLOCK_SIZE], iv_dec[AES_BLOCK_SIZE];
    RAND_bytes(iv_enc, AES_BLOCK_SIZE);
    memcpy(iv_dec, iv_enc, AES_BLOCK_SIZE);
    
    //Encryption 
    AES_KEY enc_key;
    AES_set_encrypt_key(aes_key, keylength, &enc_key);
    AES_cbc_encrypt(aes_input, enc_out, encslength, &enc_key, iv_enc, AES_ENCRYPT);

    encr = fopen(argv[2], "wb+");
    fwrite(enc_out, sizeof(unsigned char), sizeof(enc_out), encr);
    fclose(encr);
    printf("Encryption Done. \n");

    // Decryption 
    AES_KEY dec_key;
    AES_set_decrypt_key(aes_key, keylength, &dec_key);
    AES_cbc_encrypt(enc_out, dec_out, encslength, &dec_key, iv_dec, AES_DECRYPT);

    decr = fopen(argv[3], "wb+");
    fwrite(dec_out, sizeof(unsigned char), inputslength, decr);
    fclose(decr);
    printf("Decryption Done. \n");

    return 0;
}
