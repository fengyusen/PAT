#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    long long int nums[N],lmax[N],rmin[N];
    cin>>nums[0];
    lmax[0]=nums[0];
    for(int i=1;i<N;i++){
        cin>>nums[i];
        lmax[i]=max(lmax[i-1],nums[i]);
    }
    rmin[N-1]=nums[N-1];
    for(int i=N-2;i>=0;i--){
        rmin[i]=min(rmin[i+1],nums[i]);
    }
    int sum=0;
    vector<long long int> flag;
    for(int i=0;i<N;i++){
        //cout<<lmax[i]<<" "<<nums[i]<<" "<<rmin[i]<<endl;
        if(nums[i]>=lmax[i]&&nums[i]<=rmin[i]){
            sum++;
            flag.push_back(nums[i]);
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<sum-1;i++){
        cout<<flag[i]<<" ";
    }
    if(sum>0)
        cout<<flag[sum-1];
    return 0;
}