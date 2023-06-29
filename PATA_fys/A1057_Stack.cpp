#include <cstdio>
#include <stack>
#define lowbit(i) ((i) & (-i))
const int maxn = 100010;
using namespace std;
int c[maxn];
stack<int> s;
void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i))
        c[i] += v,
        printf("update: %d %d\n", i, c[i]);
}
int getsum(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) {
        sum += c[i];
        printf("getsum: %d %d\n", i, sum);
    }
    return sum;
}
void PeekMedia() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while (left < right) {
        mid = (left + right) / 2;
        if (getsum(mid) >= k)
            right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if (str[1] == 'o') {
            if (!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            } else printf("Invalid\n");
        } else {
            if (!s.empty())
                PeekMedia();
            else printf("Invalid\n");
        }
    }
    return 0;
}
// #include <iostream>
// #include <stack>
// #include <string.h>
// using namespace std;
// const int maxn = 100010, sqrN = 316;
// stack<int> st;
// int block[sqrN], table[maxn];
// void peekMedia(int k) {
//     int sum = 0;
//     int idx = 0;
//     while (sum + block[idx] < k) {
//         sum += block[idx++];
//     }
//     int num = idx * sqrN;
//     while (sum + table[num] < k) {
//         sum += table[num++];
//     }
//     printf("%d\n", num);
// }
// void Push(int x) {
//     st.push(x);
//     block[x / sqrN]++;
//     table[x]++;
// }
// void Pop() {
//     int x = st.top();
//     st.pop();
//     block[x / sqrN]--;
//     table[x]--;
//     printf("%d\n", x);
// }
// int main() {
//     int n, x;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         char cmd[20];
//         scanf("%s", cmd);
//         if (strcmp(cmd, "Push") == 0) {
//             scanf("%d", &x);
//             Push(x);
//         } else if (strcmp(cmd, "Pop") == 0) {
//             if (st.empty()) printf("Invalid\n");
//             else Pop();
//         } else if (strcmp(cmd, "PeekMedia")) {
//             if (st.empty()) printf("Invalid\n");
//             else {
//                 int k = st.size();
//                 if (k % 2 == 1) k = (k + 1) / 2;
//                 else k = k / 2;
//                 peekMedia(k);
//             }
//         }
//     }
//     return 0;
// }