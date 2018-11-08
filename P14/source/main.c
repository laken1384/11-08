#include<stdio.h>
#include<stdlib.h>
#define STUDENTS 3
#define EXAMS 4

int minimum(const int grades[][EXAMS], int pupils, int tests);
int miximum(const int grades[][EXAMS], int pupils, int tests);
double average(const int setOfGreades[], int tests);
void printArray(const int grades[][EXAMS], int pupils, int tests);
int main(void)
{
	int student;
	const int studentGrades[STUDENTS][EXAMS] =
	{	{ 77, 68, 86, 73 },
		{ 96, 87, 89, 78 },
		{ 70, 90, 86, 81 } };

	printf("The array is: \n");
	printArray(studentGrades,STUDENTS,EXAMS);

	printf("\n\nLowest grade: %d\nHighest grade: %d\n",
		minimum(studentGrades, STUDENTS, EXAMS),
		maximum(studentGrades, STUDENTS, EXAMS));
	for (student = 0; student < STUDENTS; student++)
	{
		printf("The average grade for student %d is %.2f\n",
			student, average(studentGrades[student], EXAMS));
	}


	system("pause");
	return 0;
}
int minimum(const int grades[][EXAMS], int pupils, int tests)
{
	int i, j, lowGrade = 100;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j]< lowGrade) lowGrade = grades[i][j];
		}
	}
	return lowGrade;
}
int maximum(const int grades[][EXAMS], int pupils, int tests)
{
	int i, j, HighGrade = 100;
	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j > tests; j++)
		{
			if (grades[i][j]>HighGrade) HighGrade = grades[i][j];
		}
	}
	return HighGrade;
}
double average(const int setOfGreades[], int tests)
{
	int i, total = 0;
	for (i = 0; i < tests; i++)
	{
		total += setOfGreades[i];
	}
	return (double)total/tests;
}

void printArray(const int grades[][EXAMS], int pupils, int tests)
{
	int i, j; 
	printf("                 [0]  [1]  [2]  [3]");
	for (i = 0; i < pupils; i++)
	{
		printf("\nstudentGrades[%d] ", i);
		for (j = 0; j < tests; j++)
			printf("%-5d", grades[i][j]);
	}
}