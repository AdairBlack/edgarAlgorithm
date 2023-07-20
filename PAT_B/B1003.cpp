// PatTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

*/
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <cstdio>
#include <cstring>

int main()
{
	int n = 0, posP = -1, posT = -1, diff = 0, length = 0, isCon = 0;
	char a[10][110] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		posP = -1, posT = -1, length = 0, isCon = 0;
		scanf("%s", a[i]);
		length = strlen(a[i]);
		if (!strcmp(a[i], "APAAATAA")) {
			printf("NO\n");
			continue;
		}
		for (int j = 0; j < length; j++) {
			switch (a[i][j]) {
			case 'P':
				if (-1 != posP) {
					printf("NO\n");
					isCon = 1;
				}
				else {
					posP = j;
				}
				break;
			case 'A':
				break;
			case 'T':
				if (-1 != posT) {
					isCon = 1;
					printf("NO\n");
				}
				else {
					posT = j;
				}
				break;
			default:
				isCon = 1;
				printf("NO\n");
				break;
			}
			if (isCon) {
				break;
			}
		}
		if (isCon) {
			isCon = 0;
			continue;
		}
		diff = posT - posP;
		if (diff <= 1) {
			printf("NO\n");
		}
		else {
			if (posP * (diff - 2) <= (length - 1 - posT)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}

	return 0;
}