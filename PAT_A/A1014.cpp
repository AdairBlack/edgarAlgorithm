#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int convertToMinute(int h, int m){
    return h * 60 + m;
}
struct Window{
    int endTime, popTime;
    queue<int> q;
}windows[20];

int main(){
    int n, m, k, q, query, index = 0;
    int needTime[1000], finishTime[1000];
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0; i < k; i++){
        scanf("%d", &needTime[i]);
    }
    for(int i = 0; i < n; i++){
        windows[i].endTime = windows[i].popTime = convertToMinute(8, 0);
    }
    
    for(; index < min(n * m, k); index++){
        windows[index % n].q.push(index);
        windows[index % n].endTime += needTime[index];
        if(windows[index % n].popTime != convertToMinute(8, 0)){
            windows[index % n].popTime += needTime[windows[index % n].q.front()];
        }
        finishTime[index] = windows[index % n].endTime;
    }
    for(; index < k; index++){
        int windowIndex = -1, minPopTime = 1 << 30;
        for(int i = 0; i < n; i++){
            if(windows[i].popTime < minPopTime){
                windowIndex = i;
                minPopTime = windows[i].popTime;
            }
        }
        windows[windowIndex].q.pop();
        windows[windowIndex].q.push(index);
        windows[windowIndex].endTime += needTime[index];
        windows[windowIndex].popTime += needTime[windows[windowIndex].q.front()];
        finishTime[index] = windows[windowIndex].endTime;
    }
    for(int i = 0; i < q; i++){
        scanf("%d", &query);
        if(finishTime[query - 1] - needTime[query - 1] < convertToMinute(17, 0)){
            printf("%02d:%02d\n", finishTime[query - 1] / 60, finishTime[query - 1] % 60);
        } else {
            printf("Sorry\n");
        }
    }
}
