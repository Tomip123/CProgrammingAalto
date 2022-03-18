#include <stdlib.h>
#include <stdio.h>

char *mystrchr(char *str, char c)
{
    while (*str != '\0') {
        if (*str == c) {
            return str;
        }
        str++;
    }
    return NULL;
}

int *createArray(unsigned int size)
{
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
    return array;
}

struct products {
    char *title;
    double price;
};

struct products *add_product(struct products *array, unsigned int length,
                             const char *newtitle, double newprice)
{
    struct products *newArray = realloc(array,
                                        (length+1) * sizeof(struct products));
    newArray[length].title = newtitle;
    newArray[length].price = newprice;
    return newArray;    
}

// implement your main function here
int main(){
    char *str = "Hello World!";
    char c = 'o';
    char *result = mystrchr(str, c);
    printf("%s\n", result);

    unsigned int size = 10;
    int *array = createArray(size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }

    struct products *array2 = malloc(sizeof(struct products));
    array2[0].title = "Apple";
    array2[0].price = 1.99;
    array2[1].title = "Banana";
    array2[1].price = 0.99;
    array2[2].title = "Orange";
    array2[2].price = 1.49;
    array2[3].title = "Pear";
    array2[3].price = 1.79;
    array2[4].title = "Grape";
    array2[4].price = 2.99;
    array2[5].title = "Watermelon";
    array2[5].price = 3.99;
    array2[6].title = "Strawberry";
    array2[6].price = 2.49;
    array2[7].title = "Blueberry";
    array2[7].price = 2.99;
    array2[8].title = "Raspberry";
    array2[8].price = 2.99;
    array2[9].title = "Cherry";
    array2[9].price = 2.99;
    array2 = add_product(array2, 10, "Pineapple", 3.99);
    for (int i = 0; i < 11; i++) {
        printf("%s\n", array2[i].title);
        printf("%f\n", array2[i].price);
    }
}