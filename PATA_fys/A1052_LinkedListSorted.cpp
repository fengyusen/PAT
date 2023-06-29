#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int key, addr, next;
}nodes[100010];
bool cmp (node a, node b) {return a.key < b.key;}
int main() {
    int n, f, a;
    cin >> n >> f;
    for (int i = 0; i < n; i++) {
        cin >> a >> nodes[a].key >> nodes[a].next;
        nodes[a].addr = a;
    }
    vector<node> v;
    for (int i = f; i != -1; i = nodes[i].next)
        v.push_back(nodes[i]);
    sort(v.begin(), v.end(), cmp);
    if (v.size() == 0) {
        printf("0 -1");
        return 0;
    }
    printf("%d %05d\n", v.size(), v[0].addr);
    for (int i = 0; i < v.size() - 1; i++) {
        printf("%05d %d %05d\n", v[i].addr, v[i].key, v[i+1].addr);
    }
    printf("%05d %d -1", v[v.size()-1].addr, v[v.size()-1].key);
    return 0;
}