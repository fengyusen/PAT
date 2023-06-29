#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int getTest(char *s)
{
    int len = strlen(s);
    int i = 0, a = 0, b = 0, c = 0, type = 0;
    while (s[i] == 'A')
    {
        a++;
        i++;
    }
    if (s[i] == 'P')
    {
        i++;
    }
    else
    {
        return 0;
    }
    while (s[i] == 'A')
    {
        b++;
        i++;
    }
    if (s[i] == 'T')
    {
        i++;
    }
    else
    {
        return 0;
    }
    while (i < len && s[i] == 'A')
    {
        i++;
        c++;
    }
    if (i < len)
    {
        return 0;
    }
    if (b == 1 || (b > 1 && c - b * a >= 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[10];
    for (int i = 0; i < n; i++)
    {
        char s[100];
        scanf("%s", s);
        a[i] = getTest(s);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}