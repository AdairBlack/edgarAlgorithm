#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, t;
int num[1010][1010];

struct Node{
    int x, y, data;
};

bool judge(Node node){
    for(int i = max(node.x - 1, 1); i <= min(node.x + 1, m); i++){
        for(int j = max(node.y - 1, 1); j <= min(node.y + 1, n); j++){
            if(j == node.y && i == node.x){
                continue;
            }
            if(abs(num[i][j] - node.data) <= t){
                return false;
            }
        }
    }
    return true;
}

int main(){
    map<int, int> mp;
    vector<Node> nodes;
    scanf("%d%d%d", &n, &m, &t);
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            scanf("%d", &num[i][j]);
            mp[num[i][j]]++;
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            Node node;
            node.x = i;
            node.y = j;
            node.data = num[i][j];
            if(mp[node.data] == 1 && judge(node)){
                nodes.push_back(node);
            }
        }
    }
    if(nodes.size() > 1){
        printf("Not Unique\n");
    } else if(nodes.size() == 0){
        printf("Not Exist\n");
    } else {
        printf("(%d, %d): %d\n", nodes[0].y, nodes[0].x, nodes[0].data);
    }
    return 0;
}
