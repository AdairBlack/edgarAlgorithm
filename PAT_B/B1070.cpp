#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n;
    double sum = 0, num[10010];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &num[i]);
    }
    sort(num, num + n);
    sum = num[0];
    for(int i = 1; i < n; i++){
        sum = (sum + num[i]) / 2;
    }
    printf("%.0f\n", floor(sum));
    return 0;
}
