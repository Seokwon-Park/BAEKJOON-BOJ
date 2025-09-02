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

	int n, m;
	cin >> n >> m;
	
	int ans = n;
	if (m > 0)
	{
		vector<pii> v(m);
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			v[i] = { x,y };
		}

		sort(v.begin(), v.end());

		vector<pii> remove;
		int st = v[0].first;
		int en = v[0].second;
		for (int i = 1; i < m; i++)
		{
			auto [x, y] = v[i];
			if (en < x)
			{
				remove.push_back({ st,en });
				st = x;
				en = y;
			}
			else
			{
				en = max(en, y);
			}
		}
		remove.push_back({ st,en });


		for (int i = 0; i < remove.size(); i++)
		{
			auto [x, y] = remove[i];
			ans -= y - x;
		}
	}

	cout << ans;


	return 0;
}