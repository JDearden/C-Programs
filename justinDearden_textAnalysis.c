/******************************************************
 * Name: textAnalysis.c                                *
 * Purpose: Different String Search Options            *
 * Author: Justin Dearden                              *
 * Date: June 22, 2018                                 *
 *******************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

//Function prototypes
int searchByLength(char text[10][80], int n, int wordLen);

int searchByWord(char text[10][80], int n, char *ch);

int searchByCharacter(char text[10][80], int n, char ch);

void readText(char text[][MAX_LINE_LENGTH], int n);

//Menu function to display options to the user
int menu() {
    printf("Text Analysis\n");
    printf("-----\n");
    printf("1 - Search By Character\n");
    printf("2 - Search By Word\n");
    printf("3 - Search By Length\n");
    printf("0 - Quit\n");
}

int main(void) {
    
    //Variables for the menu and switch selection options
    int menuActive = 1;
    int selection;
    int lineSelection = 1;
    
    //Variables used to pass into the functions
    int numberOfLines, wordLength, result, searchChar;
    
    //Arrays used to pass into the functions
    char lines[10][80], keyword[20];
    
    //Initial request for number of lines from the user
    printf("Enter the number of lines(<10): ");
    scanf("%d", &numberOfLines);
    
    //Loop condition to obtain the number of rows the user wants
    while (numberOfLines < 1 || numberOfLines > 10) {
        printf("Invalid Input. \n");
        
        printf("Enter the number of lines(<10): ");
        scanf("%d", &numberOfLines);
    }
    
    //Print out asking to enter text
    printf("Enter %d text lines: \n", numberOfLines);
    
    //Condition to check if number of lines entered is within range - calls the readText function
    if (numberOfLines <= 10 || numberOfLines < 0) {
        
        //function - passing in the lines array and number of lines chosen
        readText(lines, numberOfLines);
        
    }
    
    //Loop to keep the menu running and prompting the user for function calls
    while (menuActive == 1) {
        
        //Display menu options and ask for their choice
        menu();
        
        printf("\nPlease Enter a Selection :");
        scanf("%d", &selection);
        
        //Switch cases for each menu option
        switch (selection) {
            case 1:
                printf("\nEnter a character to search: ");
                scanf(" %c", &searchChar);
                
                //Function call passing in the array, number of lines chosen and the character letter to be searched
                result = searchByCharacter(lines, numberOfLines, searchChar);
                
                //Print results from the function
                printf("Number of occurrence of \"%c\" = %d. \n", searchChar, result);
                
                break;
            case 2:
                printf("Enter a keyword (less than 20 characters): \n");
                scanf(" %s", keyword);
                
                //Function call passing in the array, number of lines chosen and the keyword to be searched for
                result = searchByWord(lines, numberOfLines, keyword);
                
                //Print results from the function
                printf("Number of occurrence of \"%s\" = %d. \n", keyword, result);
                break;
                
            case 3:
                printf("Enter search Length : \n");
                scanf(" %d", &wordLength);
                
                //Function call passing in the array, number of lines chosen and the length of a word to be searched for
                result = searchByLength(lines, numberOfLines, wordLength);
                
                //Print results from the function
                printf("Number of words with length \"%d\" = %d. \n", wordLength, result);
                break;
                
            case 0:
                //Changes the menuActive variable to 2 - ending the continuous loop
                menuActive = 2;
                break;
                
            default:
                printf("Invalid Input.\n");
                
        }
    }
    
    printf("Goodbye!\n");
    
}

void readText(char text[][MAX_LINE_LENGTH], int n) {
    
    //Loop for reading in the text on the number of lines specified
    for (int i = 0; i < n; i++) {
        
        /* I tried using (gets) my compiler said it was a dangerous command and wouldn't let me continue. I tried a
         * few different variants of the (%[^]s) that included things like \t and other formats. This one was the only
         * one that worked, I believe due to the space in front clearing the buffer. This (%[^]s) wasn't covered in class
         * but I had to research it on stack overflow to get the input working.
         * */
        scanf(" %[^\n]s", text[i]);
    }
}

int searchByCharacter(char text[][MAX_LINE_LENGTH], int n, char c) {
    
    int characterResult = 0;
    
    for (int i = 0; i < n; i++) {
        
        //Pointer to the current line in the array
        char *currentLine = text[i];
        
        int n = 0;
        
        //Loop that terminates when the delimiter character is found
        while (currentLine[n] != '\0') {
            
            if (currentLine[n] == c) {
                
                //increments the results - will be passed back for printing
                characterResult++;
                
            }
            
            //Increment to start on the next character
            n++;
            
        }
        
    }
    
    //Returned value for printing
    return characterResult;
    
}

int searchByWord(char text[][MAX_LINE_LENGTH], int n, char *keyword) {
    
    //Holds the number of results when a keyword is found
    int keywordResult = 0;
    
    for (int i = 0; i < n; i++) {
        
        int n = 0;
        //Holds the size (num of characters) to be searched for
        int wordLength = 0;
        //Assumption #3 - max size of characters in any of the words is 20
        char currentWord[20];
        //Pointer to the current line in the array
        char *wordLine = text[i];
        
        //Loop that terminates when the delimiter character is found
        while (wordLine[n] != '\0') {
            
            //Assumption #4 - delimiters to tokenize the lines - changed the names from the searchByLength function, for the pointers
            if (wordLine[n] == ' ' || wordLine[n] == '\n' || wordLine[n] == ',' || wordLine[n] == '.' ||
                wordLine[n] == ';') {
                
                //Reaches the end of the word by the delimiter
                currentWord[wordLength] = '\0';
                
                //calling a string compare against the current word in the array and the keyword
                int wordMatch = strcmp(currentWord, keyword);
                
                //If the words match increment keywordResult - to be passed back to main
                if (wordMatch == 0) {
                    
                    keywordResult++;
                    
                }
                
                //Resets the wordLength back to 0
                wordLength = 0;
                
                n++;
                
            }
            
            //Will append a character to the current word
            currentWord[wordLength] = wordLine[n];
            
            //Increments by one since the character isn't a delimiter
            wordLength++;
            
            //Moves to the next character
            n++;
            
        }
        
    }
    
    return keywordResult;
    
}

int searchByLength(char text[][MAX_LINE_LENGTH], int n, int wordLen) {
    
    //Result for the number of words equal to the length of the word
    int wordLengthResults = 0;
    
    for (int i = 0; i < n; i++) {
        
        //Pointer to the current line in the array
        char *workingLine = text[i];
        
        int n = 0;
        int wordLength = 0;
        
        //Loop that terminates when the delimiter character is found
        while (workingLine[n] != '\0') {
            
            //Assumption #4 - delimiters to tokenize the lines
            if (workingLine[n] == ' ' || workingLine[n] == '\n' || workingLine[n] == ',' || workingLine[n] == '.' ||
                workingLine[n] == ';') {
                
                //Condition to check the wordLength against the wordLen passed in
                if (wordLength == wordLen) {
                    
                    //Increments the results - to be passed back to main
                    wordLengthResults++;
                    
                }
                
                //Resets the wordLength back to 0
                wordLength = 0;
                
                n++;
                
            }
            
            //Increments by one since the character isn't a delimiter
            wordLength++;
            
            //Moves to the next character
            n++;
            
        }
        
    }
    
    return wordLengthResults;
    
}
