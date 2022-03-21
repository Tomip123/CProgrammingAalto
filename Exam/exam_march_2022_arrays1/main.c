#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Compares two integers and returns their comparison result.
 * \details This function defines the order of the elements by 
 *          returning (in a stable and transitive manner): 
 *          <0	The value pointed to by 'a' goes before the value pointed to by 'b'
 *           0	The value pointed to by 'a' is equivalent to the value pointed to by 'b'
 *          >0	The value pointed to by 'a' goes after the value pointed to by 'b'
 * 
 *          In other words, this function essentially calculates the difference
 *          of the values pointed by its arguments.
 * 
 * \param a A pointer to the integer that will be compared against the 
 *          value pointer by b.
 * \param b A pointer to the integer that will be compared against the 
 *          value pointer by a.
 * \return The comparison result
 */
int compare_ints_ascending(const void* a, const void* b) {
	return *(int*) a - *(int*) b;
}

/**
 * \brief Creates a sorted copy of an integer array of n elements in ascending order.
 * 
 * \details This function creates a sorted copy of the input array 
 *          by dynamically allocating the destination array 
 *          (i.e. you should allocate the memory for the destination array).
 *          The function should return a new array that contains the same 
 *          elements of the argument array, but its elements should be sorted in 
 *          ascending order. 
 * 
 * \param array The array to be copied and sorted.
 * \param n The number of elements in the array.
 * \return The ascending sorted copy of the array.
 * 
 * \note You don't need to free the memory for array.
 * 
 * \note  stdlib.h has some useful functions that might help you to sort the array.
 *        You might need the comparison function compare_ints_ascending if you prefer to 
 *        use stdlib function for sorting the array.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
int* copy_sorted_ascending(int* array, unsigned int n) {
	int* sorted_array = malloc(n * sizeof(int));
	memcpy(sorted_array, array, n * sizeof(int));
	qsort(sorted_array, n, sizeof(int), compare_ints_ascending);
	return sorted_array;
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
	// You can write your own test code here.
	printf("Test 1: array = {3, 2, 1, 4, 5} and n = 5\n");
	int array[5] = {3, 2, 1, 4, 5};
	int* new_array = copy_sorted_ascending(array, 5);
	for (int i = 0; i < 5; i++) {
	    printf("%d ", new_array[i]);
	}
	printf("\n\n");
	free(new_array);

	printf("Test 2: array = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10} and n = 10\n");

	int array2[10] = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10};
	int* new_array2 = copy_sorted_ascending(array2, 10);
	for (int i = 0; i < 10; i++) {
	    printf("%d ", new_array2[i]);
	}
	printf("\n\n");
	free(new_array2);

	printf("Test 3: array = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20} and n = 20\n");
	int array3[20] = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int* new_array3 = copy_sorted_ascending(array3, 20);
	for (int i = 0; i < 20; i++) {
	    printf("%d ", new_array3[i]);
	}
	free(new_array3);
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
}
