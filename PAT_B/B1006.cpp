#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0, b = 0, s = 0;
	scanf("%d", &n);
	b = n / 100;
	n %= 100;
	s = n / 10;
	n %= 10;
	for (int i = 0; i < b; i++) {
		printf("%c", 'B');
	}
	for (int i = 0; i < s; i++) {
		printf("%c", 'S');
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", i);
	}
	printf("\n");

	return 0;
}

