/******************************************************
 * Name: Lab3.c                                        *
 * Purpose: Generate numbers, load array, sort array   *
 * Author: Justin Dearden                              *
 * Date: July 16, 2018                                 *
 *******************************************************/

#include <stdio.h>
//#include <stdlib.h>
#include <time.h>

#define SIZE 30

void loadArray(int *nums, int size);

void bubbleSort(int *nums, int size);

void swap(int *x, int *y);

void printArray(int *nums, int size);

void loadMenu() {
    
    printf("Lab 3\n");
    printf("-------\n");
    printf("1 - Load Array\n");
    printf("2 - Print Array\n");
    printf("3 - Sort Array\n");
    printf("0 - Exit\n");
    
}


int main() {
    
    //Variables for the menu switch case and array
    int menuActive = 1;
    int menuSelection;
    int numList[SIZE];
    
    //Loads the menu options
    loadMenu();
    
    //While loop to keep the program running
    while (menuActive == 1) {
        printf("Please make a selection: ");
        scanf("%d", &menuSelection);
        
        //Switch cases to call the functions and do print outs
        switch (menuSelection) {
            case 1:
                loadArray(numList, SIZE);
                printf("Array was loaded: \n");
                break;
            case 2:
                printf("Array Elements: \n");
                printArray(numList, SIZE);
                break;
            case 3:
                printf("Sorted Array Elements: \n");
                bubbleSort(numList, SIZE);
                printArray(numList, SIZE);
                break;
            case 0:
                menuActive = 0;
                break;
            default:
                printf("Invalid Selection! \n");
        }
    }
    
    return 0;
}


void loadArray(int *nums, int size) {
    
    //Generate random integers each iteration
    srand(time(NULL));
    
    //Loop to fill the array with integers
    for (int i = 0; i < SIZE; i++) {
        *(nums + i) = rand() % 50;
    }
}


void bubbleSort(int *nums, int size) {
    
    for (int i = 0; i < SIZE; i++) {
        for (int n = 0; n < SIZE - i - 1; n++) {
            if (*(nums + n) < *(nums + n + 1)) {
                swap(nums + n, nums + n + 1);
            }
        }
    }
}


void swap(int *x, int *y) {
    
    int temp;
    
    //Simple swap function using a temp value to perform the action
    temp = *x;
    *x = *y;
    *y = temp;
}


void printArray(int *nums, int size) {
    
    //Loop to print out the array elements
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t", *(nums + i));
    }
    
    printf("\n");
}
