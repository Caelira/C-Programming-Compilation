// Author: Prince II L. Olaguera
#include <stdio.h>
#include <stdlib.h>
#include "exercise1.h"
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
        printf("1. Back\n");
        printf("2. Do the problem again\n");
        scanf("%d", &choice);
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
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    system("cls");
}
