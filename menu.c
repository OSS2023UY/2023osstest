#include "setting.h"

void ResetMenu(bunsik menu){      //메뉴 초기화 함수, 생성자 역할을 하기 때문에 한번은 호출할
    strcpy(menu[0].foodName, "ChickenSkewer");
    menu[0].foodPrice = 4000;
    menu[0].count = 0;

    strcpy(menu[1].foodName, " Ramen");
    menu[1].foodPrice = 8500;
    menu[1].count = 0;

    strcpy(menu[2].foodName, "Gimbob");
    menu[2].foodPrice = 3000;
    menu[2].count = 0;

    strcpy(menu[3].foodName, "Tteokbokki");
    menu[3].foodPrice = 7000;
    menu[3].count = 0;
}
// ChickenSkewer | Ramen | Gimbob | Tteokbokki