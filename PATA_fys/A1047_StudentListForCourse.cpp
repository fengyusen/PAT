#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
char name[40010][6];
vector<int> student[2510];
bool cmp (int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main() {
    int n, k, cnt, temp;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", name[i], &cnt);
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &temp);
            student[temp].push_back(i);
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, student[i].size());
        sort(student[i].begin(), student[i].end(), cmp);
        for (int j = 0; j < student[i].size(); j++) {
            printf("%s\n", name[student[i][j]]);\
        }
    }
    return 0;
}
