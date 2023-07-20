#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Person{
    char name[10];
    int y, m, d;
}person[100010];

bool cmp(Person a, Person b){
    if(a.y != b.y) return a.y < b.y;
    else if(a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

int main(){
    char name[10];
    int a, b, c, n, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %d/%d/%d", name, &a, &b, &c);
        if(a * 10000 + b * 100 + c >= 18140906 && a * 10000 + b * 100 + c <= 20140906){
            strcpy(person[count].name, name);
            person[count].y = a;
            person[count].m = b;
            person[count].d = c;
            count++;
        }
    }
    sort(person, person + count, cmp);
    if(count == 0){
        printf("0\n");
    } else {
        printf("%d %s %s\n", count, person[0].name, person[count - 1].name);
    }
    return 0;
}
