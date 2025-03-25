#include <stdio.h>
#include "Module3/module3.h"
#include "Exercise2/exercise2.h"
#include "Module1/OLAGUERAPLLEx3/module1.h"
#include "Module2/OLAGUERAPLLEx4/module2.h"
#include "Exercise1/exercise1.h"
void getUserInput()
{
    int choice_module;
    int evenOdd;
    printf("Welcome to my compilation of C exercises! :)))\n");
    printf("Author: Prince II L. Olaguera BSIT 1C\n");
    printf("Please choose a module or exercise to open: \n");
    printf("1. Module 1: Functions\n");
    printf("2. Module 2: Recursion\n");
    printf("3. Module 3: Arrays\n");
    printf("4. Exercise 1\n");
    printf("5. Exercise 2\n");
    scanf("%d", &choice_module);
    while (getchar() != '\n');

    switch (choice_module)
    {
    case 1:
        module1();
        break;
    case 2:
        module2();
        break;
    case 3:
        printf("Even or odd? (Choose 1 for even, 2 for odd): \n");
        scanf("%d", &evenOdd);
        while(getchar() != '\n');
        if(evenOdd == 1){
            module3_Even();
        }else{
            module3_Odd();
        }

        break;
    case 4:
        exercise1();
        break;
    case 5:
        exercise2();
        break;
    default:
        break;
    }
}
int main()
{
    getUserInput();
    return 0;
}