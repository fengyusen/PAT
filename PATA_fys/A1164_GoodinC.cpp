#include <bits/stdc++.h>
using namespace std;

int main()
{
	string zimu[26][7];
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cin >> zimu[i][j];
		}
	}
	string s;
	getchar();
	getline(cin, s);
	vector<vector<int>> v;
	vector<int> w;
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
			w.push_back(s[i]-'A');
		else
		{
			if (!w.empty())
			{
				v.push_back(w);
				w.clear();
			}
		}
	}
	if (!w.empty())
		v.push_back(w);
	for(int i=0;i<v.size();i++){
		if(i!=0)cout<<endl;
		for (int j = 0; j < 7; j++)
		{
			for (int k = 0; k < v[i].size(); k++)
			{
				if (k != 0)
					cout << " ";
				cout << zimu[v[i][k]][j];
			}
			cout << endl;
		}
	}
	return 0;
}
