#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    double R1, P1, R2, P2, R3, P3;
    cin >> R1 >> P1 >> R2 >> P2;
    R3 = R1 * R2 * cos(P1 + P2);
    P3 = R1 * R2 * sin(P1 + P2);
    cin >> R3 >> P3;
    if (R3 > -0.005 && R3 < 0)
        R3 = 0;
    if (P3 > -0.005 && P3 < 0)
        P3 = 0;
    printf("%.2f", R3);
    if (P3 >=0)
        printf("+");
    printf("%.2fi\n", P3);
    return 0;
}