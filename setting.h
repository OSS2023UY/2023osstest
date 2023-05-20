#ifndef SETTING_H
#define SETTING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DATES 365
#define MAX_TABLES 16
#define MAX_CUSTOMERS 12
#define MAX_MENU_ITEMS 3
#define MAX_MONTHS 12
#define MAX_FOOD_ITEMS 3
#define SIZE 50


struct Customer {
    char name[SIZE];
    int people;
    int phoneNum;
    int price;
    int isPaid;
    char Menu[SIZE];
    char extra[SIZE];
    int full;
};

struct Table {
    struct Customer customer[MAX_CUSTOMERS];
    int isFull;
};

struct Date {
    struct Table tables[16];
    int isFull;
};

struct Menu {
    char foodName[50];
    int foodPrice;
    int count;
};

struct Menu menu[4];
struct Date dates[12][31];


#endif