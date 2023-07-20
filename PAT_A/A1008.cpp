#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int temp;
    scanf("%d", &n);
    int floor = 0;
    int totalTime = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        int minus = temp - floor;
        if(minus == 0) {
            totalTime += 5;
        } else if(minus > 0){
            totalTime += minus * 6 + 5;
        } else {
            totalTime += abs(minus) * 4 + 5;
        }
        floor = temp;
    }
    printf("%d\n", totalTime);
    return 0;
}
