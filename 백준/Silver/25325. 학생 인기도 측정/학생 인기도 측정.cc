#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		m.insert({ s, 0 });
	}

	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);
		istringstream iss(s);
		string tmp;
		while (getline(iss, tmp, ' '))
		{
			m[tmp]++;
		}
	}

	vector<pair<string, int>> mcp(m.begin(), m.end());
	
	sort(mcp.begin(), mcp.end(), [](auto a, auto b)
		{
			if (a.second == b.second)
				return a.first < b.first;
			return a.second > b.second;
		});
	

	for (auto [name, num] : mcp)
	{
		cout << name << ' ' << num << '\n';
	}

	return 0;
}