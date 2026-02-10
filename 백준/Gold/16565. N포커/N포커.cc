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
using Hash = unordered_map<key, value>;

int n;
ll c[55][55];

ll ncr(ll n, ll r)
{
	if (c[n][r] != -1) return c[n][r];
	return c[n][r] = (ncr(n - 1, r) + ncr(n - 1, r - 1)) % 10007;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i <= 52; i++)
	{
		fill(c[i], c[i] + 53, -1);
		c[i][0] = 1;
		c[i][i] = 1;
	}
	ll ans = 0;
	for (int i = 1; i <= n / 4; i++)
	{
		if (i % 2)
		{
			ans += ncr(13, i) * ncr(52 - i * 4, n - i * 4);
			ans %= 10007;
		}
		else
		{
			ans -= ncr(13, i) * ncr(52 - i * 4, n - i * 4);
			ans %= 10007;
			if(ans < 0) ans += 10007;
		}
	}

	cout << ans;


	return 0;
}