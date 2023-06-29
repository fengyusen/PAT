#include <bits/stdc++.h>
using namespace std;

int timeToSecond(string s){
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    return (hh * 60 + mm) * 60 + ss;
}

int main()
{
    int m, unlock_time = 24 * 60 * 60, lock_time = 0;
    string unlockID, lockID, ID_number, sign_in_time, sign_out_time;
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>ID_number>>sign_in_time>>sign_out_time;
        int sign_in_second = timeToSecond(sign_in_time);
        int sign_out_second = timeToSecond(sign_out_time);
        if(sign_in_second < unlock_time){
            unlock_time = sign_in_second;
            unlockID = ID_number;
        }
        if(sign_out_second > lock_time){
            lock_time = sign_out_second;
            lockID = ID_number;
        }
    }
    cout<<unlockID<<" "<<lockID;
    return 0;
}
