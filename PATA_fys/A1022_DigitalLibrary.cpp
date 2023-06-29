#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    map<string, vector<string> > library[6];//titles, authors, keywords, publishers, years;
    string id, s, book[6];//id, title, author, keyword, publisher, year;
    int n, m;
    cin >> n;getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, id);
        for (int j = 1; j < 6; j++) {
            if (j == 3) {
                while (cin >> s) {
                    library[j][s].push_back(id);
                    if (getchar() == '\n') break;
                }
            } else {
                getline(cin, s);
                library[j][s].push_back(id);
            }
        }
    }
    cin >> m;getchar();
    for (int i = 0; i < m; i++) {
        getline(cin, s);
        int flag = s[0] - '0';
        s = s.substr(3);
        cout << flag << ": " << s << endl;
        if (library[flag][s].empty()) cout << "Not Found" << endl;
        sort(library[flag][s].begin(), library[flag][s].end());
        for (int j = 0; j < library[flag][s].size(); j++) {
            cout << library[flag][s][j] << endl;
        }
    }
    return 0;
}