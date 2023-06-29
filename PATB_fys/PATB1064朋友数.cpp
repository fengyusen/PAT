#include <bits/stdc++.h>
using namespace std;
int getFriendNum(int num) {
    int sum = 0;
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void liu(int n,int num[])
{
    set<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(getFriendNum(num[i]));
    }
    printf("%d\n", s.size());
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
        if(it != s.begin())
            printf(" ");
        printf("%d", *it);
    }
}

void fys(int N,int nums[])
{
    int friends[40]={0},count=0;
    for(int i=0;i<N;i++){
        int sum=0;
        string str=to_string(nums[i]);

        for(int j=0;j<str.length();j++){
            sum+=(str[j]-'0');
        }
        if(friends[sum]==0){
            friends[sum]=1;
            count++;
        }
    }
    cout<<count<<endl;
    int flag=0;
    for(int i=0;i<40;i++){
        if(friends[i]==1){
            if(flag==1)cout<<" ";
            cout<<i;
            flag=1;
        }
    }
    cout<<endl;
}

int main()
{
    int N;
    cin>>N;
    int nums[N];
    srand(time(NULL));
    for(int i=0;i<N;i++){
        cin>>nums[i];
    }
    //cout<<endl;
    liu(N,nums);
    cout<<endl;
    //fys(N,nums);
    return 0;
}