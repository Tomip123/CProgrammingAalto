#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Counts the number of cleared bits (value 0) in a byte array of n elements.
 * 
 * \details This function counts the number clear bits in a byte array. 
 *          For example, if array = {0xA3, 0x58} and n = 2, the array 
 *          bytes has binary values 1010 0011 0101 1000, and the function
 *          returns 9. Since 
 *          1010 0011 0101 1000
 *           ^ ^ ^^   ^ ^   ^^^ 
 *          has 9 clear bits.
 * 
 * \param array A byte array of n elements.
 * \param n The number of bytes in array.
 * \return The number of clear bits in the bytes of array.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
unsigned int count_clear_bits_in_array(unsigned char* array, unsigned int n) {
	unsigned int count = 0;
	// Loop through each element in the array
	for (unsigned int i = 0; i < n; i++) {
		// Loop through each bit in the element
		for (int j = 0; j < 8; j++) {
			// If the bit is 0, increment the count
			if ((array[i] & (1 << j)) == 0) {
				count++;
			}
		}
	}
	return count;

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
	printf("Test 1: array = {0xA3, 0x58}, n = 2\n");
	unsigned char array1[] = {0xA3, 0x58};
	unsigned int n1 = 2;
	unsigned int count1 = count_clear_bits_in_array(array1, n1);
	printf("Output: %d\n\n", count1);

	// Test 2
	printf("Test 2: array = {0xA3, 0x58, 0xA3, 0x58}, n = 4\n");
	unsigned char array2[] = {0xA3, 0x58, 0xA3, 0x58};
	unsigned int n2 = 4;
	unsigned int count2 = count_clear_bits_in_array(array2, n2);
	printf("Output: %d\n\n", count2);

	// Test 3
	printf("Test 3: array = {0xB3, 0x58, 0xA3, 0x58}, n = 4\n");
	unsigned char array3[] = {0xB3, 0x58, 0xA3, 0x58};
	unsigned int n3 = 4;
	unsigned int count3 = count_clear_bits_in_array(array3, n3);
	printf("Output: %d\n\n", count3);
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
}
