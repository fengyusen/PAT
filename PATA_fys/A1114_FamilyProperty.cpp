#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int fa[10010], estate[10010], area[10010];
bool visit[10010];
int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
void join(int x, int y) {
    visit[x] = visit[y] = true;
    if (x == y) return ;
    int fx = find(x), fy = find(y);
    int fmin = min(fx, fy), fmax = max(fx, fy);
    fa[fmax] = fmin;
}
struct node {
    int id, number;
    double estate, area;
    bool flag;
} q[10010];
bool cmp (node a, node b) {
    if (a.flag == b.flag)
        return a.area != b.area ? a.area > b.area : a.id < b.id;
    else return a.flag;
}
int main() {
    for (int i = 0; i < 10010; i++) fa[i] = i;
    int n, id, fid, mid, k, ch;
    scanf("%d", &n);
    set<int> ids;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &id, &fid, &mid, &k);
        visit[id] = true;
        if (fid != -1 && mid != -1) join(fid, mid), join(fid, id);
        else if (fid != -1) join(fid, id);
        else if (mid != -1) join(mid, id);
        for (int j = 0; j < k; j++) {
            //visit[ch] = true;
            scanf("%d", &ch);
            join(id, ch);
        }
        scanf("%d %d", &estate[id], &area[id]);
        ids.insert(id);
    }
    for (auto it = ids.begin(); it != ids.end(); it++) {
        fid = find(*it);
        q[fid].id = fid;
        q[fid].estate += estate[*it];
        q[fid].area += area[*it];
        q[fid].flag = true;
    }
    int cnt = 0;
    for (int i = 0; i < 10010; i++) {
        if (visit[i]) q[find(i)].number++;
        if (q[i].flag) cnt++;
    }
    for (int i = 0; i < 10010; i++) {
        if (q[i].flag) {
            q[i].estate = q[i].estate / q[i].number;
            q[i].area = q[i].area / q[i].number;
        }
    }
    sort(q, q + 10010, cmp);
    printf("%d", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("\n%04d %d %.3lf %.3lf", q[i].id, q[i].number, q[i].estate, q[i].area);
    }
    return 0;
}