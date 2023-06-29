#include <bits/stdc++.h>
using namespace std;
int main()
{
    int W[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    int N;
    cin>>N;
    vector<string> id(N),wid;
    for(int i=0;i<N;i++){
        cin>>id[i];
        int sum=0;
        for(int j=0;j<17;j++){
            sum+=(id[i][j]-'0')*W[j];
        }
        int m=sum%11;
        if(id[i][17]!=M[m]){
            wid.push_back(id[i]);
        }
    }
    if(wid.size()==0)cout<<"All passed";
    for(int i=0;i<wid.size();i++){
        cout<<wid[i]<<endl;
    }

    return 0;
}