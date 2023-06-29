#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    char C;
    cin>>N>>C;
    int row=N%2?N/2+1:N/2;
    for(int i=0;i<N;i++)cout<<C;
    cout<<endl;
    for(int i=1;i<row-1;i++){
        cout<<C;
        for(int j=0;j<N-2;j++)cout<<" ";
        cout<<C<<endl;
    }
    for(int i=0;i<N;i++)cout<<C;
    return 0;
}