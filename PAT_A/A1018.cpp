#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3fffffff;
const int MAXN = 510;
int graph[MAXN][MAXN];
int currentBike[MAXN];
int capacity, n, problemStation, numberOfEdges;
bool visited[MAXN];
vector<int> preNode[MAXN];
int distanceNode[MAXN];
vector<int> path;
vector<int> tempPath;
int optOutBike = INF;
int optBackBike = INF;

void dfs(int currentNode){
    if(currentNode == 0){
        int tempOutBike = 0;
        int tempBackBike = 0;
        int remain = 0;
        int difference;
        for(int i = tempPath.size() - 1; i >= 0; i--){
            int id = tempPath[i];
            if(currentBike[id] < 0){
                if(remain < abs(currentBike[id])){
                    tempOutBike += abs(currentBike[id]) - remain;
                    remain = 0;
                } else {
                    remain += currentBike[id];
                }
            } else {
                remain += currentBike[id];
            }
        }
        tempBackBike = remain;
        
        tempPath.push_back(0);
        if(tempOutBike < optOutBike){
            optOutBike = tempOutBike;
            optBackBike = tempBackBike;
            path = tempPath;
        } else if (tempOutBike == optOutBike && tempBackBike < optBackBike){
            optBackBike = tempBackBike;
            path = tempPath;
        }
        tempPath.pop_back();
    }
    
    tempPath.push_back(currentNode);
    for(vector<int>::iterator it = preNode[currentNode].begin(); it != preNode[currentNode].end(); it++){
        dfs((*it));
    }
    tempPath.pop_back();
}

void dijkstra(){
    fill(distanceNode, distanceNode + MAXN, INF);
    distanceNode[0] = 0;
    for(int i = 0; i < n; i++){
        int nodeId = -1, minDistance = INF;
        for(int j = 0; j <= n; j++){
            if(!visited[j] && distanceNode[j] < minDistance){
                nodeId = j;
                minDistance = distanceNode[j];
            }
        }
        if(nodeId == -1) return;
        visited[nodeId] = true;
        for(int j = 0; j <= n; j++){
            if(!visited[j] && graph[nodeId][j] != INF && graph[nodeId][j] + distanceNode[nodeId] < distanceNode[j]){
                distanceNode[j] = graph[nodeId][j] + distanceNode[nodeId];
                preNode[j].clear();
                preNode[j].push_back(nodeId);
            } else if(!visited[j] && graph[nodeId][j] != INF && graph[nodeId][j] + distanceNode[nodeId] == distanceNode[j]){
                preNode[j].push_back(nodeId);
            }
        }
    }
}

int main(){
    fill(graph[0], graph[0] + MAXN * MAXN, INF);
    fill(visited, visited + MAXN, false);
    scanf("%d%d%d%d", &capacity, &n, &problemStation, &numberOfEdges);
    currentBike[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &currentBike[i]);
    }
    for(int i = 0; i <= n; i++){
        graph[i][i] = 0;
    }
    for(int i = 0; i < numberOfEdges; i++){
        int beginNode, endNode, distance;
        scanf("%d%d%d", &beginNode, &endNode, &distance);
        graph[beginNode][endNode] = graph[endNode][beginNode] = distance;
    }
    for(int i = 1; i <= n; i++){
        currentBike[i] -= capacity / 2;
    }
    dijkstra();
    dfs(problemStation);
    
    printf("%d ", optOutBike);
    for(int i = path.size() - 1; i > 0; i--){
        printf("%d->", path[i]);
    }
    printf("%d %d\n", path[0], optBackBike);
    return 0;
}

