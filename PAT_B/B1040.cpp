#include <cstdio>
#include <cstring>

int main(){
    char str[100010];
    long long p = 0, t = 0, count = 0;
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] == 'T') t++;
    }
    for(int i = 0; i < len; i++){
        if(str[i] == 'P') p++;
        if(str[i] == 'A') count += p * t;
        if(str[i] == 'T') t--;
    }
    printf("%lld\n", count % 1000000007);
    return 0;
}
