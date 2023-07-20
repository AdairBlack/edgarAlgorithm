#include <cstdio>
#include <cstring>

int main(){
    char str1[100], str2[100];
    bool hashTable[128] = {false};
    bool hasPrinted[128] = {false};
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i = 0; i < len2; i++){
        char c = str2[i];
        if(c >= 'a' && c <= 'z') c -= 32;
        hashTable[c] = true;
    }
    for(int i = 0; i < len1; i++){
        char c = str1[i];
        if(c >= 'a' && c <= 'z') c -= 32;
        if(hashTable[c] == false && hasPrinted[c] == false){
            printf("%c", c);
            hasPrinted[c] = true;
        }
    }
    printf("\n");
    return 0;
}
