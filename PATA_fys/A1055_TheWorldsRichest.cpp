#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100001;
struct node {
    int age, worth;
    char name[9];
};
bool cmp(node a, node b) {
    return a.worth != b.worth ? a.worth > b.worth :
          (a.age != b.age ? a.age < b.age : strcmp(a.name, b.name) <= 0);
}
int main() {
    int n, k, m, amin, amax;
    scanf("%d %d", &n, &k);
    vector<node> data(n), v;
    vector<int> book(205, 0);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", data[i].name, &(data[i].age), &(data[i].worth));
    }
    sort(data.begin(), data.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (book[data[i].age] < 100) {
            v.push_back(data[i]);
            book[data[i].age]++;
        }
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d %d %d", &m, &amin, &amax);
        vector<node> t;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].age >= amin && v[j].age <= amax)
                t.push_back(v[j]);
        }
        if (i != 1) printf("\n");
            printf("Case #%d:", i);
        int flag = 0;
        for (int j = 0; j < m && j < t.size(); j++) {
            //if (j) printf("\n");
            printf("\n%s %d %d", t[j].name, t[j].age, t[j].worth);
            flag = 1;
        }
        if (flag == 0) printf("\nNone");
    }
    return 0;
}