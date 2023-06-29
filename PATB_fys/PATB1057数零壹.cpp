#include <bits/stdc++.h>
using namespace std;

int main()
{
    string X;
    getline(cin,X);
    long long int sum=0;
    for(int i=0;i<X.length();i++){
        if(isalpha(X[i])){
            sum+=tolower(X[i])-'a'+1;
        }
    }
    int zero=0,one=0;
    while(sum>0){
        if(sum%2==1){
            one++;
        }
        else{
            zero++;
        }
        sum/=2;
    }
    cout<<zero<<" "<<one;
    return 0;
}
