#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int n, d, n1 = 0, n2 = 0; // n: the number of houses    d: watch days standard   n1: number of maybe empty    n2: number of empty
    double e, r1 = 0, r2 = 0; // e: electircity standard      r1: rate of maybe empty     r2: rate of empty
    scanf("%d%lf%d", &n, &e, &d);
    for(int i = 0; i < n; i++){
        int k, emptyDays = 0;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            double value;
            scanf("%lf", &value);
            if(value < e){
                emptyDays++;
            }
        }
        if(emptyDays > k / 2 && k > d){
            n2++;
        } else if(emptyDays > k / 2){
            n1++;
        }
    }
    r1 =(double) n1 / n;
    r2 =(double) n2 / n;
    printf("%.1f%% %.1f%%\n", r1 * 100, r2 * 100);
    return 0;
}
