#include <stdio.h>

struct student {
    char firstname[40];
    char lastname[40];
    int id;
    float GPA;
    int year;
};
typedef struct student Student;

void InputStdRecord(Student *StdList);
void PrintStdList(const Student *StdList);
void SaveStdList(const Student *StdList, const char *FileName);

int main() {

    Student StdList[5];

    InputStdRecord(StdList);

    PrintStdList(StdList);

    SaveStdList(StdList, "stdInfo.txt");

    return 0;

}

void InputStdRecord(Student *StdList) {

    int i = 0;

    for (i = 0; i < 4; i++) {

        printf("\nEnter Student %d details: \n", i + 1);

        printf("ID: ");

        scanf("%d", &StdList[i].id);

        printf("Firstname: ");

        scanf("%s", StdList[i].firstname);

        printf("Lastname: ");

        scanf("%s", StdList[i].lastname);

        printf("GPA: ");

        scanf("%f", &StdList[i].GPA);

        printf("Year: ");

        scanf("%d", &StdList[i].year);

    }

}

void PrintStdList(const Student *StdList) {

    printf("ID FIRSTNAME LASTNAME GPA YEAR\n");

    int i;

    for (i = 0; i < 4; i++) {

        printf("%d %s %s %.1f %d\n", StdList[i].id, StdList[i].firstname, StdList[i].lastname, StdList[i].GPA,
               StdList[i].year);

    }

}

void SaveStdList(const Student *StdList, const char *FileName) {

    FILE *studentPtr;

    studentPtr = fopen(FileName, "w");

    fprintf(studentPtr, "ID FIRSTNAME LASTNAME GPA YEAR\n");

    int i;

    for (i = 0; i < 4; i++) {

        fprintf(studentPtr, "%d %s %s %.1f %d\n", StdList[i].id, StdList[i].firstname, StdList[i].lastname, StdList[i].GPA,
                StdList[i].year);

    }

    fclose(studentPtr);

}