#include <iostream>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
bool visit[10010] = {false};
int ranked[10010] = {0};
int main() {
    int n, id, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> id;
        ranked[id] = i;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> id;
        printf("%04d: ", id);
        if (ranked[id] == 0) printf("Are you kidding?\n");
        else if (visit[id] == true) printf("Checked\n");
        else if (ranked[id] == 1) printf("Mystery Award\n");
        else if (isPrime(ranked[id])) printf("Minion\n");
        else printf("Chocolate\n");
        visit[id] = true;
    }
    return 0;
}