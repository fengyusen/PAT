#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    cin >> a;
    int index = 3;
    while(a[index] != 'E') index++;
    b += a[1] + a.substr(3, index - 3);
    int e = stoi(a.substr(index + 1));
    if (a[0] == '-') cout << '-';
    if (e < 0) {
        string z(-e - 1, '0');
        cout << "0." << z << b << endl;
    } else if (e < b.size() - 1) {
        cout << b.substr(0, e + 1) << "." << b.substr(e + 1) << endl;
    } else {
        string z(e - b.size() + 1, '0');
        cout << b << z << endl;
    }
    return 0;
}