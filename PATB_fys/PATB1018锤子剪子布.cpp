#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char A, B;
    int a = 0, b = 0, a3[3] = {0}, b3[3] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> A >> B;
        if (A == B)
            continue;
        if (A == 'C' && B == 'J')
        {
            a++;
            a3[1]++;
        }
        else if (A == 'J' && B == 'C')
        {
            b++;
            b3[1]++;
        }

        if (A == 'J' && B == 'B')
        {
            a++;
            a3[2]++;
        }
        else if (A == 'B' && B == 'J')
        {
            b++;
            b3[2]++;
        }
        if (A == 'B' && B == 'C')
        {
            a++;
            a3[0]++;
        }
        else if (A == 'C' && B == 'B')
        {
            b++;
            b3[0]++;
        }
    }
    char CJB[] = "BCJ";
    int amax = a3[1] > a3[0] ? 1 : 0;
    amax = a3[2] > a3[amax] ? 2 : amax;
    int bmax = b3[1] > b3[0] ? 1 : 0;
    bmax = b3[2] > b3[bmax] ? 2 : bmax;

    cout << a << " " << n - a - b << " " << b << endl;
    cout << b << " " << n - a - b << " " << a << endl;
    cout << CJB[amax] << " " << CJB[bmax];
    return 0;
}