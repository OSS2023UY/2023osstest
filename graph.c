#include "setting.h"
#include "CRUD.h"

void showGraph(int mm) {
    printf("%d월 매출 추이 (단위: 만원)\n", mm);

    // 매출 추이 그래프 출력
    int weekly_profit[5] = {0, 0, 0, 0, 0};  // 주별 매출 배열 초기화

    for (int j = 0; j < 31; j++) {
        // 해당 월의 주차 계산
        int week = j / 7;

        // 같은 손님이 연속으로 예약한 경우 건너뛰기
        for (int n = 0; n < 16; n++) {
            for (int m = 0; m < 12; m++) {
                if (strcmp(dates[mm - 1][j].tables[n].customer[m].name, dates[mm - 1][j].tables[n].customer[m + 1].name) == 0) {
                    m++;  // 다음 손님으로 건너뛰기
                } else {
                    weekly_profit[week] += dates[mm - 1][j].tables[n].customer[m].price;
                }
            }
        }
    }

    // 그래프 출력
    for (int i = 0; i < 5; i++) {
        printf("주차 %d |", i + 1);
        for (int j = 0; j < weekly_profit[i]; j += 10000) {  // 단위 만원
            printf("■");
        }
        printf("|");
        printf(" %d\n", weekly_profit[i]);
    }
}
