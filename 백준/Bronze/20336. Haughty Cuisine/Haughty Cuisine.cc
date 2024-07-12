#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<string>> v(n);
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			string s;
			cin >> s;
			v[i].push_back(s);
		}
	}

	cout << v[0].size() << '\n';
	for (auto str : v[0])
		cout << str << '\n';

	return 0;
}
