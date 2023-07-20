#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Faction{
    ll up, down;
};

ll gcd(ll a, ll b){
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
    } else {
        ll a = gcd(abs(f.up), abs(f.down));
        f.up /= a;
        f.down /= a;
    }
    return;
}

Faction add(Faction f1, Faction f2){
    Faction f;
    f.up = f1.up * f2.down + f2.up * f1.down;
    f.down = f1.down * f2.down;
    reduction(f);
    return f;
}

Faction minu(Faction f1, Faction f2){
    Faction f;
    f.up = f1.up * f2.down - f2.up * f1.down;
    f.down = f1.down * f2.down;
    reduction(f);
    return f;
}

Faction multi(Faction f1, Faction f2){
    Faction f;
    f.up = f1.up * f2.up;
    f.down = f1.down * f2.down;
    reduction(f);
    return f;
}

Faction divide(Faction f1, Faction f2){
    Faction f;
    f.up = f1.up * f2.down;
    f.down = f1.down * f2.up;
    reduction(f);
    return f;
}

void print(Faction f){
    reduction(f);
    bool flag = false;
    if(f.up < 0){
        printf("(");
        flag = true;
    }
    if(f.down == 1) printf("%lld", f.up);
    else if(f.down == 0) printf("Inf");
    else if(abs(f.up) > f.down){
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }
    if(flag) printf(")");
}

void printAdd(Faction f1, Faction f2){
    print(f1);
    printf(" + ");
    print(f2);
    printf(" = ");
    print(add(f1, f2));
    printf("\n");
}

void printMinu(Faction f1, Faction f2){
    print(f1);
    printf(" - ");
    print(f2);
    printf(" = ");
    print(minu(f1, f2));
    printf("\n");
}

void printMulti(Faction f1, Faction f2){
    print(f1);
    printf(" * ");
    print(f2);
    printf(" = ");
    print(multi(f1, f2));
    printf("\n");
}

void printDivide(Faction f1, Faction f2){
    print(f1);
    printf(" / ");
    print(f2);
    printf(" = ");
    print(divide(f1, f2));
    printf("\n");
}

int main(){
    Faction f1, f2;
    scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);
    reduction(f1);
    reduction(f2);
    printAdd(f1, f2);
    printMinu(f1, f2);
    printMulti(f1, f2);
    printDivide(f1, f2);
    return 0;
}
