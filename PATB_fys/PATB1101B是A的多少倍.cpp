#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,d;
    cin>>a>>d;
    string s=to_string(a);
    int b=stoi(s.substr(s.length()-d)+s.substr(0,s.length()-d));
    printf("%.2f",b*1.0/a);
    return 0;
}