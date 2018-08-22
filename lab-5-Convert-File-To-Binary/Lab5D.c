#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//PART D

struct student {
    char firstname[40];
    char lastname[40];
    int id;
    float GPA;
    int year;
};
typedef struct student Student;
//
//void PrintStdList(const Student *StudentList) {
//    printf("From struct :\n");

//    for (int i = 0; i < 4; i++) {

//        printf("%d %s %s %.2f %d", StudentList[i].id, StudentList[i].firstname, StudentList[i].lastname,
//               StudentList[i].GPA, StudentList[i].year);
//        puts(" ");
//    }
//}

int main() {

    Student StudentList[5];

    FILE *studentPtr;

    if ((studentPtr = fopen("stdInfoDA.dat", "rb+")) != NULL) {

        size_t itemSize = sizeof(Student);

        Student dataOne, dataTwo;

        int flag = 1;
        while (flag) {

            flag = 0;

            fread(&dataOne, itemSize, 1, studentPtr);

            fread(&dataTwo, itemSize, 1, studentPtr);

            while (!feof(studentPtr)) {

                if (dataTwo.GPA > dataOne.GPA) {

                    fseek(studentPtr, (itemSize * -2), SEEK_CUR);

                    fwrite(&dataTwo, itemSize, 1, studentPtr);

                    fwrite(&dataOne, itemSize, 1, studentPtr);

                    flag = 1;

                } else {

                    dataOne = dataTwo;
                }

                fread(&dataTwo, itemSize, 1, studentPtr);
            }

            if (flag) { rewind(studentPtr); }

        }
    }

    fclose(studentPtr);

    Student Two;

    FILE *pointer_read_2 = fopen("stdInfoDA.dat", "rb");

    if (pointer_read_2 == NULL) {

        printf("Cant open the file\n");

    }

    printf("Binary MODE file:\n");

    for (int i = 0; i < 4; i++) {

        fread(&Two, sizeof(struct student), 1, pointer_read_2);

        printf("%d %s %s %.2f %d\n", Two.id, Two.firstname, Two.lastname, Two.GPA, Two.year);

    }
    fclose(pointer_read_2);

    return 0;
}