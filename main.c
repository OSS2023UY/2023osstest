#include "CRUD.h"

int main(){
    tableForm table = {0};
    customer client = {0};
    int selc;

    while(1){
        showMenu();
        printf("선택 => ");
        scanf("%d", &selc);

        switch(selc){
            //예약 현황
            case 1:
                listSeat(&table);
                break;
            //예약 추가
            case 2:
                addSeat(&table);
                break;
            //예약 수정
            case 3:
                updateSeat(&table, &client);
                break;
            //예약 삭제
            case 4: 
                deleteSeat(&table);
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
            default:
                printf("잘못된 번호를 입력하셨습니다.");
                break;
        }
    }
    return 0;
}

//메뉴창 
void showMenu(){

}
