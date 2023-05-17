#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CRUD.h"




struct CUSTOMER{
    char name[SIZE];
    int people;
    int phoneNum;
    int price;
    int isPaid;
    char time[SIZE];
    char Menu[SIZE];
    char extra[SIZE]; 
    int nop;
};

struct Table{
    int s_index; //0이면 빈좌석 1이면 예약이 찬 좌석
  //  int time[12] = {0}; // 시간: 12개의 칸으로 나누어져 있음
  //  char order[100]; // 주문
    struct CUSTOMER *customer[12]; // CUSTOMER 구조체 포인터  12개의 시간으로 쪼개져 있음
};

typedef struct Day{
    struct Table *table[16];
    int full; // 이 날에 예약이 다 차면 1로 바꿈.
} day[12][31];

typedef struct Table tableForm[SIZE];
typedef struct CUSTOMER customer[SIZE];
typedef struct Day day[12][31];


int numRe = 0; 

void search(day *day){
    char sname[50]; //고객 이름
    int mm; // 월

    printf("해당 월을 입력하세요. ");
    scanf("%d", &mm);
    printf("고객의 이름을 입력하세요. ");
    scanf("%c",&sname);
    

    // for(int i=0; i<numRe; i++){
    //     if(strcmp(list[i].name, sname) == 0)
    //     printf("%s %d %s %d %d %s %s\n", list[i].name, list[i].num_people, list[i].phone, list[i].price, list[i].check, list[i].time, list[i].notes);
    // }

    for(int i=0; i<31; i++){
        for(int j=0; j<12)
        if(strcmp(day[mm-1][i], sname) == 0)
    }
}