#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int n, f, a, data[100010], next[100010];
    cin >> f >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> data[a] >> next[a];
    }
    set<int> st;
    vector<int> v1, v2;
    for (int i = f; i != -1; i = next[i]) {
        if (st.find(abs(data[i])) == st.end()) {
            v1.push_back(i);
            st.insert(abs(data[i]));
        } else v2.push_back(i);
    }
    if (v1.size() > 0) {
        for (int i = 0; i < v1.size() - 1; i++) {
            printf("%05d %d %05d\n", v1[i], data[v1[i]], v1[i+1]);
        }
        printf("%05d %d -1\n", v1[v1.size()-1], data[v1[v1.size()-1]]);
    }
    if (v2.size() > 0) {
        for (int i = 0; i < v2.size() - 1; i++) {
            printf("%05d %d %05d\n", v2[i], data[v2[i]], v2[i+1]);
        }
        printf("%05d %d -1", v2[v2.size()-1], data[v2[v2.size()-1]]);
    }
    return 0;
}