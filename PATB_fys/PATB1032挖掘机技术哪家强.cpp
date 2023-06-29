#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int scores[N+1]={0},n,score,maxscore=0,maxn=1;
    for (int i = 0; i < N; i++)
    {
        cin>>n>>score;
        scores[n]+=score;
        if(scores[n]>maxscore){
            maxscore=scores[n];
            maxn=n;
        }
    }
    cout<<maxn<<" "<<maxscore;
    return 0;
}