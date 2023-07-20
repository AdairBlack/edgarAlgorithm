#include <cstdio>

int main(){
    int t, k, n1, n2, b, q;
    scanf("%d%d", &t, &k);
    for(int i = 0; i < k; i++){
        if(t == 0){
            printf("Game Over.\n");
            break;
        }
        scanf("%d%d%d%d", &n1, &b, &q, &n2);
        if(q > t){
            printf("Not enough tokens.  Total = %d.\n", t);
            continue;
        }
        if((n2 > n1 && b == 1) || (n2 < n1 && b == 0)){
            t += q;
            printf("Win %d!  Total = %d.\n", q, t);
        } else {
            t -= q;
            printf("Lose %d.  Total = %d.\n", q, t);
        }
    }
    return 0;
}
