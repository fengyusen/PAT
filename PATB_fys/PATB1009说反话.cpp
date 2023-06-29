#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    stack<string> s;
    string line, a;
    getline(cin, line);
    int len = line.size();
    istringstream is(line);
    while (is >> a)
    {
        s.push(a);
    }
    cout << s.top();
    s.pop();
    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }
    return 0;
}
