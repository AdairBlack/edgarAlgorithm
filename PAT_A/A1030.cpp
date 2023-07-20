#include <cstdio>
#include <vector>
using namespace std;
const int MAXV = 510;
const int INF = 0xfffffff;

int adj[MAXV][MAXV], fee[MAXV][MAXV];
vector<int> pre[MAXV];
vector<int> path, tempPath;
int d[MAXV];
bool vis[MAXV] = {false};
int n, m, s, b;
int optValue = INF;

void dijkstra(int begin){
    fill(d, d + MAXV, INF);
    d[begin] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(d[j] < MIN && !vis[j]){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(adj[u][v] + d[u] < d[v]){
                d[v] = adj[u][v] + d[u];
                pre[v].clear();
                pre[v].push_back(u);
            } else if(adj[u][v] + d[u] == d[v]){
                pre[v].push_back(u);
            }
        }
    }
    return;
}
void dfs(int v){
    tempPath.push_back(v);
    if(v == s){
        int value = 0;
        for(int i = 0; i < tempPath.size() - 1; i++){
            value += fee[tempPath[i]][tempPath[i + 1]];
        }
        if(value < optValue){
            optValue = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i = 0; i < pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
    return;
}
int main(){
    scanf("%d%d%d%d", &n, &m, &s, &b);
    fill(adj[0], adj[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        scanf("%d", &adj[u][v]);
        scanf("%d", &fee[u][v]);
        adj[v][u] = adj[u][v];
        fee[v][u] = fee[u][v];
    }
    dijkstra(s);
    dfs(b);
    for(int i = path.size() - 1; i >= 0; i--){
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[b], optValue);
    return 0;
}
