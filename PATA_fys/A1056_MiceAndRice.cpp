#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    int weight, index, rank, index0;
};
bool cmp(node a, node b) {return a.index0 < b.index0;};

int main () {
    int np, ng, num;
    cin >> np >> ng;
    vector<int> v(np);
    vector<node> w(np);
    for (int i = 0; i < np; i++)
        cin >> v[i];
    queue<node> q;
    for (int i = 0; i < np; i++) {
        cin >> num;
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
        q.push(w[i]);
    }
    while (!q.empty()) {
        int size = q.size();
        if (size == 1) {
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }
        int group = size % ng == 0 ? size / ng : size / ng + 1;
        node maxnode;
        int maxn = -1, cnt = 0;
        for (int i = 0; i < size; i++) {
            node temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt++;
            if (temp.weight > maxn) {
                maxn = temp.weight;
                maxnode = temp;
            }
            if (cnt == ng || i == size - 1) {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp);
    for (int i = 0; i < np; i++) {
        if (i) cout << " ";
        cout << w[i].rank;
    }
    return 0;
}