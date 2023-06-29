#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;
const int inf = 0x3fffffff;
map<string, int> weight, dis;
map<string, map<string, int> > mp;
map<string, set<string> > pre;
set<string> visit;
vector<string> path, temppath;
int maxW = 0, numPath = 0;
string s;
void dfs(string node) {
    temppath.push_back(node);
    if (node == s) {
        numPath++;
        int sumW = 0;
        for (int i = 0; i < temppath.size() - 1; i++) {
            sumW += weight[temppath[i]];
        }
        if (sumW > maxW) {
            maxW = sumW;
            path = temppath;
        } else if (sumW == maxW && temppath.size() < path.size()) {
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (auto it = pre[node].begin(); it != pre[node].end(); it++) {
        dfs(*it);
    }
    temppath.pop_back();
}
int main() {
    int n, k, c;
    string city1, city2;
    cin >> n >> k >> s;
    for (int i = 0; i < n - 1; i++) {
        cin >> city1 >> c;
        weight[city1] = c;
        dis[city1] = inf;
    }
    for (int i = 0; i < k; i++) {
        cin >> city1 >> city2 >> c;
        mp[city1][city2] = mp[city2][city1] = c;
    }
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        string u = "";
        int minn = inf;
        for (auto it = dis.begin(); it != dis.end(); it++) {
            if (visit.find(it->first) == visit.end() && it->second < minn) {
                u = it->first;
                minn = it->second;
            }
        }
        if (u == "") break;
        visit.insert(u);
        for (auto it1 = mp[u].begin(); it1 != mp[u].end(); it1++) {
            string v = it1->first;
            if (visit.find(v) == visit.end()) {
                if (dis[v] > dis[u] + mp[u][v]) {
                    dis[v] = dis[u] + mp[u][v];
                    pre[v].clear();
                    pre[v].insert(u);
                } else if (dis[v] == dis[u] + mp[u][v]) {
                    pre[v].insert(u);
                }
            }
        }
    }
    dfs("ROM");
    printf("%d %d %d %d\n", numPath, dis["ROM"], maxW, maxW / (path.size() - 1));
    cout << s;
    for (int i = path.size() - 2; i >= 0; i--) {
        cout << "->" << path[i];
    }
    return 0;
}