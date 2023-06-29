#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,anum=0,bnum=0,am,an,bm,bn,sum=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>am>>an>>bm>>bn;
        sum=am+bm;
        if(sum==an&&sum!=bn)bnum++;
        if(sum!=an&&sum==bn)anum++;
    }
    cout<<anum<<" "<<bnum;
    return 0;
}