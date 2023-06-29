#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,flag=0;
    cin>>a>>b;
    string s=to_string(a*b);
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]!='0'||flag==1){
            cout<<s[i];
            flag=1;
        }
    }
    return 0;
}