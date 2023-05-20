#include "CRUD.h"
#include "setting.h"

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a given month
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 1 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month];
}

// Function to display the calendar for a specific month
void displayCalendar(int month, int year) {
    // Check if the month is valid
    if (month < 0 || month >= 12) {
        printf("유효하지 않은 월입니다.\n");
        return;
    }
    

    // Calculate the number of days in the month
    int daysInMonth = getDaysInMonth(month, year);

    // Display the month and year
    printf("       %d년 %d월\n", year, month + 1);
    printf("--------------------\n");
    printf(" 일 월 화 수 목 금 토\n");

    // Calculate the weekday of the first day of the month
    int weekday = 0; // 0: Sunday, 1: Monday, ..., 6: Saturday
    int firstDayOfWeek = (weekday + 1) % 7;

    // Print leading spaces
    for (int i = 0; i < firstDayOfWeek; i++) {
        printf("   ");
    }

    // Print the days of the month
    for (int day = 0; day < daysInMonth; day++) {
        // Check if the day is fully booked for reservations
       // int dateIndex = day - 1;
        if (dates[month][day].isFull == 1) {
            printf("    ");
        } else {
            printf("%3d ", day+1);
        }

        // Move to the next line after Saturday
        if ((firstDayOfWeek + day+1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}
