#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    string A,Q;
    int B,R=0;
    cin>>A>>B;
    int len=A.length();
    for(int i=0;i<len;i++)
    {
        int a=A[i]-'0'+R*10;
        R=a%B;
        char q=a/B+'0';
        if(i==0&&q=='0'&&len>1)continue;
        Q.push_back(q);
    }
    cout<<Q<<" "<<R;
    return 0;
}