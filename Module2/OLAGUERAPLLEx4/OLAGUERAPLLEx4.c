// Author: Prince II L. Olaguera pogi

#include <stdio.h>
#include "module2.h"
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

    // Prompt user to choose operation
    printf("Choose an operation:\n");
    printf("1. Fibonacci\n");
    printf("2. Factorial\n");
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

    default:
        printf("Invalid choice. Please select 1 or 2.\n");
        break;
    }

}
