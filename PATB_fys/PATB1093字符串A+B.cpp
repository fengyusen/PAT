#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    int ascii[256]={0};
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<a.size();i++){
        if(ascii[a[i]]==0)cout<<a[i];
        ascii[a[i]]=1;
    }
    for(int i=0;i<b.size();i++){
        if(ascii[b[i]]==0)cout<<b[i];
        ascii[b[i]]=1;
    }
    return 0;
}