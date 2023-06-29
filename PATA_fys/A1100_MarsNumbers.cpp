#include <iostream>
#include <string>
#include <map>
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main() {
    map<string, int> ma;
    ma["tret"] = 0;
    for (int i = 1; i < 13; i++) {
        ma[a[i]] = i;
        ma[b[i]] = i * 13;
    }
    int n, num;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string p;
        getline(cin, p);
        if (isdigit(p[0])) {
            num = stoi(p);
            int x = num % 13, y = num / 13;
            if (y) cout << b[y];
            if (x && y) cout << " ";
            if (x || num == 0)cout << a[x];
        } else {
            if (p.length() < 4) num = ma[p];
            else num = ma[p.substr(0, 3)] + ma[p.substr(4, 3)];
            cout << num;
        }
        cout << endl;
    }
    return 0;
}