#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10001;
const int INF = 0x3fffffff;

vector<int> adjacencyList[MAXN];
bool visited[MAXN];
bool inDeepest[MAXN];
int deepest = INF;
vector<int> deepestNode;
int startNode;
int n;



void dfs(int currentNode, int depth){
    visited[currentNode] = true;
    bool isLeaf = true;
    for(int i = 0; i < adjacencyList[currentNode].size(); i++){
        int v = adjacencyList[currentNode][i];
        if(!visited[v]){
            dfs(v, depth + 1);
            isLeaf = false;
        }
    }
    // if this node is the leaf, judge whether it is deeper or equally deep as others.
    // if deep as others just add
    // there will be multiple the same node in the vector, bool printed[MAXN] will do this.
    if(isLeaf){
        if(depth > deepest){
            deepest = depth;
            deepestNode.clear();
            fill(inDeepest, inDeepest + MAXN, false);
            deepestNode.push_back(startNode);
            inDeepest[startNode] = true;
        } else if(depth == deepest && !inDeepest[startNode]){
            deepestNode.push_back(startNode);
            inDeepest[startNode] = true;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    deepest = 0;
    for(int i = 1; i <= n; i++){
        int count = 1;
        fill(visited, visited + n + 1, false);
        startNode = i;
        dfs(i, 0);
        for(int j = 1; j <= n; j++){
            if(!visited[j]){
                startNode = j;
                dfs(j, 0);
                count++;
            }
        }
        if(count > 1){
            printf("Error: %d components\n", count);
            return 0;
        }
    }
    for(int i = 0; i < deepestNode.size(); i++){
        printf("%d\n", deepestNode[i]);
    }
    return 0;
}
