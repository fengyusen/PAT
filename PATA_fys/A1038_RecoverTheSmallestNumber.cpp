#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string nums[10010];
bool cmp (string a, string b){
    return a + b < b + a;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums, nums + n, cmp);
    string ans;
    for (int i = 0; i < n; i++)
        ans += nums[i];
    while(ans.length() != 0 && ans[0] == '0') ans.erase(ans.begin());
    if (ans.length() == 0) cout << 0;
    cout << ans;
    return 0;
}