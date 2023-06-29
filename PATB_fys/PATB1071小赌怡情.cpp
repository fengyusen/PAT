#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,K,n1,n2,b,t,x;
    cin>>T>>K;
    x=T;
    for(int i=0;i<K;i++){
        cin>>n1>>b>>t>>n2;
        if(x<t){
            printf("Not enough tokens.  Total = %d.\n",x);
        }
        else if((b==1&&n2>n1)||(b==0&&n2<n1)){
            x+=t;
            printf("Win %d!  Total = %d.\n",t,x);
        }
        else{
            x-=t;
            printf("Lose %d.  Total = %d.\n",t,x);
        }
        if(x==0){
            printf("Game Over.");
            break;
        }
    }
    return 0;
}