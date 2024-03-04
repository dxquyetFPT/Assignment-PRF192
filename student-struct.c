/*
    project : student management
    author: Group 2
    class: SE1940
    version: 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int N_MAX = 100;

struct student
{
    char id[20];
    char name[255];
    double diemTb;
    double diemToan;
    double diemLy;
    double diemHoa;
};

typedef struct student student_t;

int exist(char *);
student_t convertDataFromString(char *);
int processFileRead(char *, int *, student_t *);
int processWriteFile(char *, int, student_t *);
void displayMenu();
void addNewStudent(student_t *, int *);
void printListOfStudent(student_t *, int);
void searchStudentById(student_t *, int);
void calculateTheAverageScore(student_t *, int);
void sortListOfStudentByAverageScore(student_t *, int);

/*
    author: Duong Xuan Quyet
    function : exist
    description: check file exist
*/
int exist(char *fileName)
{
    int existed = 0;
    FILE *f = fopen(fileName, "r");
    if (f != NULL)
    {
        existed = 1;
        fclose(f);
    }
    return existed;
}

/*
    author: Duong Xuan Quyet
    function : convertDataFromString
    description: convert data from string to object student
*/
student_t convertDataFromString(char *s)
{
    student_t objStudent;
    int i = 0;
    int j = 0;
    while (s[i] != ';')
    {
        objStudent.id[j] = s[i];
        i++;
        j++;
    }
    objStudent.id[j] = '\0';
    i++;
    j = 0;
    while (s[i] != ';')
    {
        objStudent.name[j] = s[i];
        i++;
        j++;
    }
    objStudent.name[j] = '\0';
    char mark[255];
    j = 0;
    i++;
    while (s[i] != ';')
    {
        mark[j] = s[i];
        i++;
        j++;
    }
    mark[j] = '\0';
    char *endptr;
    objStudent.diemToan = strtod(mark, &endptr);
    char ly[255];
    j = 0;
    i++;
    while (s[i] != ';')
    {
        mark[j] = s[i];
        i++;
        j++;
    }
    mark[j] = '\0';
    objStudent.diemLy = strtod(mark, &endptr);
    j = 0;
    i++;
    while (s[i] != ';')
    {
        mark[j] = s[i];
        i++;
        j++;
    }
    mark[j] = '\0';
    objStudent.diemHoa = strtod(mark, &endptr);
    objStudent.diemTb = (objStudent.diemToan + objStudent.diemLy + objStudent.diemHoa) / 3.0f;
    return objStudent;
}

/*
    author: Duong Xuan Quyet
    function : processFileRead
    description: read file students.in and get data to the array
*/
int processFileRead(char *filename, int *size, student_t *listOfStudent)
{
    char c;
    if (exist(filename) == 0)
    {
        printf("The file %s does not exist.\n", filename);
        return 0;
    }
    FILE *f = fopen(filename, "r");
    char line[255];
    student_t objStudentInput;
    while (fgets(line, sizeof(line), f))
    {
        objStudentInput = convertDataFromString(line);
        if (*size < N_MAX)
        {
            listOfStudent[*size] = objStudentInput;
            (*size)++;
        }
    }
    fclose(f);
    printf("Read file students.in successful!\n");
    return 1;
}

/*
    author: Duong Xuan Quyet
    function : processWriteFile
    description: write data all student to file students.out
*/
int processWriteFile(char *filename, int size, student_t *listOfStudent)
{
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("can't open file'.\n");
        return 0;
    }
    fflush(stdin);
    int i = 0, j = 0;
    fprintf(f, "===== ID =========== Ho ten ========= Toan == Ly == Hoa == Diem trung binh ====\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < strlen(listOfStudent[i].name); j++)
        {
            if (listOfStudent[i].name[j] < 0 || listOfStudent[i].name[j] > 127)
            {
                listOfStudent[i].name[j] = ' ';
            }
        }
        fprintf(f, "%-12s | %-20s | %2.2lf | %2.2lf | %2.2lf | %2.2lf\n",
                listOfStudent[i].id,
                listOfStudent[i].name,
                listOfStudent[i].diemToan,
                listOfStudent[i].diemLy,
                listOfStudent[i].diemHoa,
                listOfStudent[i].diemTb);
    }
    printf("file saved!\n");
    fclose(f);
    return 1;
}

/*
    author: Duong Xuan Quyet
    function : displayMenu
    description: print menu to screen
*/
void displayMenu()
{
    printf("=============================================================");
    printf("\nMenu:\n");
    printf("1. Them sinh vien moi\n");
    printf("2. In danh sach sinh vien\n");
    printf("3. Tim kiem sinh vien theo ID\n");
    printf("4. Tinh diem trung binh cua tat ca sinh vien\n");
    printf("5. Sap xep danh sach sinh vien theo diem trung binh\n");
    printf("0. Thoat\n");
}

/*
    author: Tran Minh Quang
    function : addNewStudent
    description: add new student to array
*/
void addNewStudent(student_t *listOfStudent, int *size)
{
    // write code here
}

/*
    author: Le Hai Nam
    function : printListOfStudent
    description: print list of student to screen
*/
void printListOfStudent(student_t *listOfStudent, int size)
{
    // write code here
}

/*
    author: Nong Hoang Duy Anh
    function : searchStudentsById
    description: search student by id and print description about student
*/
void searchStudentById(student_t *listOfStudent, int size)
{
    // write code here
}

/*
    author: Duong Trong Luc
    function : calculateTheAverageScore
    description: print The Average Score of all student
*/
void calculateTheAverageScore(student_t *listOfStudent, int size)
{
    // write code here
}

/*
    author: Tran Thanh Hai
    function : sortListOfStudentByAverageScore
    description: sort list of Student by Average Score don't change root array and print list to screen
*/
void sortListOfStudentByAverageScore(student_t *listOfStudent, int size)
{
    // write code here
}

int main()
{
    student_t listOfStudent[N_MAX];
    char fi[] = "students.in";
    char fo[] = "students.out";
    int size = 0;
    if (!processFileRead(fi, &size, listOfStudent))
    {
        printf("read file fail\n");
        return 1;
    }

    int choice;
    do
    {
        displayMenu();
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addNewStudent(listOfStudent, &size);
            break;
        case 2:
            printListOfStudent(listOfStudent, size);
            break;
        case 3:
            searchStudentById(listOfStudent, size);
            break;
        case 4:
            calculateTheAverageScore(listOfStudent, size);
            break;
        case 5:
            sortListOfStudentByAverageScore(listOfStudent, size);
            break;
        case 0:
            printf("Tam biet!\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
            break;
        }
    } while (choice != 0);

    if (!processWriteFile(fo, size, listOfStudent))
    {
        printf("write file fail\n");
        return 1;
    }
    return 0;
}