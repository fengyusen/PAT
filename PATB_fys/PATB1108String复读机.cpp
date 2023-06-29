#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ascii[256]={0};
    string s,a="String";
    cin>>s;
    for(int i=0;i<s.length();i++){
        ascii[s[i]]++;
    }
    while(1){
        int flag=0;
        for(int i=0;i<a.length();i++){
            if(ascii[a[i]]>0){
                cout<<a[i];
                ascii[a[i]]--;
                flag=1;
            }
        }
        if(flag==0)break;
    }
    return 0;
}