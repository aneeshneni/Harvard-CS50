
#include <cs50.h>

#include <stdio.h>


int main(void) {
    //user input
    int length = get_int("Height: ");

    //main output
    for (int i = 0; i < length; i++) {
        int x = 0;
        while(x < 8-i) {
            printf(" ");
            x++;
        }
        for(int j = 0; j < i+1; j++) {
            printf("#");
        }
        printf("  ");
        for(int j = 0; j < i+1; j++) {
            printf("#");
        }
        printf("\n");
    }
}
