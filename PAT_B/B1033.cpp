#include <cstdio>
#include <cstring>

int main(){
    char str1[100010];
    char str2[100010];
    gets(str1);
    gets(str2);
    bool flag = false;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    bool hashTable[128] = {false};
    for(int i = 0; i < len1; i++){
        hashTable[str1[i]] = true;
        if(str1[i] >= 'A' && str1[i] <= 'Z'){
            hashTable[str1[i] + 32] = true;
        }
    }
    for(int i = 0; i < len2; i++){
        if(hashTable[str2[i]] == true){
            continue;
        } else if(str2[i] >= 'A' && str2[i] <= 'Z' && hashTable['+'] == true){
            continue;
        } else {
            printf("%c", str2[i]);
        }
    }
    printf("\n");
    return 0;
}
