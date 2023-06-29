#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b[5] = {0}, flag1 = 1;
    float a[5] = {0.0};
    int n, num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> n;
        switch (n % 5)
        {
        case 0:
            if (n % 2 == 0)
            {
                b[0]++;
                a[0] += n;
            }
            break;
        case 1:
            b[1]++;
            a[1] += (flag1 * n);
            flag1 = -flag1;
            break;
        case 2:
            b[2]++;
            a[2]++;
            break;
        case 3:
            b[3]++;
            a[3] = a[3] + n;
            break;
        case 4:
            b[4]++;
            a[4] = a[4] > n ? a[4] : n;
            break;
        }
    }
    a[3] = a[3] / b[3];
    flag1 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (flag1 == 1)
        {
            cout << " ";
        }
        flag1 = 1;
        if (b[i] <= 0)
        {
            cout << "N";
            continue;
        }
        if (i == 3)
            printf("%0.1f", a[i]);
        else
            printf("%.0f", a[i]);
        }
    return 0;
}
