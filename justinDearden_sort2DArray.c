/******************************************************
 * Name: sort2DArray.c                                 *
 * Purpose: Generate a 2D array and sort the elements  *
 * Author: Justin Dearden                              *
 * Date: July 13, 2018                                 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int A[100][100], int N, int M);

int sortMatrix(int A[100][100], int rowsize, int colsize);

void displayMatrix(int A[100][100], int N, int M);

int main(void) {
    
    int rows, columns;
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    //Check condition for the number of rows entered
    if (rows <= 99) {
        printf("Enter number of columns: ");
        scanf("%d", &columns);
        //Check condition for the number of columns entered
        if (columns <= 99) {
            
            int A[100][100];
            
            //Call functions to generate / display / sort the array
            fillMatrix(A, rows, columns);
            sortMatrix(A, rows, columns);
            displayMatrix(A, rows, columns);
        } else {
            printf("Invalid Size!\n");
        }
        
    } else {
        printf("Invalid Size!\n");
    }
    
    return 0;
    
}

/* Function to fill the array with random elements
 * Takes the input A[], int N, int M which are passed in from (A, rows, columns inside main)
 */
void fillMatrix(int A[100][100], int N, int M) {
    //Generate completely random variables
    srand(time(NULL));
    
    //Loop to fill the array with numbers between 0 and 100
    for (int i = 0; i < N; i++) {
        for (int n = 0; n < M; n++) {
            A[i][n] = rand() % 99 + 1;
        }
    }
    
    //Print out the array before the elements get sorted
    printf("Before Sorting: \n");
    for (int i = 0; i < N; i++) {
        for (int n = 0; n < M; n++) {
            printf("%3.1d ", A[i][n]);
        }
        printf("\n");
    }
}

/* Function to sort the elements of the array
 * Takes the input A[], int N, int M which are passed in from (A, rows, columns inside main)
 */
int sortMatrix(int A[100][100], int rowsize, int colsize) {
    
    int temp;
    
    //Series of for loops to sort in a descending order
    for (int i = 0; i < rowsize; i++) {
        
        for (int n = 0; n < colsize; n++) {
            
            for (int c = 0; c < rowsize; c++) {
                
                for (int j = 0; j < colsize; j++) {
                    if (A[i][n] > A[c][j]) {
                        temp = A[i][n];
                        A[i][n] = A[c][j];
                        A[c][j] = temp;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
}

/* Function to display the array and its elements
 * Takes the input A[], int N, int M which are passed in from (A, rows, columns inside main)
 */
void displayMatrix(int A[100][100], int N, int M) {
    
    printf("\nAfter Sorting: \n");
    
    //Loop for displaying the elements of the array
    for (int i = 0; i < N; i++) {
        for (int n = 0; n < M; n++) {
            printf("%3.1d ", A[i][n]);
        }
        printf("\n");
    }
}
