#include <iostream>
#include <algorithm>
using namespace std;
long long int a[100005];
int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        long long int mp = a[i] * p;
        for (int j = i + cnt; j < n; j++) {
            if (a[j] > mp) break;
            cnt = max(cnt, j - i + 1);
        }
    }
    printf("%d", cnt);
    return 0;
}