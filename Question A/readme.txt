Commands to run the program:

For Compilation: gcc D_sdes.c -lm -o Dsdes

For Encryption: ./Dsdes –e input.txt encrypt.txt key_value[0-1023] key_value[0-1023]
For Decryption: ./Dsdes –d encrypt.txt decrypt.txt key_value[0-1023] key_value[0-1023]

Usage: Dsdes <-e | -d> <input file> <output file> <key1 0-1023> <key2 0-1023>
