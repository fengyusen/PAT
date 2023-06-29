#include <bits/stdc++.h>
using namespace std;

int main()
{
    int firstaddr,addr,n,k,data[100000]={0},next[100000]={0};
    cin>>firstaddr>>n>>k;
    for(int i=0;i<n;i++){
        cin>>addr>>data[addr]>>next[addr];
    }
    vector<int> a;
    addr = firstaddr;
    while(addr!=-1){
        a.push_back(addr);
        addr=next[addr];
    }
    for(int i=0;i<a.size();i+=k)
        reverse(a.begin()+i,min(a.begin()+i+k,a.end()));
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++)
        printf("%05d %d %05d\n",a[i],data[a[i]],a[i+1]);
    printf("%05d %d -1\n",a.back(),data[a.back()]);
    // n = a.size();
    // for(int i=n-n%k;i>=0;i=i-k){
    //     for(int j=i;j<min(n,i+k);j++){
    //         if(j==n-n%k)printf("%05d %d",a[j],data[a[j]]);
    //         else printf(" %05d\n%05d %d",a[j],a[j],data[a[j]]);
    //     }
    // }
    return 0;
}
