#include <bits/stdc++.h>
using namespace std;

struct node
{
    string name;
    int gp,gm,gf,g;
};

int cmp(node a,node b)
{
    return a.g!=b.g?a.g>b.g:a.name<b.name;
}

map<string,int> idx;
int main()
{
    int P,M,N,score,cnt=1;
    cin>>P>>M>>N;
    string sno;
    vector<node> v,ans;
    for(int i=0;i<P;i++){
        cin>>sno>>score;
        if(score>=200){
            v.push_back(node{sno,score,-1,-1,0});
            idx[sno]=cnt++;
        }
    }
    for(int i=0;i<M;i++){
        cin>>sno>>score;
        if(idx[sno]!=0)v[idx[sno]-1].gm=score;
    }
    for(int i=0;i<N;i++){
        cin>>sno>>score;
        if(idx[sno]!=0){
            int temp=idx[sno]-1;
            v[temp].gf=v[temp].g=score;
            if(v[temp].gm>v[temp].gf)v[temp].g=int(v[temp].gm*0.4+v[temp].gf*0.6+0.5);
            if(v[temp].g>=60)ans.push_back(v[temp]);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        printf("%s %d %d %d %d\n",ans[i].name.c_str(),ans[i].gp,ans[i].gm,ans[i].gf,ans[i].g);
    }
    return 0;
}