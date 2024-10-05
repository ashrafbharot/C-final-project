/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  : MOHAMED ASHRAF BHAROT
Student ID#: 139539225
Email      : mamabharot@myseneca.ca
Section    : ZEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#pragma once
#include<stdio.h>
void clearInputBuffer(void);
void suspend(void);
int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int lowerbound, int upperbound);
char inputCharOption(const char  string[]);
void inputCString(char* string, int min, int max);
void displayFormattedPhone(const char string[]);