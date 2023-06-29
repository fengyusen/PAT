#include <bits/stdc++.h>
using namespace std;
#define clk_tck 100
int main()
{
    int C1,C2;
    cin>>C1>>C2;
    int runtime=(C2-C1)/clk_tck;
    int r=(C2-C1)%clk_tck;
    //cout<<runtime<<"\t"<<r;
    runtime=r>=50?runtime+1:runtime;
    //cout<<"\t"<<runtime<<endl;
    int hh,mm,ss;
    ss=runtime%60;
    runtime=runtime/60;
    mm=runtime%60;
    runtime=runtime/60;
    hh=runtime%60;
    printf("%02d:%02d:%02d",hh,mm,ss);
    return 0;
}