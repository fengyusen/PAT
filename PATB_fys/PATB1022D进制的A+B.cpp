#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,D;
    cin>>A>>B>>D;
    long n=A+B;
    string r;
    int c=0;
    do{
        c=n%D;
        r.push_back(c+'0');
        n=n/D;
    }while (n>0);
    reverse(r.begin(),r.end());
    cout<<r;
    return 0;
}