#ifndef SETTING_H
#define SETTING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256

//int count = 0; // 총 예약 개수

struct CUSTOMER{

    char name[SIZE];    //고객이름
    int people;         //인원수
    int phoneNum;       //전화번호
    int price;          //지불해야하는 가격
    int isPaid;         //지불했는지 여부
    char time[SIZE];    //시간
    char Menu[SIZE];    //메뉴
    char extra[SIZE];   //기타
    int nop;            //(설명필요!)

};

struct Table{
    int s_index ;//0이면 빈좌석 1이면 예약이 찬 좌석
  //  int time[12] = {0}; // 시간: 12개의 칸으로 나누어져 있음
  //  char order[100]; // 주문
    struct CUSTOMER *customer[12]; // CUSTOMER 구조체 포인터  12개의 시간으로 쪼개져 있음
};

typedef struct Day{
    struct Table *table[16];
    int full; // 이 날에 예약이 다 차면 1로 바꿈.
} day[12][31];


typedef struct Menu{ 
    char foodName[50];    //음식 이름
    int foodPrice;          //음식 가격
    int count;              //음식 팔린 횟수 --> 매출 추이 분석 때 사용           
}bunsik[4];

typedef struct Menu bunsik[4];
typedef struct Table tableForm[SIZE];
typedef struct CUSTOMER customer[SIZE];
typedef struct Day day[12][31];

#endif
