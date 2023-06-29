#include <iostream>
#include <algorithm>
using namespace std;
int d[100010] = {0};
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    sort(d, d + n);
    // for (int i = 0; i < n; i++) printf("%d ", d[i]);
    // printf("\n");
    for (int i = 0; i < n; i++) {
        int left = i, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int value = d[mid] + d[i];
            //printf("%d %d %d\n", i, mid, value);
            if (value == m){
                printf("%d %d", d[i], d[mid]);
                return 0;
            } else if (value > m) {
                right = mid - 1;
            } else if (value < m) {
                left = mid + 1;
            }
        }
    }
    printf("No Solution");
    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;
// int a[1005];
// int main() {
//     int n, m, value;
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &value);
//         a[value]++;
//     }
//     for (int i = 0; i <= m; i++) {
//         if ((i == m - i) && a[i] >= 2 || (a[i] > 0 && a[m - i] > 0 && i < m - i)) {
//             printf("%d %d", i, m - i);
//             return 0;
//         }
//     }
//     printf("No Solution");
//     return 0;
// }