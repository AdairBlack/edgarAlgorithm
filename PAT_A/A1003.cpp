#include <cstdio>
#include <vector>
using namespace std;
struct Node{
    int v, dis;
};
const int MAXV  = 510;
const int INF = 0xfffffff;
int n, m, c1, c2, te[MAXV], t[MAXV], d[MAXV], num[MAXV];
vector<Node> adj[MAXV];
bool vis[MAXV] = {false};

void dijkstra(int s){
    fill(d, d + MAXV, MAXV);
    fill(t, t + MAXV, 0);
    fill(num, num + MAXV, 0);
    d[s] = 0;
    t[s] = te[s];
    num[s] = 1;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].v;
            if(vis[v] == false && d[u] + adj[u][j].dis < d[v]){
                d[v] = d[u] + adj[u][j].dis;
                num[v] = num[u];
                t[v] = t[u] + te[v];
            } else if(d[u] + adj[u][j].dis == d[v] && t[u] + te[v] > t[v]){
                t[v] = t[u] + te[v];
                num[v] += num[u];
            } else if(d[u] + adj[u][j].dis == d[v]){
                num[v] += num[u];
            }
            
        }
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++){
        scanf("%d", &te[i]);
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        Node node;
        scanf("%d%d%d", &a, &b, &c);
        node.v = b;
        node.dis = c;
        adj[a].push_back(node);
        node.v = a;
        adj[b].push_back(node);
    }
    dijkstra(c1);
    printf("%d %d\n", num[c2], t[c2]);
}
