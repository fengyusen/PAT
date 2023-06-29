#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int team[1001]={0},mt=0,ms=0;
    int tid,pid,score;
    for(int i=0;i<N;i++){
        scanf("%d-%d %d",&tid,&pid,&score);
        team[tid]+=score;
        if(team[tid]>ms){
            ms=team[tid];
            mt=tid;
        }
    } 
    cout<<mt<<" "<<ms;
    return 0;
}