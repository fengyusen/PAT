#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int fa[1010], nums[1010];
vector<int> v(1010, 0);
bool flag[1010] = {false};
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void join(int x, int y) {
    int fx = find(x), fy = find(y);
    int fmax = max(fx, fy), fmin = min(fx, fy);
    fa[fmax] = fmin;
}
int main() {
    for (int i = 0; i < 1010; i++) fa[i] = i;
    int n, k, c, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d: %d", &k, &nums[i]);
        for (int j = 1; j < k; j++) {
            scanf("%d", &c);
            join(nums[i], c);
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[find(nums[i])] == 0) cnt++;
        v[find(nums[i])]++;
    }
    sort(v.begin(), v.end(), greater<int>());
    printf("%d\n%d", cnt, v[0]);
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == 0) break;
        printf(" %d", v[i]);
    }
    return 0;
}