#include <cstdio>
#include <cstring>

int main(){
    char str[10010];
    scanf("%s", str);
    if(str[0] == '-') printf("-");
    int posd = 0, pose = 0, exp = 0, len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] == '.') posd = i;
        if(str[i] == 'E'){
            pose = i;
            break;
        }
    }
    for(int i = pose + 2; i < len; i++){
        exp = exp * 10 + (str[i] - '0');
    }
    if(str[pose + 1] == '-'){
        printf("0.");
        for(int i = 0; i < exp - 1; i++){
            printf("0");
        }
        printf("%c", str[1]);
        for(int i = 3; i < pose; i++){
            printf("%c", str[i]);
        }
    } else {
        for(int i = 1; i < pose; i++){
            if(str[i] == '.') continue;
            printf("%c", str[i]);
            if(i == exp + 2 && pose - 3 != exp){
                printf(".");
            }
        }
        for(int i = 0; i < exp - pose + 3; i++){
            printf("0");
        }
    }
    printf("\n");
    return 0;
}
