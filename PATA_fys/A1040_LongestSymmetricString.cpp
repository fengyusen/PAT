#include <iostream>
using namespace std;
int dp[1010][1010] = {0};
int main() {
    string s;
    getline(cin, s);
    int n = s.length(), ans = 1;
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (i + 1 < n && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ans = l;
            }
        }
    }
    printf("%d", ans);
    return 0;
}