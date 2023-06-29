#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pw,tpw;
    int N,num=0;
    cin>>pw>>N;
    getchar();
    while(getline(cin,tpw)){
        if(tpw=="#")break;
        if(pw.compare(tpw)==0){
            cout<<"Welcome in"<<endl;
            return 0;
        }
        else{
            cout<<"Wrong password: "<<tpw<<endl;
        }
        num++;
        if(num>=N){
            cout<<"Account locked"<<endl;
            return 0; 
        }
    }
    return 0;
}