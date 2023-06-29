#include <bits/stdc++.h>
using namespace std;

int isPrime(long long int a){
    if(a<2)return 0;
    for(int i=2;i<sqrt(a);i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int l,k;
    cin>>l>>k;
    string s;`
    getchar();
    getline(cin,s);
    for(int i=0;i<=l-k;i++){
        string ss=s.substr(i,k);
        long long int num=stoll(ss);
        if(isPrime(num)){
            cout<<ss;
            return 0;
        }
    }
    cout<<"404";
    return 0;
}