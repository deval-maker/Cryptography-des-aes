Question: Use DES algorithm available from the standard library, then apply both encryption and
decryption by reading and writing from a file. Explore it by changing the initialization
vector values, input text, modes of operation. Plaintext can be a large file and need not be
a multiple of 64 bit or 128 bit.


This code does DES encryption and decryption both.

Commands to run the program:

For Compilation: gcc desOpenssl.c -lcrypto -lssl -o des
For output: ./des input.txt encrypt.txt decrypt.txt 123

Usage: aes <input file> <encryption file> <decryption file> <key String> 
