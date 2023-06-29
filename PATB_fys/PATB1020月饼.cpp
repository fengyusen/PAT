#include <bits/stdc++.h>
using namespace std;

struct mooncake
{
    float store;
    float price;
    float mount;
};

bool cmp(struct mooncake a, struct mooncake b)
{
    return a.mount > b.mount;
};

int main()
{
    int N, D;
    cin >> N >> D;
    vector<struct mooncake> moon(N);
    for (int i = 0; i < N; i++)
    {
        cin >> moon[i].store;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> moon[i].price;
    }
    for (int i = 0; i < N; i++)
    {
        moon[i].mount = moon[i].price / moon[i].store;
    }
    sort(moon.begin(), moon.end(), cmp);
    int sum = 0;
    float price = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (D - sum >= moon[i].store)
        {
            sum += moon[i].store;
            price += moon[i].price;
        }
        else
        {
            price += (moon[i].mount * (D - sum));
            break;
        }
    }
    printf("%.2f", price);
    return 0;
}