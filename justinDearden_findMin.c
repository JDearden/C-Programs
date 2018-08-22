/******************************************************
 * Name: findMin.c                                     *
 * Purpose: Generate numbers & find the minimum        *
 * Author: Justin Dearden                              *
 * Date: July 13, 2018                                 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function declarations
void fillArray(int nums[], int n);

int recursiveMinimum(int nums[], int size);

int findFreq(int nums[], int size, int key);

void displayArray(int nums[], int size);

int main(void) {
    
    //Generate completely random variables
    srand(time(NULL));
    
    //Array and size of Array
    int numList[100], size = 100;
    
    //Call to the fillArray function - passing the array and size variables
    fillArray(numList, size);
    
    /* Declaring two variables that will perform the function calls
     * int minimum will return the recursive search for the smallest element of the array
     * int find will return return the amount of times the smallest element appears
     */
    int minimum = recursiveMinimum(numList, size);
    int find = findFreq(numList, size, minimum);
    
    //Displays the array of 100 elements
    displayArray(numList, size);
    
    //Formatted print out and function calls to find the minimum element and its frequency
    printf("\nThe Minimum element is: %d \n", minimum);
    printf("The frequency of %d is: %d \n", minimum, find);
    
    return 0;
}

/* Loop to fill the array with numbers
 * Takes the input nums[] and int n which are passed in from (numList[] and size inside main)
 */
void fillArray(int nums[], int n) {
    for (int i = 0; i < n; ++i) {
        nums[i] = 1 + (rand() % 1000);
    }
}

/* Recursive function to determine the lowest element
 * Takes the input nums[] and int size which are passed in from (numList[] and size inside main)
 */
int recursiveMinimum(int nums[], int size) {
    if (size == 1) {
        return nums[0];
    } else {
        //Recursive call with the array and size
        int minimum = recursiveMinimum(nums, size - 1);
        
        //Condition check for the variable minimum to set the lowest value
        if (minimum > nums[size - 1]) {
            minimum = nums[size - 1];
        }
        
        return minimum;
    }
}

/* Function that performs a loop to find the number of times the lowest element appears
 * Takes the input nums[] & int size & int key,
 * which are passed in from (numList[] and size and minimum from inside main)
 */
int findFreq(int nums[], int size, int key) {
    int count = 0;
    
    //Loop to find the number of times the lowest element is inside the array
    for (int i = 0; i < size; ++i) {
        
        //If any element of the array equals the key "minimum value" count will increment 1
        if (nums[i] == key) {
            count++;
        }
    }
    
    //Returns the number of times the lowest element appears
    return count;
}

/* Function to display the array and its randomly generated elements
 * Takes the input nums[] and int size which are passed in from (numList[] and size inside main)
 */
void displayArray(int nums[], int size) {
    int count = 0;
    
    //Print out the opening message
    printf("Array elements are: \n");
    
    for (int i = 0; i < size; i++) {
        printf("%3.1d \t", nums[i]);
        
        if (++count == 10) {
            printf("\n");
            count = 0;
        }
    }
    
}
