#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100], path;
vector<vector<int> > ans;
int weight[100], s;
void dfs(int root, int w) {
    w += weight[root];
    if (v[root].size() == 0) {
        if (w == s) {
            path.push_back(weight[root]);
            ans.push_back(path);
            path.pop_back();
        }
        return;
    } else if (w < s) {
        path.push_back(weight[root]);
        for (int i = 0; i < v[root].size(); i++) {
            dfs(v[root][i], w);
        }
        path.pop_back();
    }
    return;
}
int main() {
    int n, m, node, k, c;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++) scanf("%d", &weight[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &node, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(0, 0);
    sort(ans.begin(), ans.end(), greater<vector<int> >());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i][0]);
        for (int j = 1; j < ans[i].size(); j++) {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}