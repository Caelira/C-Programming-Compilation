// Author: Prince II L. Olaguera
#include <stdio.h>
#include <stdlib.h>
#include "exercise1.h"
#include <windows.h>
#include "../Compiled_Olaguera.h"
// Function to compute the sum of an array
int compute_sum(int numbers[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
    }
    return sum;
}

// Function to compute the average
float compute_average(int sum, int size)
{
    return (float)sum / size;
}

void exercise1()
{
    int numbers[5];
    int sum;
    float average;
    int choice;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth, padding;

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    char *line1 = "+--------------------------------+";
    char *line2 = "|   1st Programming Exercise     |";
    char *line4 = "+--------------------------------+";

    padding = (consoleWidth - 36) / 2;

    printf("%*s%s\n", padding, "", line1);
    printf("%*s%s\n", padding, "", line2);
    printf("%*s%s\n", padding, "", line4);
    printf("Enter 5 numbers:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    sum = compute_sum(numbers, 5);
    average = compute_average(sum, 5);

    printf("\nNumbers in reverse order:\n");
    for (int i = 4; i >= 0; i--)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n\nSum: %d\n", sum);
    printf("Average: %.2f\n", average);
    while (1)
    {
        printf("Choose a number: \n");
        printf("1. Back to main menu\n");
        printf("2. Do the problem again\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        while (getchar() != '\n')
            ;
        switch (choice)
        {
        case 1:
            system("cls");
            getUserInput();
            break;
        case 2:
            system("cls");
            exercise1();
            break;
        case 3:
            printf("Thank you, come again!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    system("cls");
}
