#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

pair<ll,ll> pw[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++)
	{
		ll p, w;
		cin >> p >> w;
		pw[i] = { p, w };
	}

	sort(pw, pw + n, [](auto a, auto b) 
		{
			if (a.second == b.second)
				return a.first < b.first;
			return a.second < b.second;
		});

	ll notEatDay = max(0LL, t - n); // 안먹는날

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [p, w] = pw[i];
		ans += p + w * (notEatDay + i);
	}
	cout << ans;
	


	return 0;
}