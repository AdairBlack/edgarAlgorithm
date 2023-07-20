#include <cstdio>
#include <algorithm>
using namespace std;
struct Pie{
    double totalCost;
    double num;
    double price;
}pie[1010];

bool cmp(Pie a, Pie b){
    return a.price > b.price;
}

int main(){
    int n, d;
    double ans = 0;
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; i++){
        scanf("%lf", &pie[i].num);
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &pie[i].totalCost);
        pie[i].price = pie[i].totalCost / pie[i].num;
    }
    sort(pie, pie + n, cmp);
    for(int i = 0; i < n; i++){
        if(pie[i].num >= d){
            ans += pie[i].price * d;
            break;
        } else {
            ans += pie[i].totalCost;
            d -= pie[i].num;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
