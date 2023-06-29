#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, maxdepth = 0;
bool visit[10010];
vector<vector<int> > v;
vector<int> temp;
set<int> s;
void dfs(int node, int depth) {
    if (depth > maxdepth) {
        temp.clear();
        temp.push_back(node);
        maxdepth = depth;
    } else if (depth == maxdepth) {
        temp.push_back(node);
    }
    visit[node] = true;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == false) {
            dfs(v[node][i], depth + 1);
        }
    }
}
int main() {
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false) {
            dfs(i, 1);
            if (i == 1) {
                if (temp.size() != 0) s1 = temp[0];
                for (int t : temp) s.insert(t);
            }
            cnt++;
        }
    }
    if (cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();
        maxdepth = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for (int t : temp) s.insert(t);
        for (auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}