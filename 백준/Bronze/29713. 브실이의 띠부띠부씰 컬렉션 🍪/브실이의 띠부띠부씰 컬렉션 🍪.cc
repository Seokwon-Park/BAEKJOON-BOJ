#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> v(26);
	for (auto c : s)
	{
		v[c - 'A']++;
	}

	string p = "BRONZESILVER";
	int ix = 0;
	int ans = 0;
	while (true)
	{
		if (v[p[ix]-'A'] > 0)
		{
			v[p[ix]-'A']--;
			ix++;
			if (ix >= p.size())
			{
				ans++;
				ix = 0;
			}
		}
		else
		{
			break;
		}
	}

	cout << ans;


	return 0;
}