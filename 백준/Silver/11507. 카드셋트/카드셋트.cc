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

	unordered_map<string, bool> m;
	string s;
	cin >> s;
	vector<int> v(4, 13);
	for (int i = 0; i < s.size(); i += 3)
	{
		string tmp = s.substr(i, 3);
		if (m.find(tmp) == m.end())
		{
			m[tmp] = true;
		}
		else
		{
			cout << "GRESKA";
			return 0;
		}
	}

	for (auto [x, y] : m)
	{
		if (x[0] == 'P')
			v[0]--;
		else if (x[0] == 'K')
			v[1]--;
		else if (x[0] == 'H')
			v[2]--;
		else
			v[3]--;
	}

	for (int i : v)
		cout << i << ' ';


	return 0;
}
