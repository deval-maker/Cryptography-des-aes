#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/des.h>

#define USAGE   "Usage: desss <input file> <encryption file> <decryption file> <key String>\n"
#define DES_BLOCK_SIZE 8

int main(int argc, char **argv)
{
  int keylength,i;
  FILE *in,*out,*encr,*decr;
  char ch;

  if (argc != 5) {
      printf(USAGE);
      return(1);
  }

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

  const size_t encslength = (((inputslength + DES_BLOCK_SIZE) / DES_BLOCK_SIZE) * DES_BLOCK_SIZE );
  
  unsigned char enc_out[encslength];
  unsigned char dec_out[encslength];
  unsigned char des_input[encslength];
  memset(enc_out, '\0', sizeof(enc_out));  // NULL character paddings
  memset(dec_out, '\0', sizeof(dec_out));
  memset(des_input, '\0', sizeof(des_input));
  
  // Get Input 
  for (i=0; i<inputslength;i++) {
      des_input[i] = fgetc(in);
  }

  DES_cblock key; 
  //DES_random_key (& key); // random number algorithm generated 64 random bits 
  DES_string_to_key (argv[4], & key) ; // string generated key 
  DES_key_schedule schedule; 
  DES_set_key_checked (& key, & schedule); 
  DES_cblock iv_enc,iv_dec; 

  RAND_bytes(iv_enc, sizeof(DES_cblock));
  memcpy(iv_dec, iv_enc, sizeof(DES_cblock));

  DES_ncbc_encrypt (des_input, enc_out, strlen (des_input), & schedule, & iv_enc, DES_ENCRYPT); 
  encr = fopen(argv[2], "wb+");
  fwrite(enc_out, sizeof(unsigned char), sizeof(enc_out), encr);
  fclose(encr);
  printf("Encryption Done. \n");
   

  DES_ncbc_encrypt (enc_out, dec_out, strlen (des_input), & schedule, & iv_dec, DES_DECRYPT);
  decr = fopen(argv[3], "wb+");
  fwrite(dec_out, sizeof(unsigned char), inputslength, decr);
  fclose(decr);
  printf("Decryption Done. \n");

    return 0;
}
