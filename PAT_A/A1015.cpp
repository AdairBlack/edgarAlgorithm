#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int decimal){
    if(decimal <= 1){
        return false;
    }
    int sqr = sqrt(1.0 * decimal);
    for(int i = 2; i <= sqr; i++){
        if(decimal % i == 0){
            return false;
        }
    }
    return true;
}

bool isReversiblePrime(int decimal, int radix){
    bool originalNumber = false, reverseNumber = false;
    if(isPrime(decimal)){
        originalNumber = true;
    }
    int num[15], count = 0;
    while(decimal != 0){
        num[count++] = decimal % radix;
        decimal /= radix;
    }
    int reversed = 0;
    for(int i = 0; i < count; i++){
        reversed = reversed * radix + num[i];
    }
    if(isPrime(reversed)){
        reverseNumber = true;
    }
    return originalNumber && reverseNumber;
}

int main(){
    int decimal, radix;
    while(true){
        scanf("%d", &decimal);
        if(decimal < 0){
            break;
        }
        scanf("%d", &radix);
        if(isReversiblePrime(decimal, radix)){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
