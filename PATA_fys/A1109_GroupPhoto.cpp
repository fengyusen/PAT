#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct node {
    string name;
    int height;
} p[10010];
bool cmp (node a, node b) {
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main() {
    int n, k, m;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i].name >> p[i].height;
    }
    sort(p, p + n, cmp);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (i == 0) {
            m = n / k + n % k;
        } else {
            m = n / k;
            cout << endl;
        }
        vector<string> q(m + 1);
        int pos = m / 2;
        for (int j = 0; j < m; j++) {
            pos += j % 2 ? -j : j;
            q[pos] = p[ans++].name;
        }
        for (int j = 0; j < m; j++) {
            if (j) cout << " ";
            cout << q[j];
        }
    }
    return 0;
}