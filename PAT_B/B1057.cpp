#include <cstdio>
#include <cstring>

int changeToInt(char c){
    if(c >= 'a' && c <= 'z') return c - 'a' + 1;
    if(c >= 'A' && c <= 'Z') return c - 'A' + 1;
    return 0;
}

int main(){
    int sum = 0, num1 = 0, num0 = 0;
    char str[100010];
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        sum += changeToInt(str[i]);
    }
    while(sum != 0){
        if(sum % 2 == 1){
            num1++;
        } else {
            num0++;
        }
        sum /= 2;
    }
    printf("%d %d\n", num0, num1);
    return 0;
}
