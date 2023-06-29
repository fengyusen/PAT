#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,K=0;
    double sumf=0.0,temp;
    cin>>N;
    for(int i=0;i<N;i++){
        char X[50],Y[50];
        scanf("%s",X);
        sscanf(X,"%lf",&temp);
        sprintf(Y,"%.2f",temp);
        int flag=0;
        for(int i=0;i<strlen(X);i++){
            if(X[i]!=Y[i])
                flag=1;
        }
        if(flag==1||temp>1000||temp<-1000){
            printf("ERROR: %s is not a legal number\n",X);
            continue;
        }
        else{
            sumf+=temp;
            K++;
        }
    }
    cout<<"The average of "<<K<<" number";
    if(K>1||K==0)cout<<"s";
    cout<<" is ";
    if(K==0)cout<<"Undefined";
    else{
        printf("%.2f",sumf/K);
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int N,K=0,sum=0;
//     double sumf=0;
//     cin>>N;
//     for(int i=0;i<N;i++){
//         string X;
//         cin>>X;
//         int j=0,k=X.length()-1;
//         if(X[j]=='-'){
//             j++;
//             if(j==X.length()){
//                 cout<<"ERROR: "<<X<<" is not a legal number" <<endl;
//                 continue;
//             }
//         }

//         while(isdigit(X[j])&&j<X.length())j++;
//         while (isdigit(X[k])&&k>=-1)k--;
//         //cout<<"j:"<<j<<"k:"<<k<<" ";
//         if((j==k&&X[j]=='.'&&X.length()-1-k<=2&&X.length()-1-k>0)||(j==X.length())){
//             //cout<<X.substr(0,j)<<"\t"<<X.substr(k+1)<<" ";
//             //int numj=stoi(X.substr(0,j));
//             //int numk=stoi(X.substr(k+1));
//             double numf=stof(X);
//             if(numf>=-1000&&numf<=1000){
//                 K++;
//                 // sum+=numj*100;
//                 // if(k!=-1&&numj>=0)sum+=numk;
//                 // if(k!=-1&&numj<0)sum-=numk;
//                 //cout<<"sum:"<<sum<<"\tX:"<<stof(X)<<endl;
//                 sumf+=stof(X);
//                 continue;
//             }
            
//         }
//         cout<<"ERROR: "<<X<<" is not a legal number" <<endl;
//     }
//     cout<<"The average of "<<K<<" number";
//     if(K>1||K==0)cout<<"s";
//     cout<<" is ";
//     if(K==0)cout<<"Undefined";
//     else{
//         printf("%.2f",sumf/K);
//     }
//     return 0;
// }