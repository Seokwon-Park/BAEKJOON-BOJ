#include <bits/stdc++.h>

using namespace std;
	
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	vector<bitset<1001>> vec(n+1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].set(v);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			 ll res = (vec[i] & vec[j]).count();
			 ans +=  res* (res - 1) / 2;
		}
	}

	cout << ans;

	return 0;
}