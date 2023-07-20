#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Person{
    int hh1, mm1, ss1, hh2, mm2, ss2;
    char id[20];
};

bool cmp1(Person a, Person b){
    if(a.hh1 != b.hh1) return a.hh1 < b.hh1;
    if(a.mm1 != b.mm1) return a.mm1 < b.mm1;
    return a.ss1 < b.ss1;
}

bool cmp2(Person a, Person b){
    if(a.hh2 != b.hh2) return a.hh2 > b.hh2;
    if(a.mm2 != b.mm2) return a.mm2 > b.mm2;
    return a.ss2 > b.ss2;
}

int main(){
    vector<Person> persons;
    int m, hh, mm, ss;
    char id[20];
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%s %d:%d:%d", id, &hh, &mm, &ss);
        Person person;
        person.hh1 = hh;
        person.mm1 = mm;
        person.ss1 = ss;
        strcpy(person.id, id);
        scanf("%d:%d:%d", &hh, &mm, &ss);
        person.hh2 = hh;
        person.mm2 = mm;
        person.ss2 = ss;
        persons.push_back(person);
    }
    sort(persons.begin(), persons.end(), cmp1);
    printf("%s ", persons[0].id);
    sort(persons.begin(), persons.end(), cmp2);
    printf("%s\n", persons[0].id);
    return 0;
}
