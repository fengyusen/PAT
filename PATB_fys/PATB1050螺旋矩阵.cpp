#include <bits/stdc++.h>
using namespace std;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    int N,m,n;
    cin>>N;
    n=sqrt((double)N);
    while(n>1){
        if(N%n==0)break;
        n--;
    }
    m=N/n;
    int nums[N],mat[m][n],flag[m][n]={0};
    for(int i=0;i<N;i++){
        cin>>nums[i];
    }
    sort(nums,nums+N);
    int level=m/2+m%2,t=N-1;
    for(int i=0;i<level;i++){
        for(int j=i;j<=n-1-i&&t>=0;j++){
            mat[i][j]=nums[t--];
        }  
        for(int j=i+1;j<=m-2-i&&t>=0;j++){
            mat[j][n-1-i]=nums[t--];
        }
        for(int j=n-1-i;j>=i&&t>=0;j--){
            mat[m-1-i][j]=nums[t--];
        }
        for(int j=m-i-2;j>=i+1&&t>=0;j--){
            mat[j][i]=nums[t--];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            printf("%d", mat[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}