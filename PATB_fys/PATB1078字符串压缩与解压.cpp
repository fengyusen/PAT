#include <bits/stdc++.h>
using namespace std;

int main()
{
    char flag;
    cin >> flag;
    string s;
    getchar();
    getline(cin, s);
    if (flag == 'C')
    {
        int i = 0;
        while (i < s.length())
        {
            int num = 1;
            while (s[i] == s[i + 1])
            {
                i++;
                num++;
            }
            if (num > 1)
            {
                cout << num;
            }
            cout << s[i];
            i++;
        }
    }
    else if (flag == 'D')
    {
        int i = 0;
        while (i < s.length())
        {
            if (isdigit(s[i]))
            {
                int j = i;
                i++;
                while (isdigit(s[i]))
                    i++;
                int num = stoi(s.substr(j, i - j));
                while (num--)
                    cout << s[i];
            }
            else
            {
                cout << s[i];
            }
            i++;
        }
    }
    return 0;
}