#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    int n = str.length(), cnt = 0, pnum = 0, tnum = 0;
    for (int i = 0; i < n; i++)
        tnum = str[i] == 'T' ? tnum + 1 : tnum;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'P') pnum++;
        if (str[i] == 'T') tnum--;
        if (str[i] == 'A') cnt = (cnt + (pnum * tnum) % 1000000007) % 1000000007;
    }
    printf("%d", cnt);
    return 0;
}