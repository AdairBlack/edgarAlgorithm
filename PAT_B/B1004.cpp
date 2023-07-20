// PatTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

*/
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <cstdio>
#include <cstring>

typedef struct StudentInfo{
	char name[15];
	char id[15];
	int score;
}Student;

int main()
{
	int n = 0;
	Student high, low, temp;
	high.score = 0;
	low.score = 101;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", temp.name, temp.id, &temp.score);
		if (temp.score > high.score) {
			strcpy(high.name, temp.name);
			strcpy(high.id, temp.id);
			high.score = temp.score;
		}
		if (temp.score < low.score) {
			strcpy(low.name, temp.name);
			strcpy(low.id, temp.id);
			low.score = temp.score;
		}
	}
	printf("%s %s\n", high.name, high.id);
	printf("%s %s\n", low.name, low.id);


	return 0;
}