#include <bits/stdc++.h>
using namespace std;

int M,N,TOL;
vector<vector<int>> image;
int a[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int judge(int i,int j)
{
    for(int k=0;k<8;k++){
        int kx=i+a[k][0];
        int ky=j+a[k][1];
        if(kx>=1&&kx<=N&&ky>=1&&ky<=M&&(image[i][j]-image[kx][ky]>=0-TOL)&&(image[i][j]-image[kx][ky]<=TOL))
            return 0;
    }
    return 1;
}

int main()
{
    scanf("%d%d%d",&M,&N,&TOL);
    image.resize(N+1,vector<int>(M+1));
    map<int,int> cm;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&image[i][j]);
            cm[image[i][j]]++;
        }
    }
    int x=0,y=0,cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(cm[image[i][j]]==1&&judge(i,j)){
                x=i;
                y=j;
                cnt++;
            }
            // if(i==1&&j==1){
            //     if(image[i][j]-image[i+1][j]>TOL&&image[i][j]-image[i+1][j+1]>TOL&&image[i][j]-image[i][j+1]>TOL){
            //         if(color==-1){
            //             x=j,y=i,color=image[i][j];
            //         }
            //         else{
            //             cout<<"Not Unique"<<endl;
            //             return 0;
            //         }
            //     } 
            // }
            // if(i==1&&j==M){
            //     if(image[i][j]-image[i+1][j]>TOL&&image[i][j]-image[i+1][j-1]>TOL&&image[i][j]-image[i][j-1]>TOL){
            //         if(color==-1){
            //             x=j,y=i,color=image[i][j];
            //         }
            //         else{
            //             cout<<"Not Unique"<<endl;
            //             return 0;
            //         }
            //     } 
            // }
            // if(i==N&&j==1){
            //     if(image[i][j]-image[i-1][j]>TOL&&image[i][j]-image[i-1][j+1]>TOL&&image[i][j]-image[i][j+1]>TOL){
            //         if(color==-1){
            //             x=j,y=i,color=image[i][j];
            //         }
            //         else{
            //             cout<<"Not Unique"<<endl;
            //             return 0;
            //         }
            //     } 
            // }
            // if(i==N&&j==M){
            //     if(image[i][j]-image[i-1][j]>TOL&&image[i][j]-image[i-1][j-1]>TOL&&image[i][j]-image[i][j-1]>TOL){
            //         if(color==-1){
            //             x=j,y=i,color=image[i][j];
            //         }
            //         else{
            //             cout<<"Not Unique"<<endl;
            //             return 0;
            //         }
            //     } 
            // }
            // if(i==1&&j>1&&j<M){
            //     if(image[i][j]-image[i+1][j]>TOL&&image[i][j]-image[i+1][j+1]>TOL&&image[i][j]-image[i][j+1]>TOL&&image[i][j]-image[i][j-1]>TOL&&image[i][j]-image[i+1][j-1]>TOL){
            //         if(color==-1){
            //             x=j,y=i,color=image[i][j];
            //         }
            //         else{
            //             cout<<"Not Unique"<<endl;
            //             return 0;
            //         }
            //     } 
            // }
            // if(i==N&&j>1&&j<M){
            //     if(image[i][j]-image[i][j+1]>TOL&&image[i][j]-image[i-1][j+1]>TOL&&image[i][j]-image[i-1][j]>TOL&&image[i][j]-image[i-1][j-1]>TOL&&image[i][j]-image[i][j-1]>TOL){
            //         if(color==-1){
            //             x=j,y=i,color=image[i][j];
            //         }
            //         else{
            //             cout<<"Not Unique"<<endl;
            //             return 0;
            //         }
            //     } 
            // }
            // if(i>1&&i<N&&j==1){
            //     if(image[i][j]-image[i+1][j]>TOL&&image[i][j]-image[i+1][j+1]>TOL&&image[i][j]-image[i][j+1]>TOL&&image[i][j]-image[i-1][j+1]>TOL&&image[i][j]-image[i-1][j]>TOL){
            //         if(color==-1){
            //             x=j,y=i,color=image[i][j];
            //         }
            //         else{
            //             cout<<"Not Unique"<<endl;
            //             return 0;
            //         }
            //     } 
            // }
            // if(i>1&&i<N&&j==M){
            //     if(image[i][j]-image[i+1][j]>TOL&&image[i][j]-image[i-1][j]>TOL&&image[i][j]-image[i-1][j-1]>TOL&&image[i][j]-image[i][j-1]>TOL&&image[i][j]-image[i+1][j-1]>TOL){
            //         if(color==-1){
            //             x=j,y=i,color=image[i][j];
            //         }
            //         else{
            //             cout<<"Not Unique"<<endl;
            //             return 0;
            //         }
            //     } 
            // }
            // if(i>1&&i<N&&j>1&&j<M){
            //     int knum=0;
            //     for(int k=0;k<8;k++){
            //         if(image[i][j]-image[i+a[k][0]][j+a[k][1]]>TOL){
            //             knum++;
            //         }
            //         else if(image[i][j]-image[i+a[k][0]][j+a[k][1]]<-TOL){
            //             knum--;
            //         }
            //     } 
            //     if(knum==8||knum==-8){
            //     //if(abs(image[i][j]-image[i-1][j])>TOL&&abs(image[i][j]-image[i-1][j-1])>TOL&&abs(image[i][j]-image[i-1][j-1])>TOL&&abs(image[i][j]-image[i][j-1])>TOL&&abs(image[i][j]-image[i][j+1])>TOL&&abs(image[i][j]-image[i+1][j-1])>TOL&&abs(image[i][j]-image[i+1][j])>TOL&&abs(image[i][j]-image[i+1][j]+1)>TOL)
            //         if(color==-1){
            //             x=j,y=i,color=image[i][j];
            //             //printf("(%d, %d): %lld\n",x,y,color);
            //         }
            //         else{
            //             //printf("(%d, %d): %lld\n",x,y,color);
            //             cout<<"Not Unique"<<endl;
            //             return 0;
            //         }
            //     }
            // }

        }
    }
    if(cnt==0){
        cout<<"Not Exist"<<endl;
    }
    else if(cnt==1){
        printf("(%d, %d): %d",y,x,image[x][y]);
    }
    else{
        printf("Not Unique");
    }

    return 0;
}