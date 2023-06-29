#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A, N, D, E;
    cin >> A;
    int i = 1, j = 0;
    for (i = 1; A[i] != '.'; i++)
        ;
    N = A.substr(1, i - 1);
    for (j = i + 1; A[j] != 'E'; j++)
        ;
    D = A.substr(i + 1, j - i - 1);
    E = A.substr(j + 1);
    int e = stoi(E);
    //cout << N << " " << D << " " << E << " " << e << endl;
    if (A[0] == '-')
        cout << '-';
    if (e < 0)
    {
        int num = (-e) - N.length();
        if (num > 0)
        {
            cout << "0.";
            while (num--)
            {
                cout << "0";
            }
            cout << N << D;
        }
        else
        {
            num = -num;
            string startN = N.substr(0, num);
            string endN = N.substr(num);
            cout << startN << '.' << endN << D;
        }
    }
    else
    {
        cout << N;
        int num = e - D.length();
        if (num >= 0)
        {
            cout << D;
            while (num--)
            {
                cout << '0';
            }
        }
        else
        {
            string startD = D.substr(0, e);
            string endD = D.substr(e);
            cout << startD << "." << endD;
        }
    }
    return 0;
}