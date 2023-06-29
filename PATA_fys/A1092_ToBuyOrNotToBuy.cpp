#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2, ans;
    int nums[128] = {0}, n = 0;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) nums[s1[i]]++;
    for (int i = 0; i < s2.length(); i++)
        if (nums[s2[i]] > 0) nums[s2[i]]--;
        else n++;
    if (n == 0) printf("Yes %d", s1.length() - s2.length());
    else printf("No %d", n);
    return 0;
}