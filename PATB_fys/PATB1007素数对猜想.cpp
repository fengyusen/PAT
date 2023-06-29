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
    int n, sum = 0;
    cin >> n;
    int first = 1, second;
    for (int i = 5; i <= n; i=i+2)
    {
        second = isPrime(i);
        if (first == 1 &&second ==  1)
        {
            sum++;
        }
        first = second;
    }
    cout << sum;
    return 0;
}
