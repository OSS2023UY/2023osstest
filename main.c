#include "CRUD.h"

void showMenu();



int main() {

    
//isFull을 전부 초기화
for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 31; j++) {
        for (int k = 0; k < 16; k++) {
            for(int y=0; y<12; y++){
            dates[i][j].tables[k].customer[y].name[0] = '\0';
            dates[i][j].tables[k].customer[y].people =0;
            dates[i][j].tables[k].customer[y].full = 0;
            }
            dates[i][j].tables[k].isFull = 0;
        }
        dates[i][j].isFull = 0;
    }
    
}
int selc; //선택
int tableNumber;
char guestName[50];
int guestAge, menuChoice,  reservationDuration;
int month, year;
int menuCount, Phone;
int mm, dd;
int time;

ResetMenu();

do {
    showMenu();
    printf("메뉴를 입력하세요 : ");
    scanf("%d", &selc);

    switch (selc) {
        case 1:
            printf("날짜를 입력하세요 : ");
            scanf("%d %d", &mm, &dd);
            listSeat(mm, dd);
            break;
        case 2:
            printf("날짜를 입력하세요 : ");
            scanf("%d %d", &mm, &dd);

            printf("테이블 번호를 입력하세요 (0-15): ");
            scanf("%d", &tableNumber);

            printf("손님 이름을 입력하세요: ");
            scanf("%s", guestName);
           // getchar();

            printf("손님 전화번호를 입력하세요: ");
            scanf("%d", &Phone);

            printMenu();
            printf("메뉴를 선택하세요 (1-3): ");
            scanf("%d", &menuChoice);

            printf("수량을 선택하세요 (1-3): ");
            scanf("%d", &menuCount);

            printf("몇시부터 예약하실 건가요? ");
            scanf("%d", &time);

             printf("예약 기간을 입력하세요 (시간 단위): ");
             scanf("%d", &reservationDuration);

            // 예약 추가
            addSeat(mm, dd, tableNumber, guestName, Phone, reservationDuration, menuChoice, menuCount, time);
            break;
        case 3:
            printMenu() ;
            printf("날짜를 입력하세요 : ");
            scanf("%d %d", &mm, &dd);

            printf("테이블 번호를 입력하세요 (0-15): ");
            scanf("%d", &tableNumber);

            printf("손님 이름을 입력하세요: ");
            scanf("%s", guestName);


            updateSeat(mm,dd, tableNumber, guestName);
            break;
        case 4:
            printf("날짜를 입력하세요 : ");
            scanf("%d %d", &mm, &dd);

            printf("테이블 번호를 입력하세요 (0-15): ");
            scanf("%d", &tableNumber);

            printf("손님 이름을 입력하세요: ");
            scanf("%s", guestName);

            printf("손님 전화번호를 입력하세요: ");
            scanf("%d", &Phone);

            deleteSeat(mm,dd, tableNumber, guestName, Phone);
            break;
        case 5:
            printf("날짜를 입력하세요 : ");
            scanf("%d %d", &mm, &dd);


            printf("손님 이름을 입력하세요: ");
            scanf("%s", guestName);


            search(mm,dd, guestName);
            break;
        case 6:
            
            printf("달력을 표시할 월을 입력하세요 (1-12): ");
            scanf("%d", &mm);
            printf("달력을 표시할 년도를 입력하세요: ");
            scanf("%d", &year);

            displayCalendar(mm - 1, year);
            break;
        case 7:
            printf("확인하고 싶은 달을 입력하세요: ");
            scanf("%d", &mm);
            showGraph(mm);
            break;
        case 8:
            printf("휴무일을 입력하세요: ");
            scanf("%d %d", &mm, &dd);
            rest(mm,dd);
            break;
        case 9:
            printf("파일에 정보를 저장할 월을 입력하세요: ");
            scanf("%d", mm);

            saveList(mm);
            break;
        case 10:
            printList();
            break;
        case 11:
            printf("프로그램을 종료합니다.\n");
            break;
    
        default:
            printf("유효하지 않은 선택입니다. 다시 시도하세요.\n");
            break;
    }

    printf("\n");
} while (selc != 0);

return 0;
}


void showMenu(){
    printf("┌──────────────────┐\n");
    printf("│       메뉴       │\n");
    printf("├──────────────────┤\n");
    printf("│ 1. 예약 현황     │\n");
    printf("│ 2. 예약 추가     │\n");
    printf("│ 3. 예약 수정     │\n");
    printf("│ 4. 예약 삭제     │\n");
    printf("│ 5. 고객 정보 조회│\n");
    printf("│ 6. 캘린더 보기   │\n");
    printf("│ 7. 매출추이 확인 │\n");
    printf("│ 8. 휴업날짜 선택 │\n");
    printf("│ 9. 파일 저장     │\n");
    printf("│ 10. 파일 열기     │\n");
    printf("│ 11. 대기명단 확인│\n");
    printf("└──────────────────┘\n");
}

