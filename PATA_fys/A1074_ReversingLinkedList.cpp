#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int node[100010], data[100010] = {0}, next[100010] = {0};
    int n, k, f, a;
    scanf("%d %d %d", &f, &n, &k);
    for (int i = 0; i < n; i++)
        cin >> a >> data[a] >> next[a];
    for (n = 0, a = f; a != -1; a = next[a], n++)
        node[n] = a;
    for (int i = 0; i < n / k; i++)
        reverse(begin(node) + i * k, begin(node) + (i + 1) * k);
    for (int i = 0; i < n - 1; i++)
        printf("%05d %d %05d\n", node[i], data[node[i]], node[i+1]);
    printf("%05d %d -1\n", node[n-1], data[node[n-1]]);
    return 0;
}