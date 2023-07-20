#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int MAXW = 110;

struct Customer{
    int arriveTime, processTime;
}customers[MAXN];

int windowsEndTime[MAXW];

int convertToSeconds(int hour, int minute, int second){
    return hour * 60 * 60 + minute * 60 + second;
}

bool cmp(Customer a, Customer b){
    return a.arriveTime < b.arriveTime;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int countAll = 0, totalWaitTime = 0;
    for(int i = 0; i < n; i++){
        int hour, minute, second;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &customers[countAll].processTime);
        if(hour < 17){
            customers[countAll].arriveTime = convertToSeconds(hour, minute, second);
            customers[countAll].processTime *= 60;
            countAll++;
        }
    }
    sort(customers, customers + countAll, cmp);
    
    int index = 0;
    for(int i = 0; i < min( k, countAll); i++){
        int beginSecond = convertToSeconds(8, 0, 0);
        windowsEndTime[index] = customers[index].arriveTime < beginSecond ? beginSecond + customers[index].processTime : customers[index].arriveTime + customers[index].processTime;
        totalWaitTime += customers[index].arriveTime < beginSecond ? beginSecond - customers[index].arriveTime : 0;
        index++;
    }
    
    for(; index < countAll; index++){
        int windowId = -1, minTime = 1 << 30;
        for(int i = 0; i < k; i++){
            if(windowsEndTime[i] < minTime){
                windowId = i;
                minTime = windowsEndTime[i];
            }
        }
        totalWaitTime += customers[index].arriveTime < windowsEndTime[windowId] ? windowsEndTime[windowId] - customers[index].arriveTime : 0;
        windowsEndTime[windowId] = customers[index].arriveTime < windowsEndTime[windowId] ? windowsEndTime[windowId] + customers[index].processTime : customers[index].arriveTime + customers[index].processTime;
    }
    
    printf("%.1f\n", totalWaitTime / (60.0 * countAll));
    return 0;
}

