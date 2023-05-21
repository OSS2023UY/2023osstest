#ifndef CALENDAR_H
#define CALENDAR_H
#include "setting.h"
#include "CRUD.h"

int isLeapYear(int year);
int getDaysInMonth(int month, int year);
void displayCalendar(int month, int year);

#endif