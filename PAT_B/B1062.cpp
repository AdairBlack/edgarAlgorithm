#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Faction{
    int up, down;
};

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void reduction(Faction &f){
    if(f.down < 0){
        f.up = -f.up;
        f.down = -f.down;
    }
    if(f.up == 0){
        f.down = 1;
    }
    int d = gcd(abs(f.up), abs(f.down));
    f.up /= d;
    f.down /= d;
}

Faction minu(Faction f1, Faction f2){
    Faction f;
    f.down = f1.down * f2.down;
    f.up = f1.up * f2.down - f1.down * f2.up;
    reduction(f);
    return f;
}

Faction add(Faction f1, Faction f2){
    Faction f;
    f.down = f1.down * f2.down;
    f.up = f1.down * f2.up + f1.up * f2.down;
    reduction(f);
    return f;
}

bool bigger(Faction f1, Faction f2){
    Faction f;
    f = minu(f1, f2);
    if(f.up > 0) return true;
    return false;
}

bool biggerEqual(Faction f1, Faction f2){
    Faction f;
    f = minu(f1, f2);
    if(f.up >= 0) return true;
    return false;
}


int main(){
    int n, m, down;
    Faction f1, f2;
    bool firstFlag = true;
    vector<Faction> ans;
    scanf("%d/%d", &n, &m);
    f1.up = n;
    f1.down = m;
    reduction(f1);
    scanf("%d/%d", &n, &m);
    f2.up = n;
    f2.down = m;
    reduction(f2);
    if(!bigger(f2, f1)){
        Faction temp;
        temp = f2;
        f2 = f1;
        f1 = temp;
    }
    scanf("%d", &down);
    int count = 0;
    while(true){
        Faction f;
        f.up = count;
        f.down = down;
        reduction(f);
        if(f.down != down){
            count++;
            continue;
        }
        if(biggerEqual(f, f2)){
            break;
        }
        if(bigger(f, f1)){
            ans.push_back(f);
        }
        count++;
    }
    for(int i = 0; i < ans.size(); i++){
        Faction f;
        f = ans[i];
        printf("%s%d/%d", firstFlag ? "":" ", f.up, down);
        firstFlag = false;
    }
    printf("\n");
    return 0;
}

