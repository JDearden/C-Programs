/******************************************************
 * Name: justinDearden_Lab1.c                          *
 * Purpose: Display multiple functions                 *
 * Author: Justin Dearden                              *
 * Date: July 8, 2018                                  *
 *******************************************************/

#include <iostream>
#include <math.h>

//Menu function for displaying the options on each while loop iteration
int menu(void) {
    printf("Lab 1\n-----\n");
    printf("1 - int Factorial(int n); \n");
    printf("2 - int Fibonacci(int n); \n");
    printf("3 - int Gcd(int x, int y); \n");
    printf("4 - double Power(int a, int b); \n");
    printf("5 - int digProduct (int x); \n");
    printf("0 - QUIT\n");
}

//Function declarations
int factorial1(int n);

int factorial2(int n);

int fibonacci1(int n);

int fibonacci2(int n);

int gcd1(int n1, int n2);

int gcd2(int n1, int n2);

int power1(int n1, int n2);

int power2(int n1, int n2);

int digProduct1(int n);

int digProduct2(int n);


int main() {
    //integers to control the while loop and switch selection for the functions
    int menuActive = 1;
    int menuSelection = 0;
    int selection;
    int n, y;
    
    //Menu is set to 1 making it an infinite loop until option 0 breaks out of it
    while (menuActive == 1) {
        
        //Displays the menu options
        menu();
        
        //Asking the user for an option and entering their choice into the switch statement
        printf("Please enter a selection: ");
        scanf("%d", &menuSelection);
        
        //Switch cases that reflect the various function choices
        switch (menuSelection) {
                /* Each switch option will first ask if the user wants a iterative or recursive option
                 * The if statement will check if their selection was either 1 or 2 - anything else gets a warning
                 * If the selection was good then the print statement will activate the function call and provide the output
                 * The switch will break sending it back to the menu selection screen
                 * */
            case 1: {
                printf("Iterative (1) or recursive (2)? ");
                scanf("%d", &selection);
                if (selection == 1) {
                    printf("Please enter a positive integer: ");
                    scanf("%d", &n);
                    if (n >= 0) {
                        printf("Iterative Answer: %d\n\n", factorial1(n));
                    } else {
                        printf("Invalid Input. \n\n");
                    }
                } else if (selection == 2) {
                    if (n >= 0) {
                        printf("Please enter a positive integer: ");
                        scanf("%d", &n);
                        printf("Recursive Answer: %d\n\n", factorial2(n));
                    } else {
                        printf("Invalid Input. \n\n");
                    }
                } else {
                    printf("Invalid Input\n");
                    break;
                }
            }
                break;
                
            case 2: {
                printf("Iterative (1) or recursive (2)? ");
                scanf("%d", &selection);
                if (selection == 1) {
                    if (n >= 0) {
                        printf("Please enter a positive integer: ");
                        scanf("%d", &n);
                        printf("Iterative Answer: %d\n\n", fibonacci1(n));
                    } else {
                        printf("Invalid Input. \n\n");
                    }
                } else if (selection == 2) {
                    if (n >= 0) {
                        printf("Please enter a positive integer: ");
                        scanf("%d", &n);
                        printf("Iterative Answer: %d\n\n", fibonacci2(n));
                    } else {
                        printf("Invalid Input. \n\n");
                    }
                } else {
                    printf("Invalid Input\n");
                    break;
                }
            }
                break;
                
            case 3: {
                printf("Iterative (1) or recursive (2)? ");
                scanf("%d", &selection);
                if (selection == 1) {
                    if (n >= 0 && y >= 0) {
                        printf("Enter the first positive integer: ");
                        scanf("%d", &n);
                        printf("Enter the second positive integer: ");
                        scanf("%d", &y);
                        printf("Iterative Answer: %d\n\n", gcd1(n, y));
                    } else {
                        printf("Invalid Input. \n\n");
                    }
                } else if (selection == 2) {
                    if (n >= 0 && y >= 0) {
                        printf("Enter the first positive integer: ");
                        scanf("%d", &n);
                        printf("Enter the second positive integer: ");
                        scanf("%d", &y);
                        printf("Iterative Answer: %d\n\n", gcd2(n, y));
                    } else {
                        printf("Invalid Input. \n\n");
                    }
                } else {
                    printf("Invalid Input\n");
                    break;
                }
            }
                break;
                
            case 4: {
                printf("Iterative (1) or recursive (2)? ");
                scanf("%d", &selection);
                if (selection == 1) {
                    if (n >= 0 && y >= 0) {
                        printf("Enter the first positive integer: ");
                        scanf("%d", &n);
                        printf("Enter the second positive integer: ");
                        scanf("%d", &y);
                        printf("Iterative Answer: %d\n\n", power1(n, y));
                    } else {
                        printf("Invalid Input. \n\n");
                    }
                } else if (selection == 2) {
                    if (n >= 0 && y >= 0) {
                        printf("Enter the first positive integer: ");
                        scanf("%d", &n);
                        printf("Enter the second positive integer: ");
                        scanf("%d", &y);
                        printf("Recursive Answer: %d\n\n", power2(n, y));
                    } else {
                        printf("Invlaid Input. \n\n");
                    }
                } else {
                    printf("Invalid Input\n");
                    break;
                }
            }
                break;
                
            case 5: {
                printf("Iterative (1) or recursive (2)? ");
                scanf("%d", &selection);
                if (selection == 1) {
                    if (n >= 0) {
                        printf("Please enter a positive integer: ");
                        scanf("%d", &n);
                        printf("Iterative Answer: %d\n\n", digProduct1(n));
                    } else {
                        printf("Invalid Input. \n\n");
                    }
                } else if (selection == 2) {
                    if (n >= 0) {
                        printf("Please enter a positive integer: ");
                        scanf("%d", &n);
                        printf("Iterative Answer: %d\n\n", digProduct2(n));
                    } else {
                        printf("Invalid Input. \n\n");
                    }
                } else {
                    printf("Invalid Input\n");
                    break;
                }
            }
                break;
                
            case 0: {
                menuActive = 2;
                printf("Goodbye! \n");
            }
                break;
                
            default: {
                printf("Invalid Input.\n");
                break;
            }
                
        }
        
    }
    
    return 0;
}

