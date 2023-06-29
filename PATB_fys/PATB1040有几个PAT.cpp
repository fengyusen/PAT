#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    long long int pnum=0,tnum=0,sum=0;
    vector<long long int> aprev,anext;
    for(int i=0;i<S.length();i++){
        if(S[i]=='P'){
            pnum++;
        }
        else if(S[i]=='A'){
            aprev.push_back(pnum);
        }
    }
    for(int i=S.length()-1;i>=0;i--){
        if(S[i]=='T'){
            tnum++;
        }
        else if(S[i]=='A'){
            anext.push_back(tnum);
        }
    }
    int len=aprev.size();
    for(int i=0;i<len;i++){
        sum+=aprev[i]*anext[len-1-i];
    }
    cout<<sum%1000000007;
    return 0;
}