#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int b[110] = { 0 };
	int k = 0;
	int a[110] = { 0 };
	int first = 0;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &a[i]);
		temp = a[i];
		while (temp != 1) {
			if (0 == temp % 2) {
				temp = temp / 2;
			}
			else {
				temp = (temp * 3 + 1) / 2;
			}
			if (temp < 110) {
				b[temp] = 1;
			}
		}
	}
	sort(a, a + k);
	for (int i = k - 1; i >= 0; i--) {
		if (0 == b[a[i]]) {
			if (0 == first) {
				first = 1;
				printf("%d", a[i]);
			}
			else {
				printf(" %d", a[i]);
			}
		}
	}

	return 0;
}

