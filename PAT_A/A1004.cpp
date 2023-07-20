#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N = 110;

vector<int> G[N];
int h[N] = {0};
int leaf[N] = {0};
int max_h = 0;

void bfs(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int id = q.front();
        q.pop();
        max_h = max(max_h, h[id]);
        if(G[id].size() == 0){
            leaf[h[id]]++;
        }
        for(int i = 0; i < G[id].size(); i++){
            h[G[id][i]] = h[id] + 1;
            q.push(G[id][i]);
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int parent, k, child;
        scanf("%d%d", &parent, &k);{
            for(int j = 0; j < k; j++){
                scanf("%d", &child);
                G[parent].push_back(child);
            }
        }
    }
    h[1] = 1;
    bfs();
    for(int i = 1; i <= max_h; i++){
        if(i == 1) printf("%d", leaf[i]);
        else printf(" %d", leaf[i]);
    }
    return 0;
}
