#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id, grade;
    string name;
};
int c;
bool cmp(node a, node b) {
    switch(c) {
        case 1 :
            return a.id < b.id;
        case 2 :
            return a.name != b.name ? a.name < b.name : a.id < b.id;
        case 3 :
            return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
        default :
            return a.id < b.id;
    }
}
int main() {
    int n;
    scanf("%d %d", &n, &c);
    vector<node> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].id >> data[i].name >> data[i].grade;
    }
    sort(data.begin(), data.end(), cmp);
    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", data[i].id, data[i].name.c_str(), data[i].grade);
    }
    return 0;
}