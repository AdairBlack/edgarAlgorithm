#include <cstdio>
#include <cstring>
struct Student{
    char id[20];
    int a,b;
}students[1010];
int main(){
    int n, k;
    char idTemp[20];
    int aTemp, bTemp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", idTemp, &aTemp, &bTemp);
        students[aTemp].b = bTemp;
        strcpy(students[aTemp].id, idTemp);
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &aTemp);
        printf("%s %d\n", students[aTemp].id, students[aTemp].b);
    }
    return 0;
}
