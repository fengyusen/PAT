#include <bits/stdc++.h>
using namespace std;

int isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int m, n, t = 0, k = 2, j = 0, i = 0;
    cin >> m >> n;
    int a[10000];
    while (t < n)
    {
        if (isPrime(k))
        {
            t++;
            if (t >= m)
            {
                a[j] = k;
                j++;
            }
        }
        k++;
    }
    for (i = 0; i < (n - m + 1 - 10); i = i + 10)
    {
        for (j = i; j < i + 9; j++)
        {
            cout << a[j] << " ";
        }
        cout << a[i + 9] << endl;
    }
    for (j = i; j < n - m; j++)
    {
        cout << a[j] << " ";
    }
    cout << a[n - m];
    return 0;
}
