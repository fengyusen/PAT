#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N=0;
    cin>>N;
    int temp,sum=0;
    for(int i=0;i<N;i++){
        cin>>temp;
        sum+=temp;
    }
    cout<<sum*(N-1)*11;
    return 0;
}
