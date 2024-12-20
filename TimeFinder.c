#include <stdio.h>
#include <string.h>

void printHeader() {
    printf("  _____ _                _____ _                 _       _\n");
    printf(" |_   _(_)_ __ ___   ___|  ___(_)_ __   __| | ___ _ __\n");
    printf("   | | | | '_ ` _ \\ / _ \\ |_  | | '_ \\ / _` |/ _ \\ '__|\n");
    printf("   | | | | | | | | |  __/  _| | | | | | (_| |  __/ |\n");
    printf("   |_| |_|_| |_| |_|\\___|_|   |_|_| |_|\\__,_|\\___|_|\n\n");
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

const char* getMonthName(int month) {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return months[month - 1];
}

const char* getDayOfWeek(int day, int month, int year) {
    const char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
                          "Friday", "Saturday", "Sunday"};
    int daysElapsed = 0;

    for (int y = 1; y < year; y++) {
        daysElapsed += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        daysElapsed += getDaysInMonth(m, year);
    }
    daysElapsed += day - 1;

    return days[daysElapsed % 7];
}

void printCalendar(int day, int month, int year) {
    int daysInMonth = getDaysInMonth(month, year);
    const char* monthName = getMonthName(month);

    const char* firstDayName = getDayOfWeek(1, month, year);
    int firstDay = (strcmp(firstDayName, "Monday") == 0 ? 0 :
                    strcmp(firstDayName, "Tuesday") == 0 ? 1 :
                    strcmp(firstDayName, "Wednesday") == 0 ? 2 :
                    strcmp(firstDayName, "Thursday") == 0 ? 3 :
                    strcmp(firstDayName, "Friday") == 0 ? 4 :
                    strcmp(firstDayName, "Saturday") == 0 ? 5 : 6);

    printf("\n      %s %d\n", monthName, year);
    printf("Mo Tu We Th Fr Sa Su\n");

    for (int i = 0; i < firstDay; i++) {
        printf("   ");
    }

    for (int i = 1; i <= daysInMonth; i++) {
        if (i == day) {
            printf("%2d*", i);
        } else {
            printf("%2d ", i);
        }
        if ((i + firstDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    printHeader();

    char input[20];
    while (1) {
        printf("\nEnter day month year (e.g. 15 3 2024) or 'END' to quit: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "END") == 0) {
            printf("Goodbye!\n");
            break;
        }

        int day, month, year;
        if (sscanf(input, "%d %d %d", &day, &month, &year) == 3) {
            if (month < 1 || month > 12 || day < 1 || day > getDaysInMonth(month, year)) {
                printf("Invalid date. Please try again.\n");
            } else {
                printf("\nDay: %d\n", day);
                printf("Month: %s (%d days)\n", getMonthName(month), getDaysInMonth(month, year));
                printf("Year: %d\n", year);
                printf("Day of the week: %s\n", getDayOfWeek(day, month, year));
                printCalendar(day, month, year);
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}