#include <stdio.h>

//Part C

struct student {

    char firstname[40];
    char lastname[40];
    int id;
    float GPA;
    int year;

};

typedef struct student Student;

void InputStdRecord(Student *StdList, const char *FileName);

void PrintStdList(const Student *StdList);

void SaveStdList(const Student *StdList, const char *FileName);


int main() {

    Student StdList[5];

    InputStdRecord(StdList, "stdInfo.txt");

    PrintStdList(StdList);

    SaveStdList(StdList, "stdInfoDA.dat");

    return 0;

}

void InputStdRecord(Student *StdList, const char *FileName) {

    FILE *studentPtr;

    studentPtr = fopen(FileName, "r");

    int i = 0;

//for skipping first line

    fscanf(studentPtr, "%[^\n]s", StdList[0].firstname);

    for (i = 0; i < 5; i++) {

        fscanf(studentPtr, "%d %s %s %f %d", &StdList[i].id, StdList[i].firstname, StdList[i].lastname, &StdList[i].GPA,
               &StdList[i].year);

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

void SaveStdList(const Student *StdList, const char *FileName) {

    int count;

    FILE *save = fopen(FileName,"wb");
    
    if (!save) {
        printf("Unable to open the file!");
    }

    for ( count = 0; count < 4 ; count ++) {
        fwrite(&StdList[count], sizeof(struct student),1,save);
    }

    fclose(save);

    int i;

    struct student read_data;

    FILE *pointer_read = fopen(FileName,"rb");

    if ( pointer_read==NULL) {
        printf("Cant open the file\n");
    }

    printf("--------------------------\n" );
    printf("Binary MODE file:\n" );
    
    for (i = 0; i < 4; i++) {
        fread(&read_data,sizeof(struct student),1,pointer_read);
        printf("%d %s %s %.1f %d", read_data.id, read_data.firstname, read_data.lastname, read_data.GPA, read_data.year );
        puts(" ");
    }

    fclose(pointer_read);

}