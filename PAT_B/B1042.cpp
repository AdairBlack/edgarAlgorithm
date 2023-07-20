#include <cstdio>
#include <cstring>

int changeToInt(char c){
    if(c >= 'a' && c <= 'z') return c - 'a';
    if(c >= 'A' && c <= 'Z') return c - 'A';
    return 26;
}

int main(){
    int num[27] = {0};
    char str[1010];
    int asc, max = 0;
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        num[changeToInt(str[i])]++;
    }
    for(int i = 0; i < 26; i++){
        if(num[i] > max){
            max = num[i];
            asc = i;
        } else if(num[i] == max){
            if(i < asc){
                asc = i;
            }
        }
    }
    printf("%c %d\n", 'a' + asc, max);
    return 0;
}
