#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n), sortnums(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &sortnums[i]);
    int i, j;
    for (i = 0; i < n - 1 && sortnums[i] <= sortnums[i+1]; i++) ;
    for (j = i + 1; j < n && sortnums[j] == nums[j]; j++) ;
    if (j == n) {
        printf("Insertion Sort\n");
        sort(nums.begin(), nums.begin() + i + 2);
    } else {
        printf("Merge Sort\n");
        int k = 1, flag = 1;
        while (flag) {
            flag = 0;
            for (i = 0; i < n; i++)
                if (nums[i] != sortnums[i]) flag = 1;
            k *= 2;
            for (j = 0; j < n; j += k) {
                sort(nums.begin() + j, nums.begin() + (j + k < n ? j + k : n));
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", nums[i]);
    }
    return 0;
}