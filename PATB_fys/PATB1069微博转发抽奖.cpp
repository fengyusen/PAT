#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,s,flag=0;
    scanf("%d%d%d",&m,&n,&s);
    map<string,int> winner;
    string name;
    for(int i=1;i<=m;i++){
        cin>>name;
        //printf("i%d\ts%d\n",i,s);
        if(i==s&&winner[name]==1)s=s+1;
        else if(i==s&&winner[name]==0){
            cout<<name<<endl;
            winner[name]=1;
            flag=1;
            s+=n;
        }
    }
    if(flag==0)
        cout<<"Keep going...";
    return 0;
}