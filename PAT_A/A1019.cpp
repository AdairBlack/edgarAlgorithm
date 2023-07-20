#include <cstdio>

const int MAXN = 10;

int value;
int num[MAXN];
int count = 0;
int base;

void intToArray(){
    while(value != 0){
        num[count++] = value % base;
        value /= base;
    }
}

int main(){
    scanf("%d%d", &value, &base);
    bool pali = true;
    intToArray();
    int left = 0, right = count - 1;
    while(left < right){
        if(num[left] != num[right]){
            pali = false;
            break;
        }
        left++;
        right--;
    }
    if(pali){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for(int i = count - 1; i > 0; i--){
        printf("%d ", num[i]);
    }
    printf("%d\n", num[0]);
    return 0;
}
