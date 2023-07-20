#include <cstdio>

int main(){
    int n, k, a;
    int hashTable[110] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        hashTable[a]++;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &a);
        printf("%d", hashTable[a]);
        if(i < k - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
