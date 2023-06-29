#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;
map<string, int> weight, res;
map<string, map<string, int> > mp;
set<string> visit;
int n, k, c;
void dfs(string node, string &header, int &numNumber, int &sumweight) {
    numNumber++;
    sumweight += weight[node];
    if (weight[node] > weight[header]) header = node;
    visit.insert(node);
    for (auto it = mp[node].begin(); it != mp[node].end(); it++) {
        if (visit.find(it->first) == visit.end()) {
            dfs(it->first, header, numNumber, sumweight);
        }
    }
}
int main() {
    cin >> n >> k;
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        mp[a][b] = c, mp[b][a] = c;
        weight[a] += c, weight[b] += c;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (visit.find(it->first) == visit.end()) {
            string header = it->first;
            int sumweight = 0, numNumber = 0;
            dfs(it->first, header, numNumber, sumweight);
            if (numNumber > 2 && sumweight > k * 2) res[header] = numNumber;
        }
    }
    printf("%d\n", res.size());
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}