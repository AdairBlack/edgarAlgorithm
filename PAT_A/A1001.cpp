#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int a = 0, b = 0, sum = 0, count = 0, posNeg = 0;
	int res[5] = { 0 };
	scanf("%d %d", &a, &b);
	sum = a + b;
	if (0 <= sum)
	{
		posNeg = 1;
	}
	sum = abs(sum);
	if (0 == sum)
	{
		printf("0\n");
		return 0;
	}
	while (sum != 0)
	{
		res[count] = abs(sum % 1000);
		sum /= 1000;
		count++;
	}
	for (int i = (count - 1); i >= 0; i--)
	{
		if (((count - 1) == i) && (0 == posNeg))
		{
			printf("-");
		}
		if ((count - 1) == i)
		{
			printf("%d", res[i]);
		}
		else {
			printf(",%03d", res[i]);
		}
	}
	printf("\n");
	return 0;
}

