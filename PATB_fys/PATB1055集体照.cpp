#include <bits/stdc++.h>
using namespace std;

struct Person
{
    string name;
    int height;
};

int cmp(struct Person p1, struct Person p2)
{
    if(p1.height==p2.height)
        return p1.name<p2.name;
    return p1.height > p2.height;
}

int main()
{
    int N, K;
    cin >> N >> K;
    struct Person P[N];
    int Height[N];
    for (int i = 0; i < N; i++)
    {
        cin >> P[i].name >> P[i].height;
    }
    sort(P, P + N, cmp);
    int pernum = N / K, endnum = pernum + N % K, p = 0, t = endnum / 2;
    vector<string> team(endnum);
    for (int i = 0; i < endnum; i++)
    {
        t = i % 2 ? t - i : t + i;
        team[t] = P[p++].name;
    }
    for (int i = 0; i < endnum - 1; i++)
    {
        cout << team[i] << " ";
    }
    cout << team.back() << endl;
    for (int j = 0; j < K - 1; j++)
    {
        team.resize(pernum);t=pernum/2;
        for (int i = 0; i < pernum; i++)
        {
            t = i % 2 ? t - i : t + i;
            team[t] = P[p++].name;
        }
        for (int i = 0; i < pernum - 1; i++)
        {
            cout << team[i] << " ";
        }
        cout << team.back() << endl;
    }

    return 0;
}
