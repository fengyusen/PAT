#include <iostream>
#include <vector>
using namespace std;
int n, msize, num, h[10010];
bool isPrime (int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void insert(int key) {
    for (int step = 0; step < msize; step++) {
        int index = (key + step * step) % msize;
        if (h[index] == 0) {
            h[index] = 1;
            cout << index % msize;
            return ;
        }
    }
    cout << "-";
}
int main() {
    scanf("%d %d", &msize, &n);
    while (!isPrime(msize)) msize++;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i) cout << " ";
        insert(num);
    }
    return 0;
}