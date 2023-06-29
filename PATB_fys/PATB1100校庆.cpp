#include <bits/stdc++.h>
using namespace std;
string old(string a,string b){
    int ya=stoi(a.substr(6,4)),ma=stoi(a.substr(10,2)),da=stoi(a.substr(12,2));
    int yb=stoi(b.substr(6,4)),mb=stoi(b.substr(10,2)),db=stoi(b.substr(12,2));
    return (ya==yb?(ma==mb?da<db:ma<mb):ya<yb)?a:b;
}
int main()
{
    int n,m,num=0;
    string id,older="000000201900000000",guest=older;
    cin>>n;
    map<string,int> M;
    for(int i=0;i<n;i++){
        cin>>id;
        M[id]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>id;
        if(M[id]>0){
            num++;
            older=old(older,id);
        }else guest=old(guest,id);
    }
    cout<<num<<endl;
    if(num>0)cout<<older;
    else cout<<guest;
    return 0;
}