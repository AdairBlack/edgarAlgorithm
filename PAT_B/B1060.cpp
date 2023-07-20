#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    int num[100010];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
    }
    sort(num + 1, num + n + 1, cmp);
    int p = 1;
    while(p <= n && num[p] > p){
        p++;
    }
    printf("%d\n", p - 1);
    return 0;
}
