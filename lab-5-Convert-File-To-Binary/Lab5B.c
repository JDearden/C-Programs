#include <stdio.h>

struct student {
    char firstname[40];
    char lastname[40];
    int id;
    float GPA;
    int year;

};
typedef struct student Student;

void ReadStdRecords(Student *StdList, const char *FileName);
void PrintStdList(const Student *StdList);
void wordCap(char *word);
void SaveStdList(const Student *StdList, const char *FileName);


int main() {

    Student StdList[5];
    ReadStdRecords(StdList, "stdInfo.txt");
    PrintStdList(StdList);
    SaveStdList(StdList, "stdInfo.txt");

    return 0;

}

void ReadStdRecords(Student *StdList, const char *FileName) {

    FILE *studentPtr;

    studentPtr = fopen(FileName, "r");

    int i = 0;

//for skipping first line

    fscanf(studentPtr, "%[^\n]s", StdList[0].firstname);

    for (i = 0; i < 5; i++) {

        fscanf(studentPtr, "%d %s %s %f %d", &StdList[i].id, StdList[i].firstname, StdList[i].lastname, &StdList[i].GPA,
               &StdList[i].year);

        wordCap(StdList[i].firstname);
        wordCap(StdList[i].lastname);

    }

    fclose(studentPtr);

}

void PrintStdList(const Student *StdList) {

    printf("\nID FIRSTNAME LASTNAME GPA YEAR\n");

    int i;

    for (i = 0; i < 4; i++) {

        printf("%d %s %s %.1f %d\n", StdList[i].id, StdList[i].firstname, StdList[i].lastname, StdList[i].GPA,
               StdList[i].year);

    }

}

void wordCap(char *word) {

    int i = 0;

    while (word[i] != '\0') {

        if (word[i] >= 'a' && word[i] <= 'z')

            word[i] = word[i] - 32;

        i++;

    }

}

void SaveStdList(const Student *StdList, const char *FileName) {

    FILE *studentPtr;

    studentPtr = fopen(FileName, "w");

    fprintf(studentPtr, "ID FIRSTNAME LASTNAME GPA YEAR\n");

    int i;

    for (i = 0; i < 4; i++) {

        fprintf(studentPtr, "%d %s %s %.1f %d\n", StdList[i].id, StdList[i].firstname, StdList[i].lastname,
                StdList[i].GPA, StdList[i].year);

    }

    fclose(studentPtr);

}