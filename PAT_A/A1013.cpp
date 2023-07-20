#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0xfffffff;

int graph[1010][1010];
bool visited[1010];
int n, m, k, con;
int deleteed;

void dfs(int node){
    if(node == con) return;
    visited[node] = true;
    for(int i = 1; i <= n; i++){
        if(!visited[i] && graph[node][i] == 1){
            dfs(i);
        }
    }
}

int main(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            graph[i][j] = graph[j][i] = INF;
        }
    }
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &con);
        fill(visited, visited + 1010, false);
        int block = 0;
        for(int i = 1; i <= n; i++){
            if(i != con && !visited[i]){
                dfs(i);
                block++;
            }
        }
        printf("%d\n", block - 1);
    }
    return 0;
}

