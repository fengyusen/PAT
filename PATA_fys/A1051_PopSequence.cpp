#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int m, n, k, num;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        vector<int> nums(n + 1);
        for (int j = 1; j <= n; j++)
            cin >> nums[j];
        stack<int> st;
        int cur = 1, flag = true;
        for (int j = 1; j <= n; j++) {
            st.push(j);
            if (st.size() > m) {
                flag = false;
                break;
            }
            while (!st.empty() && st.top() == nums[cur]){
                st.pop();
                cur++;
            }
        }
        if (st.empty() && flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}