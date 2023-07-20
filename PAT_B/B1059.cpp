#include <cstdio>
#include <cstring>
#include <cmath>
bool isPrime(int value){
    if(value == 0 || value == 1){
        return false;
    }
    int s =(int) sqrt(1.0 * value);
    for(int i = 2; i <= s; i++){
        if(value % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n, k;
    int ids[10010] = {0};
    bool query[10010] = {false};
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int id;
        scanf("%d", &id);
        ids[id] = i + 1;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int q;
        scanf("%d", &q);
        printf("%04d: ", q);
        if(query[q]){
            printf("Checked\n");
        } else if(ids[q] == 0){
            printf("Are you kidding?\n");
        } else if(ids[q] == 1){
            printf("Mystery Award\n");
            query[q] = true;
        } else if(isPrime(ids[q])){
            printf("Minion\n");
            query[q] = true;
        } else {
            printf("Chocolate\n");
            query[q] = true;
        }
    }
    return 0;
}
