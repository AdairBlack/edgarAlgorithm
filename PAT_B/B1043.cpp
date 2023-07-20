#include <cstdio>
#include <cstring>

int changeToInt(char c){
    if(c == 'P') return 0;
    if(c == 'A') return 1;
    if(c == 'T') return 2;
    if(c == 'e') return 3;
    if(c == 's') return 4;
    if(c == 't') return 5;
    return 6;
}

char changeToChar(int c){
    if(c == 0) return 'P';
    if(c == 1) return 'A';
    if(c == 2) return 'T';
    if(c == 3) return 'e';
    if(c == 4) return 's';
    return 't';
}

int main(){
    int table[7] = {0};
    char str[10010];
    bool flag[7] = {false};
    bool control = false;
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        table[changeToInt(str[i])]++;
        flag[changeToInt(str[i])] = true;
    }
    for(int i = 0; i < 6; i++){
        if(flag[i]){
            control = true;
        }
    }
    while(control){
        control = false;
        for(int i = 0; i < 6;i++){
            if(flag[i]){
                printf("%c", changeToChar(i));
                table[i]--;
                if(table[i] == 0){
                    flag[i] = false;
                }
            }
        }
        for(int i = 0; i < 6; i++){
            if(flag[i]){
                control = true;
            }
        }
    }
    printf("\n");
    return 0;
}
