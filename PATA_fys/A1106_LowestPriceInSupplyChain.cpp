#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, maxd = 100010, cnt = 0, k, root, c;
vector<vector<int> > nodes(100010);
void dfs(int root, int depth) {
    if (nodes[root].size() == 0) {
        if (depth < maxd) {
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
        for (int j = 0; j < k; j++) {
            cin >> c;
            nodes[i].push_back(c);
        }
    }
    dfs(0, 0);
    printf("%.4lf %d", p * pow(1 + r/100, maxd), cnt);
    return 0;
}