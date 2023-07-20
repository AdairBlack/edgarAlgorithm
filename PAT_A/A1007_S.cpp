#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10010;

int main(){
    int n, dp[MAXN], first[MAXN], num[MAXN];
    bool flag = false;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        if(num[i] >= 0){
            flag = true;
        }
    }
    if(!flag){
        printf("0 %d %d\n", num[0], num[n - 1]);
        return 0;
    }
    
    dp[0] = num[0];
    first[0] = 0;
    for(int i = 1; i < n; i++){
        if(dp[i - 1] < 0){
            dp[i] = num[i];
            first[i] = i;
        } else {
            dp[i] = dp[i - 1] + num[i];
            first[i] = first[i - 1];
        }
    }
    int k = 0;
    for(int i = 1; i < n; i++){
        if(dp[i] > dp[k]){
            k = i;
        }
    }
    printf("%d %d %d\n", dp[k], num[first[k]], num[k]);
    return 0;
}
