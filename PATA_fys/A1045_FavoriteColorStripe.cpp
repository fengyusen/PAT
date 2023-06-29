#include <iostream>
using namespace std;
int eva[201], stripe[10001], dp[10001][201] = {0};
int main() {
    int n, m, l;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> eva[i];
    cin >> l;
    for (int j = 1; j <= l; j++) cin >> stripe[j];
    for (int j = 1; j <= l; j++)
        for (int i = 1; i <= m; i++)
            dp[j][i] = max(dp[j-1][i], dp[j][i-1]) + (stripe[j] == eva[i] ? 1 : 0);
    printf("%d", dp[l][m]);
    return 0;
}
// #include <iostream>
// using namespace std;
// int book[201], a[10001], dp[10001] = {0};
// int main() {
//     int n, m, l, x, num = 0, maxn = 0;
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++) {
//         cin >> x;
//         book[x] = i;
//     }
//     cin >> l;
//     for (int j = 1; j <= l; j++) {
//         cin >> x;
//         if (book[x] >= 1)
//             a[num++] = book[x];
//     }
//     for (int i = 0; i < num; i++) {
//         dp[i] = 1;
//         for (int j = 0; j < i; j++)
//             if (a[i] >= a[j]) 
//                 dp[i] = max(dp[i], dp[j] + 1);
//         maxn = max(dp[i], maxn);
//     }
//     printf("%d", maxn);
//     return 0;
// }