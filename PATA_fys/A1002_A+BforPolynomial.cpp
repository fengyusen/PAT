#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k = 0, e, K = 0;
    double c, coef[1001] = {0};
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> e >> c;
        coef[e] += c;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> e >> c;
        coef[e] += c;
    }
    for (int i = 0; i < 1001; i++)
    {
        if (coef[i] != 0)
            K++;
    }
    cout << K;
    for (int i = 1000; i >= 0; i--)
    {
        if (coef[i] != 0.0)
            printf(" %d %.1f", i, coef[i]);
    }
    return 0;
}
