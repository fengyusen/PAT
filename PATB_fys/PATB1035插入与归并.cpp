#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N), sortednums(N), insertnums(N), mergenums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> sortednums[i];
    }
    int i, j;
    for (i = 0; i < N - 1 && sortednums[i] <= sortednums[i + 1]; i++)
        ;
    for (j = i + 1; sortednums[j] == nums[j] && j < N; j++)
        ;
    if (j == N)
    {
        cout << "Insertion Sort" << endl;
        sort(begin(nums), begin(nums) + i + 2);
    }
    else
    {
        cout << "Merge Sort" << endl;
        int k = 1, flag = 1;
        while (flag)
        {
            flag = 0;
            for (int i = 0; i < N; i++)
            {
                if (nums[i] != sortednums[i])
                    flag = 1;
            }
            k *= 2;
            for (int j = 0; j < N; j += k)
            {
                sort(begin(nums) + j, begin(nums) + (j + k < N ? j + k : N));
            }
        }
    }
    for (int i = 0; i < nums.size()-1; i++)
    {
        cout << nums[i] << " ";
    }
    cout<<nums[N-1];
    return 0;
}