#include <stdlib.h>
#include <stdio.h>
#include "source.h"

/**
 * \brief Creates a dynamically allocated array and reads the specified number of
 *        integers from the standard input stream.
 *
 * \param n The number of integers to be read
 * \return A pointer to the allocated and filled array
 */
int *create_dyn_array(unsigned int n)
{
    int *array = malloc(n * sizeof(int));
    for (unsigned int i = 0; i < n; ++i) {
        scanf("%d", array + i);
    }
    return array;
}

/**
 * \brief Appends a new element to the existing and dynamically allocated array
 *
 * \param arr The dynamically allocated array of num elements
 * \param num The number of elements in arr
 * \param newval The value of the new element that will be appended
 * \return A pointer to the resized array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{
    int *new_arr = realloc(arr, (num + 1) * sizeof(int));
    new_arr[num] = newval;
    return new_arr;
}
