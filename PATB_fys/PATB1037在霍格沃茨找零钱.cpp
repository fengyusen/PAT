#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int pg,ag,rg,p,a,r;
    int ps,pk,as,ak,rs,rk;
    scanf("%lld.%d.%d %lld.%d.%d",&pg,&ps,&pk,&ag,&as,&ak);
    p=pg*17*29+ps*29+pk;
    a=ag*29*17+as*29+ak;
    r=a-p;
    rk=abs(r%29);
    rs=abs((r/29)%17);
    rg=r/(17*29);
    cout<<rg<<"."<<rs<<"."<<rk;
    return 0;
}