#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		map<string, int> pos;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			pos[s] = i;
		}
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			v.push_back(s);
		}

		vector<string> ans(n);
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			int target = pos[v[i]];
			ans[target] = s;
		}

		for (auto s : ans)
			cout << s << ' ';
		cout << '\n';
	}

	return 0;
}