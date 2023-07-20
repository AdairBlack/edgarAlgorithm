#include <cstdio>

int main(){
    int n, sum = 0;
    int num[10];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            sum += num[i] * 10 + num[j];
        }
    }
    printf("%d\n", sum);
    return 0;
}
