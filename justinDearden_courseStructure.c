/*******************************************************
 * Name: courseStructure.c                             *
 * Purpose: Reading & writing course data              *
 * Author: Justin Dearden                              *
 * Date: August 5, 2018                                *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct CourseInfo {
    int courseID;
    char courseName[40];
    char courseCode[10];
    char Term[6];
    int courseSections[3];
};

int loadCourseInfo(struct CourseInfo courseData[]);

int addCourseInfo(struct CourseInfo courseData[], int courseSize);

void displayCourseInfo(struct CourseInfo courseData[], const int courseSize);

void searchCourseID(struct CourseInfo courseData[], int courseSize);

void searchCourseName(struct CourseInfo courseData[], int courseSize);

void searchCourseTerm(struct CourseInfo courseData[], int courseSize);

void saveCourseInfo(struct CourseInfo courseData[], int courseSize);

//Displays the menu table
int menu() {
    printf("Assignment 3\n");
    printf("-----------\n");
    printf("1. Add a new course\n");
    printf("2. Search for a course by course ID\n");
    printf("3. Search for a course by course name\n");
    printf("4. Search for all courses by term\n");
    printf("5. Display course data\n");
    printf("6. Save course data\n");
    printf("7. EXIT\n");
}

int main() {

    //Variables that will be used for menu functions, saving and passing into the functions
    struct CourseInfo courseData[20];
    int courseSize = loadCourseInfo(courseData);
    int menuSelection;
    int menuActive = 1;

    //Continuous menu loop for selection
    while (menuActive == 1) {

        menu();

        printf("Please enter a selection: ");
        scanf("%d", &menuSelection);

        switch (menuSelection) {
            case 1: {
                courseSize = addCourseInfo(courseData, courseSize);
            }
                break;
            case 2: {
                searchCourseID(courseData, courseSize);
            }
                break;
            case 3: {
                searchCourseName(courseData, courseSize);
            }
                break;
            case 4: {
                searchCourseTerm(courseData, courseSize);
            }
                break;
            case 5: {
                displayCourseInfo(courseData, courseSize);
            }
                break;
            case 6: {
                saveCourseInfo(courseData, courseSize);
                printf("Data has been saved!\n\n");
            }
                break;
            case 7: {

                char saveData;

                printf("Do you want to save course data (Y/N): ");
                scanf(" %c", &saveData);

                saveData = toupper(saveData);

                //Will call the save function depending on the input from the user
                switch (saveData) {
                    case 'Y': {
                        //Save function and print outs, plus shutting off the menu loop
                        saveCourseInfo(courseData, courseSize);
                        printf("All course information is saved.\n");
                        printf("Goodbye.\n");
                        menuActive = 0;
                    }
                        break;
                    case 'N': {
                        //No save function called, simply ends the loop
                        printf("Goodbye.\n");
                        menuActive = 0;
                    }
                        break;
                    default: {
                        printf("Invalid Selection!\n");
                    }
                        break;
                }
            }
                break;

            default: {
                printf("Invalid Selection!\n");
            }
                break;

        }
    }

    return 0;
}

int loadCourseInfo(struct CourseInfo courseData[]) {

    int i = 0;
    char tempData[15];

    //Open the csv file from the folder destination
    FILE *openPtr = fopen("courseInfo.csv", "r");

    //Error message if the file cant be opened
    if (openPtr == NULL) {
        printf("Cannot load file\n");
        exit;
    }

    //Loop to load in data that is stored in the csv file
    while (!feof(openPtr)) {

        //Loads the course names
        fscanf(openPtr, "%[^,],", courseData[i].courseName);

        //Loads the course code (in three parts - then combined into one code)
        fscanf(openPtr, "%[^,],", tempData);
        strcpy(courseData[i].courseCode, tempData);

        fscanf(openPtr, "%[^,],", tempData);
        strcat(courseData[i].courseCode, tempData);

        //Includes the '-' for styling
        strcat(courseData[i].courseCode, "-");

        fscanf(openPtr, "%[^,],", tempData);
        strcat(courseData[i].courseCode, tempData);

        //Loads the sections (all three spots from 0-2)
        fscanf(openPtr, "%d,%d,%d,", &courseData[i].courseSections[0], &courseData[i].courseSections[1],
               &courseData[i].courseSections[2]);

        //Loads the term data
        fscanf(openPtr, "%[^,],", tempData);
        strcpy(courseData[i].Term, tempData);

        fscanf(openPtr, "%s\n", tempData);
        strcat(courseData[i].Term, tempData);

        //Loads in course ID plus increments it
        courseData[i].courseID = i + 1;
        i++;

    }

    fclose(openPtr);

    printf("\n");

    return i;
};

int addCourseInfo(struct CourseInfo courseData[], int courseSize) {

    //Creates a course ID that incremented by 1 automatically for new entries
    courseData[courseSize].courseID = courseData[courseSize - 1].courseID + 1;

    int n = 0;

    //Temp variable used for combining strings in the add function
    char completeCode[15] = "\0";

    //Enter the course name
    printf("Enter course name: ");
    scanf("%s", courseData[courseSize].courseName);

    /* Enter the three different codes in order to make the completed course code
     * values will be stored into a temporary array then copied into the .courseCode array
     */
    //Enter the Faculty Code
    printf("Enter faculty code (format xx): ");
    scanf("%s", completeCode);
    strcpy(courseData[courseSize].courseCode, completeCode);

    //Enters the Faculty Code
    printf("Enter subject code (format xx): ");
    scanf("%s", completeCode);
    strcat(courseData[courseSize].courseCode, completeCode);

    //Enters the "-" to meet the visual styling
    strcat(courseData[courseSize].courseCode, "-");

    //Enters the Level code
    printf("Enter level code (format xxx): ");
    scanf("%s", completeCode);
    strcat(courseData[courseSize].courseCode, completeCode);

    while (n < courseSize) {

        //Condition to check if the entered course code matches one stored in the struct
        if (strcmp(courseData[n].courseCode, courseData[courseSize].courseCode) == 0) {

            //Error stating what the repeated course code is
            printf("Invalid: Repeated course code (%s)! \n", courseData->courseCode);

            //Enter the Faculty Code
            printf("Enter faculty code (format xx): ");
            scanf("%s", &completeCode);
            strcpy(courseData[courseSize].courseCode, completeCode);

            //Enters the Faculty Code
            printf("Enter subject code (format xx): ");
            scanf("%s", &completeCode);
            strcpy(courseData[courseSize].courseCode, completeCode);

            //Enters the "-" to meet the visual styling
            strcpy(courseData[courseSize].courseCode, "-");

            //Enters the Level code
            printf("Enter level code (format xxx): ");
            scanf("%s", &completeCode);
            strcpy(courseData[courseSize].courseCode, completeCode);

            n = 0;

        }

        n++;
    }

    int sectionSelection;

    printf("Enter number of sections: ");
    scanf("%d", &sectionSelection);

    /* Switch case to handle the number of course sections the user picks
     * Three options, each having conditions to check whether section codes are the same
     */
    switch (sectionSelection) {
        case 1: {
            //Enters in the first section code into courseSections at position 0
            printf("Enter section code 1: ");
            scanf("%d", &courseData[courseSize].courseSections[0]);

            //Condition to make the remaining section code positions equal to 0
            courseData[courseSize].courseSections[1] = 0;
            courseData[courseSize].courseSections[2] = 0;

        }
            break;

        case 2: {
            //Enters in the first & second section codes into courseSections at position 0 & 1
            printf("Enter section code 1: ");
            scanf("%d", &courseData[courseSize].courseSections[0]);
            printf("Enter section code 2: ");
            scanf("%d", &courseData[courseSize].courseSections[1]);

            //Condition to check if the two section codes are equal to one another
            while (courseData[courseSize].courseSections[1] == courseData[courseSize].courseSections[0]) {
                //Error print out and asking to reenter the second section code again
                printf("Invalid: Repeated section code!\n");
                printf("Enter section code 2: ");
                scanf("%d", &courseData[courseSize].courseSections[1]);
            }

            //Condition to set the third section code to 0
            courseData[courseSize].courseSections[2] = 0;
        }
            break;

        case 3 : {
            //Enters in the first & second section codes into courseSections at position 0 & 1
            printf("Enter section code 1: ");
            scanf("%d", &courseData[courseSize].courseSections[0]);
            printf("Enter section code 2: ");
            scanf("%d", &courseData[courseSize].courseSections[1]);

            //Condition to check if the two section codes are equal to one another
            while (courseData[courseSize].courseSections[1] == courseData[courseSize].courseSections[0]) {
                printf("Invalid: Repeated section code!\n");
                printf("Enter section code 2: ");
                scanf("%d", &courseData[courseSize].courseSections[1]);
            }

            //Enters in the third section code into courseSections at position 2
            printf("Enter section code 3: ");
            scanf("%d", &courseData[courseSize].courseSections[2]);

            //Condition to check if the third & second section codes are equal to one another
            while (courseData[courseSize].courseSections[2] == courseData[courseSize].courseSections[0] ||
                   courseData[courseSize].courseSections[2] == courseData[courseSize].courseSections[1]) {
                printf("Invalid: Repeated section code!\n");
                printf("Enter section code 3: ");
                scanf("%d", &courseData[courseSize].courseSections[2]);
            }
        }
            break;
    }

    printf("\n");

    //Enters the semester (S, F or W) into the .Term
    printf("Enter semester (S, F or W): ");
    scanf("%s", courseData[courseSize].Term);

    //Enters the year into the temporary variable
    printf("Enter year (format yyyy): ");
    scanf("%s", completeCode);

    //Combines the Semester identifier with the temporary variable to get time .Term code
    strcat(courseData[courseSize].Term, completeCode);

    printf("Course Added.\n\n");

    //Returns the completed course entry so it can be displayed or included in other search functions
    return ++courseSize;

}

