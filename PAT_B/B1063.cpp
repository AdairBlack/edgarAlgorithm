#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    double maxn = 0;
    for(int i = 0; i < n; i++){
        double a, b, sum;
        scanf("%lf%lf", &a, &b);
        sum = a * a + b * b;
        maxn = max(maxn, sum);
    }
    printf("%.2f\n", sqrt(maxn));
    return 0;
}
