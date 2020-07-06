#include <cs50.h>
#include <stdio.h>

int main(void) {
    //variables
    long number = get_long("Enter Credit Card Number: ");
    long tester = number;
    int length = 0;
    bool boo = false;

    //getting length of number
    while (tester != 0) {
        length++;
        tester /= 10;
    }

    //repeating equation
    int eq = (number%100000000000000);

    //type of card checker (main code)
    if (length == 15) {
        printf("%i\n", length);
        printf("American Express\n");
        boo = true;
    }
    else if (length == 13) {
        printf("Visa\n");
        boo = true;
    }
    else if (length == 16 && (eq%10 == 4)) {
        printf("Visa\n");
        boo = true;
    }
    else if (length == 16 && ((eq == 51) || (eq == 53) || (eq == 53) || (eq == 54) || (eq == 55))) {
        printf("MasterCard\n");
        boo = true;
    }

    //invalid output
    else {
        printf("%i\n", length);
        printf("Invalid Card\n");
        boo = false;
    }
}
