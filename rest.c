#include "CRUD.h"

void rest(int mm,int dd){
 

  
    
        for (int k = 0; k < 16; k++) {
            for(int y=0; y<12; y++){
            dates[mm-1][dd-1].tables[k].customer[y].name[0] = '\0';
            dates[mm-1][dd-1].tables[k].customer[y].full = 0;
            }
             dates[mm-1][dd-1].tables[k].isFull = 1;
        }
       
        dates[mm-1][dd-1].isFull = 1;
    




printf("%d월 %d일이 휴무일로 지정되었습니다.\n ", mm,dd);
    
}