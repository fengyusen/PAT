#include <iostream>
using namespace std;
int pre[1000], post[1000], in[1000];
int n, cnt = 0;
bool flag = true;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    for (int i = 0; i < n; i++) {
        if (pre[0] == post[i]) {
            cnt++;
            in[cnt] = pre[0];
            for (int j = 0; j < i; j++) {
                cnt++;
                in[cnt] = post[j];
            }
            for (int j = i + 1; j < n; j++) {
                cnt++;
                in[cnt] = post[j];
            }
            break;
        }
    }
    if (cnt != n) flag = false;
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << in[i];
        if (i != n) cout << " ";
    }
    return 0;
}