
#include <bits/stdc++.h>

using namespace std;

int k, w, h;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, vector<string>> member;
	unordered_map<string, string> group;

	int n, m;
	cin >> n >> m;

	while (n--)
	{
		string g;
		cin >> g;
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			string mem;
			cin >> mem;
			member[g].push_back(mem);
			group[mem] = g;
		}
	}

	while (m--)
	{
		string name;
		int type;
		cin >> name >> type;
		if (type == 0)
		{
			sort(member[name].begin(), member[name].end());
			for (auto str : member[name])
			{
				cout << str << '\n';
			}
		}
		else
		{
			cout << group[name] << '\n';
		}
	}

	

	return 0;
}