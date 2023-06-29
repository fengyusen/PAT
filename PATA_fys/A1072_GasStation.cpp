#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int inf = 0x3fffffff;
struct node {
    int id, dist;
};
struct gasStation {
    int id, mindis, sumdis, flag;
};
bool cmp (gasStation a, gasStation b) {
    if (a.flag != b.flag) return a.flag == 1;
    else if (a.mindis != b.mindis) return a.mindis > b.mindis;
    else if (a.sumdis != b.sumdis) return a.sumdis < b.sumdis;
    else return a.id < b.id;
}
int n, m, k, ds;
vector<node> e[1011];
int dis[1011];
bool visit[1011];
struct gasStation dijstra(int s) {
    int mindis = inf, sumdis = 0;
    fill(dis, dis + 1011, inf);
    fill(visit, visit + 1011, false);
    dis[s + n] = 0;
    for (int i = 1; i <= n + m; i++) {
        int u = -1, minn = inf;
        for (int j = 1; j <= n + m; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1) break;
        visit[u] = true;
        for (int j = 0; j < e[u].size(); j++) {
            int v = e[u][j].id, d = e[u][j].dist;
            if (visit[v] == false && dis[v] > dis[u] + d) {
                dis[v] = dis[u] + d;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        sumdis += dis[i];
        mindis = min(mindis, dis[i]);
        if (dis[i] > ds) return gasStation{s, 0, 0, 0};
    }
    return gasStation{s, mindis, sumdis, 1};
}
int main() {
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    for (int i = 0; i < k; i++) {
        string s1, s2;
        int a, b, c;
        cin >> s1 >> s2 >> c;
        a = s1[0] == 'G' ? stoi(s1.substr(1)) + n : stoi(s1);
        b = s2[0] == 'G' ? stoi(s2.substr(1)) + n : stoi(s2);
        e[a].push_back(node{b, c});
        e[b].push_back(node{a, c});
    }
    vector<struct gasStation> ret(m);
    for (int i = 0; i < m; i++) {
        ret[i] = dijstra(i + 1);
    }
    sort(ret.begin(), ret.end(), cmp);
    if (ret[0].flag == 0) printf("No Solution");
    else printf("G%d\n%.1lf %.1lf\n", ret[0].id, ret[0].mindis * 1.0, 1.0 * ret[0].sumdis / n);
    return 0;
}