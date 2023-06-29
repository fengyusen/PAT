#include <iostream>
using namespace std;
int a[200010], b[200010];
int main() {
    int na, nb;
    scanf("%d", &na);
    for (int i = 1; i <= na; i++) scanf("%d", &a[i]);
    scanf("%d", &nb);
    for (int i = 1; i <= nb; i++) scanf("%d", &b[i]);
    int pa = 1, pb = 1, target = (na + nb + 1) / 2, ans, cnt = 0;
    while (pa <= na && pb <= nb) {
        ans = a[pa] <= b[pb] ? a[pa++]:b[pb++];
        if(++cnt == target) break;
    }
    if (pa <= na && cnt < target) ans = a[pa + target - cnt -1];
    else if (pb <= nb && cnt < target) ans = b[pb + target - cnt -1];
    printf("%d", ans);
    return 0;
}
