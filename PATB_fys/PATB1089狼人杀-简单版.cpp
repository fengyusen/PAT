#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int nums[n+1];
    for(int i=1;i<=n;i++)cin>>nums[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vector<int> lie,flag(n+1,1);
            flag[i]=flag[j]=-1;
            for(int k=1;k<=n;k++){
                if(nums[k]*flag[abs(nums[k])]<0)lie.push_back(k);
            }
            if(lie.size()==2&&flag[lie[0]]+flag[lie[1]]==0){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<"No Solution";
    return 0;
}