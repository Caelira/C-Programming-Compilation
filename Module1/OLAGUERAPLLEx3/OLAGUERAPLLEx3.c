// Author: Prince II L. Olaguera
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "module1.h"
#include "../../Compiled_Olaguera.h"
#include <windows.h>
// 1. ==================================
int sum(int numbers[])
{
    int summation = 0;
    for (int i = 0; i < 5; i++)
    {
        summation += numbers[i];
    }
    return summation;
}

float average1(int total)
{
    return total / 5.0;
}
// ==================================

// 2. ==================================
void feet(int inches)
{
    int feet = inches / 12;
    int remaining_inches = inches % 12;
    printf("%d inches is %d feet and %d inches\n", inches, feet, remaining_inches);
}
// ==================================

// 3. ==================================
int int_test(float num)
{
    if ((int)num != num || num == 0)
    {
        return 0; // Not an integer
    }
    else if (num < 0)
    {
        return -1; // Negative integer
    }
    else
    {
        return 1; // Positive integer
    }
}

// ==================================

// 4. ==================================
int sum_of_even(int num)
{
    return (num % 2 == 0) ? num : 0;
}

int sum_of_odd(int num)
{
    return (num % 2 != 0) ? num : 0;
}
// ==================================

// 5. ==================================
void ascending(int a, int b, int c)
{
    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    printf("Numbers in ascending order: %d %d %d\n", a, b, c);
}
// ==================================

// 6. ==================================
double perimeter(double length, double width)
{
    return 2 * (length + width);
}
// ==================================

// 7. ==================================
double product(double num1, double num2, double num3)
{
    return num1 * num2 * num3;
}
// ==================================

// 8. ==================================
double dollar_to_peso(double usd, double exchange_rate)
{
    return usd * exchange_rate;
}
// ==================================

// 9. ==================================
bool equal(int num1, int num2, int num3)
{
    return (num1 == num2) && (num2 == num3);
}
// ==================================

// 10. ==================================
void display_largest(int num1, int num2, int num3)
{
    int largest = (num1 >= num2) ? (num1 >= num3 ? num1 : num3) : (num2 >= num3 ? num2 : num3);
    printf("The largest number is: %d\n", largest);
}
// ==================================

