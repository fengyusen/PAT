#include <iostream>
#include <string>
using namespace std;
int main() {
    string num;
    cin >> num;
    int n = num.length(), carry = 0, a;
    int book[10] = {0}, b[22] = {0};
    for (int i = 0; i < n; i++) {
        a = num[n-1-i] - '0';
        book[a]++;
        a = a * 2 + carry;
        b[i] = a % 10;
        carry = a / 10;
        book[b[i]]--;
    }
    bool flag = true;
    for (int i = 0; i < 10; i++) {
        if(book[i] != 0) flag = false;
    }
    if (flag && carry == 0) {
        printf("Yes\n");
    } else printf("No\n");
    if (carry > 0) printf("1");
    for (int i = n-1; i >= 0; i--) {
        printf("%d", b[i]);
    }
    return 0;
}