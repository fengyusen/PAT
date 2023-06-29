#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,num,h=1000,l=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        h=min(h,num);
    }
    for(int i=0;i<n;i++){
        cin>>num;
        l=max(l,num);
    }
    if(h-l>0)printf("Yes %d",h-l);
    else printf("No %d",l-h+1);
    return 0;
}