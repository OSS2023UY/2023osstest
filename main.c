#include "CRUD.h"

void showMenu();

int main(){
    tableForm table = {0};
    customer client = {0};
    day day ={0};
    bunsik menu;
 


    UpdateMenu(&menu);  // 배열에 값 설정

    int selc;

    
    label:
    while(1){
        showMenu();
        printf("선택 => ");
        scanf("%d", &selc);

        switch(selc){
            //예약 현황
            case 1:
                listSeat(&day);
                break;
            //예약 추가
            case 2:
                addSeat(&day,&menu);
                break;
            //예약 수정
            case 3:
                updateSeat(&day);
                break;
            //예약 삭제
            case 4: 
                deleteSeat(&day);
                break;
            //파일 불러오기(from txt file)
            case 5:

                break;
            //예약된 고객 정보 조회
            case 6:

                break;
            //대기명단 확인
            case 7:

                break;
            //매출추이 확인
            case 8:

                break;
            //휴업날짜 선택
            case 9:

                break;
            case 10:
                break;

            default:
                printf("잘못된 번호를 입력하셨습니다.");
                break;
        }
    }
    return 0;
}

//메뉴창 
void showMenu(){
    printf("┌──────────────────┐\n");
    printf("│       메뉴       │\n");
    printf("├──────────────────┤\n");
    printf("│ 1. 예약 현황     │\n");
    printf("│ 2. 예약 추가     │\n");
    printf("│ 3. 예약 수정     │\n");
    printf("│ 4. 예약 삭제     │\n");
    printf("│ 5. 파일 불러오기 │\n");
    printf("│ 6. 고객 정보 조회│\n");
    printf("│ 7. 대기명단 확인 │\n");
    printf("│ 8. 매출추이 확인 │\n");
    printf("│ 9. 휴업날짜 선택 │\n");
    printf("└──────────────────┘\n");
}
