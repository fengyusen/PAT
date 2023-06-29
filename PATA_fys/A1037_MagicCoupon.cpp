#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int nc, np;
    scanf("%d", &nc);
    vector<int> coupons(nc);
    for (int i = 0; i < nc; i++) scanf("%d", &coupons[i]);
    scanf("%d", &np);
    vector<int> product(np);
    for (int i = 0; i < np; i++) scanf("%d", &product[i]);
    sort(coupons.begin(), coupons.end());
    sort(product.begin(), product.end());
    int money = 0, i = 0, j = 0;
    while (i < nc && j < np && coupons[i] < 0 && product[j] < 0)
        money += coupons[i++] * product[j++];
    i = nc - 1, j = np - 1;
    while (i >= 0 && j >= 0 && coupons[i] > 0 && product[j] > 0)
        money += coupons[i--] * product[j--];
    printf("%d", money);
    return 0;
}