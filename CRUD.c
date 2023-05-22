#include "CRUD.h"
#include <string.h>



void printMenu() {
    printf("메뉴:\n");
     for (int i = 0; i < 4; i++) 
    printf("%d. %s - %d원\n", i + 1, menu[i].foodName, menu[i].foodPrice);
}


// 예약 추가
void addSeat(int mm, int dd, int tableNumber, char guestName[], int guestPhone, int reservationDuration, int menuChoice, int menuCount, int time) {
    // 날짜 인덱스 계산
    int m = mm-1;
    int d =dd-1;
    char timeString[50];
    // 날짜 확인
    
        // 날짜가 가득 찼는지 확인
        if (dates[m][d].isFull == 1) {
            printf("해당 날짜의 예약이 모두 찼습니다.\n");
            return;
        }

            // 테이블 번호 확인
            if (tableNumber >= 0 && tableNumber < 16) {
                // 테이블이 가득 찼는지 확인
                if (dates[m][d].tables[tableNumber].isFull == 1) {
                    printf("해당 테이블은 이미 예약이 가득 찼습니다.\n");
                    return;
                }
            int choice;
            //선택한 시간이 예약 가능한 지 확인
            for(int i = time-1; i < reservationDuration+time-1; i++){
                if (dates[m][d].tables[tableNumber].customer[i].full !=0) {
                    printf("해당 시간에는 예약이 이미 있습니다.\n");
                    printf("해당 시간에 대기하시겠습니까? (Yes : 1 | No : 0)\n");
                    scanf("%d", &choice);
                    //Yes
                    if(choice == 1){
                        my_queue queue;
                        dates[m][d].isQueued++;
                        dates[m][d].tables[tableNumber].isQueued++;
                        queue = dates[m][d].tables[tableNumber].queued;
                        insert_q(&queue, dates[m][d].tables[tableNumber].customer[i]);
                    }
                    //No
                    return;
                }
            }

            //예약정보 입력 시작 - 아직은 이름과 전번만
            for (int i =time-1; i < reservationDuration+time-1; i++) {
                strcpy(dates[m][d].tables[tableNumber].customer[i].name, guestName);
                dates[m][d].tables[tableNumber].customer[i].phoneNum = guestPhone;
                dates[m][d].tables[tableNumber].customer[i].full = 1;
                strcpy(dates[m][d].tables[tableNumber].customer[i].Menu, menu[menuChoice-1].foodName);
                dates[m][d].tables[tableNumber].customer[i].price = menu[menuChoice-1].foodPrice * menuCount;
                dates[m][d].tables[tableNumber].customer[i].people = menuCount;
                dates[m][d].tables[tableNumber].customer[i].tableNum = tableNumber+1;
                dates[m][d].tables[tableNumber].customer[i].orderedDay = dd;
                snprintf(timeString, sizeof(timeString), "%d:00 - %d:00", time, time + reservationDuration);
                dates[m][d].tables[tableNumber].customer[i].orderedTime = strdup(timeString);
            }
            

            //
            int count=0;
            for(int i=0; i<12; i++){
                if( dates[m][d].tables[tableNumber].customer[i].full == 1)
                count++;
            }
            if(count == 12) {
                dates[m][d].tables[tableNumber].isFull = 1;
            }
                    printf("예약이 추가되었습니다.\n");
                    return;
                    
            }else{
                 printf("테이블 번호를 잘못 입력하셨습니다. \n");
                 return;
            }
           
        
    
}



