#include <iostream>
using namespace std;
const int inf = 0x3ffffff;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510] = {false};
int main() {
    int n, m, c1, c2, a, b, c;
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++) cin >> weight[i];
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (visit[j] == false && dis[j]  < minn) {
                minn = dis[j];
                u = j;
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if (dis[u] + e[u][v] == dis[v]) {
                    num[v] +=  num[u];
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}