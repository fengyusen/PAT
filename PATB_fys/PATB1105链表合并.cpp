#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l1,l2,num,data[100000]={0},next[100000]={-1};
    vector<int> list1,list2,list;
    cin>>l1>>l2>>num;
    for(int i=0;i<num;i++){
        int addr;
        cin>>addr>>data[addr]>>next[addr];
    }
    int n=0,m=0,node=0;
    node=l1;
    while(node!=-1){
        list1.push_back(node);
        node=next[node];
        n++;
    }
    node=l2;
    while(node!=-1){
        list2.push_back(node);
        node=next[node];
        m++;
    }
    if(m>=2*n){
        int t=m;m=n;n=t;
        t=l1;l1=l2;l2=t;
        list1.swap(list2);
    }
    int j=m-1;
    for(int i=0;i<n;i++){
        list.push_back(list1[i]);
        if(i%2==1&&j>=0){
            list.push_back(list2[j--]);
        }
    }
    for(int i=0;i<list.size()-1;i++){
        printf("%05d %d %05d\n",list[i],data[list[i]],list[i+1]);
    }
    printf("%05d %d -1",list.back(),data[list.back()]);
    return 0;
}