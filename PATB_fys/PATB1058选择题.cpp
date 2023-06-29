#include <bits/stdc++.h>
using namespace std;
int N, M;
struct MultiSelection
{
    int fullValue;
    int optionNum;
    int correctOptionNum;
    string allCorrectOptions;
    int errorNum = 0;
};

int main()
{
    cin >> N >> M;
    struct MultiSelection MS[M];
    vector<vector<string>> Answer(N, vector<string>(M));
    int Score[N] = {0};
    for (int i = 0; i < M; i++)
    {
        cin >> MS[i].fullValue >> MS[i].optionNum >> MS[i].correctOptionNum;
        getline(cin, MS[i].allCorrectOptions);
        MS[i].allCorrectOptions.erase(0, 1);
    }
    int n = 0, maxError = 0;
    vector<int> errorQuestion;
    for (int i = 0; i < N; i++)
    {
        string s;
        getline(cin, s);
        int j = 0, t = 0;
        while (j < s.length())
        {
            if (s[j] == '(')
            {
                j = j + 1;
                int k = s[j] - '0';
                j = j + 2;
                Answer[n][t] = s.substr(j, 2 * k - 1);
                if (MS[t].allCorrectOptions.compare(Answer[n][t]) != 0)
                {
                    MS[t].errorNum++;
                    if (MS[t].errorNum > maxError)
                    {
                        errorQuestion.clear();
                        maxError = MS[t].errorNum;
                        errorQuestion.push_back(t);
                    }
                    else if (MS[t].errorNum == maxError)
                    {
                        errorQuestion.push_back(t);
                    }
                }
                else
                {
                    Score[n] += MS[t].fullValue;
                }
                j = j + 2 * k - 1;
                t++;
            }
            j = j + 2;
        }
        cout << Score[n] << endl;
        n++;
    }
    if (errorQuestion.size() == 0)
    {
        cout << "Too simple";
        return 0;
    }
    cout << maxError << " ";
    sort(errorQuestion.begin(), errorQuestion.end());
    for (int i = 0; i < errorQuestion.size() - 1; i++)
    {
        cout << errorQuestion[i] + 1 << " ";
    }
    cout << errorQuestion.back() + 1;
    return 0;
}
