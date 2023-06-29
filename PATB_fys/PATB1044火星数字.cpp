#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string R[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int N;
    cin >> N;
    string s;
    getchar();
    for (int i = 0; i < N; i++)
    {
        getline(cin,s);
        if (s[0]>'9')
        {
            int t1 = 0, t2 = 0;
            string s1 = s.substr(0, 3), s2;
            if (s.length() > 4)
                s2 = s.substr(4, 3);
            for (int j = 1; j <= 12; j++)
            {
                if (s1 == S[j] || s2 == S[j])
                    t2 = j;
                if (s1 == R[j])
                    t1 = j;
            }
            cout << t1 * 13 + t2<<endl;
        }
        else
        {
            int num = stoi(s);
            if (num / 13)
                cout << R[num / 13];
            if (num / 13 && num % 13)
                cout << " ";
            if (num % 13 || num == 0)
                cout << S[num % 13];
            cout << endl;
        }
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string S[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
//     string R[13]={"","tam","hel","maa","huh","you","kes","hei","elo","syy","lok","mer","jou"};
//     map<string,int> Stable,Rtable;
//     for(int i=0;i<13;i++){
//         Stable[S[i]]=i;
//         Rtable[R[i]]=i*13;
//     }
//     int N;
//     cin>>N;
//     string strs[N];
//     getline(cin,strs[0]);
//     for(int i=0;i<N;i++){
//         getline(cin,strs[i]);
//     }
//     for(int i=0;i<N;i++){
//         if(isalpha(strs[i][0])){
//             // string s1=strs[i].substr(0,3),s2;
//             // if(strs[i].size()>4)s2=strs[i].substr(4,3);
//             // cout<<Rtable[s1.append(" ")]+Stable[s1]+Stable[s2]<<endl;
//             string ten=strs[i].substr(0,3);
//             string one=strs[i].substr(strs[i].size()-3,3);
//             cout<<Rtable[ten]+Stable[one]<<endl;
//         }
//         else{
//             int num=stoi(strs[i]);
//             if(num/13)cout<<R[num/13];
//             if(num/13&&num%13)cout<<" ";
//             if(num%13||num==0)cout<<S[num%13];
//             cout<<endl;
//         }
//     }
//     return 0;
// }