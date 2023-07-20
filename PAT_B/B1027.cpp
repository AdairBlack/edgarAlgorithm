#include <cstdio>
#include <cmath>

int main(){
    int n, line;
    char s;
    scanf("%d %c", &n, &s);
    line = sqrt((double) ((n + 1) / 2));
    for(int i = line; i > 1; i--){
        for(int j = 0; j < line - i; j++){
            printf(" ");
        }
        for(int j = 0; j < 2 * i - 1; j++){
            printf("%c", s);
        }
        printf("\n");
    }
    for(int j = 0; j < line - 1; j++){
        printf(" ");
    }
    printf("%c", s);
    printf("\n");
    for(int i = 2; i <= line; i++){
        for(int j = 0; j < line - i; j++){
            printf(" ");
        }
        for(int j = 0; j < 2 * i - 1; j++){
            printf("%c", s);
        }
        printf("\n");
    }
    printf("%d\n", n - 2 * line * line + 1);
    return 0;
}

