#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 40;

struct Node{
    int data;
    Node *lchild, *rchild;
};

int pre[MAXN], in[MAXN], post[MAXN];

Node* create(int postL, int postR, int inL, int inR){
    if(postL > postR){
        return NULL;
    }
    Node* root = new Node;
    root -> data = post[postR];
    int k;
    for(k = inL; k <= inR; k++){
        if(in[k] == post[postR]){
            break;
        }
    }
    int numLeft = k - inL;
    root -> lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root -> rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

int main(){
    int n;
    queue<Node*> q;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    Node* root = create(0, n - 1, 0, n - 1);
    if(root != NULL){
        q.push(root);
    }
    while(!q.empty()){
        Node* currentNode = q.front();
        q.pop();
        printf("%d", currentNode -> data);
        if(currentNode -> lchild != NULL){
            q.push(currentNode -> lchild);
        }
        if(currentNode -> rchild != NULL){
            q.push(currentNode -> rchild);
        }
        if(!q.empty()){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
