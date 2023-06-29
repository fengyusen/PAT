#include <iostream>
#include <vector>
using namespace std;
int d[100010] = {0};
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        d[i] += d[i-1];
    }
    vector<int> ret;
    int minans = d[n], tempans;
    for (int i = 0; i < n; i++) {
        int left = i + 1, right = n  , mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (d[mid] - d[i] >= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        tempans = d[right] - d[i];
        //printf("%d-%d=%d %d\n", i, left, tempans, minans);
        if (tempans >= m && tempans <= minans) {
            if (tempans < minans) {
                //printf("*****\n");
                minans = tempans;
                ret.clear();
            }
            ret.push_back(i+1);
            ret.push_back(left);
        }
    }
    for (int i = 0; i < ret.size(); i += 2) {
        if (i) printf("\n");
        printf("%d-%d", ret[i], ret[i+1]);
    }
    return 0;
}