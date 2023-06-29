#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s, t;
    getchar();
    for (int j = 0; j < n; j++) {
        getline(cin, s);
        if (!j) {
            t = s;
            continue;
        }
        int slen = s.length(), tlen = t.length();
        int len = min(slen, tlen);
        for (int i = 1; i <= len; i++) {
            if (s[slen - i] != t[tlen - i]) {
                t = t.substr(tlen - i + 1);
                break;
            }
        }
    }
    if (t.length()) cout << t << endl;
    else cout << "nai" << endl;
    return 0;
}