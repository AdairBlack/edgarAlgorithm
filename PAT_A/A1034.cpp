#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAXN = 2010;

map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;
int G[MAXN][MAXN] = {0}, weight[MAXN] = {0};
int n, k, numPerson = 0;
bool visited[MAXN] = {false};

int change(string str){
    if(stringToInt.find(str) != stringToInt.end()){
        return stringToInt[str];
    } else {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        numPerson++;
        return numPerson - 1;
    }
}

void dfs(int currentNode, int& head, int& population, int& totalWeight){
    population++;
    visited[currentNode] = true;
    if(weight[currentNode] > weight[head]){
        head = currentNode;
    }
    for(int i = 0; i < numPerson; i++){
        if(G[currentNode][i] != 0){
            totalWeight += G[currentNode][i];
            G[currentNode][i] = G[i][currentNode] = 0;
            if(!visited[i]){
                dfs(i, head, population, totalWeight);
            }
        }
    }
}

void dfsTraverse(){
    for(int i = 0; i < numPerson; i++){
        int population  = 0, head = i, totalWeight = 0;
        if(!visited[i]){
            dfs(i, head, population, totalWeight);
            if(totalWeight > k && population > 2){
                Gang[intToString[head]] = population;
            }
        }
    }
}

int main(){
    int w;
    string str1, str2;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        G[id1][id2] += w;
        G[id2][id1] += w;
        weight[id1] += w;
        weight[id2] += w;
    }
    dfsTraverse();
    cout << Gang.size() << endl;
    for(map<string, int>::iterator it = Gang.begin(); it != Gang.end(); it++){
        cout << it -> first << " " << it -> second << endl;
    }
    return 0;
}
