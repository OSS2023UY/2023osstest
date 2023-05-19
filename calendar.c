#include "CRUD.h"
#include "setting.h"

void drawCalendar(day calendar) {
    int mm; // 월
    printf("몇 월 달의 캘린더를 보시겠습니까? ");
    scanf("%d", &mm);

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 각 월의 일수

    printf("     일   월   화   수   목   금   토\n");
    printf("------------------------------------\n");

    int dayOfWeek = 0; // 0부터 6까지, 0은 일요일

    for (int day = 0; day < daysInMonth[mm - 1]; day++) {
        if (dayOfWeek == 0) {
            printf(" ");
        }

        if (day + 1 < 10) {
            printf(" ");
        }

        printf("  %d", day + 1);

        if (dayOfWeek == 6) {
            printf("\n");
        }

        // 예약이 가득 찬 날인 경우 비워져 있는 상태로 표시
        if (calendar[mm - 1][day].full == 1) {
            printf("     ");
        }

        dayOfWeek = (dayOfWeek + 1) % 7;
    }

    printf("\n");
}

