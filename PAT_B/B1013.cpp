#include <cstdio>
#include <cmath>

int prime[10010];

bool isPrime(int n){
    if(n <= 1) return false;
    int sqr = (int) sqrt(n);
    for(int i = 2; i <= sqr; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void init(int n){
    int count = 0, i = 2;
    while(count < n){
        if(isPrime(i)){
            prime[count++] = i;
        }
        i++;
    }
}

int main(){
    int begin, end;
    scanf("%d%d", &begin, &end);
    init(end);
    for(int i = begin - 1; i < end; i++){
        printf("%d", prime[i]);
        if(i != begin - 1 && (i - begin + 2) % 10 == 0){
            printf("\n");
        } else if(i == end - 1){
            printf("\n");
        } else {
            printf(" ");
        }
    }
    return 0;
}
