#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,num1,num2,nums[100000]={0},flag[100000]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num1>>num2;
        nums[num1]=num2;
        nums[num2]=num1;
    }
    int M;
    cin>>M;
    int m[M]={0};
    vector<int> lone;
    for(int i=0;i<M;i++){
        cin>>m[i];
        flag[m[i]]=1;
    }
    for(int i=0;i<M;i++){
        if(flag[nums[m[i]]]!=1){
            lone.push_back(m[i]);
        }
    }
    sort(lone.begin(),lone.end());
    cout<<lone.size()<<endl;
    for(int i=0;i<lone.size();i++){
        if(i!=0)printf(" ");
        printf("%05d",lone[i]);
    }

    return 0;
}