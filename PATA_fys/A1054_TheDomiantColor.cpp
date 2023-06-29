#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;
int main() {
    map<string, int> mp;
    string s, word, ret;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i = 0, j = 0, n = s.length(), ans = 0;
    while(i < n) {
        while (i < n && !isalnum(s[i])) i++;
        j = i;
        while (j < n && isalnum(s[j])) j++;
        word = s.substr(i, j - i);
        mp[word]++;
        if (mp[word] > ans) {
            ans = mp[word];
            ret = word;
        }
        i = j;
    }
    cout << ret << " " << ans;
    return 0;
}