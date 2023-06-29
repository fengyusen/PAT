#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    while(y^=x^=y^=x%=y)
    return x;
}
int isPrime(int n){
    if(n<=2)return 0;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)return 0;
    return 1;
}
int main()
{
    int n,k,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>m;
        cout<<"Case "<<i<<endl;
        
    }
    return 0;
}