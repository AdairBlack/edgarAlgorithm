#include <cstdio>
#include <map>
using namespace std;
int main(){
    int n, m, sumS = 0, sumT = 0;
    map<int, int> mp;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int num;
        scanf("%d", &num);
        mp[num] = 1;
    }
    for(int i = 0; i < n; i++){
        bool first = true;
        char str[5];
        int k;
        scanf("%s %d", str, &k);
        for(int j = 0; j < k; j++){
            int temp;
            scanf("%d", &temp);
            if(mp[temp] == 1){
                sumT++;
                if(first){
                    sumS++;
                    first = false;
                    printf("%s: %04d", str,temp);
                } else {
                    printf(" %04d", temp);
                }
            }
        }
        if(!first){
            printf("\n");
        }
    }
    printf("%d %d\n", sumS, sumT);
    return 0;
}
