#include <bits/stdc++.h>
using namespace std;

int main()
{
    string M,W;
    getline(cin,M);
    getline(cin,W);
    int m[256]={0},w[256]={0};
    for(int i=0;i<M.size();i++){
        m[M[i]]++;
    }
    for(int i=0;i<W.size();i++){
        w[W[i]]++;
    }
    int d=0,s=0;
    for(int i=0;i<256;i++){
        if(m[i]>=w[i])d+=(m[i]-w[i]);
        else{
            s+=(w[i]-m[i]);}
    }
    if(s>0)cout<<"No "<<s;
    else cout<<"Yes "<<d;
    return 0;
}