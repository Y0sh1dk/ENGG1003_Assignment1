//TODO: Add user interface that allows user to pick which cipher method to use and to input a key
//TODO: Add math library somehow
//TODO: add arguments to functions



// Function Prototypes:
int rotation_cipher_decrypter();
int rotation_cipher_encrypter();
int substitution_cipher_encrypter();
int substitution_cipher_decrypter();

void array_zeroer(int *x, int N);
int array_length(int *x);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    printf("Please select an option: \n");
    printf("~~~~~~~~~~Rotation Cipher~~~~~~~~~~ \n");
    printf("a) Encryption with a rotation cipher given plain text and key: \n");
    printf("b) Decryption with a rotation cipher given cipher text and key: \n");
    printf("b) Decryption with a rotation cipher given cipher text and NO key: \n\n");
    printf("~~~~~~~~~~Substitution Cipher~~~~~~~~~~ \n");
    printf("c) Encryption with a substitution cipher given plain text and key: \n");
    printf("d) Decryption with a substitution cipher given cipher text and key: \n\n");
}



/*
 *  Function Name: rotation_cipher_encrypter
 *
 *  Takes a input.txt file and outputs a encrypted.txt file
 */
int rotation_cipher_encrypter() {

}


/*
 *  Function Name: rotation_cipher_decrypter
 *
 *  Takes a encrypted.txt file and outputs a decrypted.txt file
 */
int rotation_cipher_decrypter(){

}

/*
 *  Function Name: substitution_cipher_encrypter
 *
 *  Takes a input.txt file and outputs a encrypted.txt file
 */
int substitution_cipher_encrypter() {

}



/*
 *  Function Name: substitution_cipher_decrypter
 *
 *  Takes a input.txt file and outputs a encrypted.txt file
 */
int substitution_cipher_decrypter() {

}



/*
 *  Function Name: array_zeroer
 *
 *  Takes arguments array name and length to zero
 * array_zeroer(arrayName, arrayLength)
 */
void array_zeroer(int *x, int N) {
    int i;
    for(i = 0; i < N; i++) {
        x[i] = 0;
    }
    return;
}


/*
 *  Function Name: array_length
 *
 *  Takes arguments array name
 * array_length(arrayName)
 */
int array_length(int *x) {
    int n;
    n = sizeof(x);
    return n;
}