#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    getchar();
    for(int i=0;i<n;i++){
        getline(cin,s);
        if(s.length()<6){
            printf("Your password is tai duan le.\n");
            continue;
        }
        int flagdigit=0,flagalpha=0,flag=1;
        for(int j=0;j<s.length();j++){
            if(!isalnum(s[j])&&s[j]!='.')flag=0;
            else if(isdigit(s[j]))flagdigit=1;
            else if(isalpha(s[j]))flagalpha=1;
        }
        if(flag==0){
                printf("Your password is tai luan le.\n");
                continue;
        }else if(flagdigit==0){
            printf("Your password needs shu zi.\n");
            continue;
        }else if(flagalpha==0){
            printf("Your password needs zi mu.\n");
            continue;
        }
        else printf("Your password is wan mei.\n");

    }
    return 0;
}