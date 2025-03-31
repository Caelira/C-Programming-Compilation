// Author: Prince II L. Olaguera pogi

#include <stdio.h>
#include "module2.h"
#include <windows.h>
#include <stdlib.h>
#include "../../Compiled_Olaguera.h"
#define MAX 1000 // limit for memoization

// Array to store Fibonacci numbers for memoization
unsigned long long int memo[MAX];

// Function to calculate Fibonacci using recursion with memoization
unsigned long long int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

// Function to calculate factorial using recursion
unsigned long long int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void module2()
{
    int choice, n;

    // Initialize memo array with -1 for Fibonacci
    for (int i = 0; i < MAX; i++)
    {
        memo[i] = -1;
    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth, padding;

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    char *line1 = "+--------------------------------+";
    char *line2 = "|            Module 2            |";
    char *line3 = "|            Recursion           |";
    char *line4 = "+--------------------------------+";

    padding = (consoleWidth - 36) / 2;

    printf("%*s%s\n", padding, "", line1);
    printf("%*s%s\n", padding, "", line2);
    printf("%*s%s\n", padding, "", line3);
    printf("%*s%s\n", padding, "", line4);
    // Prompt user to choose operation
    printf("Choose an operation:\n");
    printf("1. Fibonacci\n");
    printf("2. Factorial\n");
    printf("3. Exit\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Get user input for the number
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Error: Please enter a non-negative integer.\n");
        return;
    }

    switch (choice)
    {
    case 1:
        if (n >= MAX)
        {
            printf("Error: Please enter an integer less than %d for Fibonacci.\n", MAX);
        }
        else
        {
            printf("Fibonacci of %d is %llu\n", n, fibonacci(n));
        }
        break;

    case 2:
        if (n > 20)
        {
            printf("Warning: Result may overflow for factorial of %d.\n", n);
        }
        printf("Factorial of %d is %llu\n", n, factorial(n));
        break;
    case 3:
        printf("Thank you, come again!\n");
        exit(0);
    default:
        printf("Invalid choice. Please select 1 or 2.\n");
        break;
    }
    int menu;
    while (1)
    {
        printf("Choose a number: \n");
        printf("1. Back to main menu\n");
        printf("2. Back to recursion menu\n");
        printf("3. Exit\n");
        scanf("%d", &menu);
        while (getchar() != '\n')
            ;
        system("cls");
        switch (menu)
        {
        case 1:
            system("cls");
            getUserInput();
            break;
        case 2:
            system("cls");
            module2();
        case 3:
            printf("Thank you, come again!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
