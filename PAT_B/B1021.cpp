#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int hashTable[10];
    char str[1010];
    memset(hashTable, 0, sizeof(hashTable));
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        hashTable[str[i] - '0']++;
    }
    for(int i = 0; i < 10; i++){
        if(hashTable[i] != 0){
            printf("%d:%d\n", i, hashTable[i]);
        }
    }
    return 0;
}
