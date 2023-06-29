#include <bits/stdc++.h>
using namespace std;
int main()
{
    string I,R,W;
    cin>>I>>R;
    int ascii[255]={0};
    for(int i=0;i<R.length();i++)
    {
        R[i]=toupper(R[i]);
        ascii[R[i]]=1;
    } 
    for(int i=0;i<I.length();i++)
    {
        I[i]=toupper(I[i]);
        if(ascii[I[i]]==0){
            cout<<I[i];
            ascii[I[i]]=1;
        }
    } 
    return 0;
}