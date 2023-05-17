#include "setting.h"

struct Menu{ 
    char foodName[SIZE];    //음식 이름
    int foodPrice;          //음식 가격
    int count;              //음식 팔린 횟수 --> 매출 추이 분석 때 사용           
};

typedef struct Menu ChickenSkewer;
typedef struct Menu Ramen;
typedef struct Menu Gimbob;
typedef struct Menu Tteokbokki;

// ChickenSkewer | Ramen | Gimbob | Tteokbokki
