#include <cstdio>
#include <cstring>
int main(){
    int times[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char table[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int n;
    bool flag = false;
    bool noNum = false;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char num[20];
        scanf("%s", num);
        int sum = 0;
        for(int j = 0; j < 17; j++){
            if(!(num[j] >= '0' && num[j] <= '9')){
                noNum = true;
                break;
            }
            sum += ((num[j] - '0') * times[j]);
        }
        sum %= 11;
        if(noNum){
            printf("%s\n", num);
            flag = true;
        }else if(table[sum] != num[17]){
            printf("%s\n", num);
            flag = true;
        }
        noNum = false;
    }
    if(!flag){
        printf("All passed\n");
    }
    return 0;
}
