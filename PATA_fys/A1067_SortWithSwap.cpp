#include <iostream>
using namespace std;
int main() {
    int n, num, cnt = 0, a[100010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        a[num] = i;
    }
    for (int i = 1; i < n; i++) {
        if (i != a[i]) {
            while (a[0] != 0){
                swap(a[0], a[a[0]]);
                cnt++;
            }
            if (i != a[i]) {
                swap(a[0], a[i]);
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}