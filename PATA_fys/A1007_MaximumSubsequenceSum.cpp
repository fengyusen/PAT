#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    int start_index = 0, end_index = k - 1, largest_sum = -1;
    int left = 0, sum = 0;
    vector<int> nums(k);
    for(int i = 0; i < k; i++){
        cin>>nums[i];
        sum += nums[i];
        if(sum < 0){
            sum = 0;
            left = i + 1;
        } else if(largest_sum < sum) {
            largest_sum = sum;
            start_index = left;
            end_index = i;
        }
    }
    if(largest_sum < 0) largest_sum = 0;
    printf("%d %d %d", largest_sum, nums[start_index], nums[end_index]);
    return 0;
}
