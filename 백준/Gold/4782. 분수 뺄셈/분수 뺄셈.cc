#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll b, n;
	while (cin >> b >> n)
	{
		vector<pair<ll, ll>> v;
		if (b == 0 && n == 0)break;

		ll x = 0;
		for (ll d = 1; d <= n && d * d <= b; d++)
		{
			if (n % d == 0 && b % (d * d) == 0)
			{
				x = d;
			}
		}

		ll kmin = n / x;

		for (ll k = -n; b * k * k / (n * n) <= b; k+= kmin)
		{
			if (n + k == 0 || (n + k == n && b - b * k * k / (n * n) == b)) continue;
			if (b * k * k % (n * n) == 0)
			{
				v.push_back({ b - b * k * k / (n * n), n + k });
			}
		}

		sort(v.begin(), v.end(), [](auto& a, auto& b)
			{
				return (double)a.first / a.second < (double)b.first / b.second;
			});

		for (auto [a, b] : v)
		{
			cout << a << '/' << b << ' ';
		}
		cout << '\n';
	}

	return 0;
}