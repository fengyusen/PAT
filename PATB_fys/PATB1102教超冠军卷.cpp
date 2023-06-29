#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,price,purchaser,max_sell=-1,max_sales=-1;
    string ID,sellID,salesID;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ID>>price>>purchaser;
        if(purchaser>max_sell){
            max_sell=purchaser;
            sellID=ID+" ";
        }
        if(purchaser*price>max_sales){
            max_sales=price*purchaser;
            salesID=ID+" ";
        }
    }
    cout<<sellID<<max_sell<<endl;
    cout<<salesID<<max_sales<<endl;
    return 0;
}