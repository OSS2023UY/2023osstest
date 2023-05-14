#include "CRUD.h"

void listSeat(tableForm *table){
    printf("추가해주세요\n");
}
void addSeat(tableForm *table){
    int seatNum;
    //좌석 입력
    printf("추가할 좌석 번호를 입력하세요 : ");
    scanf("%d", &seatNum);

    //이미 사용중인 좌석이면 표시
    if(table->s_index[seatNum-1] != 0) {
        printf("이미 사용중인 좌석입니다.\n");
        return;
    }
    //좌석 추가
    table->s_index[seatNum-1] = 1;
    //시간 추가(추가해야됨!)
    //(시간 추가 코드)

    // 완료 표시
    printf("%d번 좌석이 추가되었습니다.\n", seatNum);
}
void updateSeat(tableForm *table, customer *cust) {
    int seatNum, choice, addedTime, timeDiff;
    printf("변경할 좌석 번호를 입력하세요 : ");
    scanf("%d", &seatNum);

    if (table->s_index[seatNum - 1] == 0) {
        printf("사용 중인 좌석이 아닙니다.\n");
        return;
    }

    printf("[1] 고객 정보 변경\n[2] 메뉴 변경\n[3] 시간 추가/축소\n");
    printf("원하는 작업의 번호를 입력하세요 : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("변경할 고객 정보를 입력하세요.\n");
            printf("이름 : ");
            scanf("%s", cust->name);
            printf("인원 수 : ");
            scanf("%d", &cust->people);
            printf("전화번호 : ");
            scanf("%d", &cust->phoneNum);
            printf("가격 : ");
            scanf("%d", &cust->price);
            printf("지불 여부(1: 지불 완료, 0: 미지불) : ");
            scanf("%d", &cust->isPaid);
            break;
        case 2:
            printf("변경할 메뉴를 입력하세요 : ");
            scanf("%s", cust->Menu);
            printf("추가 요청사항을 입력하세요 : ");
            scanf("%s", cust->extra);
            break;
        case 3:
            printf("변경할 시간을 입력하세요(단위: 시간) : ");
            scanf("%d", &timeDiff);
            table->time += timeDiff;
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

void addOrder(tableForm *table){

}
void deleteSeat(tableForm *table){
    int seatNum;
    printf("삭제할 좌석 번호를 입력하세요 : ");
    scanf("%d", &seatNum);

    if (table->s_index[seatNum-1] == 0) {
        printf("해당 좌석은 이미 비어있습니다.\n");
        return;
    }

    table->s_index[seatNum-1] = 0;
    printf("%d번 좌석이 삭제되었습니다.\n", seatNum);
}
