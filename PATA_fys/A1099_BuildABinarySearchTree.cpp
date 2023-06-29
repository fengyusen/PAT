#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[100];
int n, t = 0, maxlevel = 0, val[100], lchild[100] = {-1}, rchild[100] = {-1}, nums[100];
void inOrder(int root, int level) {
    maxlevel = max(level, maxlevel);
    if (root >= n || root < 0) return;
    inOrder(lchild[root], level + 1);
    val[root] = nums[t++];
    inOrder(rchild[root], level + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &lchild[i], &rchild[i]);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    sort(nums, nums + n);
    inOrder(0, 0);
    v[0].push_back(0);
    for (int i = 0; i <= maxlevel; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (i) printf(" ");
            printf("%d", val[v[i][j]]);
            if (lchild[v[i][j]] != -1) v[i+1].push_back(lchild[v[i][j]]);
            if (rchild[v[i][j]] != -1) v[i+1].push_back(rchild[v[i][j]]);
        }
    }
    return 0;
}