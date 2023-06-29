#include <bits/stdc++.h>
using namespace std;

int main()
{
    double p[1010] = {0.0}, q[1010] = {0.0}, r[2020] = {0.0}, a;
    int k, n, kr = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n >> a;
        p[n] = a;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n >> a;
        for (int j = 0; j <= 1000; j++)
        {
            r[n + j] += p[j] * a;
        }
    }
    for (int i = 0; i < 2010; i++)
    {
        if (r[i] != 0)
            kr++;
    }
    cout << kr;
    for (int i = 2010; i >= 0; i--)
    {
        if (r[i] != 0)
            printf(" %d %.1f", i, r[i]);
    }
    return 0;
}
