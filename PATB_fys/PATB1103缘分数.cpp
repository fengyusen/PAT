#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,flag=0;
    cin>>m>>n;
    for(int a=m;a<=n;a++){
        int a1=a*a*a-(a-1)*(a-1)*(a-1);
        int c=sqrt(a1);
        if(c*c==a1){
            for(int b=2;b<=sqrt(c);b++){
                if(b*b+(b-1)*(b-1)==c){
                    cout<<a<<" "<<b<<endl;
                    flag=1;
                }
            }
        }
    }
    if(flag==0)cout<<"No Solution";
    return 0;
}