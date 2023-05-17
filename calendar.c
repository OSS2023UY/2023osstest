#include "CRUD.h"

void printCalendar(day *day) {

    int mm; //월
    printf("몇월 달의 캘린더를 보실건가요?");
    scanf("월 입력=> %d", &mm);
    printf("+--------------------------------+\n");
    printf("|           Reservation          |\n");
    printf("+--------------------------------+\n");
    printf("| Sun | Mon | Tue | Wed | Thu | Fri | Sat |\n");
    printf("+--------------------------------+\n");

    
        for (int j = 0; j < 12; j++) {
            if (j == 0 && i < 9) {
                printf("| ");
            }

            if (day[mm]->full == 1) {
                // 글자가 연한 색상으로 출력
                printf("\033[1;30m");
            } else {
                // 글자가 찐한 색상으로 출력
                printf("\033[0;37m");
            }

            printf("%3d ", i + 1); // 일자 출력

            printf("\033[0m"); // ANSI 이스케이프 시퀀스를 사용하여 텍스트 색상을 기본값으로 변경

            if (j == 11) {
                printf("|\n");
            }
        }
    

    printf("+--------------------------------+\n");
}