#include <bits/stdc++.h>
using namespace std;

int isPrime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}

int main()
{
    int N,ID[10000]={0},id;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>id;
        ID[id]=i+1;
    }
    int K;
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>id;
        //cout<<id<<"-"<<ID[id]<<":";
        if(ID[id]==-1)printf("%04d: Checked\n",id);
        else if(ID[id]==0){printf("%04d: Are you kidding?\n",id);continue;}
        else if(ID[id]==1)printf("%04d: Mystery Award\n",id);
        else if(isPrime(ID[id]))printf("%04d: Minion\n",id);
        else if(ID[id]>1)printf("%04d: Chocolate\n",id);
        ID[id]=-1;
    }
    return 0;
}
