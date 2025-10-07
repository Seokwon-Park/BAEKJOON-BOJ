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

	ll n;
	cin >> n;
	if (n == (ll)sqrt(n) * (ll)sqrt(n))
	{
		cout << -1;
		return 0;
	}

	int ans = 0;
	for (ll a = 1; a * a <= n / 2; a++)
	{
		ll a2 = a * a;
		ll b = (ll)sqrt(n - a2);
		if (b * b == n - a2)
		{
			ans++;
		}
	}

	for (ll i = 1; i * i < n; i++)
	{
		if (n % i == 0)
		{
			if (i % 2 == (n / i) % 2)
			{
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}