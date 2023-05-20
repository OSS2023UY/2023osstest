#include "setting.h"

//day [0][0] ~ [11][30] 까지 1번씩 진행
//day 안에 customer[0] ~ customer[11]까지 1번씩 진행
//만약 customer[n]의 손님이 customer[n+1]과 동일하다면 customer[n+2]로 넘어가기
//customer[n]에 예약한 손님의 price 변수를 전부더하기
//해당 변수를 통해 그래프를 만들기 (1주일 기준)

void calProfit(day *day){
    int month = 0;
    //주수입(주 간격)
    int w1_profit = 0;  //1주
    int w2_profit = 0;  //2주
    int w3_profit = 0;  //3주
    int w4_profit = 0;  //4주
    int w5_profit = 0;  //5주

    printf("확인하고 싶은 달을 입력하세요: ");
    scanf("%d", &month);

    for(int j = 0; j < 7; j++){
        //만약 customer[n]의 손님이 customer[n+1]과 동일하다면 customer[n+2]로 넘어가기(continue)
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(m > 0 && strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }

    for(int j = 7; j < 14; j++){
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }

    for(int j = 14; j < 21; j++){
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }

    for(int j = 21; j < 28; j++){
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }

    for(int j = 28; j < 31; j++){
        for(int n = 0; n < 16; n++){
            for(int m = 0; m < 12; m++){
                if(strcmp(day[month][j]->table[n]->customer[n], day[month][j]->table[n]->customer[n-1]) == 0) continue;
                w1_profit += day[month][j]->table[n]->customer[m]->price;
            }
        }
    }
}

void showGraph(day day) {
    int month;
    printf("확인하고 싶은 달을 입력하세요: ");
    scanf("%d", &month);
    printf("%d월 매출 추이 (단위: 만원)\n", month);

    // 매출 추이 그래프 출력
    int weekly_profit[5] = {0};  // 주별 매출 배열 초기화

    for (int j = 0; j < 31; j++) {
        // 해당 월의 주차 계산
        int week = j / 7;

        // 같은 손님이 연속으로 예약한 경우 건너뛰기
        for (int n = 0; n < 16; n++) {
            for (int m = 0; m < 11; m++) {
                if (strcmp(day[month][j].table[n]->customer[m], day[month][j].table[n]->customer[m + 1]) == 0) {
                    m++;  // 다음 손님으로 건너뛰기
                } else {
                    weekly_profit[week] += day[month][j].table[n]->customer[m]->price;
                }
            }
        }
    }

    // 그래프 출력
    for (int i = 0; i < 5; i++) {
        printf("주차 %d |", i + 1);
        for (int j = 0; j < weekly_profit[i]; j += 10000) {     //단위 만원
            printf("■");
        }
        printf("|");
        printf(" %d\n", weekly_profit[i]);
    }
}

