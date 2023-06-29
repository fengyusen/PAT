#include <iostream>
#include <string>
using namespace std;
string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
    string str[4];
    int w = -1, d, h;
    for(int i = 0; i < 4; i++) cin >> str[i];
    int n = min(str[0].length(), str[1].length());
    for (int i = 0; i < n; i++) {
        if (str[0][i] >= 'A' && str[0][i] <= 'G' && str[0][i] == str[1][i] && w == -1) {
            w = str[0][i] - 'A';
            //continue;
        } else if ((isdigit(str[0][i]) || str[0][i] >= 'A' && str[0][i] <= 'N') && str[0][i] == str[1][i] && w != -1) {
            if (isdigit(str[0][i])) d = str[0][i] - '0';
            else d = 10 + str[0][i] - 'A';
            break;
        }
    }
    n = min(str[2].length(), str[3].length());
    for (int i = 0; i < n; i++) {
        if (isalpha(str[2][i]) && str[2][i] == str[3][i]) {
            h = i;
            break;
        }
    }
    cout << week[w];
    printf(" %02d:%02d", d, h);
    return 0;
}