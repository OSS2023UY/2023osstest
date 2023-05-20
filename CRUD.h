#ifndef CRUD_H
#define CRUD_H
#include "setting.h"



void printMenu();
void addSeat(int mm, int dd, int tableNumber, char guestName[], int guestPhone, int reservationDuration, int menuChoice, int menuCount, int time);
void deleteSeat(int mm,int dd, int tableNumber, char guestName[], int Phone);
void updateSeat(int mm,int dd, int tableNumber, char guestName[]);
void listSeat(int mm, int dd);
void search(int mm, int dd, char guestName[]);


int isLeapYear(int year) ;
int getDaysInMonth(int month, int year);
void displayCalendar(int month, int year);
void rest(int mm,int dd);
void showGraph(int mm);
void ResetMenu();
void saveList(int mm);
void printList();
// void calculateMonthSales(int month, int year, struct MonthSales* monthSales);
// void displaySalesGraph(int month, int year);


#endif