#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    if (n == 0)
    {
        cout << "0 0";
        return 0;
    }
    cout << m * n << " " << n - 1;
    while (cin >> m >> n)
    {
        if (n != 0)
        {
            cout << " " << m * n << " " << n - 1;
        }
    }
    return 0;
}
