#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ji = "0123456789JQK";
    string A, B, C;
    cin >> A >> B;
    int lena = A.length(), lenb = B.length();
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    if (lena > lenb)
        B.append(lena - lenb, '0');
    if (lenb > lena)
        A.append(lenb - lena, '0');
    for (int i = 0; i < A.length(); i++)
    {
        if (i % 2 == 0)
        {
            C.push_back(ji[(A[i] + B[i] - '0' - '0') % 13]);
        }
        else
        {
            C.push_back((B[i] - A[i] + 10) % 10 + '0');
        }
    }
    reverse(C.begin(), C.end());
    cout << C;
    return 0;
}