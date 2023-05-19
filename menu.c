#include "setting.h"

struct Menu{ 
<<<<<<< HEAD
    int ChickenSkewers; // Â´ÃŸÂ²Â¿Ã„Â¡
    int Ramen; //Â¶Ã³Â¸Ã©
    int Gimbob; //Â±Ã¨Â¹Ã¤
    int Tteokbokki; //Â¶Â±ÂºÂºÃ€ÃŒ
};


=======
    char foodName[50];    //À½½Ä ÀÌ¸§
    int foodPrice;          //À½½Ä °¡°İ
    int count;              //À½½Ä ÆÈ¸° È½¼ö --> ¸ÅÃâ ÃßÀÌ ºĞ¼® ¶§ »ç¿ë           
};

typedef struct Menu bunsik[4];

void UpdateMenu(bunsik menu){
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
>>>>>>> 1a0d483aab63b22f0f56178a3c166c9852a111a0
