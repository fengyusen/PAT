#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string oper(string s) {
    string r = s, n;
    int carry = 0;
    reverse(r.begin(), r.end());
    for (int i = s.length()-1; i >= 0; i--) {
        int v = s[i] - '0' + r[i] - '0' + carry;
        carry = v / 10;
        n = to_string(v % 10) + n;
    }
    //cout << r << " + " << s << " = " << n << endl;
    if (carry > 0) n = "1" + n;
    return n;
}
bool isPalindromic(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    return r == s;
}
int main() {
    int k, steps = 0;
    string s;
    cin >> s >> k;
    while (!isPalindromic(s) && steps < k){
        s = oper(s);
        steps++;
    }
    cout << s << endl << steps;
    return 0;
}