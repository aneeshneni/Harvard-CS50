#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//function declarations
int count_letters(string x);
int count_words(string x);
int count_sentences(string x);
double level_calculator(int letters, int words, int sentences);
string level_output(double level);

//main
int main(void) {
    string text = get_string("Text: ");
    //printf("%d letter(s)\n", count_letters(text));
    //printf("%d word(s)\n", count_words(text));
    //printf("%d sentence(s)\n", count_sentences(text));
    printf("%s\n", level_output(level_calculator(count_letters(text), count_words(text), count_sentences(text))));
}

//letter counter with string input using char upper OR lower
int count_letters(string x) {
    int letters = 0;
    for(int i = 0; i < strlen(x); i ++) {
        if (islower(x[i]) != 0 || isupper(x[i]) != 0) {
            letters++;
        }
    }
    return letters;
}

//word counter with string input using space as '32'
int count_words(string x) {
    int words = 1;
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] == 32) {
            words ++;
        }
    }
        return words;
}

//sentence counter with string input using . ! ?
int count_sentences(string x) {
    int sentences = 0;
    for(int i = 0; i < strlen(x); i++) {
        if (x[i] == 33 || x[i] == 63 || x[i] == 46) {
            sentences++;
        }
    }
    return sentences;
}

//grade level calculator
double level_calculator(int letters, int words, int sentences) {
    double l = 100.0/words * letters;
    double s = 100.0/words * sentences;
    double level = .0588 * l - 0.296 * s - 15.8;
    return level;
}

//grade level output
string level_output(double level) {
    string output = "";
    int intlevel = round(level);
    if (intlevel < 1) {
        printf("Before Grade 1");
    }
    else if (intlevel >= 16) {
        printf("Grade 16+");
    }
    else {
        printf("Grade %i", intlevel);
    }
    return "";
}
