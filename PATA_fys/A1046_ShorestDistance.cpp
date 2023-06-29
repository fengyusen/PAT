#include <stdio.h>

int main()
{
    int n, dis[100005] = {0}, i = 0, j = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        int c = 0;
        scanf("%d", &c);
        dis[i] = dis[i - 1] + c;
    }
    int sum = dis[n];
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int dab = a-- > b-- ? dis[a] - dis[b] : dis[b] - dis[a];
        int dba = sum - dab;
        printf("%d\n", dab < dba ? dab : dba);
    }
    return 0;
}