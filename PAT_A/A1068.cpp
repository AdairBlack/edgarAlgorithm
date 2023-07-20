#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10010;
const int MAXV = 110;
int n, m, w[MAXN], dp[MAXV];
bool choice[MAXN][MAXV], flag[MAXN];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    fill(dp, dp + MAXV, 0);
    fill(choice[0], choice[0] + MAXN * MAXV, false);
    fill(flag, flag + MAXN, false);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        for(int v = m; v >= w[i]; v--){
            if(dp[v - w[i]] + w[i] >= dp[v]){
                dp[v] = dp[v - w[i]] + w[i];
                choice[i][v] = true;
            }
        }
    }
    if(dp[m] != m){
        printf("No Solution");
    } else {
        int k = n, v = m, count = 0;
        while(v != 0){
            if(choice[k][v]){
                count++;
                flag[k] = true;
                v -= w[k];
            }
            k--;
        }
        for(int i = n; i >= 1; i--){
            if(flag[i]){
                count--;
                printf("%d", w[i]);
                if(count > 0) printf(" ");
            }
        }
    }
    return 0;
    
}
