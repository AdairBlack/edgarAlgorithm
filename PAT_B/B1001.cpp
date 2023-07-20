#include <cstdio>

int main()
{
    int num = 0;
    int count = 0;
    scanf("%d", &num);
    while (1 != num)
    {
        count++;
        if (0 == num % 2)
        {
            num /= 2;
        }
        else
        {
            num = (3 * num + 1) / 2;
        }
    }
    printf("%d", count);
    return 0;
}
