#include <cstdio>

int main(){
    int n, a, b, c, d, num1 = 0, num2 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int num = a + c;
        if(a + c == b && a + c != d){
            num1++;
        } else if(a + c != b && a + c == d){
            num2++;
        }
    }
    printf("%d %d\n", num2, num1);
    return 0;
}
