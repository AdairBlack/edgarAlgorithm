#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int num,n;
    double ans;
    int a[5] = {0};
    int count[5] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if(num % 5 ==  0){
            if(num % 2 == 0){
                a[0] += num;
                count[0]++;
            }
        } else if(num % 5 == 1){
            if(count[1] % 2 == 0) a[1] += num;
            else a[1] -= num;
            count[1]++;
        } else if(num % 5 == 2){
            count[2]++;
        } else if(num % 5 == 3){
            a[3] += num;
            count[3]++;
        } else {
            a[4] = max(a[4], num);
            count[4]++;
        }
    }
    
    if(count[3] != 0) ans =(double) a[3] / count[3];
    
    for(int i = 0; i < 5; i++){
        if(count[i] == 0) printf("N");
        else if(i == 3){
            printf("%.1f", ans);
        } else if(i == 2){
            printf("%d", count[i]);
        } else {
            printf("%d", a[i]);
        }
        if(i != 4) printf(" ");
    }
    printf("\n");
    return 0;
}
