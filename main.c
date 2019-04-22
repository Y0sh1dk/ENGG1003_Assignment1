// Function Prototypes:
int rotation_cipher_decrypter_file(char *input_path, char *output_path, int key );
int rotation_cipher_encrypter_file(char *input_path, char *output_path, int key );

int substitution_cipher_encrypter(char *string, int string_size, char *key);
int substitution_cipher_decrypter(char *string, int string_size, char *key);

void array_zeroer(int *x, int N); // Not necessary?
void string_uppercaser(char *string, int string_size);

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
    char input_path[] = "encrypted.txt";
    char output_path[] = "decrypted.txt";
    int key = 1;

    rotation_cipher_decrypter_file(input_path, output_path, key);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



/*
 *  Function Name: rotation_cipher_encrypter_file
 *
 *  Takes a input text file and outputs a encrypted text file
 */
int rotation_cipher_encrypter_file(char *input_path, char *output_path, int key ) {
    int temp;
    char c;
    FILE *input;
    FILE *output;
    input = fopen(input_path, "r"); 
    if (input == NULL) { // incase if incorrect input path, returns 0
        perror("fopen()");
        return 0;
    }
    output = fopen(output_path, "w");

    while (fscanf(input, "%c", &c) == 1 ) { //While fscanf() is successful, if not successful it wont return 1
        if (c >= 'A' && c <= 'Z') {
            temp = c - 'A' + key;
            if (temp >= 0) {
                c = (temp % 26 + 'A');
            }
            else if (temp < 0) { // Not necessary as there will never be a negative but for consistency between encrypter/decrypter it was added
                c = ((temp +26) % 26 + 'A');
            }
            
        }
        fprintf(output, "%c", c);
    }
}


/*
 *  Function Name: rotation_cipher_decrypter_file
 *
 *  Takes a input text file and outputs a decrypted text file
 */
int rotation_cipher_decrypter_file(char *input_path, char *output_path, int key ) {
    char c;
    int temp;
    FILE *input;
    FILE *output;
    input = fopen(input_path, "r");
    if (input == NULL) { // incase if incorrect input path, returns 0
        perror("fopen()");
        return 0;
    }
    output = fopen(output_path, "w");

    while (fscanf(input, "%c", &c) == 1 ) { //While fscanf() is successful, if not successful it wont return 1
        if (c >= 'A' && c <= 'Z') {
            temp = c - 'A' - key;
            if (temp >= 0) {
                c = (temp % 26 + 'A');
            }
            else if (temp < 0) { //Have to have incase temp is negative, Mod is undefined of negative numbers
                c = ((temp + 26) % 26 + 'A');
            }

        }
        fprintf(output, "%c", c);
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