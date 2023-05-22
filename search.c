#include "CRUD.h"
#include "setting.h"

void search(int mm, int dd, char guestName[]) {
    // 날짜 인덱스 계산
    int m = mm-1;
    int d =dd-1;
    int found = 0; // 고객 정보 찾았는지 여부를 나타내는 변수

    
        printf("날짜: %d월 %d일\n", mm,dd);
        printf("검색 결과:\n");

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 12; j++) {
                if (dates[m][d].tables[i].customer[j].full == 1 && strcmp(dates[m][d].tables[i].customer[j].name, guestName) == 0) {
                     printf("테이블 번호: %d, 손님 이름: %s, 손님 전화번호: %d,  지불여부: %d, 지불할 가격: %d원\n",
                       i, dates[m][d].tables[i].customer[j].name, dates[m][d].tables[i].customer[j].phoneNum,
                       dates[m][d].tables[i].customer[j].isPaid,
                       dates[m][d].tables[i].customer[j].price);
                       found = 1; // 고객 정보를 찾았음을 표시
                       break;
                }
            }
        }
    if (!found) {
        printf("해당 손님의 예약을 찾을 수 없습니다.\n");
    }
}