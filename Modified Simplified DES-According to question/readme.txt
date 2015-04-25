Question: The IP and IP-1 are cancelled while performing encryption and decryption, the plaintext is
directly used without permutation. S0 and S1 boxes are also swapped. Will it affect the
working of the code? Will we obtain the original plaintext after decryption? Change
SDES code and arrive at a conclusion

Commands to run the program:

For Compilation: gcc modified_sdes.c -lm -o msdes

For Encryption: ./msdes –e input.txt encrypt.txt key_value[0-1023]
For Decryption: ./msdes –d encrypt.txt decrypt.txt key_value[0-1023]

Usage: msdes <-e | -d> <input file> <output file> <key 0-1023>\n
