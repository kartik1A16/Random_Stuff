#include <stdio.h>
#include <stdlib.h>

void decToBin(int n) {
    if (n == 0) { printf("0"); return; }
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) printf("%d", binaryNum[j]);
}

void decToOct(int n) {
    if (n == 0) { printf("0"); return; }
    int octalNum[100];
    int i = 0;
    while (n > 0) {
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) printf("%d", octalNum[j]);
}

void decToHex(int n) {
    if (n == 0) { printf("0"); return; }
    char hexNum[100];
    int i = 0;
    
    while (n > 0) {
        int temp = n % 16;
        
        if (temp < 10) {
            hexNum[i] = temp + 48;
        } else {
            hexNum[i] = temp + 55;
        }
        
        i++;
        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--) printf("%c", hexNum[j]);
}

int binToDec(long long n) {
    int dec = 0, base = 1;
    while (n > 0) {
        int last_digit = n % 10;
        if (last_digit > 1) return -1;
        dec += last_digit * base;
        base = base * 2;
        n = n / 10;
    }
    return dec;
}

int main() {
    int choice, num;
    long long bnum;

    do {
        printf("BASE CONVERTER\n");
        printf("1. Decimal to Binary\n");
        printf("2. Decimal to Octal\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Binary  to Decimal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Decimal Number: ");
                scanf("%d", &num);
                printf("Binary: ");
                decToBin(num);
                printf("\n");
                break;

            case 2:
                printf("Enter Decimal Number: ");
                scanf("%d", &num);
                printf("Octal: ");
                decToOct(num);
                printf("\n");
                break;

            case 3:
                printf("Enter Decimal Number: ");
                scanf("%d", &num);
                printf("Hexadecimal: ");
                decToHex(num);
                printf("\n");
                break;

            case 4:
                printf("Enter Binary Number: ");
                scanf("%lld", &bnum);
                int res = binToDec(bnum);
                if(res == -1) printf("Invalid binary number.\n");
                else printf("Decimal: %d\n", res);
                break;

            case 0:
                printf("Exit\n");
                break;

            default:
                printf("Invalid, Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}