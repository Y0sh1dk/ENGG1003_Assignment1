//TODO: Add user interface that allows user to pick which cipher method to use and to input a key
//TODO: Add math library somehow
//TODO: add arguments to functions



// Function Prototypes:
int rotation_cipher_decrypter();
int rotation_cipher_encrypter();
int substitution_cipher_encrypter();
int substitution_cipher_decrypter();

void array_zeroer(int *x, int N);
void string_lowercaser(int *x, int string_size); // (array name, string length)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    char string[] = "thisssss is a TEST string";

    int string_size;
    string_size = sizeof(string);




    int key = 2;

    printf("%d\n", string_size);

    for( int counter = 0; counter < string_size; counter++) { // ONLY WORKS IN LOWER CASE AT THE MOMENT
        int character;
        character = string[counter];
        if( character >= 'a' && character <= 'z') {
            character = character + key;
            if (character > 'z') {
                character = character - 'z' + 'a' - 1;
            }
        }
        string[counter] = character;
    }

    for( int counter = 0; counter < string_size; counter++) { // ONLY WORKS IN LOWER CASE AT THE MOMENT
        int character;
        character = string[counter];
        if( character >= 'a' && character <= 'z') {
            character = character - key;
            if (character > 'z') {
                character = character - 'z' + 'a' - 1;
            }
        }
        string[counter] = character;
    }


    printf("%s", string);
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
    int counter;
    for(counter = 0; counter < N; counter++) {
        x[counter] = 0;
    }
    return;
}



void string_lowercaser(int *x, string_size) {
for(int counter = 0; counter < string_size; counter++) {
    int character;
    character = x[counter];
    if (character >= 'A' && character <= 'Z') {
        character = character + 32;
    }
    x[counter] = character;
}
}