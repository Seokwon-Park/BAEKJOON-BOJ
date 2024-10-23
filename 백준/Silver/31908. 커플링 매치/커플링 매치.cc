#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

unordered_map<string, vector<string>> um;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		if (b == "-")continue;
		um[b].push_back(a);
	}

	vector<vector<string>> ans;
	for (auto p : um)
	{
		if (p.second.size() == 2)
		{
			ans.push_back(p.second);
		}
	}

	cout << ans.size() << '\n';

	for (auto v : ans)
	{
		cout << v[0] << ' ' << v[1] << '\n';
	}

	return 0;
}
