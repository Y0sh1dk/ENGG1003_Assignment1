// Function Prototypes:
int rotation_cipher_decrypter(char *input_path, char *output_path, int key );
int rotation_cipher_encrypter(char *input_path, char *output_path, int key );

int substitution_cipher_encrypter(char *input_path, char *output_path, char *key);
int substitution_cipher_decrypter(char *input_path, char *output_path, char *key);

float dictionary_compare(char *input_path);
void array_zeroer(int *x, int N); // Not necessary?
void string_uppercaser(char *string, int string_size);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main() {


    char input_path[] = "encrypted.txt";
    char output_path[] = "decrypted.txt";
    int a = 0;
    while( dictionary_compare(output_path) < 0.38 && a <=26) { //above 38%
        rotation_cipher_decrypter(input_path, output_path, a);
        a++;
}

    //rotation_cipher_decrypter(input_path, output_path, 14);





    char altAlphabet[] = {"ZYXWVUTSRQPONMLKJIHGFEDCBA"}; // HAS TO HAVE 26 CHARACTER IN IT OR ELSE WILL GET WACK RESULTS

    //substitution_cipher_encrypter(input_path, output_path, altAlphabet);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



/*
 *  Function Name: rotation_cipher_encrypter
 *
 *  Takes a input text file and outputs a encrypted text file
 */
int rotation_cipher_encrypter(char *input_path, char *output_path, int key ) {
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
        if (c >= 'A' && c <= 'Z') { // Checks if each character is inbetwwen the ASCII values A and Z
            temp = c - 'A' + key;
            if (temp >= 0) {
                c = (temp % 26 + 'A');
            }
            else if (temp < 0) { // Not necessary as there will never be a negative but for consistency between encrypter/decrypter it was added
                c = ((temp +26) % 26 + 'A');
            }
            
        }
        fprintf(output, "%c", c); // prints the encrypted character to file
    }
}


/*
 *  Function Name: rotation_cipher_decrypter
 *
 *  Takes a input text file and outputs a decrypted text file
 */
int rotation_cipher_decrypter(char *input_path, char *output_path, int key ) {
    char c;
    int temp;
    FILE *input;
    FILE *output;
    input = fopen(input_path, "r");
    if (input == NULL) { // incase if incorrect input path, returns 0
        perror("fopen()");
        return 0;
    }
    output = fopen(output_path, "w"); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    while (fscanf(input, "%c", &c) == 1 ) { //While fscanf() is successful, if not successful it wont return 1
        if (c >= 'A' && c <= 'Z') { // Checks if each character is inbetwwen the ASCII values A and Z
            temp = c - 'A' - key;
            if (temp >= 0) {
                c = (temp % 26 + 'A');
            }
            else if (temp < 0) { //Have to have incase temp is negative, Mod is undefined of negative numbers
                c = ((temp + 26) % 26 + 'A');
            }

        }
        fprintf(output, "%c", c); // prints the encrypted character to file
    }
    fprintf(output, "\n");
    fclose(input);
    fclose(output);
}


/*
 *  Function Name: substitution_cipher_encrypter
 *
 *  Takes a input.txt file and outputs a encrypted.txt file
 */
int substitution_cipher_encrypter(char *input_path, char *output_path, char *key) {
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
        if (c >= 'A' && c <= 'Z') { // Checks if each character is inbetwwen the ASCII values A and Z
            c = key[c-65];
        }
        fprintf(output, "%c", c); // prints the encrypted character to file
    }
}



/*
 *  Function Name: substitution_cipher_decrypter
 *
 *  Takes a input.txt file and outputs a encrypted.txt file
 */
int substitution_cipher_decrypter(char *input_path, char *output_path, char *key) {
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
        if (c >= 'A' && c <= 'Z') { // Checks if each character is inbetwwen the ASCII values A and Z
            c = key[c-65];
        }
        fprintf(output, "%c", c); // prints the encrypted character to file
    }

}


/*
 *  Function Name: dictionary_compare
 *
 *  takes a text file and compares it to a 'top 100' word dictionary
 *  outputs a percentage
 *
 *  ABOVE 40% IS GOOD
 */
float dictionary_compare(char *input_path) {
    FILE *input;
    input = fopen(input_path, "r");

    char dictionary[] = {"THEOFANDTOAINFORISONTHATBYTHISWITHIYOUITNOTORBEAREFROMATASYOURALLHAVENEWMOREANWASWEWILLHOMECANUSABOUTIFPAGEMYHASSEARCHFREEBUTOURONEOTHERDONOINFORMATIONTIMETHEYSITEHEUPMAYWHATWHICHTHEIRNEWSOUTUSEANYTHERESEEONLYSOHISWHENCONTACTHEREBUSINESSWHOWEBALSONOWHELPGETPMVIEWONLINEFIRSTAMBEENWOULDHOWWEREMESERVICESSOMETHESECLICKITSLIKESERVICETHANFIND"};
    // Dictionary[] contains top 100 words in one string, jank
    float correct = 0;
    char c[50]; //max word length is 50
    float wordcount = 0;
    float per_correct;
    while (fscanf(input, "%s", &c) == 1 ) {
        wordcount++;
        if (strstr(dictionary, c) != NULL) {
            correct++;
        }
    }
    fclose(input);
    per_correct = correct/wordcount;
    return per_correct;

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
    for (int counter = 0; counter < string_size; counter++) {
        if (string[counter] >= 'a' && string[counter] <= 'z') {
            string[counter] = string[counter] - 32;
        }
    }
}