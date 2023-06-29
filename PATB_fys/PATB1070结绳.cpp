#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    sort(nums,nums+n);
    int sum=nums[0];
    for(int i=1;i<n;i++){
        sum=(sum+nums[i])/2;
    } 
    cout<<sum;
    return 0;
}