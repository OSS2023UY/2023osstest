#include "CRUD.h"
#include <string.h>


void listSeat(day *day) {

    int dd; // 일
    int mm; // 월

    printf("날짜를 입력하세요");
    scanf("%d %d", &mm, &dd);

    int m = mm-1;
    int d = dd-1;

    for(int i = 0; i < 16; i++) {
        printf("좌석 번호: %d\n", i + 1);
        printf("------------------------\n");

        for(int j=0; j<12; j++){
        if(day[m][d]->table[i]->customer[j]->people == 0) continue; // 해당 테이블에 인원수가 0이면 다음 고객의 정보가 출력

        if(day[m][d]->table[i]->customer[j]->phoneNum == day[m][d]->table[i]->customer[j-1]->phoneNum) continue; // 전 시간과 같은 고객 정보가 들어 있으면 continue
        
            printf("고객 정보:\n");
            printf("이름: %s\n", day[m][d]->table[i]->customer[j]->name);
            printf("인원 수: %d\n", day[m][d]->table[i]->customer[j]->people);
            printf("전화번호: %d\n", day[m][d]->table[i]->customer[j]->phoneNum);
            printf("가격: %d\n", day[m][d]->table[i]->customer[j]->price);
            printf("지불 여부: %d\n", day[m][d]->table[i]->customer[j]->isPaid);
            printf("예약 시간: %s\n", day[m][d]->table[i]->customer[j]->time);
            printf("메뉴: %s\n", day[m][d]->table[i]->customer[j]->Menu);
            printf("추가 요청사항: %s\n", day[m][d]->table[i]->customer[j]->extra);
            printf("------------------------\n");
        }
    }
}
void addSeat(day *day, bunsik *menu){

    int dd; // 일
    int mm; // 월

    printf("날짜를 입력하세요");
    scanf("%d %d", &mm, &dd);

    int m = mm-1;
    int d = dd-1;

    // 이미 예약이 꽉 찬 날이면 return
    if(day[m][d]-> full) {
        printf("%d월 %d일은 예약하실 수 없습니다.", mm,dd);
        return;
    }

    int seatNum;
    //좌석 입력
    printf("예약 좌석 번호를 입력하세요 : ");
    scanf("%d", &seatNum);

    // //이미 예약이 다 찬 좌석이면 return
    // if(day[m][d]->table[seatNum-1]->s_index != 0) {
    //     printf("예약 할 수 없는 좌석입니다.\n");
    //     return;
    // }


///////////////////////////////예약 가능한 시간 보여주기!

    int clock; //예약 시작 시간
    int during; //몇시간 동안 할건지
    printf("예약할 시간을 선택하세요: ");
    scanf("%d", &clock);
    printf("몇시간 동안 하실 건가요?");
    scanf("%d", &during);


    char name[50];

    printf("고객 정보를 입력하세요.\n");
    printf("----------------------\n");
    printf("이름 : ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    getchar();
    strcpy(day[m][d]->table[seatNum-1]->customer[clock-1]->name, name);
    printf("인원 수 : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->people);
    getchar();
    printf("전화번호 : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->phoneNum);
    printf("지불 여부(1: 지불 완료, 0: 미지불) : ");
    scanf("%d", &day[m][d]->table[seatNum-1]->customer[clock-1]->isPaid);
    /////////////////////////////////////////////

     printf("메뉴를 입력하세요:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: %d원\n", menu[i]->foodName, menu[i]->foodPrice);
    }

    printf("메뉴 번호를 선택하세요: ");
    int menuNum;
    scanf("%d", &menuNum);
    if (menuNum < 1 || menuNum > 4) {
        printf("잘못된 메뉴 번호입니다.\n");
        return;
    }

    strcpy(day[m][d]->table[seatNum-1]->customer[clock-1]->Menu, menu[menuNum - 1]->foodName);

    day[m][d]->table[seatNum-1]->customer[clock-1]->price = menu[menuNum - 1]->foodPrice * day[m][d]->table[seatNum-1]->customer[clock-1]->people;

    ///////////////////////////////////////////
    printf("추가 요청사항을 입력하세요 : ");
    scanf("%s", day[m][d]->table[seatNum-1]->customer[clock-1]->extra);


//예약한 모든 시간을 1로 표시함.
    int k = clock-1;
    for(int i=0; i<during; i++){
        day[m][d]->table[seatNum-1]->customer[k]->nop = 1;
        k++;
    }

// 해당 날의 테이블에 예약이 다 차면 테이블 구조체에 있는 s_index를 1로 만들어서 더 이상 예약을 할 수 없도록 한다.
int p = 0;
for(int i=0; i<12; i++){
    if(day[m][d]->table[seatNum-1]->customer[i]->nop == 1) p++;
}
if(p==12) day[m][d]->table[seatNum-1]->s_index =1;

   
// 완료 표시
    printf("예약이 완료되었습니다.\n");
}


void updateSeat(day *day) {

    int dd; // 일
    int mm; // 월

    printf("날짜를 선택하시세요(월/일): ");
    scanf("%d %d", &mm, &dd);

    int m = mm-1;
    int d = dd-1;


    int seatNum, choice, addedTime, timeDiff;
    printf("변경할 좌석 번호를 입력하세요 : ");
    scanf("%d", &seatNum);

    
    if (day[m][d]->table[seatNum-1]->s_index== 0) {
        printf("사용 중인 좌석이 아닙니다.\n");
        return;
    }

    int t = seatNum-1;

    
    int now;
    printf("현재 고객의 전화번호를 입력하세요.");
    scanf("%d", &now);
    
    printf("[1] 고객 정보 변경\n[2] 메뉴 변경\n[3] 시간 추가/축소\n");
    printf("원하는 작업의 번호를 입력하세요 : ");
    scanf("%d", &choice);

            char name1[50];
            int people1;
            int phoneNum1;
            int price1;
            int isPaid1;

    switch (choice) {
        case 1:

          
            for(int i=0; i<12; i++) {
                
            }
            printf("변경할 고객 정보를 입력하세요.\n");
            printf("이름 : ");
            scanf("%s", name1);
            printf("인원 수 : ");
            scanf("%d", &people1);
            printf("전화번호 : ");
            scanf("%d", &phoneNum1);
            printf("가격 : ");
            scanf("%d", &price1);
            printf("지불 여부(1: 지불 완료, 0: 미지불) : ");
            scanf("%d", &isPaid1);

            for(int i=0; i<12; i++) {
                if(day[m][d]->table[t]->customer[i]->phoneNum == now){
                    strcpy(day[m][d]->table[t]->customer[i]->name, name1);
                    day[m][d]->table[t]->customer[i]->people = people1;
                    day[m][d]->table[t]->customer[i]->phoneNum = phoneNum1;
                    day[m][d]->table[t]->customer[i]->price =price1;
                    day[m][d]->table[t]->customer[i]-> isPaid =isPaid1;
                }
            }
            break;
        case 2:

            // for(int i=0; i<12; i++) {
            //     if(day[m][d]->table[t]->customer[i]->phoneNum == now){
            //         strcpy(day[m][d]->table[t]->customer[i]->name, name);
            //         day[m][d]->table[t]->customer[i]->people = people;
            //         day[m][d]->table[t]->customer[i]->phoneNum = phoneNum;
            //         day[m][d]->table[t]->customer[i]->price =price;
            //         day[m][d]->table[t]->customer[i]-> isPaid =isPaid;
            //     }
            // }
            // printf("변경할 메뉴를 입력하세요 : ");
            // scanf("%s", cust[t]->Menu);
            // printf("추가 요청사항을 입력하세요 : ");
            // scanf("%s", cust[t]->extra);
            break;
        case 3:
            printf("변경할 시간을 입력하세요(단위: 시간) : ");
            scanf("%d", &timeDiff);
          //  table[t]->time += timeDiff;
            if (timeDiff > 0) {
                printf("%d시간이 추가되었습니다.\n", timeDiff);
            } else if (timeDiff < 0) {
                printf("%d시간이 축소되었습니다.\n", -timeDiff);
            } else {
                printf("시간 변경이 없습니다.\n");
            }
            break;
        default:
            printf("잘못된 입력입니다.\n");
            break;
    }
}


void deleteSeat(day *day){
     int dd;
    int mm;

    printf("날짜를 입력하세요 : ");
    scanf("%d %d", &mm, &dd);

    int seatNum;
    printf("삭제할 좌석 번호를 입력하세요 : ");
    scanf("%d", &seatNum);

    if (day[mm-1][dd-1]->table[seatNum-1]->s_index == 0) {
        printf("해당 좌석은 이미 비어있습니다.\n");
        return;
    }

    for (int i = 0; i < 12; i++) {
        if (day[mm-1][dd-1]->table[seatNum-1]->customer[i] != NULL) {
            day[mm-1][dd-1]->table[seatNum-1]->customer[i] = NULL;
        }
    }

    day[mm-1][dd-1]->table[seatNum-1]->s_index = 0;
    printf("%d번 좌석이 삭제되었습니다.\n", seatNum);

}



void UpdateMenu(bunsik *menu){
    strcpy(menu[0]->foodName, "ChickenSkewer");
    menu[0]->foodPrice = 4000;
    menu[0]->count = 0;

    strcpy(menu[1]->foodName, "Ramen");
    menu[1]->foodPrice = 8500;
    menu[1]->count = 0;

    strcpy(menu[2]->foodName, "Gimbob");
    menu[2]->foodPrice = 3000;
    menu[2]->count = 0;

    strcpy(menu[3]->foodName, "Tteokbokki");
    menu[3]->foodPrice = 7000;
    menu[3]->count = 0;
}