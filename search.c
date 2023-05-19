#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CRUD.h"

void search(day *day){
    char sname[50]; //고객 이름
    int mm; // 월
    int dd; //일

    printf("날짜를 입력하세요. ");
    scanf("%d", &mm, &dd);
    printf("고객의 이름을 입력하세요. ");
    scanf("%c",&sname);
    printf("고객의 전화번로를 입력하세요. ");
    
    

    for(int i=0; i<16; i++){
        for(int j=0; j<12; i++){
        if(strcmp(day[mm-1][dd-1]->table[i]->customer[j]->name, sname) == 0)
        printf("%s %d %d %d %d\n", day[mm-1][dd-1]->table[i]->customer[j]->name, day[mm-1][dd-1]->table[i]->customer[j]->people, day[mm-1][dd-1]->table[i]->customer[j]->phoneNum, day[mm-1][dd-1]->table[i]->customer[j]->price,day[mm-1][dd-1]->table[i]->customer[j]->isPaid);
        }
    }
}