#include <cstdio>
#include <cstring>
int changeToInt(char c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    } else if(c >='a' &&  c <= 'z'){
        return c - 'a' + 10;
    }
    return c - 'A' + 36;
}

int main(){
    int hashTable[62] = {0};
    int count = 0;
    char str1[1010];
    char str2[1010];
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i = 0; i < len1; i++){
        hashTable[changeToInt(str1[i])]++;
    }
    for(int i = 0; i < len2; i++){
        hashTable[changeToInt(str2[i])]--;
    }
    for(int i = 0; i < len2; i++){
        count += hashTable[changeToInt(str2[i])];
    }
    if(count < 0){
        count = 0;
        for(int i = 0; i < 62; i++){
            if(hashTable[i] < 0) {
                count += hashTable[i];
            }
        }
        printf("No %d\n", -count);
    } else {
        printf("Yes %d\n", len1 - len2);
    }
    return 0;
}

