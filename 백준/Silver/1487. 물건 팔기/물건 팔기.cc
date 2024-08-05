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
		int p, d;
		cin >> p >> d;
		v[i] = make_pair(p, d);
	}
	sort(v.begin(), v.end());

	int ans = 0;
	int maxEarn = 0;
	for (int i = 0; i < n; i++)
	{
		int price = v[i].first;
		int earn = 0;
		for (int j = 0; j < n; j++)
		{
			if (price <= v[j].first && price - v[j].second >= 0)
			{
				earn += price - v[j].second;
			}
		}
		if (earn > 0 && maxEarn< earn)
		{
			maxEarn = earn;
			ans = price;
		}
	}
	cout << ans;

	return 0;
}