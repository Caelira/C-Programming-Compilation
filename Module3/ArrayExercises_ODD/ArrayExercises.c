// Author: Prince II L. Olaguera
#include <stdio.h>
#include "../module3.h"
#include <stdlib.h>
#include "../../Compiled_Olaguera.h"
// Function to print the array in reverse order
void reverse(int nums[], int length)
{
    printf("In reversed order: \n");
    for (int i = length - 1; i >= 0; i--)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

// Function to calculate and print the sum of corresponding indices in two arrays
void sum_of_index(int list1[], int list2[], int length)
{
    int sum;
    for (int i = 0; i < length; i++)
    {
        sum = list1[i] + list2[i];
        printf("Sum of index %d (%d + %d): %d\n", i, list1[i], list2[i], sum);
    }
}

// Function to calculate the sum of positive numbers in an array
int sum_of_positive(int nums[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (nums[i] > 0)
        {
            sum += nums[i];
        }
    }
    return sum;
}

// Function to calculate the sum of negative numbers in an array
int sum_of_negative(int nums[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (nums[i] < 0)
        {
            sum += nums[i];
        }
    }
    return sum;
}

// Function to merge two sorted arrays into a third sorted array
void merge(int list1[], int list2[], int list3[], int length1, int length2)
{
    int i = 0, j = 0, k = 0;
    while (i < length1 && j < length2)
    {
        if (list1[i] < list2[j])
        {
            list3[k++] = list1[i++];
        }
        else
        {
            list3[k++] = list2[j++];
        }
    }
    while (i < length1)
    {
        list3[k++] = list1[i++];
    }
    while (j < length2)
    {
        list3[k++] = list2[j++];
    }
}

void module3_Odd()
{
    // File pointers and variables
    FILE *input = fopen("Module3/ArrayExercises_ODD/input.txt", "r");

    if (input == NULL)
    {
        printf("input.txt not found\n");
    }
    FILE *positiveNegative = fopen("Module3/ArrayExercises_ODD/positiveNegative.txt", "r");
    if (positiveNegative == NULL)
    {
        printf("input.txt not found\n");
    }
    int length, length2, choice;
    int list1[10] = {1, 3, 5, 7, 9, 11, 12, 13, 15, 19};
    int list2[10] = {1, 2, 4, 5, 6, 7, 9, 10, 16, 20};
    int list3[20];
    int list4[10] = {1, 3, -5, 7, -9, 0, 1, 0, 5, -9};
    int list5[10] = {1, 2, 4, -5, 6, 7, -9, 0, 6, -2};
    // Read lengths from files
    fscanf(input, "%d", &length);
    int nums[length];
    fscanf(positiveNegative, "%d", &length2);
    int nums2[length2];

    // Display problem choices
    printf("Choose the problem you want to solve (Odd numbers, choose 1 - 9):\n");
    printf("1. Reverse an array of numbers.\n");
    printf("3. Merge two sorted arrays into a third sorted array.\n");
    printf("5. Sum of corresponding indices in two arrays.\n");
    printf("7. Sum of positive and negative numbers from a file.\n");
    printf("9. Append two arrays and display the result.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        // Read numbers from the file
        for (int i = 0; i < length; i++)
        {
            fscanf(input, "%d", &nums[i]);
        }
        // Call the print_reverse function
        reverse(nums, length);
        fclose(input);
        break;

    case 3:
        system("cls");
        // Merge two sorted arrays into a third sorted array
        merge(list1, list2, list3, 10, 10);
        // Print the merged array
        printf("Merged array: \n");
        for (int i = 0; i < 20; i++)
        {
            printf("%d ", list3[i]);
        }
        printf("\n");
        break;

    case 5:
        system("cls");
        // Calculate and print the sum of corresponding indices
        sum_of_index(list4, list5, 10);
        break;

    case 7:
        system("cls");
        // Read numbers from the file
        for (int i = 0; i < length2; i++)
        {
            fscanf(positiveNegative, "%d", &nums2[i]);
        }
        // Calculate and print the sum of positive and negative numbers
        printf("Sum of all positive numbers: %d\n", sum_of_positive(nums2, length2));
        printf("Sum of all negative numbers: %d\n", sum_of_negative(nums2, length2));
        fclose(positiveNegative);
        break;

    case 9:
        system("cls");
        // Append list2 to list1 and print the result
        for (int i = 0; i < 10; i++)
        {
            list3[i] = list1[i];
        }
        for (int i = 0; i < 10; i++)
        {
            list3[i + 10] = list2[i];
        }
        printf("List1 contains: \n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", list1[i]);
        }
        printf("\nList2 contains: \n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", list2[i]);
        }
        // Print the appended array
        printf("\nAppended array: \n");
        for (int i = 0; i < 20; i++)
        {
            printf("%d ", list3[i]);
        }
        printf("\n");
        break;

    default:
        printf("Invalid input\n");
        break;
    }
    int menu;
    while (1)
    {
        printf("Choose a number: \n");
        printf("1. Back to main menu\n");
        printf("2. Back\n");
        scanf("%d", &menu);
        while(getchar() != '\n');
        switch (menu)
        {
        case 1:
            system("cls");
            getUserInput();
            break;
        case 2:
            system("cls");
            module3_Odd();
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
