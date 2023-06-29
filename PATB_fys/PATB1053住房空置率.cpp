#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, D, numa = 0, numb = 0;
    double e;
    cin >> N >> e >> D;
    for (int i = 0; i < N; i++)
    {
        int K, daya = 0;
        double ei;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> ei;
            if (ei < e)
                daya++;
        }
        if (daya * 2 > K && K > D)
        {
            numb++;
        }
        else if (daya * 2 > K && K <= D)
        {
            numa++;
        }
    }
    printf("%.1f%% %.1f%%", numa * 100.0 / N, numb * 100.0 / N);
    return 0;
}