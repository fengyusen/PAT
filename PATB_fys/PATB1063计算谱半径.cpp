#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int num1=0,num2=0;
    double sum=0.0,temp=0.0;
    for(int i=0;i<N;i++){
        cin>>num1>>num2;
        temp=sqrt(num1*num1+num2*num2);
        sum=max(sum,temp);
    }
    printf("%.2f",sum);
    return 0;
}