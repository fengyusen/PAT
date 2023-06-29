#include <bits/stdc++.h>
using namespace std;

struct school{
    string name;
    int score,num;
};
int cmp(school a,school b){
    return a.score!=b.score?a.score>b.score:(a.num!=b.num?a.num<b.num:a.name<b.name);
}
int main()
{
    int n;
    map<string,int> cnt;
    map<string,double> sum;
    cin>>n;
    for(int i=0;i<n;i++){
        string sno,sch;
        double score=0.0;
        cin>>sno>>score>>sch;
        if(sno[0]=='B')score=score/1.5;
        else if(sno[0]=='T')score=score*1.5;
        for(int j=0;j<sch.length();j++)sch[j]=tolower(sch[j]);
        cnt[sch]++;
        sum[sch]+=score;
    }
    vector<school> ans;
    for(auto it=cnt.begin();it!=cnt.end();it++)
        ans.push_back(school{it->first,(int)sum[it->first],cnt[it->first]});
    sort(ans.begin(),ans.end(),cmp);
    printf("%d\n",ans.size());
    int rank=1,pres=-1;
    for(int i=0;i<ans.size();i++){
        if(pres!=ans[i].score)rank=i+1;
        pres=ans[i].score;
        printf("%d %s %d %d\n",rank,ans[i].name.c_str(),ans[i].score,ans[i].num);
    }
    return 0;
}