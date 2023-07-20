#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n = 0, m = 0, temp = 0;
	int a[110] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &temp);
		a[(i + m) % n] = temp;
	}

	printf("%d", a[0]);
	for (int i = 1; i < n; i++)
	{
		printf(" %d", a[i]);
	}

	return 0;
}

