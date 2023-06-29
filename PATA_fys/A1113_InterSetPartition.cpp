#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, sum = 0, s1 = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n/2; i++) s1 += nums[i];
    cout << n % 2 << " " << sum - 2 * s1;
    return 0;
}