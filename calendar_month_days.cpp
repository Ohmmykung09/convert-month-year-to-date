#include <stdio.h>

int main() {
    int bro[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int a, year;
    scanf("%d %d", &a, &year);

    if (a >= 1 && a <= 12) {
        if (a == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
            printf("29");
        } else {
            printf("%d", bro[a - 1]);
        }
    } else {
        printf("Error");
    }

    return 0;
}

