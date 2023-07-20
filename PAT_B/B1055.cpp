#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Person{
    char name[10];
    int height;
}persons[10010];

bool cmp(Person a, Person b){
    if(a.height != b.height) return a.height > b.height;
    return strcmp(a.name, b.name) < 0;
}

//bool cmp(Person a, Person b){
//    if(a.height != b.height) return a.height < b.height;
//    return strcmp(a.name, b.name) > 0;
//}
//
//bool cmpRow(Person a, Person b){
//    if(a.height != b.height) return a.height > b.height;
//    return strcmp(a.name, b.name) < 0;
//}

int main(){
    int n, k, begin = 0;
    vector<Person> rows[10];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%s %d", persons[i].name, &persons[i].height);
    }
    sort(persons, persons + n, cmp);
    
    int pre = n - k * (n / k);
    
    if(n % k != 0){
        begin = 1;
        for(int i = 0; i < pre + n / k; i++){
            if(i % 2 == 1){
                rows[0].insert(rows[0].begin(), persons[i]);
            } else {
                rows[0].push_back(persons[i]);
            }
        }
    }
    
    for(int i = begin; i < k; i++){
        for(int j = i * (n / k) + begin * pre; j < (i + 1) * (n / k) + begin * pre; j++){
            if((j - i * (n / k) - begin * pre) % 2 == 1){
                rows[i].insert(rows[i].begin(), persons[j]);
            } else {
                rows[i].push_back(persons[j]);
            }
        }
    }
    
//    sort(persons, persons + n, cmp);
//    for(int i = 0; i < k - 1; i++){
//
//        sort(persons + i * (n / k), persons + (i + 1) * (n / k), cmpRow);
//
//        for(int j = i * (n / k); j < (i + 1) * (n / k); j++){
//            if((j - i * (n / k)) % 2 == 1){
//                rows[k - i - 1].insert(rows[k - i - 1].begin(), persons[j]);
//            } else {
//                rows[k - i - 1].push_back(persons[j]);
//            }
//        }
//    }
//
//    for(int i = (k - 1) * (n / k); i < n; i++){
//        sort(persons + (k - 1) * (n / k), persons + n, cmpRow);
//        if((i - (k - 1) * (n / k)) % 2 == 1){
//            rows[0].insert(rows[0].begin(), persons[i]);
//        } else {
//            rows[0].push_back(persons[i]);
//        }
//    }
    
    
    for(int i = 0; i < k; i++){
        for(int j = 0; j < rows[i].size(); j++){
            printf("%s", rows[i][j].name);
            if(j < rows[i].size() - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
