#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> num[i];
    }
    if (num[0] > 0)
    {
        int i = 1;
        while (num[i] == 0)
        {
            i++;
        }
        cout << i;
        num[i]--;
    }
    int i = 0;
    while (i <= 9)
    {
        while (num[i] > 0)
        {
            cout << i;
            num[i]--;
        }
        i++;
    }
    return 0;
}