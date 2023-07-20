#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
    char id[10];
    int d, c, total;
} result1[100010], result2[100010], result3[100010], result4[100010];

bool cmp(Student a, Student b){
    if(a.total != b.total) return a.total > b.total;
    else if(a.d != b.d) return a.d > b.d;
    else return strcmp(a.id, b.id) < 0;
}

int main(){
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, n, l, h;
    scanf("%d%d%d", &n, &l, &h);
    int count = n;
    char str[10];
    int grade1, grade2;
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", str, &grade1, &grade2);
        if(grade1 < l || grade2 < l){
            count--;
            continue;
        } else if(grade1 >= h && grade2 >= h){
            strcpy(result1[count1].id, str);
            result1[count1].d = grade1;
            result1[count1].c = grade2;
            result1[count1].total = grade1 + grade2;
            count1++;
            continue;
        } else if(grade1 >= h && grade2 < h){
            strcpy(result2[count2].id, str);
            result2[count2].d = grade1;
            result2[count2].c = grade2;
            result2[count2].total = grade1 + grade2;
            count2++;
            continue;
        } else if(grade1 < h && grade2 < h && grade1 >= grade2){
            strcpy(result3[count3].id, str);
            result3[count3].d = grade1;
            result3[count3].c = grade2;
            result3[count3].total = grade1 + grade2;
            count3++;
            continue;
        } else {
            strcpy(result4[count4].id, str);
            result4[count4].d = grade1;
            result4[count4].c = grade2;
            result4[count4].total = grade1 + grade2;
            count4++;
            continue;
        }
    }
    sort(result1, result1 + count1, cmp);
    sort(result2, result2 + count2, cmp);
    sort(result3, result3 + count3, cmp);
    sort(result4, result4 + count4, cmp);
    printf("%d\n", count);
    for(int i = 0; i < count1; i++){
        printf("%s %d %d\n", result1[i].id, result1[i].d, result1[i].c);
    }
    for(int i = 0; i < count2; i++){
        printf("%s %d %d\n", result2[i].id, result2[i].d, result2[i].c);
    }
    for(int i = 0; i < count3; i++){
        printf("%s %d %d\n", result3[i].id, result3[i].d, result3[i].c);
    }
    for(int i = 0; i < count4; i++){
        printf("%s %d %d\n", result4[i].id, result4[i].d, result4[i].c);
    }
    return 0;
}


