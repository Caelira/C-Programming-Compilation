// Author: Prince II L. Olaguera

#include <stdio.h>
#include "../module3.h"

// Function to validate and store unique numbers
void validate(int one[], int unique[], int length)
{
    int i, j, k = 0;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (one[i] == unique[j])
            {
                break;
            }
        }
        if (j == k)
        {
            unique[k] = one[i];
            k++;
        }
    }
}

// Write a program that reads the numbers from a file, and store them into an array named
// “numbers”. From the array, find the maximum and minimum elements, and its index. (Note:
// The array size is 15, and the first line of the file indicates the number of data to be read)
void max_min(int numbers[], int length)
{
    int i, max = numbers[0], min = numbers[0], maxIndex = 0, minIndex = 0;
    for (i = 1; i < length; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
            maxIndex = i;
        }
        if (numbers[i] < min)
        {
            min = numbers[i];
            minIndex = i;
        }
    }
    printf("Max: %d, Index: %d\n", max, maxIndex);
    printf("Min: %d, Index: %d\n", min, minIndex);
}
void split(int list[], int positive[], int negative[], int length)
{
    int i, j = 0, k = 0;
    for (i = 0; i < length; i++)
    {
        if (list[i] > 0)
        {
            positive[j] = list[i];
            j++;
        }
        else if (list[i] < 0)
        {
            negative[k] = list[i];
            k++;
        }
    }
}
int finder(int nums[], int length, int number)
{
    for (int i = 0; i < length; i++)
    {
        if (number == nums[i])
        {
            return i;
        }
    }
    return -1;
}

void module3_Even()
{
    // 2. ===================================
    FILE *input = fopen("Module3/Array_Even_Olaguera/inputFirst.txt", "r");

    if (input == NULL)
    {
        printf("Error opening inputFirst.txt");
        return;
    }
    int one[15], unique[15] = {0}, i, choice;
    //===================================
    // 4. ===================================
    int list[20] = {-1, 2, 3, -4, 5, 6, -7, 8, 9, 10, -11, 12, 13, -14, 15, 16, -17, 18, 19, 20};
    int positive[20] = {0}, negative[20] = {0};
    // ===================================
    // 6. ===================================
    FILE *numFile = fopen("Module3/Array_Even_Olaguera/numbers.txt", "r");
    int len = 0;
    if (numFile == NULL)
    {
        printf("Error opening numbers.txt");
        return;
    }
    int numbers[15];
    // ===================================
    // 8. ===================================
    int arr[20] = {1, 3, -5, 7, -9, 0, 1, 0, 5, -9, 1, 2, 4, -5, 6, 7, -9, 0, 6, -2};
    int index, length = sizeof(arr) / sizeof(arr[0]), userNum;
    // ===================================
    // 10.===================================
    int matrix1[2][3] = {{0, 1, 2}, {9, 8, 7}};
    int matrix2[2][3] = {{6, 5, 4}, {3, 4, 5}};
    int matrix3[2][3], j;
    // ===================================

    printf("Choose the problem you want to solve (Even numbers, choose the number(even)):\n");
    printf("2. Store unique numbers from an array.\n");
    printf("4. Split the array into positive and negative numbers.\n");
    printf("6. Find the maximum and minimum elements of an array.\n");
    printf("8. Find the index of a number in an array.\n");
    printf("10. Add two matrices.\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 2:
        for (i = 0; i < 15; i++)
        {
            fscanf(input, "%d", &one[i]);
        }
        fclose(input);

        validate(one, unique, 15);

        printf("Array one: ");
        for (i = 0; i < 15; i++)
        {
            printf("%d ", one[i]);
        }
        printf("\n");

        printf("Array unique: ");
        for (i = 0; i < 15 && unique[i] != 0; i++)
        {
            printf("%d ", unique[i]);
        }
        printf("\n");
        fclose(input);
        break;
    case 4:
        split(list, positive, negative, 20);
        printf("Positive array: ");
        for (i = 0; i < 20 && positive[i] != 0; i++)
        {
            printf("%d ", positive[i]);
        }
        printf("\n");
        printf("Negative array: ");
        for (i = 0; i < 20 && negative[i] != 0; i++)
        {
            printf("%d ", negative[i]);
        }
        break;
    case 6:
        fscanf(numFile, "%d", &len);
        int numbers[15];
        for (i = 0; i < 15; i++)
        {
            fscanf(numFile, "%d", &numbers[i]);
        }
        max_min(numbers, len);
        fclose(numFile);
        break;
    case 8:
        printf("Enter a number that you want to search from the list: ");
        scanf("%d", &userNum);

        index = finder(arr, length, userNum);

        if (index != -1)
        {
            printf("%d can be found at index %d\n", userNum, index);
        }
        else
        {
            printf("%d is not in the list.\n", userNum);
        }

        break;
    case 10:
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
            {
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d ", matrix3[i][j]);
            }
            printf("\n");
        }
        // lovelots maam <3
        break;
    default:
        break;
    }

}