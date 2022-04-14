#include "filebasics.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Print the given text file to the standard output stream.
 * 
 * \param filename The name of the file
 * \return The number of characters printed or -1 if file opening or reading 
 *         fails.
 */
int print_file_and_count(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
        count++;
    }
    fclose(fp);
    return count;
}

/**
 * \brief Compares two files and returns the first line that differ
 *        in the two files, concatenated together, separated by four dashes, on
 *        different lines.      
 * 
 * \param file1 The name of the first file
 * \param file2 The name of the second file
 * 
 * \note You can assume that lines are not longer than 1000 characters.
 * 
 * \return A dynamically allocated string that contains the first different 
 *         lines in the files. An example string is 
 * 
 *            printf("Hello world!\n");
 *       ----
 *            printf("Hello world\n");
 * \returns NULL if the files are equal or if either one of the 
            files ends.
 */
char* difference(const char* file1, const char* file2) {
    FILE* fp1 = fopen(file1, "r");
    FILE* fp2 = fopen(file2, "r");
    if (fp1 == NULL || fp2 == NULL) {
        return NULL;
    }
    char* line1 = malloc(sizeof(char) * 1000);
    char* line2 = malloc(sizeof(char) * 1000);
    while (fgets(line1, 1000, fp1) != NULL && fgets(line2, 1000, fp2) != NULL) {
        if (strcmp(line1, line2) != 0) {
            char* result = malloc(sizeof(char) * 2000);
            strcpy(result, line1);
            strcat(result, "----\n");
            strcat(result, line2);
            free(line1);
            free(line2);
            fclose(fp1);
            fclose(fp2);
            return result;
        }
    }
    free(line1);
    free(line2);
    fclose(fp1);
    fclose(fp2);
    return NULL;
}
