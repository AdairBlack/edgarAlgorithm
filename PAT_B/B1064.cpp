#include <cstdio>
#include <algorithm>
using namespace std;
int get(int value){
    int sum = 0;
    while(value != 0){
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

int main(){
    int n, count = 0;
    bool num[40] = {false};
    bool first = true;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);
        if(!num[get(input)]){
            count++;
        }
        num[get(input)] = true;
    }
    printf("%d\n", count);
    for(int i = 1; i < 40; i++){
        if(num[i]){
            if(first){
                printf("%d", i);
                first = false;
            } else {
                printf(" %d", i);
            }
        }
    }
    printf("\n");
    return 0;
}
