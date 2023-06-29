#include <bits/stdc++.h>
using namespace std;

inline int gcd(int a,int b) {
	if(b) while((a%=b) && (b%=a));
	return a+b;
}

int main()
{
    int N1,M1,N2,M2,K;
    scanf("%d/%d %d/%d %d",&N1,&M1,&N2,&M2,&K);
    if(N1*M2>N2*M1){
        swap(N1,N2);
        swap(M1,M2);
    }
    int num=0,flag=0;
    vector<int> nums;
    while(N1*K>=num*M1)num++;
    while(N1*K<M1*num&&M2*num<N2*K){
        if(gcd(K,num)==1){
            printf("%s%d/%d",flag==1?" ":"",num,K);
            flag=1;
        }
        num++;
    }
    return 0;
}