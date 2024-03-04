#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N_MAX 100

char id[N_MAX][20];
char name[N_MAX][255];
double diemTb[N_MAX];
double diemToan[N_MAX];
double diemLy[N_MAX];
double diemHoa[N_MAX];

int size = 0;

int exist(char *);
void convertDataFromString(char *, int);
int processFileRead(char *);
int processWriteFile(char *);
void displayMenu();
void addNewStudent();
void printListOfStudent();
void searchStudentById();
void calculateTheAverageScore();
void sortListOfStudentByAverageScore();

/*
	author: Duong Xuan Quyet
	function : exist
	description: check file exist
*/
int exist(char *fileName)
{
	FILE *f = fopen(fileName, "r");
	if (f != NULL)
	{
		fclose(f);
		return 1;
	}
	return 0;
}

/*
	author: Duong Xuan Quyet
	function : convertDataFromString
	description: convert data from string to array
*/
void convertDataFromString(char *s, int index)
{
	int i = 0;
	int j = 0;
	while (s[i] != ';')
	{
		id[index][j] = s[i];
		i++;
		j++;
	}
	id[index][j] = '\0';
	i++;
	j = 0;
	while (s[i] != ';')
	{
		name[index][j] = s[i];
		i++;
		j++;
	}
	name[index][j] = '\0';
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
	diemToan[index] = strtod(mark, &endptr);
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
	diemLy[index] = strtod(mark, &endptr);
	j = 0;
	i++;
	while (s[i] != ';')
	{
		mark[j] = s[i];
		i++;
		j++;
	}
	mark[j] = '\0';
	diemHoa[index] = strtod(mark, &endptr);
	diemTb[index] = (diemToan[index] + diemLy[index] + diemHoa[index]) / 3.0f;
}

/*
	author: Duong Xuan Quyet
	function : processFileRead
	description: read file students.in and get data to the array
*/
int processFileRead(char *filename)
{
	if (!exist(filename))
	{
		printf("The file %s does not exist.\n", filename);
		return 0;
	}
	FILE *f = fopen(filename, "r");
	char line[255];
	while (fgets(line, sizeof(line), f))
	{
		convertDataFromString(line, size);
		size++;
	}
	fclose(f);
	printf("Read file %s successful!\n", filename);
	return 1;
}

/*
	author: Duong Xuan Quyet
	function : processWriteFile
	description: write data all student to file students.out
*/
int processWriteFile(char *filename)
{
	FILE *f = fopen(filename, "w");
	if (f == NULL)
	{
		printf("Can't open file.\n");
		return 0;
	}
	int i = 0;
	fprintf(f, "===== ID =========== Ho ten ========= Toan == Ly == Hoa == Diem trung binh ====\n");
	for (i = 0; i < size; i++)
	{
		fprintf(f, "%-12s | %-20s | %2.2lf | %2.2lf | %2.2lf | %2.2lf\n",
				id[i], name[i], diemToan[i], diemLy[i], diemHoa[i], diemTb[i]);
	}
	printf("File saved!\n");
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
	printf("=============================================================\n");
	printf("Menu:\n");
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
void addNewStudent()
{
	// Write code here
}

/*
	author: Le Hai Nam
	function : printListOfStudent
	description: print list of student to screen
*/
void printListOfStudent()
{
	// Write code here
}

/*
	author: Nong Hoang Duy Anh
	function : searchStudentsById
	description: search student by id and print description about student
*/
void searchStudentById()
{
	// Write code here
}

/*
	author: Duong Trong Luc
	function : calculateTheAverageScore
	description: print The Average Score of all student
*/
void calculateTheAverageScore()
{
	// Write code here
}

/*
	author: Tran Thanh Hai
	function : sortListOfStudentByAverageScore
	description: sort list of Student by Average Score don't change root array and print list to screen
*/
void sortListOfStudentByAverageScore()
{
	// Write code here
}

int main()
{
	char fi[] = "students.in";
	char fo[] = "students.out";

	if (!processFileRead(fi))
	{
		printf("Read file fail\n");
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
			addNewStudent();
			break;
		case 2:
			printListOfStudent();
			break;
		case 3:
			searchStudentById();
			break;
		case 4:
			calculateTheAverageScore();
			break;
		case 5:
			sortListOfStudentByAverageScore();
			break;
		case 0:
			printf("Tam biet!\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long nhap lai.\n");
			break;
		}
	} while (choice != 0);

	if (!processWriteFile(fo))
	{
		printf("Write file fail\n");
		return 1;
	}
	return 0;
}
