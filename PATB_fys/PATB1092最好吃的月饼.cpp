#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    long long int sum[n+1]={0},num,maxsum=0;
    vector<int> winner;
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            cin>>num;
            sum[j]+=num;
            if(i==m-1&&sum[j]>maxsum){
                maxsum=sum[j];
                winner.clear();
                winner.push_back(j);
            }
            else if(i==m-1&&sum[j]==maxsum){
                winner.push_back(j);
            }
        }
    }
    printf("%lld\n",maxsum);
    for(int i=0;i<winner.size();i++){
        if(i!=0)cout<<" ";
        cout<<winner[i];
    }
    return 0;
}