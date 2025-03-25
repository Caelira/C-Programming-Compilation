// Author: Prince II L. Olaguera
#include <stdio.h>
#include "exercise1.h"
// Function to compute the sum of an array
int compute_sum(int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum;
}

// Function to compute the average
float compute_average(int sum, int size) {
    return (float)sum / size;
}

void exercise1() {
    int numbers[5];
    int sum;
    float average;

    printf("Enter 5 numbers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    sum = compute_sum(numbers, 5);
    average = compute_average(sum, 5);

    printf("\nNumbers in reverse order:\n");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", numbers[i]);
    }

    printf("\n\nSum: %d\n", sum);
    printf("Average: %.2f\n", average);

}
