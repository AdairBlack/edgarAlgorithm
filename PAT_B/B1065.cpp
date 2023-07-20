#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int n, m, count = 0;
    map<int, int> mp;
    int ans[100000];
    bool table1[100000] = {false}, table2[100000] = {false};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int p1, p2;
        scanf("%d%d", &p1, &p2);
        table1[p1] = true;
        table1[p2] = true;
        mp[p1] = p2;
        mp[p2] = p1;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int p;
        scanf("%d", &p);
        table2[p] = true;
    }
    for(int i = 0; i < 100000; i++){
        if(table2[i]){
            if(!table1[i]){
                ans[count++] = i;
            } else {
                if(table2[mp[i]] == false){
                    ans[count++] = i;
                }
            }
        }
    }
    sort(ans, ans + count);
    printf("%d\n", count);
    for(int i = 0; i < count; i++){
        if(i != 0) printf(" ");
        printf("%05d", ans[i]);
    }
//    printf("\n");
    return 0;
}
