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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	map<int, pii>minrc;
	map<int, pii>maxrc;

	int r, c;
	cin >> r >> c;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, v, h;
		cin >> a >> v >> h;
		if (minrc.find(a) == minrc.end())
		{
			minrc[a] = { INF, INF };
		}
		minrc[a].first = min(minrc[a].first, v);
		minrc[a].second = min(minrc[a].second, h);

		maxrc[a].first = max(maxrc[a].first, v);
		maxrc[a].second = max(maxrc[a].second, h);
	}

	ll ans = 0;
	ll num = 0;
	for (auto [x, pii] : minrc)
	{
		ll h = maxrc[x].first - minrc[x].first + 1;
		ll w = maxrc[x].second - minrc[x].second + 1;
		if (h * w > ans)
		{
			ans = h * w;
			num = x;
		}
	}
	cout << num << ' ' << ans;


	return 0;
}