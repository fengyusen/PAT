#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> a(N);
    for (int i = 0; i < N; i++) a[i] = i;//scanf("%d", &a[i]);
    sort(a.begin(), a.end(), greater<int>());
    int n = sqrt(N), t = 0;
    while (N % n != 0 && n >= 1) n--;
    int m = N / n, level = m / 2 + m % 2;
    vector<vector<int> > b(m, vector<int>(n));
    for (int k = 0; k < level; k++) {
        int i = k, j = k;
        for (int j = i; j <= n - 1 - i && t <= N - 1; j++)
                b[i][j] = a[t++];
        for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
                b[j][n - 1 - i] = a[t++];
        for (int j = n - i - 1; j >= i && t <= N - 1; j--)
                b[m - 1 - i][j] = a[t++];
        for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)
                b[j][i] = a[t++];
        //for (; j < n-k-1 && t <= N - 1; j++) b[i][j] = a[t++];//, printf("%d %d %d %d\n", ans, i, j, v[i][j]);
        //for (; i < m-k-1 && t <= N - 1; i++) b[i][j] = a[t++];//, printf("%d %d %d %d\n", ans, i, j, v[i][j]);
        //for (; j > k     && t <= N - 1; j--) b[i][j] = a[t++];//, printf("%d %d %d %d\n", ans, i, j, v[i][j]);
        //for (; i > k     && t <= N - 1; i--) b[i][j] = a[t++];//, printf("%d %d %d %d\n", ans, i, j, v[i][j]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++)
            printf("%d ", b[i][j]);
        printf("%d\n", b[i][n - 1]);
    }
    printf("********\n");
    for (int k = 0; k < level; k++) {
        int i = k, j = k;
        // for (int j = i; j <= n - 1 - i && t <= N - 1; j++)
        //         b[i][j] = a[t++];
        // for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
        //         b[j][n - 1 - i] = a[t++];
        // for (int j = n - i - 1; j >= i && t <= N - 1; j--)
        //         b[m - 1 - i][j] = a[t++];
        // for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)
        //         b[j][i] = a[t++];
        for (; j < n-k-1 && t <= N - 1; j++) b[i][j] = a[t++];//, printf("%d %d %d %d\n", ans, i, j, v[i][j]);
        for (; i < m-k-1 && t <= N - 1; i++) b[i][j] = a[t++];//, printf("%d %d %d %d\n", ans, i, j, v[i][j]);
        for (; j > k     && t <= N - 1; j--) b[i][j] = a[t++];//, printf("%d %d %d %d\n", ans, i, j, v[i][j]);
        for (; i > k     && t <= N - 1; i--) b[i][j] = a[t++];//, printf("%d %d %d %d\n", ans, i, j, v[i][j]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            printf("%d", b[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
    
}