void module1()
{
    // 1. Sum and Average
    int userNumbers[5], totalSum, averageValue, choice;
    int inchesInput, number, sumEven = 0, sumOdd = 0;
    int firstNum, secondNum, thirdNum;
    double length, width, num1, num2, num3;
    double usd, exchangeRate;
    int numA, numB, numC;
    FILE *file = fopen("numbers.txt", "r");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth, padding;

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    char *line1 = "+--------------------------------+";
    char *line2 = "|            Module 1            |";
    char *line3 = "|            Function            |";
    char *line4 = "+--------------------------------+";

    padding = (consoleWidth - 36) / 2;

    printf("%*s%s\n", padding, "", line1);
    printf("%*s%s\n", padding, "", line2);
    printf("%*s%s\n", padding, "", line3);
    printf("%*s%s\n", padding, "", line4);

    // display the problems a user might be interested in
    printf("Choose a problem to solve:\n\n");

    printf("Choose a problem to solve:\n");
printf("1. Sum and Average: Implement \"sum\" and \"average\" functions for five numbers.\n");
printf("2. Inches to Feet: Implement \"feet\" function to convert inches to feet and inches.\n");
printf("3. Integer Test: Read numbers from a file and use \"int_test()\" to check if they are positive, negative, or zero.\n");
printf("4. Sum of Evens and Odds: Use \"sum_of_even\" and \"sum_of_odd\" functions to compute sums from a file.\n");
printf("5. Ascending Order: Read three numbers per line from a file until three zeros appear, then sort using \"ascending\".\n");
printf("6. Perimeter: Implement \"perimeter\" function to compute the perimeter of a rectangle.\n");
printf("7. Product: Implement \"product\" function to compute the product of three numbers.\n");
printf("8. Currency Conversion: Implement \"dollar_to_peso\" function to convert USD to PHP.\n");
printf("9. Equality Check: Implement \"equal\" function to determine if three numbers are equal.\n");
printf("10. Largest Number: Implement a function to find the largest among three numbers.\n");

    printf("11. Exit\n");
    // Ask user for the problem they want to solve
    printf("Enter the number of the problem you want to solve (1- 10): ");
    scanf("%d", &choice);

    switch (choice)
    {
    // choice 1: Sum and Average
    case 1:
    {
        system("cls");
        int userNumbers[5], totalSum;
        float averageValue;
        // user prompt
        printf("Please enter 5 numbers:\n");

        // get user input
        for (int i = 0; i < 5; i++)
        {
            printf("Enter number %d: ", i + 1);
            scanf("%d", &userNumbers[i]);
        }
        // call the functions
        totalSum = sum(userNumbers);
        averageValue = average1(totalSum);
        // display resultd
        printf("Total Sum: %d\n", totalSum);
        printf("Average: %.2f\n", averageValue);
        break;
    }
        // choice 2: Feet
    case 2:
    {
        system("cls");
        int inchesInput;
        // user prompt
        printf("Enter the number of inches to convert to feet: ");
        // get user input and call function
        scanf("%d", &inchesInput);
        feet(inchesInput);
        break;
    }
    // choice 3: int_test
    case 3:
    {
        system("cls");
        FILE *file = fopen("Module1/OLAGUERAPLLEx3/numbers(3).txt", "r");
        float number;

        if (file == NULL)
        {
            printf("File not found.\n");
            return;
        }

        while (fscanf(file, "%f", &number) != EOF)
        {
            printf("Value: %.2f, Result: %d\n", number, int_test(number));
        }

        fclose(file);
        break;
    }
    // choice 4: sum_of_even and sum_of_odd
    case 4:
    {
        system("cls");
        FILE *file = fopen("Module1/OLAGUERAPLLEx3/numbers(4).txt", "r");
        int number, sumEven = 0, sumOdd = 0;
        // check if file exists
        if (file == NULL)
        {
            printf("Error: File not found.\n");
            return;
        }
        // read file and call functions
        while (fscanf(file, "%d", &number) != EOF)
        {
            sumEven += sum_of_even(number);
            sumOdd += sum_of_odd(number);
        }
        fclose(file);
        // display results
        printf("Total Sum of Even Numbers: %d\n", sumEven);
        printf("Total Sum of Odd Numbers: %d\n", sumOdd);
        break;
    }
    // choice 5: ascending
    case 5:
    {
        system("cls");
        FILE *file = fopen("Module1/OLAGUERAPLLEx3/numbers(5).txt", "r");
        if (file == NULL)
        {
            printf("Error: File not found.\n");
            return;
        }

        int firstNum, secondNum, thirdNum;

        while (fscanf(file, "%d %d %d", &firstNum, &secondNum, &thirdNum) == 3)
        {
            // check if the three numbers are zero then terminate the program
            if (firstNum == 0 && secondNum == 0 && thirdNum == 0)
            {
                break;
            }
            // Call the ascending function
            ascending(firstNum, secondNum, thirdNum);
        }

        fclose(file);
        break;
    }
    // choice 6: perimeter
    case 6:
    {
        system("cls");
        double length, width;
        // get user input
        printf("Enter the length and width of the rectangle (separated by spaces): ");
        scanf("%lf %lf", &length, &width);
        // call function perimeter to get the perimeter
        printf("Perimeter of the rectangle: %.2f\n", perimeter(length, width));
        break;
    }
    // choice 7: product
    case 7:
    {
        system("cls");
        double num1, num2, num3;
        // get user input
        printf("Please enter 3 numbers to calculate the product (separated by spaces): ");
        scanf("%lf %lf %lf", &num1, &num2, &num3);
        // call function product to get the product
        printf("Product of the numbers: %.2f\n", product(num1, num2, num3));
        break;
    }
    // choice 8: dollar_to_peso
    case 8:
    {
        system("cls");
        double usd, exchangeRate;
        // get user input
        printf("Enter the amount in USD and the exchange rate to Peso (separated by spaces): ");
        scanf("%lf %lf", &usd, &exchangeRate);
        // call function dollar_to_peso to get the amount in Peso
        printf("Amount in Peso: %.2f\n", dollar_to_peso(usd, exchangeRate));
        break;
    }
    // choice 9: equal
    case 9:
    {
        system("cls");
        int numA, numB, numC;
        // get user input
        printf("Please enter 3 numbers to check if they are equal (separated by spaces): ");
        scanf("%d %d %d", &numA, &numB, &numC);
        // call function equal to check if the numbers given by the user are equal
        if (equal(numA, numB, numC))
        {
            printf("All three numbers are equal.\n");
        }
        else
        {
            printf("The numbers are not equal.\n");
        }
        break;
    }
    // choice 10: display_largest
    case 10:
    {
        system("cls");
        int numA, numB, numC;
        // get user input
        printf("Enter 3 numbers to find the largest (separated by spaces): ");
        scanf("%d %d %d", &numA, &numB, &numC);
        // call function display_largest to get the largest number
        display_largest(numA, numB, numC);
        break;
    }
    case 11:
        printf("Thank you, come again!\n");
        exit(0);
        break;
    // default case if the user enters an invalid input
    default:
        printf("Invalid choice. Please select a number between 1 and 11.\n");
        break;
    }
    int menu;
    while (1)
    {
        printf("Choose a number: \n");
        printf("1. Back to main menu\n");
        printf("2. Back to functions menu\n");
        printf("3. Exit\n");
        scanf("%d", &menu);
        while (getchar() != '\n')
            ;
        switch (menu)
        {
        case 1:
            system("cls");
            getUserInput();
            break;
        case 2:
            system("cls");
            module1();
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