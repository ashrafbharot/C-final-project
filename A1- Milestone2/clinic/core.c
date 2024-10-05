/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  :Mohamed Ashraf Bharot
Student ID#:139539225
Email      :mamabharot@myseneca.ca
Section    :ZEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//
#include "core.h"
#include<string.h>

void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; 
    }
}


void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


int inputInt(void)
{
    int value = 0, a = 0;

    char newLine = 'x';

    do {

        scanf("%d%c", &value, &newLine);


        if (newLine != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else {
            a = 1;
        }

    } while (!a);

    return value;
}

int inputIntPositive(void)
{
    int value = 0, x= 0;

    do {

        value = inputInt();

        if (value <= 0) {

            printf("ERROR! Value must be > 0: ");
        }
        else {
           x = 1;
        }

    } while (!x);

    return value;
}


int inputIntRange(int lowerLimit, int upperLimit)
{
    int value  = 0, x = 0;
    do {

        value = inputInt();

        if (value < lowerLimit || value > upperLimit) {

            printf("ERROR! Value must be between %d and %d inclusive: ", lowerLimit, upperLimit);
        }
        else {
            x= 1;
        }

    } while (!x);

    return value;
}


char inputCharOption(const char validChars[])
{
    int i, x;

    char userChar, newLine = 'x';

    do {

        x = 0;
        scanf(" %c%c", &userChar, &newLine);

        for (i = 0; validChars[i] != '\0'; i++) {

            if (userChar == validChars[i]) {
                x = 1;
            }
        }

        if (!x) {
            printf("ERROR: Character must be one of [%s]: ", validChars);

        }

    } while (!x);

    return userChar;
}


void inputCString(char str[], int min, int max)
{
    int cnt = 0;
    int x = 0;
    char string[1000 + 1] = {0};
   
    do
    {
        cnt = 0;
        scanf("%1000[^\n]", string);
        clearInputBuffer();
        cnt = strlen(string);

        if (min == max && cnt != min) {
            printf("ERROR: String length must be exactly %d chars: ",min);
        }

        else if (cnt > max) {
            printf("ERROR: String length must be no more than %d chars: ",max);
        }
        else if (cnt < min) {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }
        else {
          x = 1;
        }

    } while (!x);
    
    strcpy(str, string);
}


void displayFormattedPhone(const char* string)
{
    int cnt = 0;
    int x = 1;
    int i = 0;

    if (string != NULL)
    {
        cnt = strlen(string);
        for (i = 0; string[i] != '\0'; i++)
        {
            if (string[i] < '0' || string[i] > '9')
            {
                x = 0;
            }
        }

        if (cnt != 10 || x == 0)
        {
            printf("(___)___-____");
        }
        else
        {
            printf("(%.3s)%.3s-%.4s", &string[0], &string[3], &string[6]);
        }
    }


    else
    {
        printf("(___)___-____");
    }
}