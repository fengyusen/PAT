#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, a = 0;
    cin >> n;
    if (n >= 100)
    {
        a = n / 100;
        n = n % 100;
        while (a-- > 0)
        {
            cout << 'B';
        }
    }
    if (n >= 10)
    {
        a = n / 10;
        n = n % 10;
        while (a-- > 0)
        {
            cout << 'S';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i;
    }
}