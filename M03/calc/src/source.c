#include "source.h"
#include <math.h>
#include <stdio.h>

void simple_math(void)
{
    float number1, number2;
    char operation;

    scanf("%f %c %f", &number1, &operation, &number2);

    switch (operation)
    {
        case '+':
            printf("%.1f\n", number1 + number2);
            break;
        case '-':
            printf("%.1f\n", number1 - number2);
            break;
        case '*':
            printf("%.1f\n", number1 * number2);
            break;
        case '/':
            if (number2 == 0 || number1 == 0)
            {
                printf("ERR\n");
            }
            else
            {
                printf("%.1f\n", number1 / number2);
            }
            break;
        default:
            printf("ERR\n");
            break;
    }

}
