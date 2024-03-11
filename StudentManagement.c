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
void sortListOfStudentBySubject();
void findStudentsByKeyword();
void deleteStudentById();
void updateStudentById();
void gradingStudents();

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
	printf("6. in danh sach ra file students.out\n");
	printf("7. sap xep sinh vien theo diem thanh phan\n");
	printf("8. tim sinh vien bang tu khoa\n");
	printf("9. xoa sinh vien bang id\n");
	printf("10. chinh sua sinh vien bang id\n");
	printf("11. xep loai hoc luc sinh vien\n");
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
	printf("Nhap ma sinh vien: ");
	scanf("%s", &id[size]);

	printf("\nNhap ten sinh vien: ");
	scanf(" %[^\n]", &name[size]);

	printf("\nNhap diem Toan: ");
	scanf("%lf", &diemToan[size]);

	printf("\nNhap diem Ly: ");
	scanf("%lf", &diemLy[size]);

	printf("\nNhap diem Hoa: ");
	scanf("%lf", &diemHoa[size]);

	diemTb[size] = (diemToan[size] + diemLy[size] + diemHoa[size]) / 3.0f;

	size++;
}

/*
	author: Le Hai Nam
	function : printListOfStudent
	description: print list of student to screen
*/
void printListOfStudent()
{
	// Write code here
	int i;
	printf("===== ID =========== Ho ten ========= Toan == Ly == Hoa == Diem trung binh ====\n");
	for (i = 0; i < size; i++)
	{
		printf("%-12s | %-20s | %2.2lf | %2.2lf | %2.2lf | %2.2lf\n",
			   id[i], name[i], diemToan[i], diemLy[i], diemHoa[i], diemTb[i]);
	}
}

/*
	author: Nong Hoang Duy Anh
	function : searchStudentsById
	description: search student by id and print description about student
*/
void searchStudentById()
{
	// Write code here
	char ID[32];
	printf("Nhap ID:");
	scanf("%s", &ID);
	int count = 0;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (strcmp(id[i], ID) == 0)
		{
			printf("Thong tin sinh  vien:\n");
			printf("Ma sinh vien:%s\n", id[i]);
			printf("Ho va ten:%s\n", name[i]);
			printf("Diem Toan:%.2f\n", diemToan[i]);
			printf("Diem Hoa:%.2f\n", diemHoa[i]);
			printf("Diem Ly:%.2f\n", diemLy[i]);
			printf("Diem Trung Binh:%.2f\n", diemTb[i]);
			count++;
		}
	}
	if (count == 0)
	{
		printf("khong tim thay sinh vien\n");
	}
}

/*
	author: Duong Trong Luc
	function : calculateTheAverageScore
	description: print The Average Score of all student
*/
void calculateTheAverageScore()
{
	// Write code here
	double total = 0.0; // Su dung double cho tung diem
	int i;
	for (i = 0; i < size; i++)
	{
		total += diemTb[i];
	}
	printf("\nDiem trung binh cua tat ca sinh vien la: %.2lf\n", total / size); // Tra ve gia tri double
}

/*
	author: Tran Thanh Hai
	function : sortListOfStudentByAverageScore
	description: sort list of Student by Average Score don't change root array and print list to screen
*/
void sortListOfStudentByAverageScore()
{
	// Write code here
	int i = 0;
	int j = 0;
	char tempid[N_MAX][20];
	char tempname[N_MAX][255];
	double tempdiemTb[N_MAX];
	double tempdiemToan[N_MAX];
	double tempdiemLy[N_MAX];
	double tempdiemHoa[N_MAX];
	for (i = 0; i < size; i++)
	{
		strcpy(tempid[i], id[i]);
		strcpy(tempname[i], name[i]);
		tempdiemTb[i] = diemTb[i];
		tempdiemToan[i] = diemToan[i];
		tempdiemLy[i] = diemLy[i];
		tempdiemHoa[i] = diemHoa[i];
	}
	char temp[20];
	char temp1[255];
	double temp2;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (tempdiemTb[i] < tempdiemTb[j])
			{

				strcpy(temp, tempid[i]);
				strcpy(tempid[i], tempid[j]);
				strcpy(tempid[j], temp);

				strcpy(temp1, tempname[i]);
				strcpy(tempname[i], tempname[j]);
				strcpy(tempname[j], temp1);

				temp2 = tempdiemTb[i];
				tempdiemTb[i] = tempdiemTb[j];
				tempdiemTb[j] = temp2;

				temp2 = tempdiemToan[i];
				tempdiemToan[i] = tempdiemToan[j];
				tempdiemToan[j] = temp2;

				temp2 = tempdiemLy[i];
				tempdiemLy[i] = tempdiemLy[j];
				tempdiemLy[j] = temp2;

				temp2 = tempdiemHoa[i];
				tempdiemHoa[i] = tempdiemHoa[j];
				tempdiemHoa[j] = temp2;
			}
		}
	}
	printf("===== ID =========== Ho ten ========= Toan == Ly == Hoa == Diem trung binh ====\n");
	for (i = 0; i < size; i++)
	{
		printf("%-12s | %-20s | %2.2lf | %2.2lf | %2.2lf | %2.2lf\n",
			   tempid[i], tempname[i], tempdiemToan[i], tempdiemLy[i], tempdiemHoa[i], tempdiemTb[i]);
	}
}

