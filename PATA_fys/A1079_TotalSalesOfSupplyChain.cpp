#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double p, r, sum = 0.0;
struct node {
    int amount;
    vector<int> child;
};
vector<node> nodes;
void dfs(int root, int depth) {
    int num = nodes[root].child.size();
    if (num == 0) {
        sum += p * pow(1 + r, depth) * nodes[root].amount;
    } else {
        for (int i = 0; i < num; i++) {
            dfs(nodes[root].child[i], depth+1);
        }
    }
}
int main() {
    int n, k, c;
    cin >> n >> p >> r;
    r /= 100;
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k == 0) cin >> nodes[i].amount;
        for (int j = 0; j < k; j++) {
            cin >> c;
            nodes[i].child.push_back(c);
        }
    }
    dfs(0, 0);
    printf("%.1lf", sum);
    return 0;
}