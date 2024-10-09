#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

unordered_map<string, vector<ll>> um;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ll pigmax = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		ll m;
		cin >> s >> m;
		if (s == "pig")
		{
			pigmax = max(pigmax, m);
		}
		else
		{
			um[s].push_back(m);
		}
	}

	ll ans = pigmax;
	for (auto [name, influ] : um)
	{
		for (int i : influ)
		{
			if (i < pigmax)
			{
				ans += i;
			}
		}
	}
	cout << ans;
	
	return 0;
}
