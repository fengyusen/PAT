#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int num=0;
    while (num<10)
    {
        string str=s;
        reverse(str.begin(),str.end());
        if(str.compare(s)==0){
            cout<<s<<" is a palindromic number.\n";
            return 0;
        }
        else{
            cout<<s<<" + "<<str<<" = ";
            int carry=0;
            for(int i=s.length()-1;i>=0;i--){
                int n1=s[i]-'0';
                s[i]=(n1+(str[i]-'0')+carry)%10+'0';
                carry=(n1+(str[i]-'0')+carry)/10;
            }
            if(carry>0)s.insert(s.begin(),(char)(carry+'0'));
            cout<<s<<endl;
        }
        num++;
    }
    cout<<"Not found in 10 iterations."<<endl;
    return 0;
}