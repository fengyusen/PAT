#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {return a > b;}
int tag[10000];
int main()
{
    int k;
    cin >> k;
    vector<int> nums(k);
    for (int i = 0; i < k; i++)
    {
        int n = 0;
        cin >> n;
        nums[i] = n;
        while (n != 1)
        {
            if (n % 2 != 0)
                n = 3 * n + 1;
            n = n / 2;
            if (tag[n] == 1)
                break;
            tag[n] = 1;
        }
    }
    int flag = 0;
    sort(nums.begin(),nums.end(),cmp);
    for (int i = 0; i < nums.size(); i++)
    {
        if (tag[nums[i]] != 1)
        {
            if (flag == 1)
                cout << " ";
            cout << nums[i];
            flag = 1;
        }
    }
    return 0;
}