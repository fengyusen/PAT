#include <bits/stdc++.h>
using namespace std;
int main()
{
    string N;
    int Nmax, Nmin, num = 0;
    cin >> N;
    N.insert(0, 4 - N.length(), '0');
    do{
        sort(N.begin(), N.end(), greater<char>());
        Nmax = stoi(N);
        sort(N.begin(), N.end());
        Nmin = stoi(N);
        num = Nmax - Nmin;
        printf("%04d - %04d = %04d\n", Nmax, Nmin, num);
        N = to_string(num);
        N.insert(0, 4 - N.length(), '0');
    } while (num != 6174 && num != 0);
    return 0;
}