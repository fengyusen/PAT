#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
vector<int> post, in, pre;
stack<int> st;
void postOrder(int root, int start, int end) {
    if (start > end) return;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    postOrder(root + 1, start, i - 1);
    postOrder(root + 1 + i - start, i + 1, end);
    post.push_back(pre[root]);
}
int main() {
    int n, val;
    cin >> n;
    string s;
    while (in.size() < n) {
        cin >> s;
        if (s == "Push") {
            cin >> val;
            st.push(val);
            pre.push_back(val);
        } else if (s == "Pop") {
            val = st.top();
            st.pop();
            in.push_back(val);
        }
    }
    postOrder(0, 0, n - 1);
    for (int i = 0; i < post.size(); i++) {
        if (i) printf(" ");
        printf("%d", post[i]);
    }
    return 0;
}