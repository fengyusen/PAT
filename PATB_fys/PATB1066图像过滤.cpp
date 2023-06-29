#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M,N,A,B,K;
    cin>>M>>N>>A>>B>>K;
    int image;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&image);
            if(image>=A&&image<=B){
                image=K;
            }
            if(j!=0)printf(" ");
            printf("%03d",image);
        }
        printf("\n");
    }
    return 0;
}