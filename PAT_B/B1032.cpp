#include <cstdio>
#include <algorithm>
using namespace std;

struct School{
    int order, score;
}school[100010];

bool cmp(School a, School b){
    return a.score > b.score;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n + 1; i++){
        school[i].order = i;
        school[i].score = 0;
    }
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        school[a].score += b;
    }
    sort(school, school + n + 1, cmp);
    printf("%d %d\n", school[0].order, school[0].score);
    return 0;
}
