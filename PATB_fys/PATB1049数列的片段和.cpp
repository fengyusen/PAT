#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    double num;
    long long sum=0;
    for(int i=0;i<N;i++){
        cin>>num;
        sum+=(long long)(num*1000)*(i+1)*(N-i);
    }
    printf("%.2f",sum/1000.0);
    return 0;
}