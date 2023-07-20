#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
    double score;
};

struct Node{
    int num, totalSum, rightSum;
    double score;
    map<char, bool> answerMp;
    map<char, int> wrongMp;
};

struct WrongNode{
    int num, sum;
    char cho;
};

bool cmp(WrongNode a, WrongNode b){
    if(a.sum != b.sum) return a.sum > b.sum;
    if(a.num != b.num) return a.num < b.num;
    return a.cho < b.cho;
}

int main(){
    int n, m;
    vector<Node> nodes;
    vector<WrongNode> wrongNodes;
    vector<Student> students;
    scanf("%d %d", &n, &m);
    scanf("\n");
    for(int i = 1; i <= m; i++){
        Node node;
        node.num = i;
        scanf("%lf %d %d", &node.score, &node.totalSum, &node.rightSum);
        for(int j = 0; j < node.rightSum; j++){
            char ans;
            scanf(" %c", &ans);
            node.answerMp[ans] = true;
        }
        scanf("\n");
        nodes.push_back(node);
    }
    
//    printf("\n%d\n", nodes.size());
//    for(int i = 0; i < nodes.size(); i++){
//        for(map<char, bool>::iterator it = nodes[i].answerMp.begin(); it != nodes[i].answerMp.end(); it++){
//            if(it -> second){
//                printf("%c ", it -> first);
//            }
//        }
//        printf("\n");
//    }
    
    for(int i = 0; i < n; i++){
        Student s;
        s.score = 0;
        for(int j = 0; j < m; j++){
            map<char, bool> tempChooseMap;
            int ansSum;
            scanf("(%d", &ansSum);
            int right = 0;
            bool wrong = false;
            for(int k = 0; k < ansSum; k++){
                char c;
                scanf(" %c", &c);
                if(nodes[j].answerMp[c]){
                    right++;
                    tempChooseMap[c] = true;
                } else {
                    nodes[j].wrongMp[c]++;
                    wrong = true;
                }
            }
            for(map<char, bool>::iterator k = nodes[j].answerMp.begin(); k != nodes[j].answerMp.end(); k++){
                if(k -> second && !tempChooseMap[k -> first]){
                    nodes[j].wrongMp[k -> first]++;
                }
            }
            if(!wrong && right != 0){
                if(right == nodes[j].rightSum){
                    s.score += nodes[j].score;
                } else {
                    s.score += nodes[j].score / 2;
                }
            }
            scanf(")");
//            printf("Here\n");
            if(j < m - 1){
                scanf(" ");
            }
//            printf("Here\n");
        }
//        printf("Here\n");
        students.push_back(s);
        if(i < n - 1){
            scanf("\n");
        }
//        printf("Here\n");
//        printf("%.1f\n", s.score);
    }
    for(int i = 0; i < m; i++){
        Node node = nodes[i];
        for(map<char, int>::iterator it = nodes[i].wrongMp.begin(); it != nodes[i].wrongMp.end(); it++){
            if(it -> second > 0){
                WrongNode tempWrongNode;
                tempWrongNode.num = i + 1;
                tempWrongNode.sum = it -> second;
                tempWrongNode.cho = it -> first;
                wrongNodes.push_back(tempWrongNode);
            }
        }
    }
    sort(wrongNodes.begin(), wrongNodes.end(),cmp);
    for(int i = 0; i < n; i++){
        printf("%.1f\n", students[i].score);
    }
    if(wrongNodes.size() != 0){
        for(int i = 0; i < wrongNodes.size(); i++){
            if(wrongNodes[i].sum == wrongNodes[0].sum){
                printf("%d %d-%c\n", wrongNodes[i].sum, wrongNodes[i].num, wrongNodes[i].cho);
            } else {
                break;
            }
        }
    } else {
        printf("Too simple\n");
    }
}
