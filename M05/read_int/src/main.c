#include <stdio.h>

int *read_int(int *number)
{
    // returns directly the integer (int) that was read and not the pointer (int*). If the number cannot be read, the function returns -1. In addition to this, modify the main function code as below.
    int c;
    int sign = 1;
    int i = 0;
    int *result = number;

    while ((c = getchar()) != EOF && c != '\n')
    {
        if (c == '-')
        {
            sign = -1;
        }
        else if (c >= '0' && c <= '9')
        {
            *number = *number * 10 + (c - '0');
            i++;
        }
        else
        {
            return -1;
        }
    }
    *number = *number * sign;
    return result;
}

int main(void)
{
    int a;
    int *ptr_a = &a;
    int ret = read_int(ptr_a);
    if (read_int(ptr_a) != -1)
        printf("reading succeeded: %d\n", a);
    else
        printf("not a valid number\n");

    // Another way to do the same thing
    read_int(&a);
    printf("r: %d\n", ret);

    return 0;
}