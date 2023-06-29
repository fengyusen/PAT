#include <iostream>
#include <string>
using namespace std;
bool a[256];
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.length(); i++) a[s2[i]] = true;
    for (int i = 0; i < s1.length(); i++) {
        if (!a[s1[i]]) cout << s1[i];
    }
    return 0;
}