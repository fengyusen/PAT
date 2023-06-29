#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n,pat1,pat2;
    cin>>n>>pat1>>pat2;
    string num;
    pat1.insert(0,n.length()-pat1.length(),'0');
    pat2.insert(0,n.length()-pat2.length(),'0');
    int carry=0;
    for(int i=n.length()-1;i>=0;i--){
        int p1=pat1[i]-'0',p2=pat2[i]-'0',N=n[i]-'0';
        N=N==0?10:N;
        num.push_back((p1+p2+carry)%N+'0');
        carry=(p1+p2+carry)/N;
    }
    if(carry>0)num.push_back('1');
    int flag=0;
    for(int i=num.length()-1;i>=0;i--){
        if(num[i]!='0'||flag==1){
            cout<<num[i];
            flag=1;
        }
    }
    if(flag==0)cout<<0;
    //cout<<stoull(num);
    return 0;
    
}