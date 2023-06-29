#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > follows(1010);
int bfs(int use, int layer) {
    int cnt = 0;
    bool visit[1010] = {false};
    queue<int> q;
    q.push(use);
    visit[use] = true;
    for (int i = 0; i < layer; i++) {
        int n = q.size();
        for (int j = 0; j < n; j++) {
            int top = q.front();
            q.pop();
            for (int k = 0; k < follows[top].size(); k++) {
                if (visit[follows[top][k]] == false) {
                    q.push(follows[top][k]);
                    visit[follows[top][k]] = true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
int main() {
    int n, l, k, f;
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> f;
            follows[f].push_back(i);
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> f;
        cout << bfs(f, l) << endl;
    }
    return 0;
}