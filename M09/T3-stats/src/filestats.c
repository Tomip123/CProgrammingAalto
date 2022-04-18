
#include "filestats.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * \brief Returns the number of lines in a file. 
 * 
 * \param filename The name of the file.
 * \return The number of lines in the file, or -1 if an error occurs. 
 */
int line_count(const char* filename) {
    // The function parses a text file, and finds the lines in the the file, and returns the number of lines it has found.
    // The function assumes that a newline character is a part of the string which comes before the newline character.
    // If the last line of the file is not empty, it should be counted as a line even if it does not end with a newline character.
    // If there is an error, the function should return -1.

    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }


    // Initialize variables
    int line_count = 0;
    char c;
    int newline_found = 0;

    // Read the file
    while ((c = fgetc(fp)) != EOF) {
        // If a newline character is found, increment the line count
        
        if (c == '\n') {
            line_count++;
            newline_found = 1;
        }
        // If a newline character is not found, set the newline_found flag to 0
        else {
            newline_found = 0;
        }
    }

    // If the last line of the file is not empty, increment the line count
    if (newline_found == 0) {
        line_count++;
    }

    // Close the file
    fclose(fp);

    // Return the line count
    return line_count;


    
}

/**
 * \brief Returns the number of words in a file.
 * 
 * \details The function assumes that a word is formed by alphabetical characters
 *          as defined in ctype.h so that isalpha() returns nonzero value.
 * 
 *          The words are separated by a white space character as defined in 
 *          ctype.h so that isspace() returns nonzero value.
 * 
 * \param filename The name of the file.
 * \return The number of words in the file, or -1 if an error occurs.
 */
int word_count(const char* filename) {
    // The function assumes that a word is defined as follows. word is a substring that contains at least one alphabetical character as defined in ctype.h and isalpha function returns a nonzero value.
    // It also assumes that two words are separated by one or more whitespace characters as defined in ctype.h and isspace function returns a nonzero value.
    // If there is an error, the function should return -1. Otherwise, it returns the number of words it found.

    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    // Initialize variables
    int word_count = 0;
    char c;
    int word_found = 0;

    // Read the file
    while ((c = fgetc(fp)) != EOF) {
        // If a word is found, increment the word count
        if (isalpha(c) && word_found == 0) {
            word_count++;
            word_found = 1;
        }
        // If a word is not found, set the word_found flag to 0
        else if (!isalpha(c)) {
            word_found = 0;
        }
    }

    // Close the file
    fclose(fp);

    // Return the word count
    return word_count;
}
