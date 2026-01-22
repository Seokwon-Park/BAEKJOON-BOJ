#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using hashmap = unordered_map<key, value>;

string func(string s)
{
	string ret = "";
	for (auto c : s)
	{
		switch (c)
		{
		case 'R':
			ret += 'S';
			break;
		case 'S':
			ret += 'P';
			break;
		case 'P':
			ret += 'R';
			break;
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<map<string, int>> v(m+1);
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= s.size(); j++)
		{
			string sub = s.substr(0, j);
			v[j][sub]++;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (auto [a, b] : v[i])
		{
			if (b <= k)
			{
				cout << a.size() << '\n' << func(a);
				return 0;
			}
		}
	}
	cout << -1;

	return 0;
}