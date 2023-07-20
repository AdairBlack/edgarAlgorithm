#include <cstdio>
#include <algorithm>
using namespace std;
int num[110], numTemp[110], numChanged[110];
int n;

bool isSame(int a[], int b[]){
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

void printArray(int a[]){
    for(int i = 0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
}

bool insertSort(){
    for(int i = 0; i < n; i++){
        numTemp[i] = num[i];
    }
    bool flag = false;
    for(int i = 1; i < n; i++){
        if(i != 1 && isSame(numTemp, numChanged)){
            flag = true;
        }
        int temp = numTemp[i], j = i;
        while(j > 0 && numTemp[j - 1] > temp){
            numTemp[j] = numTemp[j - 1];
            j--;
        }
        numTemp[j] = temp;
        if(flag){
            printf("Insertion Sort\n");
            printArray(numTemp);
            return true;
        }
    }
    return false;
}

void mergeSort(){
    for(int i = 0; i < n; i++){
        numTemp[i] = num[i];
    }
    bool flag = false;
    for(int step = 2; step / 2 <= n; step *= 2){
        if(step != 2 && isSame(numTemp, numChanged)){
            flag = true;
        }
        for(int i = 0; i < n; i += step){
            sort(numTemp + i, numTemp + min(i + step, n));
        }
        if(flag){
            printf("Merge Sort\n");
            printArray(numTemp);
            return;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &numChanged[i]);
    }
    if(!insertSort()) mergeSort();
    return 0;
}
