#include <bits/stdc++.h>
using namespace std;
int isPrime(int a){
    if(a<2)return 0;
    for(int i=2;i<=sqrt(a);i++)
        if(a%i==0)return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    if(isPrime(n)&&isPrime(n-6))printf("Yes\n%d",n-6);
    else if(isPrime(n)&&isPrime(n+6))printf("Yes\n%d",n+6);
    else{
        while(!((isPrime(n)&&isPrime(n-6))||(isPrime(n)&&isPrime(n+6))))n++;
        printf("No\n%d",n);
    }
    return 0;
}