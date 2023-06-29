#include <iostream>
#include <string>
using namespace std;
long int gcd(long int a, long int b) {
    return !b ? a : gcd(b, a % b);
}
string printFraction(long int a, long int b) {
    if (a * b == 0) return b == 0 ? "Inf" : "0";
    string s;
    if (b < 0) {a = -a, b = - b;}
    int g = gcd(abs(a), b);
    a /= g, b /= g;
    int n = a / b;
    a = a % b;
    if (n < 0) a = -a;
    if (n != 0 && a == 0) s = to_string(n);
    else if (n == 0 && a != 0) s = to_string(a) + "/" + to_string(b);
    else s = to_string(n) + " " + to_string(a) + "/" + to_string(b);
    if (n < 0 || a < 0) s = '(' + s + ')';
    return s;
}
int main() {
    long int a, b, a1, b1, a2, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    string s1 = printFraction(a1, b1), s2 = printFraction(a2, b2);
    cout << s1 << " + " << s2 << " = " << printFraction((long int)(a1 * b2 + a2 * b1), (long int)b1 * b2) << endl;
    cout << s1 << " - " << s2 << " = " << printFraction((long int)(a1 * b2 - a2 * b1), (long int)b1 * b2) << endl;
    cout << s1 << " * " << s2 << " = " << printFraction((long int)(a1 * a2), (long int)(b1 * b2)) << endl;
    cout << s1 << " / " << s2 << " = " << printFraction((long int)(a1 * b2), (long int)(b1 * a2)) << endl;
    return 0;
}