/* Pass in the integer value obtained in the switch case
 * i is checked against n and the loop counts to it performing the multiplication
 * storing the result inside the result variable - which is returned
 * */
int factorial1(int n) {
    
    int result = 1, i;
    for (i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
    
}

/* Pass in the integer value obtained in the switch case
 * n is checked to see if its less then 1 - if it is 1 is returned for printing
 * if n is larger than 1 - the return will be n multiplied by the function call again with n-1 counting down
 * */
int factorial2(int n) {
    
    if (n < 1) {
        return 1;
    } else {
        return n * factorial2(n - 1);
    }
}

/* Array is set to n + 2 to handle the case of 0
 * n is passed by the switch case and stored into the array fib[n+2]
 * */
int fibonacci1(int n) {
    int fib[n + 2];
    int i;
    
    //output for an 0 or 1 entry by the user
    fib[0] = 0;
    fib[1] = 1;
    
    for (i = 2; i <= n; i++) {
        //Add the previous 2 numbers then store the series inside the array
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    return fib[n];
}

/* n is passed in from the switch case
 * if n is 0 or 1 then those values are returned in order to handle those inputs
 * The function calls itself with n-1 and n-2 being applied the same way as the array except for
 * the function call
 * */
int fibonacci2(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci2(n - 1) + fibonacci2(n - 2);
}

/* Two integers are passed in from the switch case
 * The loop run condition checks that n1 is not the same as n2 - numbers that are equal get the same result
 * if condition will check if n1 is greater than n2 - if so will be subtracted from n1 until return
 * else will have n1 subtracted from n2 until return
 * */
int gcd1(int n1, int n2) {
    
    while (n1 != n2) {
        if (n1 > n2) {
            n1 -= n2;
        } else {
            n2 -= n1;
        }
    }
    
    return n1;
}

/* Two integers are passed in from the switch case
 * The if condition checks that n2 is not equal to 0 - if so 0 will be returned
 * the function calls itself with the values of n2 and n1 modulo n2 - reducing it to the GCD
 * */
int gcd2(int n1, int n2) {
    if (n2 != 0) {
        return gcd2(n2, n1 % n2);
    } else {
        return n1;
    }
}


/* Two integers are passed in from the switch case
 * if n2 does not equal 0 then the return will be the power function with the two input values
 * else 1 is just returned
 * */
int power1(int n1, int n2) {
    if (n2 != 0) {
        return pow(n1, n2);
    } else {
        return 1;
    }
}

/* Two integers are passed in from the switch case
 * if n2 does not equal 0 then the return will be n1 multiplied by the function - 1
 * to reduce the input values to zero
 * */
int power2(int n1, int n2) {
    if (n2 != 0) {
        return (n1 * power2(n1, n2 - 1));
    } else {
        return 1;
    }
}

/* One integer is passed in from the switch case
 * While n is greater than 0
 * int p will be multiplied by n modulo 10 and n will be divided by 10 to reach zero
 * */
int digProduct1(int n) {
    int p = 1;
    while (n > 0) {
        p *= (n % 10);
        n /= 10;
    }
    return p;
}

/* One integer is passed in from the switch case
 * if n is less then 10 that value will be returned
 * else - n will be modulo by 10 and multiplied by the function call with n divided by 10 to reach 0
 * */
int digProduct2(int n) {
    if (n < 10) {
        return n;
    } else {
        return (n % 10) * digProduct2(n / 10);
    }
}
