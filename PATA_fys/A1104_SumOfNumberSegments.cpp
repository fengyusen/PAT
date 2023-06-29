#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    double num;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &num);
        sum += (long long)(num * 1000) * (i + 1) * (n - i);
    }
    printf("%.2lf", sum / 1000.0);
    return 0;
}