#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
int main(){
    int dp[MAXN][MAXN];
    char str[MAXN];
    fill(dp[0], dp[0] + MAXN * MAXN, 0);
    gets(str);
    int len = strlen(str);
    int ans = 1;
    for(int i = 0; i < len; i++){
        dp[i][i] = 1;
        if(i < len - 1 && str[i] == str[i + 1]){
            dp[i][i + 1] = 1;
            ans = 2;
        }
    }
    for(int l = 3; l <= len; l++){
        for(int i = 0; i + l - 1 < len; i++){
            int j = i + l - 1;
            if(str[i] == str[j] && dp[i + 1][j - 1] == 1){
                dp[i][j] = 1;
                ans = l;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
