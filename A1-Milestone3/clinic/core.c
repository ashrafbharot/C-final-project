/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :Prabhdeep Kaur
Student ID#:145698221
Email      :prabhdeep-kaur4@myseneca.ca
Section    :ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "string.h"
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
//This function validates that an integer value is entered and returned otherwise it would display an error message.
int inputInt(void)
{
    char character = ' ';
    int value;

    do
    {
        scanf("%d%c", &value, &character);

        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (character != '\n');


    return value;
}

//This function validates a positive integer value is entered and returned or it would display an error message.
int inputIntPositive(void)
{
    char character = ' ';
    int value;

    do
    {
        scanf("%d%c", &value, &character);

        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a number: ");
        }

        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value <= 0);


    return value;
}

//This function validates that an integer value is entered within the permitted range (inclusive) and returned or it would display an error message
int inputIntRange(int lowerBound, int upperBound)
{
    char character = ' ';
    int value;

    do
    {
        scanf("%d%c", &value, &character);

        if (character != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        else if (!(value <= upperBound && value >= lowerBound))
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (!(value <= upperBound && value >= lowerBound));

    return value;
}

//This function validates a single character value is entered within the list of valid characters and returned. 
char inputCharOption(char string[])
{
    int i, count = 0;
    char input;

    do
    {
        scanf(" %c", &input);

        for (i = 0; string[i] != '\0'; i++)
        {
            if (input == string[i])
            {
                count++;
            }
        }

        if (count == 0) {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
    } while (count == 0);


    clearInputBuffer();
    return input;
}

// This function validates a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments 
void inputCString(char* string, int minChar, int maxChar)
{
    int continue_loop = 1;
    char ch = 'a';

    while (continue_loop)
    {
        int length = 0;

        while (ch != '\n' && length <= maxChar)
        {
            ch = getchar();
            string[length] = ch;
            length++;
        };


        if (ch == '\n' && length <= (maxChar + 1))
        {
            length--;
            string[length] = '\0';
        }

        else
        {
            string[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && length != minChar)
        {
            printf("ERROR: String length must be exactly %d chars: ", minChar);
            ch = 'a';
        }
        else if (length < minChar || length > maxChar)
        {
            if (length > maxChar)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
                ch = 'a';
            }
            else if (length < minChar)
            {
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
                ch = 'a';
            }
        }
        else
        {
            continue_loop = 0;
        }
    }
}

// This function is the same as inputCString but is exclusively for numbers
void inputCStringNumbers(char* string, int minChar, int maxChar)
{
    int continue_loop = 1;
    char ch = 'a';

    while (continue_loop)
    {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= maxChar)
        {
            ch = getchar();
            string[len] = ch;
            len++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && len <= (maxChar + 1))
        {
            len--;
            string[len] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            string[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar)
        {
            printf("Invalid 10-digit number! Number: ");
            ch = 'a';
        }
        else {
            continue_loop = 0;
        }
    }
}



// it is to determine a string of 10 characters long and digits from 0 - 9
void displayFormattedPhone(const char* string)
{
    if (string != NULL)
    {
        int length = 0, i, Count = 0;

        length = strlen(string);
        if (length == 10)
        {
            i = 0;
            for (i = 0; string[i] != '\0'; i++)
            {
                if (string[i] >= '0' && string[i] <= '9')
                {
                    Count++;
                }
            }


            if (Count == 10)
            {


                printf("(");
                for (i = 0; string[i] != '\0'; i++)
                {
                    if (i < 3)
                    {
                        printf("%c", string[i]);
                    }
                }
                printf(")");
                for (i = 0; string[i] != '\0'; i++)
                {
                    if (i >= 3 && i < 6)
                    {
                        printf("%c", string[i]);
                    }
                }
                printf("-");
                for (i = 0; string[i] != '\0'; i++)
                {
                    if (i >= 6 && i < 10)
                    {
                        printf("%c", string[i]);
                    }
                }
            }

            else
            {
                printf("(___)___-____");
            }
        }
        else
        {
            printf("(___)___-____");
        }
    }
    else if (string == NULL)
    {
        printf("(___)___-____");
    }

}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////