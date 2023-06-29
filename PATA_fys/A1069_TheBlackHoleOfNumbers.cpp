#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    s = string(4 - s.length(), '0') + s;
    do {
        string a = s;
        sort(a.begin(), a.end());
        string b = a;
        reverse(b.begin(), b.end());
        s = to_string(stoi(b) - stoi(a));
        s = string(4 - s.length(), '0') + s;
        cout << b << " - " << a << " = " << s << endl;
    } while (s != "6174" && s != "0000");
    return 0;
}