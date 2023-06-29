#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d,n;
    cin>>d>>n;
    string s=to_string(d);
    for(int i=1;i<n;i++){
        string S;
        char pre=s[0];
        int num=1;
        for(int j=1;j<s.length();j++){
            if(s[j]==pre)num++;
            else{
                S+=pre+to_string(num);
                pre=s[j];
                num=1;
            }
        }
        S+=pre+to_string(num);
        s=S;
    }
    cout<<s;
    return 0;
}