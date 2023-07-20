#include <cstdio>
struct Poly{
    int exp;
    double coe;
}poly[1001];
double ans[2001];
int main(){
    int n, m, number = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%lf", &poly[i].exp, &poly[i].coe);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int exp;
        double coe;
        scanf("%d%lf", &exp, &coe);
        for(int j = 0; j < n; j++){
            ans[exp + poly[j].exp] += (coe * poly[j].coe);
        }
    }
    for(int i = 0; i <= 2000; i++){
        if(ans[i] != 0.0) number++;
    }
    printf("%d", number);
    for(int i = 2000; i >= 0; i--){
        if(ans[i] != 0.0){
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}
