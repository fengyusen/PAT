#include <iostream>
#include <vector>
using namespace std;
const int inf = 0x3fffffff;
int e[510][510], cost[510][510], dis[510];
bool visit[510];
vector<int> pre[510], path, temppath;
int n, m, s, d, mincost = inf;
void dfs(int v) {
    temppath.push_back(v);
    if (v == s) {
        int tempcost = 0;
        for (int i = temppath.size() - 1; i > 0; i--) {
            tempcost += cost[temppath[i]][temppath[i - 1]];
        }
        if (tempcost < mincost) {
            mincost = tempcost;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(cost[0], cost[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    int  a, b, e0, c0;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a, &b, &e0, &c0);
        e[a][b] = e[b][a] = e0;
        cost[a][b] = cost[b][a] = c0;
    }
    pre[s].push_back(s);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[v] == dis[u] + e[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(d);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d", dis[d], mincost);
    return 0;
}