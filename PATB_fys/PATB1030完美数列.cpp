#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,p;
    cin>>N>>p;
    long long nums[N];
    for(int i=0;i<N;i++){
        cin>>nums[i];
    }
    sort(nums,nums+N);
    int sum=1;
    for(int i=0;i<N-1;i++){
        long long mp=nums[i]*p;
        for(int j=i+sum;j<N;j++){
            if(nums[j]>mp)break;
            sum=max(sum,j-i+1);
        }
    }
    cout<<sum;
    return 0;
}