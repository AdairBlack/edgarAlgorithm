#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

char num1[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char num2[12][5] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> mp;

int changeToEarth(char str[]){
    string s(str);
    return mp[s];
}

void init(){
    mp["tret"] = 0;
    mp["jan"] = 1;
    mp["feb"] = 2;
    mp["mar"] = 3;
    mp["apr"] = 4;
    mp["may"] = 5;
    mp["jun"] = 6;
    mp["jly"] = 7;
    mp["aug"] = 8;
    mp["sep"] = 9;
    mp["oct"] = 10;
    mp["nov"] = 11;
    mp["dec"] = 12;
    
    mp["tam"] = 1 * 13;
    mp["hel"] = 2 * 13;
    mp["maa"] = 3 * 13;
    mp["huh"] = 4 * 13;
    mp["tou"] = 5 * 13;
    mp["kes"] = 6 * 13;
    mp["hei"] = 7 * 13;
    mp["elo"] = 8 * 13;
    mp["syy"] = 9 * 13;
    mp["lok"] = 10 * 13;
    mp["mer"] = 11 * 13;
    mp["jou"] = 12 * 13;
}

int main(){
    init();
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        char str[10];
        gets(str);
        if(str[0] >= '0' && str[0] <= '9'){
            int len = strlen(str);
            int total = 0, numOne, numTow;
            for(int j = 0; j < len; j++){
                total = total * 10 + (str[j] - '0');
            }
            numOne = total % 13;
            numTow = total / 13;
            if(numTow != 0) printf("%s", num2[numTow - 1]);
            if(numOne != 0 && numTow != 0) printf(" ");
            if(numOne != 0) printf("%s", num1[numOne]);
            if(numTow == 0 && numOne == 0) printf("tret");
            printf("\n");
        } else {
            int pos = 0;
            char numOne[5], numTow[5];
            char numSingle[5];
            int len = strlen(str);
            for(int j = 0; j < len; j++){
                if(str[j] == ' ') pos = j;
            }
            if(pos != 0){
                for(int j = 0; j < pos; j++){
                    numTow[j] = str[j];
                }
                numTow[pos] = '\0';
                int m = pos;
                for(int j = 0; j < len - pos; j++){
                    numOne[j] = str[++m];
                }
                numOne[len - pos] = '\0';
            } else {
                strcpy(numSingle, str);
            }
            if(pos != 0){
                int total = changeToEarth(numTow) + changeToEarth(numOne);
                printf("%d\n", total);
            } else {
                int total = changeToEarth(numSingle);
                printf("%d\n", total);
            }
        }
    }
    return 0;
}
