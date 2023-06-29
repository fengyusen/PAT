#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, i = 1;
    char c;
    cin >> N >> c;
    int n = sqrt((N + 1) / 2);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= n - 1 - abs(i - n); j++)
            cout << " ";
        for (int j = 1; j <= 2 * abs(i - n) + 1; j++)
            cout << c;
        cout << endl;
    }
    cout << N - (2 * n * n - 1);
    return 0;
}