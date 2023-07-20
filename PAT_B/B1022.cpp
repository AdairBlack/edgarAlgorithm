#include <cstdio>

int main(){
    int a, b, c, d;
    int ans[35];
    scanf("%d%d%d", &a, &b, &d);
    c = a + b;
    if(c == 0){
        printf("0\n");
        return 0;
    }
    int i = 0;
    while(c != 0){
        ans[i++] = c % d;
        c /= d;
    }
    while(i > 0){
        printf("%d", ans[--i]);
    }
    printf("\n");
    return 0;
}
