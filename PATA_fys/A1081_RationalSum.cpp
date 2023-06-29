#include <iostream>
using namespace std;
long int gcd(long int a, long int b) {
    return !b ? a : gcd(b, a % b);
}
int main() {
    long int n, a = 0, b = 1, a1, b1;
    scanf("%ld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%ld/%ld", &a1, &b1);
        a = a * b1 + b * a1, b = b * b1;
        int g = gcd(abs(a), b);
        a /= g, b /= g;
    }
    n = a / b;
    a %= b;
    if (n == 0 && a == 0) printf("0");
    else if (n != 0 && a == 0) printf("%d", n);
    else if (n == 0 && a != 0) printf("%d/%d", a, b);
    else printf("%d %d/%d", n, a, b);
    return 0;
}