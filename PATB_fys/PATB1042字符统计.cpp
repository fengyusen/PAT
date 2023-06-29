#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    getline(cin, S);
    int nums[27] = {0}, maxnum = 0, maxc = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (isalpha(S[i]))
        {
            int c = tolower(S[i]) - 'a';
            nums[c]++;
            if (nums[c] == maxnum)
            {
                maxc = min(maxc, c);
                maxnum = nums[c];
            }
            else if (nums[c] >= maxnum)
            {
                maxc = c;
                maxnum = nums[c];
            }
        }
    }
    printf("%c %d",(char)(maxc+'a'),maxnum);
    return 0;
}