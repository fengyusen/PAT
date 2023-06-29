#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S,R="PATest";
    cin>>S;
    int asc[256]={0};
    for(int i=0;i<S.length();i++){
        asc[S[i]]++;
    }
    int flag=1;
    while(flag){
        flag=0;
        for(int i=0;i<R.length();i++){
            if(asc[R[i]]>0){
                cout<<R[i];
                asc[R[i]]--;
                flag=1;
            }
        }
    }
    return 0;
}