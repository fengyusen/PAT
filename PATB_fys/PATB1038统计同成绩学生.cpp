#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int score=0,scores[101]={0};
    for(int i=0;i<N;i++){
        cin>>score;
        scores[score]++;
    }
    int K;
    cin>>K;
    int ret[K],k;
    for(int i=0;i<K;i++){
        cin>>k;
        ret[i]=scores[k];
    }
    for(int i=0;i<K-1;i++){
        cout<<ret[i]<<" ";
    }
    cout<<ret[K-1];
    return 0;
}