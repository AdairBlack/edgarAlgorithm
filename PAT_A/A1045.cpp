#include <cstdio>
#include <algorithm>
using namespace std;

//In the order of favorite color, each color is unique, so hash color to order.
//The color can be duplicate so hash[i] >= hash[j]
//The length of dp[] is 10010 not 210

int main(){
    int n, m, l, count = 0;
    int pattern[210], target[10010], hash[210], dp[10010];
    bool has[210] = {false};
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &pattern[i]);
        has[pattern[i]] = true;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++){
        int a;
        scanf("%d", &a);
        if(has[a]){
            target[count++] = a;
        }
    }
    for(int i = 0; i < m; i++){
        hash[pattern[i]] = i;
    }
    
    int longest = 0;
    for(int i = 0; i < count; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(hash[target[i]] >= hash[target[j]]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        longest = max(dp[i], longest);
    }
    
    printf("%d\n", longest);
    return 0;
}
