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

	ll n, m, k, x, y;
	cin >> n >> m >> k >> x >> y;

	vector<pair<ll, ll>> v(n);

	for (int i = 0; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	sort(v.begin(), v.end(), [&](const auto& i, const auto& j)
		{
			return i.first * x - i.second * y < j.first * x - j.second * y;
		});

	ll xk = k;
	ll yk = k;
	for (int i = 0; i < m; i++)
	{
		auto [a, b] = v[i];
		xk += a;
		yk -= b;
	}
	cout << xk * x + yk * y;

	return 0;
}