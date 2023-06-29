#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    double amounts, prices, value;
};
bool cmp (node a, node b) {return a.value > b.value;}
int main() {
    int n;
    double d, profit = 0.0;
    scanf("%d %lf", &n, &d);
    vector<node> moon(n);
    for (int i = 0; i < n; i++) scanf("%lf", &moon[i].amounts);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &moon[i].prices);
        moon[i].value = moon[i].prices / moon[i].amounts;
    }
    sort(moon.begin(), moon.end(), cmp);
    int i = 0;
    while(d > 0 && i < n) {
        double a = min(d, moon[i].amounts);
        d -= a;
        profit += a * moon[i].value;
        i++;
    }
    printf("%.2lf", profit);
    return 0;
}