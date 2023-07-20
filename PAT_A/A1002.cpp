#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
    int exp;
    double coe;
}l1[10], l2[10], ans[20];

bool cmp(Node a, Node b){
    return a.exp > b.exp;
}

int main(){
    int k1, k2, count = 0;
    scanf("%d", &k1);
    for(int i = 0; i < k1; i++){
        scanf("%d%lf", &l1[i].exp, &l1[i].coe);
    }
    scanf("%d", &k2);
    for(int i = 0; i < k2; i++){
        scanf("%d%lf", &l2[i].exp, &l2[i].coe);
    }
    sort(l1, l1 + k1, cmp);
    sort(l2, l2 + k2, cmp);
    int i = 0, j = 0;
    while(i < k1 && j < k2){
        if(l1[i].exp < l2[j].exp){
            ans[count++] = l2[j];
            j++;
        } else if(l1[i].exp > l2[j].exp){
            ans[count++] = l1[i];
            i++;
        } else {
            if(l1[i].coe + l2[j].coe == 0){
                i++;
                j++;
                continue;
            }
            Node temp;
            temp.exp = l1[i].exp;
            temp.coe = l1[i].coe + l2[j].coe;
            ans[count++] = temp;
            j++;
            i++;
        }
    }
    while(i < k1){
        ans[count++] = l1[i++];
    }
    while(j < k2){
        ans[count++] = l2[j++];
    }
    printf("%d", count);
    for(int i = 0; i < count; i++){
        printf(" %d %.1f", ans[i].exp, ans[i].coe);
    }
    printf("\n");
    return 0;
}
