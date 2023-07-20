#include <cstdio>

int main(){
    int a, b, clock, time, hh, mm, ss;
    scanf("%d %d", &a, &b);
    clock = b - a;
    time = clock / 100;
    if(clock % 100 >= 50) time++;
    ss = time % 60;
    time /= 60;
    mm = time % 60;
    time /= 60;
    hh = time % 60;
    printf("%02d:%02d:%02d\n", hh, mm, ss);
    return 0;
}
