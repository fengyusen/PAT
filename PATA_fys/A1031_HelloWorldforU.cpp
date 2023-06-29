#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n = s.length();
    int n1 = (n + 2) / 3;
    int n2 = n + 2 - 2 * n1;
    string space(n2 - 2, ' ');
    for (int i = 0; i < n1 - 1; i++) {
        cout<<s[i]<<space<<s[n-1-i]<<endl;
    }
    cout<<s.substr(n1-1, n2);
    return 0;
}