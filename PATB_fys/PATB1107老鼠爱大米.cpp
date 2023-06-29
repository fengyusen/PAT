#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,num,wt=0,wa=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        wt=0;
        for(int j=0;j<m;j++){
            cin>>num;
            wt=max(num,wt);
        }
        if(i!=0)cout<<" ";
        cout<<wt;
        wa=max(wt,wa);
    }
    cout<<"\n"<<wa;
    return 0;
}