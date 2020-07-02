#include <cs50.h>
#include <stdio.h>

int main(void) {
    long number = get_long("Enter Credit Card Number: ");
    int tester = number;
    int length = 0;
    bool boo = false;
    while (tester != 0) {
        length++;
        tester /= 10;
    }
    int eq = (number%100000000000000);
    if (length == 15) {
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
    else {
        printf("Invalid Card");
        boo = false;
    }
}
