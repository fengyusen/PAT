#include <cstdio>
using namespace std;
int main() {
    int a1, b1, c1, a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    int c = (c1 + c2) % 29, carry = (c1 + c2) / 29 ;
    int b = (carry + b1 + b2) % 17;
    carry = (carry + b1 + b2) / 17;
    int a = (carry + a1 + a2);
    printf("%d.%d.%d", a, b, c);
    return 0;
}