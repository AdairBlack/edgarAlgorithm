#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
const int INF = 0x3fffffff;
int graph[MAXN][MAXN];
int n, m, k, current;
bool visited[MAXN];

void dfs(int start){
    visited[start] = true;
    for(int i = 1; i <= n; i++){
        if(i == current){
            continue;
        }
        if(!visited[i] && graph[start][i] != INF){
            dfs(i);
        }
    }
}

int main(){
    fill(graph[0], graph[0] + MAXN * MAXN, INF);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }
    int count = 0;
    for(int i = 0; i < k; i++){
        count = 0;
        fill(visited, visited + MAXN, false);
        int temp;
        scanf("%d", &temp);
        current = temp;
        for(int i = 1; i <= n; i++){
            if(i == current){
                continue;
            }
            if(!visited[i]){
                count++;
                dfs(i);
            }
        }
        printf("%d\n", count - 1);
    }
    return 0;
}
