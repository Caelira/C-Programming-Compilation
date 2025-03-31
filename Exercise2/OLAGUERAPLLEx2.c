#include <stdio.h>
#include "exercise2.h"
#include <stdlib.h>
#include <windows.h>
#include "../Compiled_Olaguera.h"
// function that sorts the array in ascending manner (bubble sort)
void sortNumbers(int nums[], int length)
{
	int temp = nums[0];
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}
double average(int nums[], int length)
{
	int sum = 0;
	double ave;
	for (int i = 0; i < length; i++)
	{
		sum += nums[i];
	}
	ave = (float)sum / length;
	return ave;
}
// function that returns the largest number in the array
int largestNum(int nums[], int length)
{
	int temp = nums[0];
	for (int i = 0; i < length; i++)
	{
		if (temp < nums[i])
		{
			temp = nums[i];
		}
	}
	return temp;
}
// function that calculates the sum of the array
int arraySum(int nums[], int length)
{
	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += nums[i];
	}
	return sum;
}
// function that display the values
void displayValues(int nums[], int length)
{
	int sum, largest;
	double ave;
	sum = arraySum(nums, length);
	largest = largestNum(nums, length);
	ave = average(nums, length);
	// prints the values
	printf("Given numbers: \n");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", nums[i]);
	}
	// calls the sortNumbers function because if it is called too early, we can no longer print the given numbers
	sortNumbers(nums, length);

	printf("\nSorted numbers:\n");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\nThe sum of all numbers: \n%d\n", sum);
	printf("The average: \n%.2lf\n", ave);
	printf("Largest number: \n%d\n", largest);
}
void exercise2()
{
	// initialization and declaration of variables
	int choice;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int consoleWidth, padding;

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	char *line1 = "+--------------------------------+";
	char *line2 = "|   2nd Programming Exercise     |";
	char *line4 = "+--------------------------------+";

	padding = (consoleWidth - 36) / 2;

	printf("%*s%s\n", padding, "", line1);
	printf("%*s%s\n", padding, "", line2);
	printf("%*s%s\n", padding, "", line4);

	// asks the user how many numbers they want to use
	printf("How many numbers do you want to sort, calculate the sum, and find the largest?\n");
	scanf("%d", &choice);

	// declares the variables depending on the choice of the user
	int nums[choice];
	int length = sizeof(nums) / sizeof(nums[0]), largest, sum;

	// dynamically accepts user input based on the size of the array
	for (int i = 0; i < length; i++)
	{
		printf("Enter %d numbers: ", choice);
		scanf("%d", &nums[i]);
	}
	// calls the displayValues function
	displayValues(nums, length);

	while (1)
	{
		printf("Choose a number: \n");
		printf("1. Back to main menu\n");
		printf("2. Do the problem again\n");
		printf("3. Exit\n");
		scanf("%d", &choice);
		while (getchar() != '\n')
			;
		system("cls");
		switch (choice)
		{
		case 1:
			system("cls");
			getUserInput();
			break;
		case 2:
			system("cls");
			exercise2();
			break;
		case 3:
			printf("Thank you, come again!\n");
			exit(0);
			break;
		default:
			printf("Invalid choice\n");
		}
	}
}