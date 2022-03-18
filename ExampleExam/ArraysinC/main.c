#include <stdlib.h>
#include <stdio.h>

/*
Implement the following function that
processes table numbers that contains unsigned integers. The table 
ends with number 0. The function should return the largest integer in the table.
*/
unsigned int pickmax(unsigned int *numbers){
    unsigned int max = 0;
    while(*numbers != 0){
        if(*numbers > max){
            max = *numbers;
        }
        numbers++;
    }
    return max;
}

// implement also the main function that tests the functionality of 
// the function you implemented above by 
// at least three different parameter combinations
int main(void){
    unsigned int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
    printf("%d\n", pickmax(numbers));
    return 0;
}