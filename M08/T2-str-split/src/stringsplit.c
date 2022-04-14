#include "stringsplit.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * \brief Splits a string into its parts, and returns a dynamically allocated  
 *        array of strings that are dynamically allocated.
 * 
 * \details For example called with "Test string split" and " ",
 *          the function returns ["Test", "string", "split", NULL].
 *          
 *          Or called with "Another - test" and " - ",
 *          returns ["Another", "test", NULL].
 * 
 * \param str The null-terminated string to split.
 * \param split The token string to split str with.
 * \return An array of strings that contains parts of str in each of 
 *         strings excluding the split.      
 */
char** split_string(const char* str, const char* split) {
    // str can be "Split_ab!#this_ab!#case_ab!#correctly_ab!#too!" and split is "_ab!#"
    // Result is ["Split", "this", "case", "correctly", "too!", NULL]
    //
    // str can be "One. .more. .test. .for. .string. .splitting." and split is ". ."
    // Result is ["One", "more", "test", "for", "string", "splitting."]
    //

    
}


/**
 * \brief Prints string parts that are split with split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void print_split_string(char** split_string) {
    int i = 0;
    while (split_string[i] != NULL) {
        printf("%s\n", split_string[i]);
        i++;
    }
}

/**
 * \brief Releases dynamically allocated string parts by split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void free_split_string(char** split_string) {
    int i = 0;
    while (split_string[i] != NULL) {
        free(split_string[i]);
        i++;
    }
    free(split_string);
}
