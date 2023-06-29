#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    int n, k, ki, ni;
    string name;
    scanf("%d %d", &n, &k);
    unordered_map<string, vector<int>> course;
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &ki, &ni);
        for (int j = 0; j < ni; j++) {
            cin >> name;
            course[name].push_back(ki);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << endl;
        cin >> name;
        cout << name;
        printf(" %d", course[name].size());
        sort(course[name].begin(), course[name].end());
        for (int j = 0; j < course[name].size(); j++) {
            printf(" %d", course[name][j]);
        }
    }
    return 0;
}
