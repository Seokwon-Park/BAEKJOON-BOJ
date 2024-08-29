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
	vector<pii> v;

	map<int, int> xline;
	map<int, int> yline;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
		xline[x]++;
		yline[y]++;
	}

	sort(v.begin(), v.end());

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [x, y] = v[i];
		ll ys = xline[x];
		ll xs = yline[y];

		ans += (ys - 1) * (xs - 1);
	}
	cout << ans;

	return 0;
}