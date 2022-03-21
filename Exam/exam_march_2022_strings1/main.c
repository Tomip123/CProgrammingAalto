#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Converts all non-alphabetical characters in a null-terminated 
 *        string to lower case a, 'a'.
 * 
 * \details This function finds all non-alphabetical characters in a string and 
 *          converts these characters into lower-case 'a'. It changes the found 
 *          non-alphabetical characters inplace so that no dynamic allocation is 
 *          needed.
 * 
 * \param str The null-terminated string with some non-alphabetical characters.
 * 
 * \note stdlib provides useful character handling functions in ctype.h. 
 *       ctype.h documentation also states different character classes,  
 *       including alphabetical characters.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
void convert_non_alphabetical(char* str) {
	// Iterate through the string
	int i = 0;
	while (str[i] != '\0') {
		// If current character is not alphabetical
		if (!isalpha(str[i])) {
			str[i] = 'a';
		}
		i++;
	}

	return;
}

/**
 * \brief conducts the tests for your implementation.
 * 
 * \details You are strongly encouraged to test your implementation
 * using this function. Try to create at least three test cases to check
 * whether your function implementation is correct.
 * 
 */
void my_tests(void) {
	
	// Test 1
	printf("Test 1: str = \"Hello World!\"\n");
	char str1[] = "Hello World!";
	convert_non_alphabetical(str1);
	printf("Output: %s\n\n", str1);

	// Test 2
	printf("Test 2: str = \"Hello World! 123\"\n");
	char str2[] = "Hello World! 123";
	convert_non_alphabetical(str2);
	printf("Output: %s\n\n", str2);

	// Test 3
	printf("Test 3: str = \"Hello World! 123 abc\"\n");
	char str3[] = "Hello World! 123 abc";
	convert_non_alphabetical(str3);
	printf("Output: %s\n\n", str3);

	// Test 4
	printf("Test 4: str = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\n");
	char str4[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	convert_non_alphabetical(str4);
	printf("Output: %s\n\n", str4);

	// Test 5
	printf("Test 5: str = \"abcdefghijklmnopqrstuvwxyz\"\n");
	char str5[] = "abcdefghijklmnopqrstuvwxyz";
	convert_non_alphabetical(str5);
	printf("Output: %s\n\n", str5);

	// Test 6
	printf("Test 6: str = \"1234567890\"\n");
	char str6[] = "1234567890";
	convert_non_alphabetical(str6);
	printf("Output: %s\n\n", str6);
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
}
