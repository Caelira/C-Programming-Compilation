#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Compiled_Olaguera.h"
#include "Module3/module3.h"
#include "Exercise2/exercise2.h"
#include "Module1/OLAGUERAPLLEx3/module1.h"
#include "Module2/OLAGUERAPLLEx4/module2.h"
#include "Exercise1/exercise1.h"

void welcomeMessage()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth, padding;

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    char *line1 = "+--------------------------------+";
    char *line2 = "|   Welcome to My C Program!     |";
    char *line3 = "|   Press any key to continue... |";
    char *line4 = "+--------------------------------+";

    padding = (consoleWidth - 36) / 2;

    printf("%*s%s\n", padding, "", line1);
    printf("%*s%s\n", padding, "", line2);
    printf("%*s%s\n", padding, "", line3);
    printf("%*s%s\n", padding, "", line4);

    system("pause >nul");

    system("cls");
}

void getUserInput()
{
    int choice_module;
    int evenOdd;

    while (1)
    {
        printf("Welcome to my compilation of C exercises! :)))\n");
        printf("Author: Prince II L. Olaguera BSIT 1C\n");
        printf("Please choose a module or exercise to open (Choose a number 1 - 5): \n");
        printf("1. Module 1: Functions\n");
        printf("2. Module 2: Recursion\n");
        printf("3. Module 3: Arrays\n");
        printf("4. Exercise 1\n");
        printf("5. Exercise 2\n");
        printf("6. Exit\n");
        scanf("%d", &choice_module);
        while (getchar() != '\n')
            ;
        switch (choice_module)
        {
        case 1:
            system("cls");
            module1();
            break;
        case 2:
            system("cls");
            module2();
            break;
        case 3:
            printf("Even or odd? (Choose 1 for even, 2 for odd): \n");
            scanf("%d", &evenOdd);
            while (getchar() != '\n')
                ;
            if (evenOdd == 1)
            {
                system("cls");
                module3_Even();
            }
            else
            {
                system("cls");
                module3_Odd();
            }

            break;
        case 4:
            system("cls");
            exercise1();
            break;
        case 5:
            system("cls");
            exercise2();
            break;
        case 6:
            printf("Thank you, come again!\n");
            return;
            break;

        default:
            printf("Please enter 1 - 6 only \n");
            break;
        }
    }
}
int main()
{
    welcomeMessage();
    getUserInput();
    return 0;
}