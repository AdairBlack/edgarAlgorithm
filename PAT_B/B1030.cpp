#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int num[100010];
    bool flag = false;
    int n, p, maxn = 0;
    scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    int p1 = 0, p2 = 0;
    while(p1 < n && p2 < n){
        while((long long)num[p1] * p >= num[p2]){
            if(p2 == n - 1){
                p2++;
                flag = true;
                break;
            }
            p2++;
        }
        maxn = max(maxn, p2 - p1);
        if(flag) break;
        p1++;
    }
    printf("%d\n", maxn);
    return 0;
}
