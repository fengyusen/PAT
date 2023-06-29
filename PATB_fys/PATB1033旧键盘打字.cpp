#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ascii[256]={0},flag=0;
    string W,I;
    getline(cin,W);
    getline(cin,I);
    for(int i=0;i<W.size();i++){
        ascii[W[i]]=1;
    }
    for(int i=0;i<I.size();i++){
        if(ascii['+']==1&&isupper(I[i]))continue;
        if(ascii[toupper(I[i])]==1)continue;
        cout<<I[i];
        flag=1;
    }
    if(flag==0)cout<<endl;
    return 0;
}