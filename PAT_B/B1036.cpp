#include <cstdio>

int main(){
    int n;
    char c;
    scanf("%d %c", &n, &c);
    for(int i = 0; i < n; i++){
        printf("%c", c);
    }
    printf("\n");
    int row  = n / 2 - 2;
    if(n % 2 == 1) row++;
    for(int i = 0; i < row; i++){
        printf("%c", c);
        for(int j = 0; j < n - 2; j++){
            printf(" ");
        }
        printf("%c", c);
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
