#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//function declarations
bool checker(string key);
string encrypt(int x, string y);

//main
int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./Caesar key\n");
    }
    else if (checker(argv[1])) {
        string text = get_string("plaintext: ");
        printf("ciphertext: %s\n", encrypt(atoi(argv[1]), text));
    }
    else {
        printf("Usage: ./Caesar key\n");
    }
}

//checks to make sure key is only integers
bool checker(string key) {
    bool error = true;
    for (int i = 0; i < strlen(key); i++) {
        if (key[i] < 48 || key[i] > 57) {
            error = 0;
        }
        if (!error){
            return false;
        }
    }
    return true;
}

//encrypts string text using key
string encrypt(int x, string y) {
    string pi = "";
    pi = y;
    for(int i = 0; i < strlen(y); i ++) {
        if (isupper(y[i])) {
            pi[i] = (y[i] + x + 13) % 26 + 65;
        }
        else if (islower(y[i])) {
            pi[i] = (y[i] + x + 7) % 26 + 97;
        }
        else {
            pi[i] = y[i];
        }
    }
    return pi;
}

