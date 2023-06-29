#include <bits/stdc++.h>
using namespace std;
string digits[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main(){
    string s;
    cin>>s;
    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        sum += s[i] - '0';
    }
    string ssum = to_string(sum);
    cout<<digits[ssum[0] - '0'];
    for(int i = 1; i < ssum.length(); i++){
        cout<<" "<<digits[ssum[i] - '0'];
    }
    return 0;
}
