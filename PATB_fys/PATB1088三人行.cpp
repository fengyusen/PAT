#include <bits/stdc++.h>
using namespace std;
int m, x, y;
void str(double a)
{
    if (a == m)
        printf(" Ping");
    else if (a > m)
        printf(" Cong");
    else
        printf(" Gai");
}

int main()
{
    scanf("%d %d %d", &m, &x, &y);
    for (int i = 99; i >= 10; i--)
    {
        int j = i % 10 * 10 + i / 10;
        double k = abs(j - i) * 1.0 / x;
        if (j == k * y)
        {
            cout << i;
            str(i);
            str(j);
            str(k);
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}