void displayCourseInfo(struct CourseInfo courseData[], const int courseSize) {

    //Prints out the headings and dashed line (as per the styling in the sample run through)
    printf("\n%-5s%-15s%-10s%-7s%-11s\n", "ID", "Name", "Code", "Term", "Sections");
    printf("---------------------------------------------\n");

    //Loop to print out the data
    for (int i = 0; i < courseSize; i++) {

        //Prints out the formatted data
        printf("%-5d%-15s%-10s%-6s %-2d,%-2d,%-2d\n", courseData[i].courseID, courseData[i].courseName,
               courseData[i].courseCode, courseData[i].Term, courseData[i].courseSections[0],
               courseData[i].courseSections[1], courseData[i].courseSections[2]);
    }

    printf("\n");

}

void searchCourseID(struct CourseInfo courseData[], int courseSize) {

    int courseID;

    //Will be used to search for the ID
    printf("Enter course ID: ");
    scanf("%d", &courseID);

    printf("\n");

    //Loop to cycle through the data checking for the courseID
    for (int i = 0; i < courseSize; i++) {

        if (courseID == courseData[i].courseID) {
            //Prints out the headings and dashed line (as per the styling in the sample run through)
            printf("%-5s%-15s%-10s%-7s%-11s\n", "ID", "Name", "Code", "Term", "Sections");
            printf("---------------------------------------------\n");

            //Prints out the formatted data when and ID has been found
            printf("%-5d%-15s%-10s%-6s %-2d,%-2d,%-2d\n", courseData[i].courseID, courseData[i].courseName,
                   courseData[i].courseCode, courseData[i].Term, courseData[i].courseSections[0],
                   courseData[i].courseSections[1], courseData[i].courseSections[2]);

            printf("\n");

            return;

        }
    }

    printf("Course ID %d was not found.\n", courseID);
    printf("\n");

}

