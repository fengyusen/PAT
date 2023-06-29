#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, modified_num = 0;
    cin >> n;
    string name, password;
    vector<string> modified;
    for (int i = 0; i < n; i++) {
        cin >> name >> password;
        bool flag = false;
        for (auto &str : password) {
            switch(str) {
                case '1' : str = '@'; flag = true; break;
                case '0' : str = '%'; flag = true; break;
                case 'l' : str = 'L'; flag = true; break;
                case 'O' : str = 'o'; flag = true; break;
            }
        }
        if (flag == true) {
            modified_num++;
            modified.push_back(name + " " + password);
        }
    }
    if (!modified_num) {
        if (n == 1)
            cout << "There is " << n <<" account and no account is modified" << endl;
        else cout << "There are " << n <<" accounts and no account is modified" << endl;
    } else {
        cout << modified_num << endl;
        for (auto &modi : modified) {
            cout << modi.first << " " << modi.second << endl;
        }
    }
    return 0;
}