Question: Extend the code to perform Triple Simplified DES

Commands to run the program:

For Compilation: gcc T_sdes.c -lm -o Tsdes

For Encryption: ./Tsdes –e input.txt encrypt.txt key_value[0-1023] key_value[0-1023] key_value[0-1023]
For Decryption: ./Tsdes –d encrypt.txt decrypt.txt key_value[0-1023] key_value[0-1023] key_value[0-1023]

Usage: Tsdes <-e | -d> <input file> <output file> <key1 0-1023> <key2 0-1023> <key1 0-1023>
