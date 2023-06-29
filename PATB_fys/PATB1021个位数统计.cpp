#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    cin>>N;
    int m[10]={0};
    for(int i;i<N.length();i++)
    {
        m[N[i]-'0']++;
    }
    for(int i=0;i<10;i++)
    {
        if(m[i]>0){
            cout<<i<<":"<<m[i]<<endl;
        }
    }
    return 0;
}