#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
struct Node{
    int data, first, end;
}dp[maxn];
int main(){
    bool allNegetive = true;
    int n, num[maxn];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        if(num[i] >= 0){
            allNegetive = false;
        }
    }
    if(allNegetive){
        printf("0 %d %d\n", num[0], num[n - 1]);
        return 0;
    }
    dp[0].data = num[0];
    dp[0].first = num[0];
    dp[0].end = num[0];
    for(int i = 1; i < n; i++){
        if(num[i] > dp[i - 1].data + num[i]){
            dp[i].data = num[i];
            dp[i].first = num[i];
            dp[i].end = num[i];
        } else {
            dp[i].data = dp[i - 1].data + num[i];
            dp[i].first = dp[i - 1].first;
            dp[i].end = num[i];
        }
    }
    int k = 0;
    for(int i = 1; i < n; i++){
        if(dp[i].data > dp[k].data){
            k = i;
        }
    }
    printf("%d %d %d\n", dp[k].data, dp[k].first, dp[k].end);
    return 0;
}
