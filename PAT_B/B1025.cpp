#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
    int address, data, next, order;
}node[maxn];

bool cmp(Node a, Node b){
    return a.order < b.order;
}

int main(){
    for(int i = 0; i < maxn; i++){
        node[i].order = maxn;
    }
    int first, n, k;
    scanf("%d %d %d", &first, &n, &k);
    for(int i = 0; i < n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        node[a].address = a;
        node[a].data = b;
        node[a].next = c;
    }
    int p = first, count = 0;
    while(p != -1){
        node[p].order = count;
        p = node[p].next;
        count++;
    }
    sort(node, node + maxn, cmp);
    for(int i = 0; i < count / k; i++){
        for(int j = (i + 1) * k - 1; j > i * k; j--){
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
        }
        if(i < count / k - 1){
            printf("%05d %d %05d\n", node[i * k].address, node[i * k].data, node[(i + 2) * k - 1].address);
        } else {
            if(count % k == 0){
                printf("%05d %d -1\n", node[i * k].address, node[i * k].data);
            } else {
                printf("%05d %d %05d\n", node[i * k].address, node[i * k].data, node[(i + 1) * k].address);
                for(int j = (i + 1) * k; j < count - 1; j++){
                    printf("%05d %d %05d\n", node[j].address, node[j].data, node[j].next);
                }
                printf("%05d %d -1\n", node[count - 1].address, node[count - 1].data);
            }
        }
    }
    return 0;
}
