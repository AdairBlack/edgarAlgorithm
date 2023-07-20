#include <cstdio>
#include <cstring>

char week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
char str[4][70];

int main(){
    for(int i = 0; i < 4; i++){
        scanf("%s",str[i]);
    }
    int len[4];
    for(int i = 0; i < 4; i++){
        len[i] = strlen(str[i]);
    }
    int i;
    for(i = 0; i < len[0] && i < len[1]; i++){
        if(str[0][i] >= 'A' && str[0][i] <= 'G' && str[0][i] == str[1][i]){
            printf("%s ", week[str[0][i] - 'A']);
            break;
        }
    }
    for(int j = i + 1; j < len[0] && j < len[1]; j++){
        if(str[0][j] >= 'A' && str[0][j] <= 'N' && str[0][j] == str[1][j]){
            printf("%02d:", str[0][j] - 'A' + 10);
            break;
        }
        if(str[0][j] >= '0' && str[0][j] <= '9' && str[0][j] == str[1][j]){
            printf("%02d:", str[0][j] - '0');
            break;
        }
    }
    for(int j = 0; j < len[2] && j < len[3]; j++){
        if((str[2][j] >= 'a' && str[3][j] <= 'z' && str[2][j] == str[3][j]) || (str[2][j] >= 'A' && str[3][j] <= 'Z' && str[2][j] == str[3][j])){
            printf("%02d\n", j);
            break;
        }
    }
    return 0;
}
