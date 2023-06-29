#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    int value[M],answer[M];
    for(int i=0;i<M;i++){
        cin>>value[i];
    }
    for(int i=0;i<M;i++){
        cin>>answer[i];
    }
    int temp;
    for(int i=0;i<N;i++){
        int v=0;
        for(int j=0;j<M;j++){
            cin>>temp;
            if(temp==answer[j])
                v+=value[j];
        }
        cout<<v<<endl;
    }
    return 0;
}