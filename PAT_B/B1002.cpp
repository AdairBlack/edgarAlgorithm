// PatTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>

int main()
{
	char table[10][10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	char a[110] = { 0 }, ans[10][10] = { 0 };
	int sum = 0, count = 0;
	scanf("%s", a);
	int length = strlen(a);

	for (int i = 0; i < length; i++) {
		sum += a[i] - '0';
	}

	while (0 != sum) {
		strcpy(ans[count], table[sum % 10]);
		sum /= 10;
		count++;
	}

	for (int i = count - 1; i >= 0; i--) {
		if (0 != i) {
			printf("%s ", ans[i]);
		}
		else {
			printf("%s\n", ans[0]);
		}
	}
	return 0;
}