/*
	author: Tran Thanh Hai
	function : sortListOfStudentBySubject
	description: sort list of Student by Subject Score don't change root array and print list to screen
*/
void sortListOfStudentByMaths()
{
	// code here
	int i = 0;
	int j = 0;
	char tempid[N_MAX][20];
	char tempname[N_MAX][255];
	double tempdiemTb[N_MAX];
	double tempdiemToan[N_MAX];
	double tempdiemLy[N_MAX];
	double tempdiemHoa[N_MAX];
	for (i = 0; i < size; i++)
	{
		strcpy(tempid[i], id[i]);
		strcpy(tempname[i], name[i]);
		tempdiemTb[i] = diemTb[i];
		tempdiemToan[i] = diemToan[i];
		tempdiemLy[i] = diemLy[i];
		tempdiemHoa[i] = diemHoa[i];
	}
	char temp[20];
	char temp1[255];
	double temp2;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (tempdiemToan[i] < tempdiemToan[j])
			{

				strcpy(temp, tempid[i]);
				strcpy(tempid[i], tempid[j]);
				strcpy(tempid[j], temp);

				strcpy(temp1, tempname[i]);
				strcpy(tempname[i], tempname[j]);
				strcpy(tempname[j], temp1);

				temp2 = tempdiemTb[i];
				tempdiemTb[i] = tempdiemTb[j];
				tempdiemTb[j] = temp2;

				temp2 = tempdiemToan[i];
				tempdiemToan[i] = tempdiemToan[j];
				tempdiemToan[j] = temp2;

				temp2 = tempdiemLy[i];
				tempdiemLy[i] = tempdiemLy[j];
				tempdiemLy[j] = temp2;

				temp2 = tempdiemHoa[i];
				tempdiemHoa[i] = tempdiemHoa[j];
				tempdiemHoa[j] = temp2;
			}
		}
	}
	printf("===== ID =========== Ho ten ========= Toan == Ly == Hoa == Diem trung binh ====\n");
	for (i = 0; i < size; i++)
	{
		printf("%-12s | %-20s | %2.2lf | %2.2lf | %2.2lf | %2.2lf\n",
			   tempid[i], tempname[i], tempdiemToan[i], tempdiemLy[i], tempdiemHoa[i], tempdiemTb[i]);
	}
}
void sortListOfStudentByPhysical()
{
	// code here
	int i = 0;
	int j = 0;
	char tempid[N_MAX][20];
	char tempname[N_MAX][255];
	double tempdiemTb[N_MAX];
	double tempdiemToan[N_MAX];
	double tempdiemLy[N_MAX];
	double tempdiemHoa[N_MAX];
	for (i = 0; i < size; i++)
	{
		strcpy(tempid[i], id[i]);
		strcpy(tempname[i], name[i]);
		tempdiemTb[i] = diemTb[i];
		tempdiemToan[i] = diemToan[i];
		tempdiemLy[i] = diemLy[i];
		tempdiemHoa[i] = diemHoa[i];
	}
	char temp[20];
	char temp1[255];
	double temp2;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (tempdiemLy[i] < tempdiemLy[j])
			{

				strcpy(temp, tempid[i]);
				strcpy(tempid[i], tempid[j]);
				strcpy(tempid[j], temp);

				strcpy(temp1, tempname[i]);
				strcpy(tempname[i], tempname[j]);
				strcpy(tempname[j], temp1);

				temp2 = tempdiemTb[i];
				tempdiemTb[i] = tempdiemTb[j];
				tempdiemTb[j] = temp2;

				temp2 = tempdiemToan[i];
				tempdiemToan[i] = tempdiemToan[j];
				tempdiemToan[j] = temp2;

				temp2 = tempdiemLy[i];
				tempdiemLy[i] = tempdiemLy[j];
				tempdiemLy[j] = temp2;

				temp2 = tempdiemHoa[i];
				tempdiemHoa[i] = tempdiemHoa[j];
				tempdiemHoa[j] = temp2;
			}
		}
	}
	printf("===== ID =========== Ho ten ========= Toan == Ly == Hoa == Diem trung binh ====\n");
	for (i = 0; i < size; i++)
	{
		printf("%-12s | %-20s | %2.2lf | %2.2lf | %2.2lf | %2.2lf\n",
			   tempid[i], tempname[i], tempdiemToan[i], tempdiemLy[i], tempdiemHoa[i], tempdiemTb[i]);
	}
}
void sortListOfStudentByChemistry()
{
	// code here
	int i = 0;
	int j = 0;
	char tempid[N_MAX][20];
	char tempname[N_MAX][255];
	double tempdiemTb[N_MAX];
	double tempdiemToan[N_MAX];
	double tempdiemLy[N_MAX];
	double tempdiemHoa[N_MAX];
	for (i = 0; i < size; i++)
	{
		strcpy(tempid[i], id[i]);
		strcpy(tempname[i], name[i]);
		tempdiemTb[i] = diemTb[i];
		tempdiemToan[i] = diemToan[i];
		tempdiemLy[i] = diemLy[i];
		tempdiemHoa[i] = diemHoa[i];
	}
	char temp[20];
	char temp1[255];
	double temp2;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (tempdiemHoa[i] < tempdiemHoa[j])
			{

				strcpy(temp, tempid[i]);
				strcpy(tempid[i], tempid[j]);
				strcpy(tempid[j], temp);

				strcpy(temp1, tempname[i]);
				strcpy(tempname[i], tempname[j]);
				strcpy(tempname[j], temp1);

				temp2 = tempdiemTb[i];
				tempdiemTb[i] = tempdiemTb[j];
				tempdiemTb[j] = temp2;

				temp2 = tempdiemToan[i];
				tempdiemToan[i] = tempdiemToan[j];
				tempdiemToan[j] = temp2;

				temp2 = tempdiemLy[i];
				tempdiemLy[i] = tempdiemLy[j];
				tempdiemLy[j] = temp2;

				temp2 = tempdiemHoa[i];
				tempdiemHoa[i] = tempdiemHoa[j];
				tempdiemHoa[j] = temp2;
			}
		}
	}
	printf("===== ID =========== Ho ten ========= Toan == Ly == Hoa == Diem trung binh ====\n");
	for (i = 0; i < size; i++)
	{
		printf("%-12s | %-20s | %2.2lf | %2.2lf | %2.2lf | %2.2lf\n",
			   tempid[i], tempname[i], tempdiemToan[i], tempdiemLy[i], tempdiemHoa[i], tempdiemTb[i]);
	}
}
void sortListOfStudentBySubject()
{
	// code here
	printf("Menu 2:\n");
	printf("0. Thoat menu!\n");
	printf("1. Sap xep danh sach sinh vien theo diem toan\n");
	printf("2. Sap xep danh sach sinh vien theo diem ly\n");
	printf("3. Sap xep danh sach sinh vien theo diem hoa\n");
	int choice;
	do
	{
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			sortListOfStudentByMaths();
			break;
		case 2:
			sortListOfStudentByPhysical();
			break;
		case 3:
			sortListOfStudentByChemistry();
			break;
		case 0:
			printf("Thoat Menu 2! \n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long nhap lai.\n");
			break;
		}
	} while (choice != 0);
}

