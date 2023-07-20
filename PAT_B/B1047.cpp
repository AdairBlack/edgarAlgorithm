#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    int table[1010] = {0};
    int maxn = 0, num;
    for(int i = 0; i < n; i++){
        int a, b, c;
        scanf("%d-%d %d", &a, &b, &c);
        table[a] += c;
        if(table[a] > maxn){
            maxn = table[a];
            num = a;
        }
    }
    printf("%d %d\n", num, maxn);
    return 0;
}
