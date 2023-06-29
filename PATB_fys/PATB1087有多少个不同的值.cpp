#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,num[100000]={0},nums=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int sum=i/2+i/3+i/5;
        //cout<<i<<":"<<sum<<endl;
        if(num[sum]==0){
            num[sum]=1;
            nums++;
        }
    }
    cout<<nums;
    return 0;
}