#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,num;
    cin>>n;
    int nums[n]={0};
    for(int i=1;i<=n;i++){
        cin>>num;
        nums[abs(num-i)]++;
    }
    for(int i=n-1;i>=0;i--){
        if(nums[i]>1)
            printf("%d %d\n",i,nums[i]);
    }
    return 0;
}