/*
	author: Duong Xuan Quyet
	function : checkKeywordOnName
	description: check keyword exist on the name
*/
int checkKeywordOnName(char *keyWord, char *name)
{
	char tempName[255];
	strcpy(tempName, name);
	strupr(tempName);
	char tempKeyword[255];
	strcpy(tempKeyword, keyWord);
	strupr(tempKeyword);
	if (strstr(tempName, tempKeyword) != NULL)
		return 1;
	return 0;
}

/*
	author: Duong Xuan Quyet
	function : findStudentsByKeyword
	description: find student by keyword input from screen
*/
void findStudentsByKeyword()
{
	char keyword[255];
	getchar();
	printf("nhap tu khoa:");
	scanf("%[^\n]", &keyword);
	int count = 0;
	int i = 0;
	printf("danh sach sinh vien chua %s la:\n", keyword);
	printf("===== ID =========== Ho ten ========= Toan == Ly == Hoa == Diem trung binh ====\n");
	for (i = 0; i < size; i++)
	{
		if (checkKeywordOnName(keyword, name[i]))
		{
			count++;
			printf("%-12s | %-20s | %2.2lf | %2.2lf | %2.2lf | %2.2lf\n",
				   id[i], name[i], diemToan[i], diemLy[i], diemHoa[i], diemTb[i]);
		}
	}
	if (!count)
	{
		printf("khong tim thay sinh vien\n");
	}
}

