#include <cstdio>
int main(){
    int n;
    double total = 0, num;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &num);
        total += num * (i + 1) * (n - i);
    }
    printf("%.2f\n", total);
    return 0;
}

