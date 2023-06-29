#include <iostream>
#include <vector>
using namespace std;
const int inf = 0x3fffffff;
int weight[510], e[510][510], dis[510];
int minneed = inf, minback = inf;
vector<int> pre[510], path, temppath;
bool visit[510] = {false};
void dfs (int v) {
    temppath.push_back(v);
    if (v == 0) {
        int need = 0, back = 0;
        for (int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if (weight[id] > 0) {
                back += weight[id];
            } else {
                if (back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if (need < minneed) {
            minneed = need;
            minback = back;
            path = temppath;
        } else if (need == minneed && back < minback) {
            minback = back;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    int cmax, n, sp, m, a, b, c;
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;
    }
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    dis[0] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j <= n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                minn = dis[j];
                u = j;
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v <= n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[v] > e[u][v] + dis[u]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[v] == e[u][v] + dis[u]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    printf("%d 0", minneed);
    for (int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minback);
    return 0;
}