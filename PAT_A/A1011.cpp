#include <cstdio>

int main(){
    char cha[4] = {'W', 'T', 'L'};
    double odds[3][3];
    double win[3];
    char bet[4];
    for(int i = 0; i < 3; i++){
        int maxi = 0;
        double maxo = -1;
        for(int j = 0; j < 3; j++){
            scanf("%lf", &odds[i][j]);
            if(odds[i][j] > maxo){
                maxi = j;
                maxo = odds[i][j];
                win[i] = maxo;
            }
            bet[i] = cha[maxi];
        }
    }
    double profit;
    profit = (win[0] * win[1] * win[2] * 0.65 - 1) * 2;
    printf("%c %c %c ", bet[0], bet[1], bet[2]);
    printf("%.2f\n", profit);
}
