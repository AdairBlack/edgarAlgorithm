/* The output is a long long not 0-9 or a-z
   So the biggest radix for the unknown radix number is the decimal number of the known radix number
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL INF = (1LL << 63) - 1;
LL Map[256];

void init(){
    for(char c = '0'; c <= '9'; c++){
        Map[c] = c - '0';
    }
    for(char c = 'a'; c <= 'z'; c++){
        Map[c] = c - 'a' + 10;
    }
}

LL convertNumber10(char a[], LL radix, LL t){
    int len = strlen(a);
    LL ans = 0;
    for(int i = 0; i < len; i++){
        ans = ans * radix + Map[a[i]];
        if(ans > t || ans < 0) return -1;
    }
    return ans;
}

int cmp(char N2[], LL radix,LL t){
    LL num = convertNumber10(N2, radix, t);
    if(num < 0) return 1;
    if(t > num) return -1;
    else if(t == num) return 0;
    else return 1;
}

LL binarySearch(char N2[], LL left, LL right, LL t){
    while(left <= right){
        LL mid = (left + right) / 2;
        int flag = cmp(N2, mid, t);
        if(flag == 0) return mid;
        else if(flag == -1) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

LL findLargestDigit(char N2[]){
    LL ans = -1;
    int len = strlen(N2);
    for(int i = 0; i < len; i++){
        if(Map[N2[i]] > ans){
            ans = Map[N2[i]];
        }
    }
    return ans + 1;
}

int main(){
    char N1[15], N2[15], temp[15];
    int tag;
    LL radix;
    init();
    scanf("%s %s %d %lld", N1, N2, &tag, &radix);
    if(tag == 2){
        strcpy(temp, N2);
        strcpy(N2, N1);
        strcpy(N1, temp);
    }
    LL t = convertNumber10(N1, radix, INF);
    LL low = findLargestDigit(N2);
    LL high = max(low, t) + 1;
    LL ans = binarySearch(N2, low, high, t);
    if(ans == -1) printf("Impossible\n");
    else printf("%lld\n", ans);
    return 0;
}
