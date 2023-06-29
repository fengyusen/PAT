#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int pw[n]={0};
    for(int i=0;i<n;i++){
        scanf("\n");
        char c,h;
        int flag=0;
        for(int j=0;j<4;j++){
            if(j!=0)scanf(" ");
            scanf("%c-%c",&c,&h);
            if(h-'T'==0&&flag==0){
                pw[i]=1+c-'A';
                flag=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<pw[i];
    }
    return 0;
    
}