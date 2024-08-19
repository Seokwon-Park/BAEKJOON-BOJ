#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].second;
	}

	sort(v.begin(), v.end(), [](auto a, auto b)
		{
			if (a.second == b.second)
				return a.first < b.first;
			return a.second < b.second;
		});

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += v[i].first + v[i].second * i;
	}

	cout << ans;
	

	return 0;
}
