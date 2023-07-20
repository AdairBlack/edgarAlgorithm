#include <cstdio>

int main()
{
    long long a, b;
    int as, bs;
    long long ansa = 0, ansb = 0;
    scanf("%lld %d %lld %d", &a, &as, &b, &bs);
    while(a > 0){
        if(a % 10 == as){
            ansa = ansa * 10 + (a % 10);
        }
        a /= 10;
    }
    while(b > 0){
        if(b % 10 == bs){
            ansb = ansb * 10 + (b % 10);
        }
        b /= 10;
    }
    printf("%lld\n", ansa + ansb);
    return 0;
}
