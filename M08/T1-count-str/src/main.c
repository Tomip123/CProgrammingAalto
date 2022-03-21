#include <stdio.h>
#include <string.h>
#include "source.h"
#include "source.c"

int main()
{
    /* Count substr */
    char str2[] = "one two one twotwo three";
    printf("num_substr: %d\n", num_substr(str2, "two"));
    
    char str3[] = "abcdefghijk";
    printf("num_substr: %d\n", num_substr(str3, "kkk"));

    char str4[] = "ttatamtammtammitammi";
    printf("num_substr: %d\n", num_substr(str4, "tammi"));

    char str5[] = "a b a b b b c d";
    printf("num_substr: %d\n", num_substr(str5, "b"));

        
    return 0;
}
