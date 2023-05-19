#ifndef SETTING_H
#define SETTING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256

int count = 0; // 총 예약 개수


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

#endif
