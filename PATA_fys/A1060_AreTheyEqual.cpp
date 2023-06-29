#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
pair<string, int> convert(string s, int n) {
    int p = s.find('.'), k = 0, q = 0;
    string d;
    if (p == string::npos) p = s.size();
    while (q < s.size() && (s[q] == '0' || s[q] == '.')) q++;
    if (q == s.size() && s.back() == '0') q = p + 1;
    if (q > s.size()) q = s.size();
    if (p > q) {
        d = s.substr(q, p - q);
        if (p < s.size()) d += s.substr(p + 1);
    } else if (q > 0) d = s.substr(q);
    d += string(100, '0');
    d = d.substr(0, n);
    k = p - q;
    if (k < 0) k++;
    return pair<string, int>(d, k);
}
int main() {
    int n, i = 0;
    string a, b;
    cin >> n >> a >> b;
    if (n == 0) { cout << "YES 0.*10^0";return 0; }
    auto sa = convert(a, n), sb = convert(b, n);
    if (sa == sb) cout << "YES";
    else cout << "NO" << " 0." + sa.first + "*10^" << sa.second;
    cout << " 0."+sb.first+"*10^" << sb.second<<endl;
    return 0;
}