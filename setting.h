#ifndef SETTING_H
#define SETTING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256

struct CUSTOMER{
    char name[SIZE];
    int people;
    int phonenum;
    int price;
    int ispaid;
    char time[SIZE];
    char extra[SIZE];
};

struct Table{
    int s_index[16];
    int time;
    char order[100];
};

typedef struct Table tableForm;
typedef struct CUSTOMER customer;

#endif
