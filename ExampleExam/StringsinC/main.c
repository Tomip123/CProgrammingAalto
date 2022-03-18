#include <stdlib.h>
#include <stdio.h>

/*
Implement the following function that
concatenates string src after string dest. The function does not allocate 
memory, but it assumes that the calling function arranges the memory 
somehow (as with the original strcat function). The function 
returns pointer to the beginning of the string. In this task you must 
not use the strcat function that is defined in string.h header.
*/
char* mystrcat(char *dest, const char *src){
    char *p = dest;
    while(*p != '\0'){
        p++;
    }
    while(*src != '\0'){
        *p = *src;
        p++;
        src++;
    }
    *p = '\0';
    return dest;
}

// implement also the main function that tests the functionality of 
// the function you implemented above by 
// at least three different parameter combinations
int main(void){
    char str1[20] = "Hello";
    char str2[20] = "World";
    char str3[20] = "!";
    printf("%s\n", mystrcat(str1, str2));
    printf("%s\n", mystrcat(str1, str3));
    printf("%s\n", mystrcat(str2, str3));
    return 0;
}