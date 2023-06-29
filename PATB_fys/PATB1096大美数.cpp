#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k,num;
    vector<int> v;
    cin>>k;
    for(int i=0;i<k;i++){
        v.clear();
        cin>>num;
        for(int j=1;j<=num;j++){
            if(num%j==0){
                v.push_back(j);
            }
        }
        if(v.size()<4)printf("No\n");
        else{
            int flag=0;
            for(int a=0;a<v.size();a++){
                for(int b=a+1;b<v.size();b++){
                    for(int c=b+1;c<v.size();c++){
                        for(int d=c+1;d<v.size();d++){
                            if((v[a]+v[b]+v[c]+v[d])%num==0)flag=1;
                        }
                    }
                }
            }
            if(flag==1)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}