#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    char str[110];
    char intToEnglish[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int len, sum = 0, sumNum[5], countSum = 0;
    gets(str);
    len = strlen(str);
    for(int i = 0; i < len; i++){
        sum += str[i] - '0';
    }
    if(sum == 0){
        printf("zero\n");
        return 0;
    }
    while(sum != 0){
        sumNum[countSum++] = sum % 10;
        sum /= 10;
    }
    reverse(sumNum, sumNum + countSum);
    for(int i = 0; i < countSum; i++){
        printf("%s", intToEnglish[sumNum[i]]);
        if(i < countSum - 1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
