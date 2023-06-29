#include <iostream>
using namespace std;
int main() {
    int next[100010] = {0};
    bool node[100010] = {false};
    char data[100010];
    int n, f1, f2, a;
    scanf("%d %d %d", &f1, &f2, &n);
    for (int i = 0; i < n; i++)
        cin >> a >> data[a] >> next[a];
    for (a = f1; a != -1; a = next[a]) 
        node[a] = true;
    for (a = f2; a != -1; a = next[a])
        if (node[a] == true) {
            printf("%05d", a);
            return 0;
        }
    printf("-1");
    return 0;
}