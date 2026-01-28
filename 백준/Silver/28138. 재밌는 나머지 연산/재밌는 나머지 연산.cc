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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, r;
	cin >> n >> r;

	ll res = n - r;
	ll ans = 0;

	for (ll i = 1; i * i <= res; i++)
	{
		if (res % i == 0)
		{
			if (res / i != i)
			{
				if (res / i > r) ans += res / i;
				if (i > r) ans += i;
			}
			else
			{
				if (i > r) ans += i;
			}
		}
	}
	cout << ans;
	


	return 0;
}