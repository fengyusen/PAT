#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[5]={2,0,1,9,0};
    cin>>n;
    for(int i=0;i<min(4,n);i++)cout<<a[i];
    if(n>4){
        for(int i=4;i<n;i++){
            a[4]=(a[0]+a[1]+a[2]+a[3])%10;
            cout<<a[4];
            a[0]=a[1];a[1]=a[2];a[2]=a[3];a[3]=a[4];
            
        }
    }
    return 0;
}