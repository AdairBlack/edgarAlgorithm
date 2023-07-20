#include <cstdio>
#include <vector>
using namespace std;
struct Node{
    int address, data, next;
}nodes[100000];

int main(){
    int first, n, k;
    vector<Node> ans;
    scanf("%d %d %d", &first, &n, &k);
    for(int i = 0; i < n; i++){
        int address, data, next;
        scanf("%d %d %d", &address, &data, &next);
        nodes[address].address = address;
        nodes[address].data = data;
        nodes[address].next = next;
    }
    Node node = nodes[first];
    vector<Node> a, b, c; // a is all negective numbers, b is all [0,k] numbers, c is others
    while(1){
        if(node.data < 0){
            a.push_back(node);
        } else if(node.data >= 0 && node.data <= k){
            b.push_back(node);
        } else {
            c.push_back(node);
        }
        if(node.next == -1){
            break;
        }
        node = nodes[node.next];
    }
    for(int i = 0; i < a.size(); i++){
        Node temp = a[i];
        if(i != a.size() - 1){
            temp.next = a[i + 1].address;
        } else {
            temp.next = -1;
        }
        ans.push_back(temp);
    }
    for(int i = 0; i < b.size(); i++){
        if(i == 0 && ans.size() != 0){
            ans[ans.size() - 1].next = b[0].address;
        }
        Node temp = b[i];
        if(i != b.size() - 1){
            temp.next = b[i + 1].address;
        } else {
            temp.next = -1;
        }
        ans.push_back(temp);
    }
    for(int i = 0; i < c.size(); i++){
        if(i == 0 && ans.size() != 0){
            ans[ans.size() - 1].next = c[0].address;
        }
        Node temp = c[i];
        if(i != c.size() - 1){
            temp.next = c[i + 1].address;
        }
        else {
            temp.next = -1;
        }
        ans.push_back(temp);
    }
    for(vector<Node>::iterator it = ans.begin(); it != ans.end(); it++){
        
        printf("%05d %d", (*it).address, (*it).data);
        if((*it).next == -1 ){
            printf(" -1\n");
        } else {
            printf(" %05d\n", (*it).next);
        }
    }
    return 0;
}
