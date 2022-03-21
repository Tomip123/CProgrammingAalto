#include "myprint.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int myprint(const char *str, ...) {
    va_list args;
    int i = 0;
    char *s;
    int c;
    int ret = 0;
    va_start(args, str);
    while (str[i] != 0) {
        if (str[i] == '&') {
            c = va_arg(args, int);
            ret++;
            s = malloc(20);
            sprintf(s, "%d", c);
            printf("%s", s);
            free(s);
        } else {
            printf("%c", str[i]);
        }
        i++;
    }
    va_end(args);
    return ret;
}