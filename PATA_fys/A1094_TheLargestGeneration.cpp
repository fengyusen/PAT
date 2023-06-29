#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int maxp = 0, maxl = 1;
vector<vector<int> > nodes(101);
void bfs (int root) {
    queue<int> q;
    q.push(root);
    int level = 1;
    while (!q.empty()) {
        int size = q.size();
        if (size > maxp) {maxp = size, maxl = level;}
        for (int i = 0; i < size; i++) {
            int top = q.front();
            q.pop();
            for (int j = 0; j < nodes[top].size(); j++) {
                q.push(nodes[top][j]);
            }
        }
        level++;
    }
    
}
int main() {
    int n, m, k, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c >> k;
        nodes[c].resize(k);
        for (int j = 0; j < k; j++){
            cin >> nodes[c][j];
        }
    }
    bfs(1);
    printf("%d %d", maxp, maxl);
    return 0;
}