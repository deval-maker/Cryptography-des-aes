Question: Explore whether Meet in the Middle Attack applied to Double DES (discussed in Page no.
195 in 5th edition of Stallings) can be applied to your Double Simplified DES code or
differential and linear cryptanalysis (discussed in Page no. 89 in 5th edition of Stallings)
can be applied to Simplified DES code. Check whether it is possible or not through your
code.

Here used input.txt and encrypt.txt are generated from Double simplified DES code. 
encrypt.txt is encrypted cyphertext of input.txt usig key1=12 and key2=25.

Commands to run the program:

For Compilation: gcc meetMAttack.c -lm -o mim

For Output: ./mim input.txt encrypt.txt

Usage: mim <plaintext file> <Cyphertext file>
