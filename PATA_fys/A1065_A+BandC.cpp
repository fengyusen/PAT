#include <stdio.h>
int main() {
    int t, i = 0;
    scanf("%d", &t);
    while(i++ < t) {
        long long int a, b ,c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long int res = a + b;
        bool flag;
        if (a > 0 && b > 0 && res < 0) flag = true;
        else if (a < 0 && b < 0 && res >= 0) flag = false;
        else if (res > c) flag = true;
        else flag = false;
        if (flag) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
}