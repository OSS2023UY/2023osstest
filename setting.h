#ifndef SETTING_H
#define SETTING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DATES 365
#define MAX_TABLES 16
#define MAX_CUSTOMERS 12
#define MAX_MENU_ITEMS 3
#define MAX_MONTHS 12
#define MAX_FOOD_ITEMS 3
#define SIZE 50
#define Q_SIZE 6

typedef struct {
    char name[SIZE];                    //이름
    int people;
    int phoneNum;
    int price;
    int isPaid;
    char Menu[SIZE];
    char extra[SIZE];
    int full;
    int tableNum;
    int orderedDay;
    int orderedTime;
} Customer;

typedef struct {
    Customer customer[MAX_CUSTOMERS];
    int isFull;
    int isQueued;
    my_queue queued;
} Table;

typedef struct {
    Table tables[MAX_TABLES];
    int isFull;
    int isQueued;
} Date;

typedef struct {
    char foodName[SIZE];
    int foodPrice;
    int count;
} Menu;

typedef struct {
    Customer q[Q_SIZE];     //최대 5명 대기 가능
    int front, rear;
} my_queue;

Date dates[12][31];
Menu menu[4];

#endif
