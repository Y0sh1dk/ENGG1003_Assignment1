//TODO: Clean up comments

// Function Prototypes:
int rotation_cipher_decrypter(char *string, int string_size, int key); // (array name, string length, key)
int rotation_cipher_encrypter(char *string, int string_size, int key); // (array name, string length, key)
int substitution_cipher_encrypter(char *string, int string_size, char *key);
int substitution_cipher_decrypter(char *string, int string_size, char *key);
void array_zeroer(int *x, int N); // Not necessary?
void string_uppercaser(char *string, int string_size); // (array name, string length)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main() {
    /*
    printf("Please select an option: \n");
    printf("~~~~~~~~~~Rotation Cipher~~~~~~~~~~ \n");
    printf("a) Encryption with a rotation cipher given plain text and key: \n");
    printf("b) Decryption with a rotation cipher given cipher text and key: \n");
    printf("b) Decryption with a rotation cipher given cipher text and NO key: \n\n");
    printf("~~~~~~~~~~Substitution Cipher~~~~~~~~~~ \n");
    printf("c) Encryption with a substitution cipher given plain text and key: \n");
    printf("d) Decryption with a substitution cipher given cipher text and key: \n\n");
    */
    char string[] = "This IS a TEST string";
    string_uppercaser(string, sizeof(string));
    int key = 6;

    rotation_cipher_encrypter(string, sizeof(string), key);
    rotation_cipher_decrypter(string, sizeof(string), key);

    printf("%s", string);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


/*
 *  Function Name: rotation_cipher_encrypter
 *
 *  Takes arguments (string name, string length, key)
 */
int rotation_cipher_encrypter(char *string, int string_size, int key) {
    for (int counter = 0; counter < string_size; counter++) {
        if (string[counter] >= 'A' && string[counter] <= 'Z') {
            string[counter] = ((string[counter] - 'A' + key) % 26 + 'A');
        }
    }
}

/*
 *  Function Name: rotation_cipher_decrypter
 *
 *  Takes arguments (string name, string size, key)
 */
int rotation_cipher_decrypter(char *string, int string_size, int key){
    for( int counter = 0; counter < string_size; counter++) {
        if( string[counter] >= 'A' && string[counter] <= 'Z') {
            string[counter] = ((string[counter] - 'A' - key) % 26 + 'A');
        }
    }
}

/*
 *  Function Name: substitution_cipher_encrypter
 *
 *  Takes a input.txt file and outputs a encrypted.txt file
 */
int substitution_cipher_encrypter(char *string, int string_size, char *key) {

}



/*
 *  Function Name: substitution_cipher_decrypter
 *
 *  Takes a input.txt file and outputs a encrypted.txt file
 */
int substitution_cipher_decrypter(char *string, int string_size, char *key) {

}



/*
 *  Function Name: array_zeroer
 *
 *  Takes arguments array name and length to zero
 * array_zeroer(arrayName, arrayLength)
 */
void array_zeroer(int *x, int N) {
    for(int counter = 0; counter < N; counter++) {
        x[counter] = 0;
    }
}



void string_uppercaser(char *string, int string_size) {
    for(int counter = 0; counter < string_size; counter++) {
        if (string[counter] >= 'a' && string[counter] <= 'z') {
                string[counter] = string[counter] - 32;
        }
    }
}


