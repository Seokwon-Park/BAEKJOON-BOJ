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

	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { x,y };
	}
	sort(v.begin(), v.end());

	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + n / 2 - 1; j < n; j++)
		{
			int w = v[j].first - v[i].first + 2;

			vector<int> ylist;
			for (int k = i; k <= j; k++)
			{
				ylist.push_back(v[k].second);
			}
			sort(ylist.begin(), ylist.end());


			for (int k = 0; k <= ylist.size() - n / 2; k++)
			{
				int h = ylist[k + n / 2 - 1] - ylist[k] + 2;

				ans = min(ans, w * h);
			}
		}
	}
	cout << ans;

	return 0;
}