#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,k;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>k;
        int num,flag=0;
        for(int n=1;n<10;n++){
            string s1=to_string(k);
            string s2=to_string(n*k*k);
            s2=s2.substr(s2.size()-s1.size());
            if(s1.compare(s2)==0&&flag==0){
                num=n;
                flag=1;
            }
        }
        if(flag==1)printf("%d %d\n",num,num*k*k);
        else printf("No\n");
    }
    return 0;
}