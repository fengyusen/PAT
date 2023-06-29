#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int r[n];
    for(int i=0;i<n;i++)
    {
        long long int a=0,b=0,c=0;
        cin>>a>>b>>c;
        r[i]=a-c+b>0?1:0;
    } 
    for(int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1;
        if(r[i]==1){
            cout<<": true"<<endl;
        }
        else{
            cout<<": false"<<endl;
        }
    } 
    return 0;
}
