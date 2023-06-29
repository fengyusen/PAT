#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, maxd = 0, cnt = 0, k, root;
vector<vector<int> > nodes(100010);
void dfs(int root, int depth) {
    if (nodes[root].size() == 0) {
        if (depth > maxd) {
            maxd = depth;
            cnt = 1;
        } else if (depth == maxd) cnt++;
        return;
    }
    for (int i = 0; i < nodes[root].size(); i++) {
        dfs(nodes[root][i], depth+1);
    }
}
int main() {
    double p, r;
    cin >> n >> p >> r;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k >= 0) nodes[k].push_back(i);
        else root = i;
    }
    dfs(root, 0);
    printf("%.2lf %d", p * pow(1 + r/100, maxd), cnt);
    return 0;
}