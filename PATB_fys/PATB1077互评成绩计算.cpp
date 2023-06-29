#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        int num,tech,sum=0;
        vector<int> score;
        cin>>tech;
        for(int j=1;j<n;j++){
            cin>>num;
            if(num>=0&&num<=m)
                score.push_back(num);
        }
        sort(score.begin(),score.end());
        for(int j=1;j<score.size()-1;j++){
            sum+=score[j];
        }
        sum=(sum*1.0/(score.size()-2)+tech)/2.0+0.5;
        printf("%d\n",sum);
    }
    return 0;
}