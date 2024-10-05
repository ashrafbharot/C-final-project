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

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"core.h"


void clearInputBuffer(void) {
	
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
	int value;
	char newline = ' ';

	do
	{
		scanf(" %d%c", &value, &newline);

		if (newline != '\n')
		{
			clearInputBuffer(); 
			printf("Error! Input a whole number: ");
		}

	} while (newline != '\n');
	
	return value;
}
int inputIntPositive(void)
{
	int value;
	char newline = ' ';
	int itr = 1;

	do
	{
		scanf(" %d%c", &value, &newline);

		if (newline != '\n')
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
		else if (value <=0)
		{
			printf("ERROR! Value must be > 0: ");
		}
		else 
		{
			itr = 0;
		}

	} while (itr);

	return value;
}

int inputIntRange(int lowerbound, int upperbound) {
	
	char newchar = ' ';
	int value;
	

	do {
		scanf(" %d%c", &value, &newchar);

		if (newchar != '\n') {
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}

		else if (!(value <= upperbound && value >= lowerbound)) {
			printf("ERROR! Value must be between -3 and 11 inclusive: ");
		}
	} while (!(value <= upperbound && value >= lowerbound));

	
	return value;
}

char inputCharOption(const char string[])
{
	int i;
	int a = 0;
	char value;

	do
	{
		scanf(" %c", &value);

		for (i = 0; string[i] != '\0'; i++)
		{

			if (value == string[i])
			{
				a++;
			}
		}
			if(a==0)
			{
				  printf("ERROR: Character must be one of [%s]: ", string);
			}
	    
	} while (a==0);
	clearInputBuffer();
	return value;
}
void inputCString(char* string, int min, int max)
{
	char value = 'a';
	int x = 1;

	while (x)
	{
		int  cnt = 0;
		while (value != '\n' && cnt <= max)
		{
			value = getchar();
			string[cnt] = value;
			cnt++;
		};
		if (value == '\n' && cnt <= (max + 1)) {
			cnt--;
			string[cnt] = '\0';
		}
		else
		{

			string[max] = '\0';
			clearInputBuffer();
		}
		if (min == max && cnt != min) {
			printf("ERROR: String length must be exactly %d chars: ", min);
			value = 'a';

		}
		else if (cnt < min || cnt > max) {
			if (cnt > max) {
				printf("ERROR: String length must be no more than %d chars: ", max);
				value = 'a';
			}

			else if (cnt < min) {
				printf("ERROR: String length must be between %d and %d chars: ", min, max);
				value = 'a';
			}
		}

		else {
			x = 0;
		}
	}
}
	
void displayFormattedPhone(const char* string) 
{
	int i;
	int ctr = 1;
	if (string != NULL)
	{
		for(i=0; string[i] && ctr; i++)
		{
			if (string[i] < 48 || string[i] > 57)
			{
				ctr = 0;
			}
		}
	}
	if (i == 10 && ctr == 1)
	{
		printf("(");

		for (i = 0; i < 3; i++)
		{
			printf("%c", string[i]);
		}
		printf(")");

		for (i = 3; i < 6; i++)
		{
			printf("%c", string[i]);
		}
		printf("-");

		for (i = 6; i < 10; i++)
		{
			printf("%c", string[i]);
		}
	}
	else
	{
		printf("(___)___-____");
	}
}


