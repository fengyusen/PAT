#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M,studentNum=0,itemsNum=0;
    scanf("%d %d",&N,&M);
    int items[10000]={0};
    for(int i=0;i<M;i++){
        int m;
        scanf("%d",&m);
        items[m]=1;
    }
    for(int i=0;i<N;i++){
        int K,flag=0;
        char name[4];
        scanf("%s %d",&name,&K);
        for(int k=0;k<K;k++){
            int it;
            scanf("%d",&it);
            if(items[it]==1){
                if(flag==0){
                    printf("%s: ",name);
                    studentNum++;
                }
                else{
                    printf(" ");
                }
                printf("%04d",it);
                flag=1;
                itemsNum++;
            }
        }
        if(flag==1)
            printf("\n");
    }
    printf("%d %d",studentNum,itemsNum);
    return 0;
}