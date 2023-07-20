#include <cstdio>
#include <cstring>

int main(){
    int n;
    char password[21], str[21];
    scanf("%s %d", password, &n);
    getchar();
    for(int i = 0; i < n; i++){
        gets(str);
        if(strlen(str) == 1 && str[0] == '#'){
            return 0;
        }
        if(strcmp(str, password) != 0){
            printf("Wrong password: %s\n", str);
            if(i == n - 1){
                printf("Account locked\n");
                return 0;
            }
        } else {
            printf("Welcome in\n");
            return 0;
        }
    }
}
