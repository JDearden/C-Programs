/******************************************************
 * Name: justinDearden_Lab2.c                          *
 * Purpose: Perform Binary and Sequential Searches     *
 * Author: Justin Dearden                              *
 * Date: July 8, 2018                                  *
 *******************************************************/

#include <stdio.h>

//Menu function for displaying the options on each while loop iteration
int menu(void) {
    printf("Lab 2\n-----\n");
    printf("1 - Sequential Search\n");
    printf("2 - Binary Search \n");
    printf("3 - QUIT \n");
}

//Function declarations
void loadArray(int nums[], int size);

int binarySearch(int nums[], int size, int key);

int sequentialSearch(int nums[], int size, int key);

int getKey();


int main(void) {
    
    //Variables for the array nums and the size of 500 elements
    int nums[500], size = 500;
    int menuSelection, key;
    
    loadArray(nums, size);
    
    while (1) {
        //Prints the menu function
        menu();
        
        //Asks the user for a selection to load in one of the switch cases
        printf("Please enter a selection: ");
        scanf("%d", &menuSelection);
        
        //Quit option to end the loop and terminate program
        if (menuSelection == 3) {
            printf("Goodbye!\n");
            break;
        }
        
        //Switch cases for the three options - each performs a print statement that calls on the function
        switch (menuSelection) {
            case 1: {
                key = getKey();
                printf("Number of comparison using sequential search is %d.\n\n", sequentialSearch(nums, size, key));
            }
                break;
                
            case 2: {
                key = getKey();
                printf("Number of comparison using binary search is %d.\n\n", binarySearch(nums, size, key));
            }
                break;
                
            default: {
                printf("Invalid Input.\n\n");
            }
                break;
        }
    }
    
    return 0;
    
}

//Load the values into the array, the values come from the main function
void loadArray(int nums[], int size) {
    
    int i;
    
    for (i = 1; i <= size; i++) {
        
        nums[i - 1] = i * i;
    }
    
}

int binarySearch(int nums[], int size, int key) {
    
    //Value for total that will be used to count the amount of times key is present
    //Values for the left and right options that will be used for sorting
    int total = 0;
    int leftOption = 1, rightOption = size - 1;
    
    while (leftOption <= rightOption) {
        
        //Sets the value of the middle options
        //rightOption is using the value sent in from the main function of 500
        int middle = leftOption + (rightOption - leftOption) / 2;
        
        total++;
        
        //Condition to check for perfect squares based on the middle value checked against the array
        if (nums[middle] == key) {
            
            printf("%d is a perfect square.\n", key);
            
            return total;
            
        }
        
        total++;
        
        //Sort through the array using the left and right search options
        if (nums[middle] < key) {
            
            leftOption = middle + 1;
            
        } else {
            
            rightOption = middle - 1;
        }
        
    }
    
    printf("%d is not a perfect square.\n", key);
    
    return total;
    
}

/* The size of the array is loaded in from the main function
 * along with the value of key
 * */
int sequentialSearch(int nums[], int size, int key) {
    
    //comparison is set to 0 and will be counted up for each occurrence of the key value
    int i, total = 0;
    
    //Comparing i to the size of the array (500 elements)
    for (i = 0; i < size; i++) {
        //Each time the key value is found the comparison will increment 1
        total++;
        
        //Condition to check for the value of the key inside the array elements to determine if its a perfect square
        if (nums[i] == key) {
            
            printf("%d is a perfect square.\n", key);
            
            //returns the total now inside total
            return total;
            
        }
        
    }
    
    //If the value is not a perfect square the else statement will be printed stating otherwise
    printf("%d is not a perfect square.\n", key);
    
    return total;
    
}

int getKey() {
    
    int key;
    
    while (1) {
        //Asks the user for the input value and that value is stored in the int key
        printf("Please enter a positive number to search (< 250,000): ");
        scanf("%d", &key);
        
        //Condition to make sure the key is above 1 and below 250,000
        if (key < 1 || key > 250000) {
            printf("Invalid Input.\n\n");
            
        } else {
            
            break;
        }
        
    }
    
    //Return the value of key to the print function inside the switch statement, will be used for printing
    return key;
}
