#include <bits/stdc++.h>
using namespace std;

long long int a1, b1, a2, b2;

void simply(long long int a, long long int b)
{
    if (b == 0)
    {
        printf("Inf");
        return;
    }
    if (a == 0)
    {
        printf("0");
        return;
    }
    int flag1 = 0,flag2=0;
    if (a < 0)
    {
        flag1 = 1;
        a = -a;
    }
    if (b < 0)
    {
        flag2 = 1;
        b = -b;
    }
    int flag=flag1^flag2;
    long long int k = a / b;
    a = a % b;
    if (a > 0)
    {
        long long int a0 = a, b0 = b;
        while (b0 % a0 != 0)
        {
            long long int temp = b0;
            b0 = a0;
            a0 = temp % a0;
        }
        a = a / a0, b = b / a0;
    }
    if (flag)
        printf("(-");
    if (k > 0)
        printf("%lld", k);
    if (k > 0 && a > 0)
        printf(" ");
    if (a > 0)
        printf("%lld/%lld", a, b);
    if (flag)
        printf(")");
}

void add()
{
    simply(a1, b1);
    cout << " + ";
    simply(a2, b2);
    cout << " = ";
    simply(a1 * b2 + a2 * b1, b1 * b2);
    cout << endl;
}

void sub()
{
    simply(a1, b1);
    cout << " - ";
    simply(a2, b2);
    cout << " = ";
    simply(a1 * b2 - a2 * b1, b1 * b2);
    cout << endl;
}
void mul()
{
    simply(a1, b1);
    cout << " * ";
    simply(a2, b2);
    cout << " = ";
    simply(a1 * a2, b1 * b2);
    cout << endl;
}
void div()
{
    simply(a1, b1);
    cout << " / ";
    simply(a2, b2);
    cout << " = ";
    simply(a1 * b2, b1 * a2);
    cout << endl;
}

int main()
{
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    add();
    sub();
    mul();
    div();
    return 0;
}