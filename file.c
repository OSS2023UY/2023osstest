#include "setting.h"
#include "CRUD.h"

// 파일 저장 함수
void saveList(int mm) {
    char filename[100];

    sprintf(filename, "%d", mm);

    FILE *fp;
    fp = fopen(filename, "w"); // 사용자가 입력한 파일 이름으로 파일 열기

    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    //총매출 계산
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

    int totalMoney=0; //총매출
    for(int i=0; i<5; i++){
        totalMoney+=weekly_profit[i];
    }


    int totalCount=0; // 팔린 음식 개수
    for (int j = 0; j < 31; j++) {
        for (int n = 0; n < 16; n++) {
                for (int m = 0; m < 12; m++) {
                    if (strcmp(dates[mm - 1][j].tables[n].customer[m].name, dates[mm - 1][j].tables[n].customer[m + 1].name) == 0) {
                        m++;  // 다음 손님으로 건너뛰기
                    } else {
                        totalCount += dates[mm - 1][j].tables[n].customer[m].people;
                    }
                }
            }
    }
    
    //가장 많이 팔린 음식
      int bestMenu[4]={0};
    for (int j = 0; j < 31; j++) {
      
        for (int n = 0; n < 16; n++) {
                for (int m = 0; m < 12; m++) {
                    if (strcmp(dates[mm - 1][j].tables[n].customer[m].name, dates[mm - 1][j].tables[n].customer[m + 1].name) == 0) {
                        m++;  // 다음 손님으로 건너뛰기
                    } else {
                        if(strcmp(dates[mm-1][j].tables[n].customer[m].Menu, "ChickenSkewer")) bestMenu[0] +=dates[mm - 1][j].tables[n].customer[m].people;
                        else if(strcmp(dates[mm-1][j].tables[n].customer[m].Menu, "Ramen")) bestMenu[1] +=dates[mm - 1][j].tables[n].customer[m].people;
                        else if(strcmp(dates[mm-1][j].tables[n].customer[m].Menu, "Gimbob")) bestMenu[2] +=dates[mm - 1][j].tables[n].customer[m].people;
                        else if(strcmp(dates[mm-1][j].tables[n].customer[m].Menu, "Tteokbokki")) bestMenu[3] +=dates[mm - 1][j].tables[n].customer[m].people;
                    }
                }
            }
    }

    int max = bestMenu[0];
    for(int i=0; i<4; i++){
        if(max<bestMenu[i]) max =bestMenu[i];
    }

    char best[100];
    if(max ==best[0]) strcpy(best,"ChickenSkewer");
    else if(max ==best[1]) strcpy(best,"Ramen");
    else if(max ==best[2]) strcpy(best,"Gimbob");
    else if(max ==best[3]) strcpy(best,"Tteokbokki");


    fprintf(fp, "!%d월! \n총매출은 %d입니다.\n팔린음식의 개수는 %d개 입니다. \n가장 많이 팔린 음식은 %s입니다.", mm, totalMoney, totalCount, best);

    fclose(fp); // 파일 닫기
}

// 파일 출력 함수
void printList() {
    FILE *fp;
    char filename[100];
    int countt = 0;
    char line[100];

    printf("파일의 이름을 입력하세요: ");
    scanf("%s", filename);
    fp = fopen(filename, "r"); // 파일 열기

    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    printf("파일 내용:\n");

    // 파일의 내용을 한 줄씩 읽어서 출력
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        countt++;
    }
}