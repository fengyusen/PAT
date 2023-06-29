#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 999999999;
int dis[510], Time[510], e[510][510], w[510][510], dispre[510], Timepre[510], weight[510], NodeNum[510];
bool visit[510];
int st, fin;
vector<int> dispath, Timepath;
void dfsDis(int v) {
    dispath.push_back(v);
    if (v == st) return ;
    dfsDis(dispre[v]);
}
void dfsTime(int v) {
    Timepath.push_back(v);
    if (v == st) return ;
    dfsTime(Timepre[v]);
}
int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, flag, len, t;
        cin >> a >> b >> flag >> len >> t;
        e[a][b] = len;
        w[a][b] = t;
        if (flag == 0) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    cin >> st >> fin;
    dis[st] = 0;
    weight[st] = 0;
    for (int i = 0; i < n; i++) {
        dispre[i] = i;
    }
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
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                } else if (dis[v] == dis[u] + e[u][v] && weight[v] > weight[u] + w[u][v]) {
                    weight[v] = weight[u] + w[u][v];
                    dispre[v] = u;
                }
            }
        }
    }
    dfsDis(fin);
    Time[st] = 0;
    fill(visit, visit + 510, false);
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (visit[j] == false && Time[j] < minn) {
                minn = Time[j];
                u = j;
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (visit[v] == false && w[u][v] != inf) {
                if (Time[v] > Time[u] + w[u][v]) {
                    Time[v] = Time[u] + w[u][v];
                    NodeNum[v] = NodeNum[u] + 1;
                    Timepre[v] = u;
                } else if (Time[v] == Time[u] + w[u][v] && NodeNum[v] > NodeNum[u] + 1) {
                    NodeNum[v] = NodeNum[u] + 1;
                    Timepre[v] = u;
                }
            }
        }
    }
    dfsTime(fin);
    
    printf("Distance = %d", dis[fin]);
    if (dispath == Timepath) {
        printf("; Time = %d: %d", Time[fin], st);
    } else {
        printf(": %d", st);
        for (int i = dispath.size() - 2; i >= 0; i--) printf(" -> %d", dispath[i]);
        printf("\nTime = %d: %d", Time[fin], st);
    }
    for (int i = Timepath.size() - 2; i >= 0; i--) printf(" -> %d", Timepath[i]);
    
    return 0;
}