#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c, p, r, d;
    scanf("%lld.%lld.%lld", &a, &b, &c);
    p = a * 17 * 29 + b * 29 + c;
    scanf("%lld.%lld.%lld", &a, &b, &c);
    r = a * 17 * 29 + b * 29 + c;
    if(r < p) printf("-");
    d = abs(r - p);
    c = d % 29;
    d /= 29;
    b = d % 17;
    d /= 17;
    a = d;
    printf("%lld.%lld.%lld\n", a, b, c);
    return 0;
}
