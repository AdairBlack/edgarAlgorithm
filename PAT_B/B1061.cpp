#include <cstdio>

int main(){
    int n, m;
    int score[110], right[110];
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &score[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &right[i]);
    }
    for(int i = 0; i < n; i++){
        int sum = 0, ans;
        for(int j = 0; j < m; j++){
            scanf("%d", &ans);
            if(ans == right[j]){
                sum += score[j];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
