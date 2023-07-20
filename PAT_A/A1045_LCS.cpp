#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXC = 210;
const int MAXN = 10010;
int a[MAXC], b[MAXN], dp[MAXC][MAXN];
int main(){
    int n, m, l;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &l);
    for(int i = 1; i <= l; i++){
        scanf("%d", &b[i]);
    }
    for(int i = 0; i <= m; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= l; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= l; j++){
            int ans = max(dp[i - 1][j], dp[i][j - 1]);
            if(a[i] == b[j]){
                dp[i][j] = ans + 1;
            } else {
                dp[i][j] = ans;
            }
        }
    }
    printf("%d\n", dp[m][l]);
    return 0;
}
