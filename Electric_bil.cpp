#include <stdio.h>

int main() {
    char name[50];
    float unit, bill, surcharge = 0;
    
    printf("Enter your name: ");
    scanf("%s", name);

    printf("\nEnter your units: ");
    scanf("%f", &unit);

    if (unit > 0 && unit <= 100) {
        bill = unit * 0.60;
    } else if (unit > 100 && unit <= 300) {
        bill = 100 * 0.60 + (unit - 100) * 0.80;
    } else if (unit > 300) {
        bill = 100 * 0.60 + 200 * 0.80 + (unit - 300) * 0.90;
    } else {
        printf("Enter how much units you have ...\n");
        return 0;
    }

    if (bill < 50) {
        bill = 50;
    }

    if (bill > 300) {
        surcharge = bill * 0.15;
        bill += surcharge;
    }

    printf("\nMr. %s welcome to WBSEDCL electricity board ", name);
    printf("\nYour surcharge is %.2f", surcharge);
    printf("\nYour bill is %.2f", bill);

    return 0;
}
