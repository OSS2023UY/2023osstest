#include <stdio.h>
#include <string.h>

struct List{
    char name[50]; // 이름
    int num_people; // 인원수
    char phone[20]; // 전화번호
    int price; // 가격
    int check; // 결제 완료 유무 (0: 미결제, 1: 결제 완료)
    char time[30]; // 시간대
    char notes[100]; // 추가 사항
};

struct List list[100]; // 예약 정보를 저장할 배열
int numRe = 0; // 현재 예약 정보 개수

void delete() {

    char name[50];
    char phone[50];
    printf("삭제할 예약자의 이름을 입력하세요.");
    scanf("%s", name);
    printf("삭제할 예약자의 전화번호를 입력하세요.");
    scanf("%s", phone);

//char* name, char* phone

    int i, j;
    for (i = 0; i < numRe; i++) {
        // 이름과 전화번호가 일치하는 예약 정보를 찾음
        if (strcmp(list[i].name, name) == 0 && strcmp(list[i].phone, phone) == 0) {
            
            for (j = i; j < numRe - 1; j++) {  // 삭제하고 배열 정리
                list[j] = list[j+1];
            }
            numRe--;
            printf("예약 정보가 삭제되었습니다.\n");
            return;
        }
    }
    printf("일치하는 예약 정보가 없습니다.\n");
}