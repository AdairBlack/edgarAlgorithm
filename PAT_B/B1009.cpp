#include <cstdio>
#include <cstring>

int main(){
    char str[90];
    char ans[90][90];
    gets(str);
    int len = strlen(str);
    int num = 0, pos = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == ' '){
            ans[num++][pos] = '\0';
            pos = 0;
        } else {
            ans[num][pos++] = str[i];
            if(i == len - 1){
                ans[num++][pos] = '\0';
            }
        }
    }
    
    for(int i = num - 1; i >= 0; i--){
        printf("%s", ans[i]);
        if(i > 0) printf(" ");
    }
    
    return 0;
}
