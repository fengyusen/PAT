#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int findPrime(int n, int idx) {
    for (int i = idx + 1; i <= sqrt(n); i++) {
        if (isPrime(i) && n % i == 0)
            return i;
    }
    return n;
}
int main() {
    long long int n, p1 = 1, k1 = 0;
    scanf("%lld", &n);
    if (n == 1) {
        printf("1=1");
        return 0;
    }
    printf("%lld=", n);
    bool flag = true;
    while (n > 1) {
        for (int i = p1 + 1; i <= sqrt(n); i++) {
            if (isPrime(i) && n % i == 0) {
                p1 = i;
                break;
            }
        }
        //p1 = findPrime(n, p1);
        k1 = 0;
        while (n % p1 == 0) {
            n /= p1;
            k1++;
        }
        if (flag) printf("*");
        flag = false;
        printf("%lld", p1);
        if (k1 > 1) printf("^%lld", k1);
    }
    return 0;
}