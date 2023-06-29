#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n, m, k, num, a, b;
    scanf("%d", &n);
    vector<set<int> > sets(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &num);
            sets[i].insert(num);
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        int nc = 0, nt = sets[b].size();
        for (set<int>::iterator it = sets[a].begin(); it != sets[a].end(); it++) {
            if (sets[b].find(*it) != sets[b].end()) nc++;
            else nt++;
        }
        printf("%.1lf%%\n", nc * 100.0 / nt);
    }
    return 0;
}