#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    string sno[N+1],s;
    int t[N+1],a,b;
    for(int i=0;i<N;i++){
        cin>>s>>a>>b;
        sno[a]=s;
        t[a]=b;
    } 
    int n;
    cin>>n;
    int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n-1;i++){
        cout<<sno[c[i]]<<" "<<t[c[i]]<<endl;
    }
    cout<<sno[c[n-1]]<<" "<<t[c[n-1]]<<endl;
    return 0;
}