#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    int a[40], num = 0;
    do {
        a[num++] = n % b;
        n /= b;
    } while(n != 0);
    bool flag = true;
    for (int i = 0; i <= num / 2; i++) {
        if (a[i] != a[num - 1 - i]) {
            flag = false;
            break;
        }
    }
    if (flag) printf("Yes\n");
    else printf("No\n");
    for (int i = num - 1; i >= 0; i--) {
        printf("%d", a[i]);
        if (i) printf(" ");
    }
    return 0;
}