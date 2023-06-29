#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y,s,gmax=0,gmin=20000,smax=0,smin=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>x>>y;
        int g=x*x+y*y;
        if(g<gmin){
            gmin=g;
            smin=s;
        }
        if(g>gmax){
            gmax=g;
            smax=s;
        }
    }
    printf("%04d %04d",smin,smax);
    return 0;
}