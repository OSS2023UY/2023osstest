#include "CRUD.h"
void rest(day *day){
    printf("휴무일을 선택하세요");

    int mm; //월
    int dd; //일

    scanf("%d %d", &mm, &dd);

    day[mm-1][dd-1]->full = 1;

    
}