/*
	author: Tran Thanh Hai
	function : deleteStudentById
	description: delete Student By Id input from screen
*/
void deleteStudentById()
{
	// code here
	char ID[32];
	printf("Nhap ID:");
	scanf("%s", &ID);
	int count = 0;
	int i = 0;
	int j;
	for (i = 0; i < size; i++)
	{
		if (strcmp(id[i], ID) == 0)
		{
			count = 1;
			for (j = i; j < size; j++)
			{
				strcpy(id[j], id[j + 1]);
				strcpy(name[j], name[j + 1]);
				diemTb[j] = diemTb[j + 1];
				diemToan[j] = diemToan[j + 1];
				diemLy[j] = diemLy[j + 1];
				diemHoa[j] = diemHoa[j + 1];
			}
			size--;
			printf("Da xoa sinh vien co ID = %s \n", ID);
			break;
		}
	}
	if (count == 0)
	{
		printf("khong tim thay sinh vien\n");
	}
}

/*
	author: Duong Xuan Quyet
	function : updateStudentById
	description: update student by id input from screen
*/
void updateStudentById()
{
	char ID[20];
	printf("Nhap ma sinh vien can cap nhat: ");
	scanf("%s", ID);

	strupr(ID);

	int found = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		if (strcmp(id[i], ID) == 0)
		{
			found = 1;
			printf("Thong tin hien tai cua sinh vien:\n");
			printf("Ma sinh vien: %s\n", id[i]);
			printf("Ho va ten: %s\n", name[i]);
			printf("Diem Toan: %.2lf\n", diemToan[i]);
			printf("Diem Ly: %.2lf\n", diemLy[i]);
			printf("Diem Hoa: %.2lf\n", diemHoa[i]);

			printf("\nNhap thong tin moi cho sinh vien :\n");

			printf("Nhap ten moi: ");
			scanf(" %[^\n]", name[i]);

			printf("Nhap diem Toan moi: ");
			scanf("%lf", &diemToan[i]);

			printf("Nhap diem Ly moi: ");
			scanf("%lf", &diemLy[i]);

			printf("Nhap diem Hoa moi: ");
			scanf("%lf", &diemHoa[i]);

			diemTb[i] = (diemToan[i] + diemLy[i] + diemHoa[i]) / 3.0;

			printf("Cap nhat sinh vien thanh cong!\n");
			break;
		}
	}

	if (!found)
	{
		printf("Khong tim thay sinh vien voi ma so %s\n", ID);
	}
}

/*
	author: Duong Xuan Quyet
	function : gradingStudents
	description: grading Students and print to screen
*/
void gradingStudents()
{
	const int numClasses = 6;
	const double classBoundaries[6] = {9.0, 8.0, 7.0, 6.0, 5.0, 0.0};
	const char classNames[6][40] = {"Xuat sac", "Gioi", "Kha", "Trung Binh Kha", "Trung binh", "Yeu"};

	printf("===== ID =========== Ho ten ========= Toan == Ly == Hoa == Diem trung binh ==== Xep loai ====\n");
	int i, j;
	for (i = 0; i < size; i++)
	{
		char classRank[40] = "";

		for (j = 0; j < numClasses; j++)
		{
			if (diemTb[i] >= classBoundaries[j])
			{
				strcpy(classRank, classNames[j]);
				break;
			}
		}

		printf("%-12s | %-20s | %2.2lf | %2.2lf | %2.2lf | %2.2lf | %s\n",
			   id[i], name[i], diemToan[i], diemLy[i], diemHoa[i], diemTb[i], classRank);
	}
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
		case 6:
			if (!processWriteFile(fo))
			{
				printf("Write file fail\n");
				return 1;
			}
			break;
		case 7:
			sortListOfStudentBySubject();
			break;
		case 8:
			findStudentsByKeyword();
			break;
		case 9:
			deleteStudentById();
			break;
		case 10:
			updateStudentById();
			break;
		case 11:
			gradingStudents();
			break;
		case 0:
			printf("Tam biet!\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long nhap lai.\n");
			break;
		}
	} while (choice != 0);

	return 0;
}
