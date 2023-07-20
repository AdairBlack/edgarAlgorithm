#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, temp, numa = 0, numb = 0;
    int num[4], a[4], b[4];
    scanf("%d", &n);
    temp = n;
    while(true){
        for(int i = 0; i < 4; i++){
            num[i] = n % 10;
            n = n / 10;
        }
        sort(num, num + 4, cmp);
        for(int i = 0; i < 4; i++){
            a[i] = num[i];
            numa = numa * 10 + a[i];
        }
        sort(num, num + 4);
        for(int i = 0; i < 4; i++){
            b[i] = num[i];
            numb = numb * 10 + b[i];
        }
        if(numb == numa){
            printf("%04d - %04d = 0000\n", numa, numb);
            break;
        } else {
            n = numa - numb;
            printf("%04d - %04d = %04d\n", numa, numb, n);
            if(n == 6174){
                break;
            }
            numa = 0;
            numb = 0;
        }
    }
    
    return 0;
    
}
