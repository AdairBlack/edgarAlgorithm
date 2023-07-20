#include <cstdio>

int main(){
    int m, n, a, b, c;
    scanf("%d%d%d%d%d", &m, &n, &a, &b, &c);
    int ans[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int temp;
            scanf("%d", &temp);
            if(temp >= a && temp <= b){
                temp = c;
            }
            ans[i][j] = temp;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j != 0) printf(" ");
            printf("%03d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
