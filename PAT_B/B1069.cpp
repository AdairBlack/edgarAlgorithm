#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    int m, n, s;
    bool has = false;
    map<string, int> mp;
    scanf("%d%d%d", &m, &n, &s);
    for(int i = 1; i <= m; i++){
        string str;
        cin >> str;
        if((i - s) >= 0 && (i - s) % n == 0){
            if(mp[str] != 0){
                s += 1;
                continue;
            }
            has = true;
            cout << str << endl;
            mp[str]++;
        }
    }
    if(!has){
        printf("Keep going...\n");
    }
    return 0;
}
