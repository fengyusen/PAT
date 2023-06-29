#include <iostream>
using namespace std;
int fa[10001], cnt[10001], exist[10001];
int find (int x) {
    return x == fa[x] ? x : find(fa[x]);
}
void Union (int a, int b) {
    int faA = find(a), faB = find(b);
    if (faA < faB) {
        fa[faB] = faA;
        cnt[faA] += cnt[faB];
    } else if (faA > faB) {
        fa[faA] = faB;
        cnt[faB] += cnt[faA];
    }

}
void init (int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        cnt[i] = 1;
        exist[i] = 0;
    }
}

int main () {
    init (10001);
    int N, B, K, Q;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        int root = 0;
        for (int j = 0; j < K; j++) {
            cin >> B;
            exist[B] = 1;
            if (j == 0) {
                root = B;
                continue;
            }
            Union (root, B);
        }
    }
    int tree = 0, bird = 0;
    for (int i = 1; i <= 10000; i++) {
        if (exist[i] == 1) {
            bird++;
            if (fa[i] == i) {
                tree++;
            }
        }
    }
    cout << tree << " " << bird << endl;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}