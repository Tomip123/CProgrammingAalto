#include <stdio.h>

int *read_int(int *number)
{
    int ret;
    if (number == NULL) { // Check the given pointer
        return NULL; // If the pointer is NULL, exit the function
    }
    ret = scanf("%d", number);
    if (ret != 1) { // Check whether reading succeeded
        return NULL;
    }
    return number;
}

int main(void)
{
    int a;
    int *ptr_a = &a;
    int ret = -1000;
    if (read_int(ptr_a))
        printf("reading succeeded: %d\n", a);
    else
        printf("not a valid number\n");

    // Another way to do the same thing
    read_int(&a);
    printf("r: %d\n", ret);

    return 0;
}