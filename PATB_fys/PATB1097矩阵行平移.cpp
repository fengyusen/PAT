#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,x,m=0;
    cin>>n>>k>>x;
    int nums[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    for(int i=0;i<n;i=i+2){
        for(int j=n-1;j>=0;j--){
            if(j>m)nums[i][j]=nums[i][j-m-1];
            else nums[i][j]=x;
        }
        m=(m+1)%k;
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j][i];
        }
        if(i!=0)cout<<" ";
        cout<<sum;
    }
    return 0;
}