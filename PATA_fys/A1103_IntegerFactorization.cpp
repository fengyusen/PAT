#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
struct node {int x, y, z;};
int m, n, l, t;
int arr[1290][130][62], direct[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
bool visit[1290][130][62] = {false};
bool judge(node a) {
    if (a.x >= m || a.x < 0 || a.y >= n || a.y < 0 || a.z >= l || a.z < 0) 
        return false;
    if (arr[a.x][a.y][a.z] == 0 || visit[a.x][a.y][a.z] == true) 
        return false;
    return true;
}
int bfs(node a) {
    int volume = 0;
    queue<node> q;
    q.push(a);
    visit[a.x][a.y][a.z] = true;
    while (!q.empty()) {
        node top = q.front();
        q.pop();
        volume++;
        for (int i = 0; i < 6; i++) {
            node b;
            b.x = top.x + direct[i][0];
            b.y = top.y + direct[i][1];
            b.z = top.z + direct[i][2];
            if (judge(b) == true) {
                q.push(b);
                visit[b.x][b.y][b.z] = true;
            }
        }
    }
    if (volume >= t) return volume;
    else return 0;
}
int main() {
    cin >> m >> n >> l >> t;
    for (int k = 0; k < l; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j][k];
            }
        }
    }
    int ans = 0;
    for (int k = 0; k < l; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                node a;
                a.x = i, a.y = j, a.z = k;
                if (judge(a) == true)
                    ans += bfs(a);
            }
        }
    }
    printf("%d", ans);
    return 0;
}