void deleteSeat(int mm,int dd, int tableNumber, char guestName[], int Phone) {
// 날짜 인덱스 계산
    int m = mm-1;
    int d =dd-1;
    int count =0;


        for (int i = 0; i < 12; i++) {
              
            if (dates[m][d].tables[tableNumber].customer[i].full == 1 && strcmp(dates[m][d].tables[tableNumber].customer[i].name, guestName) == 0) {
                dates[m][d].tables[tableNumber].customer[i].name[0] = '\0';
                dates[m][d].tables[tableNumber].customer[i].phoneNum = 0;
                dates[m][d].tables[tableNumber].customer[i].price = 0;
                dates[m][d].tables[tableNumber].customer[i].full = 0;
                dates[m][d].tables[tableNumber].isFull = 0;

                dates[m][d].isFull = 0;
                count++;

                
            }

        }
        if(count >0) {
            printf("예약이 삭제되었습니다.\n");
            return;
        }
        printf("해당 손님의 예약을 찾을 수 없습니다.\n");
    

}

void updateSeat(int mm,int dd, int tableNumber, char guestName[]) {
    // 날짜 인덱스 계산
    int m = mm-1;
    int d =dd-1;
    char names[100];
    int newPhone;
    int menuChoice;
    int menuCount;
    int customerIndex = -1; // 기존 손님의 인덱스

// 기존 손님의 인덱스 찾기
         for (int i = 0; i < 12; i++) {
        if (dates[m][d].tables[tableNumber].customer[i].full == 1 && strcmp(dates[m][d].tables[tableNumber].customer[i].name, guestName) == 0) {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex != -1) {
        printf("새로운 손님 이름을 입력하세요: ");
        scanf("%s", names);

        printf("새로운 손님 전화번호를 입력하세요: ");
        scanf("%d", &newPhone);

        printMenu();
        printf("새로운 메뉴를 선택하세요 (1-3): ");
        scanf("%d", &menuChoice);

        printf("새로운 수량을 선택하세요 (1-3): ");
        scanf("%d", &menuCount);

         // 기존 손님의 정보 수정
        for (int i = 0; i < 12; i++) {
        if (dates[m][d].tables[tableNumber].customer[i].full == 1 && strcmp(dates[m][d].tables[tableNumber].customer[i].name, guestName) == 0) {
             strcpy(dates[m][d].tables[tableNumber].customer[i].name, names);
        dates[m][d].tables[tableNumber].customer[i].phoneNum = newPhone;
        strcpy(dates[m][d].tables[tableNumber].customer[i].Menu, menu[menuChoice - 1].foodName);
        dates[m][d].tables[tableNumber].customer[i].price = menu[menuChoice - 1].foodPrice * menuCount;
        dates[m][d].tables[tableNumber].customer[i].people = menuCount;
        }
    }

        // 기존 손님의 정보 수정
       
        

        printf("\n예약이 수정되었습니다.\n");
    } else {
        printf("해당 손님의 예약을 찾을 수 없습니다.\n");
    }
    
}


void listSeat(int mm, int dd) {
    // 날짜 인덱스 계산
    int m = mm - 1;
    int d = dd - 1;

    // 날짜 확인
    if (m >= 0 && m < 12 && d >= 0 && d < 31) {
        // 날짜가 가득 찼는지 확인

        printf("날짜: %d월 %d일\n", mm, dd);
        printf("손님 목록:\n");

        for (int i = 0; i < 16; i++) {
            // 테이블이 가득 찼는지 확인

            for (int j = 0; j < 12; j++) {
                // 예약이 있는 경우에만 출력
                if (dates[m][d].tables[i].customer[j].full == 1 && strcmp(dates[m][d].tables[i].customer[j].name, dates[m][d].tables[i].customer[j-1].name) != 0 && dates[m][d].tables[i].customer[j].phoneNum != dates[m][d].tables[i].customer[j-1].phoneNum) {

                    printf("테이블 번호: %d, 손님 이름: %s, 손님 전화번호: %d, 메뉴: %s, 가격: %d원\n",
                           i, dates[m][d].tables[i].customer[j].name,
                           dates[m][d].tables[i].customer[j].phoneNum,
                           dates[m][d].tables[i].customer[j].Menu,
                           dates[m][d].tables[i].customer[j].price);
                }
            }
           
        }
    } else {
        printf("유효하지 않은 날짜입니다.\n");
    }
}









