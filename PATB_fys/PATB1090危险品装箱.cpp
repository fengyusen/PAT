#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b;
    vector <vector<int>> item(100000);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        item[a].push_back(b);item[b].push_back(a);
    }
    for(int i=0;i<m;i++){
        int num,temp,tag=0,flag[100000]={0};
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>temp;
            flag[temp]=1;
            for(int k=0;k<item[temp].size();k++){
                if(flag[item[temp][k]]==1){
                    tag=1;
                }
            }
        }
        if(tag==1)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}