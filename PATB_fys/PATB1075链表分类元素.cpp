#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Data[100000]={0},Next[100000]={0},firstaddr,addr,N,K;
    cin>>firstaddr>>N>>K;
    vector<int> Address,Address2,Address3;
    for(int i=0;i<N;i++){
        cin>>addr>>Data[addr]>>Next[addr];
    }
    addr=firstaddr;
    while(addr!=-1){
        if(Data[addr]<0)Address.push_back(addr);
        else if(Data[addr]>=0&&Data[addr]<=K)Address2.push_back(addr);
        else if(Data[addr]>K)Address3.push_back(addr);
        addr=Next[addr];
    }
    Address.insert(Address.end(),Address2.begin(),Address2.end());
    Address.insert(Address.end(),Address3.begin(),Address3.end());
    for(int i=0;i<Address.size()-1;i++){
        printf("%05d %d %05d\n",Address[i],Data[Address[i]],Address[i+1]);
    }
    printf("%05d %d -1\n",Address.back(),Data[Address.back()]);
    return 0;
    
}