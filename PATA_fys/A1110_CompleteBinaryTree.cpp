#include <iostream>
#include <queue>
#include <string>
using namespace std;
int r[20], l[20], p[20], t[20], flag = 0, n;
void dfs(int root, int layer) {
    if (root == -1) return ;
    if (layer >= n) {
        flag = 1;
        return;
    }
    t[layer] = root;
    dfs(l[root], 2 * layer + 1);
    dfs(r[root], 2 * layer + 2);
}
int main() {
    cin >> n;
    string c1, c2;
    for (int i = 0; i < n; i++) r[i] = l[i] = p[i] = -1;
    for (int i = 0; i < n; i++) {
        cin >> c1 >> c2;
        if (c1 != "-") l[i] = stoi(c1), p[l[i]] = i;
        if (c2 != "-") r[i] = stoi(c2), p[r[i]] = i;
    }
    int root = 0;
    while (p[root] != -1) root = p[root];
    dfs(root, 0);
    if (flag) printf("NO %d", root);
    else printf("YES %d", t[n - 1]);
    return 0;
}