void searchCourseName(struct CourseInfo courseData[], int courseSize) {

    char courseName[40];

    //Stores the course name to be searched for in a string
    printf("Enter course Name: ");
    scanf("%s", courseName);

    printf("\n");

    //Loop to cycle through the data checking for the course name
    for (int i = 0; i < courseSize; i++) {
        //Checking for the entered course name against what is in the data
        if (strcmp(courseData[i].courseName, courseName) == 0) {
            printf("%-5s%-15s%-10s%-7s%-11s\n", "ID", "Name", "Code", "Term", "Sections");
            printf("---------------------------------------------\n");

            //Prints out the formatted data when and course name has been found
            printf("%-5d%-15s%-10s%-6s %-2d,%-2d,%-2d\n", courseData[i].courseID, courseData[i].courseName,
                   courseData[i].courseCode, courseData[i].Term, courseData[i].courseSections[0],
                   courseData[i].courseSections[1], courseData[i].courseSections[2]);

            printf("\n");

            return;

        }
    }
    printf("Course name %s was not found\n", courseName);
    printf("\n");
}

void searchCourseTerm(struct CourseInfo courseData[], int courseSize) {

    //Variables used to create the course term search
    char semester[6];
    char year[6];
    char searchDate[12];

    printf("\n");

    printf("Enter semester (S, F or W): ");
    scanf("%s", semester);

    printf("Enter year (format yyyy): ");
    scanf("%s", year);

    //Combines the semester and year variables that will be used to search
    strcpy(searchDate, semester);
    strcat(searchDate, year);

    printf("\n");

    //Loop to cycle through the data checking for the course term
    for (int i = 0; i < courseSize; i++) {
        //Checking for the entered course term against what is in the data
        if (strcmp(courseData[i].Term, searchDate) == 0) {
            printf("%-5s%-15s%-10s%-7s%-11s\n", "ID", "Name", "Code", "Term", "Sections");
            printf("---------------------------------------------\n");

            //Prints out the formatted data when and course term has been found
            printf("%-5d%-15s%-10s%-6s %-2d,%-2d,%-2d\n", courseData[i].courseID, courseData[i].courseName,
                   courseData[i].courseCode, courseData[i].Term, courseData[i].courseSections[0],
                   courseData[i].courseSections[1], courseData[i].courseSections[2]);

            printf("\n");

            return;

        }
    }

    printf("Course term %s was not found\n", searchDate);
    printf("\n");
}

void saveCourseInfo(struct CourseInfo courseData[], int courseSize) {

    //Open the csv file from the folder destination
    FILE *openPtr = fopen("courseInfo.csv", "w");

    //Error message if the file cant be opened
    if (openPtr == NULL) {
        printf("Cannot open file");
        exit(1);
    }

    //Loop to write all the info to the csv file
    for (int i = 0; i < courseSize; i++) {

        //Formatted fprintf to create the separation in the file and print the data
        fprintf(openPtr, "CourseID,%d,\nCourseName,%s,\nCourseCode,%s,\nTerm,%c%c%c%c%c,\nSections,%d,%d,%d\n",
                courseData[i].courseID = i + 1,
                courseData[i].courseName, courseData[i].courseCode, courseData[i].Term[0], courseData[i].Term[1],
                courseData[i].Term[2], courseData[i].Term[3],
                courseData[i].Term[4], courseData[i].courseSections[0], courseData[i].courseSections[1],
                courseData[i].courseSections[2]);

    }

    fclose(openPtr);

}