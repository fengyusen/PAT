#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int nums[N],flag[N];
    for(int i=0;i<N;i++){
        cin>>nums[i];
    } 
    sort(nums,nums+N,greater<int>());
    int ans=0,p=0;
    while(ans<N&&nums[p]>p+1){
        p++;
        ans++;
    }
    cout<<ans;
    return 0;
}
