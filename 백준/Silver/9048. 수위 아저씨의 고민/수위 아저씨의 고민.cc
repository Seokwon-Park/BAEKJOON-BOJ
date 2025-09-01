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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int f, r, n;
		cin >> f >> r >> n;

		vector<int> v[35];

		for (int i = 1; i <= f; i++)
		{
			v[i].push_back(0);
		}

		for (int i = 0; i < n; i++)
		{
			int y, x;
			cin >> y >> x;
			v[y].push_back(x);
		}

		for (int i = 1; i <= f; i++)
		{
			v[i].push_back(r + 1);
			sort(v[i].begin(), v[i].end());
		}

		int ans = 0;
		for (int y = 1; y <= f; y++)
		{
			//if (v[y].empty()) continue;
			int res = INF;
			for (int i = 0; i < v[y].size() - 1; i++)
			{
				int tmp = (v[y][i] + r + 1 - v[y][i + 1]) * 2;
				res = min(res, tmp);
			}
			int tmp = (v[y][v[y].size()-2] + r + 1 - v[y][v[y].size() - 1]) * 2;
			res = min(res, tmp);
			ans += res;
		}
		ans += f * 2 + r + 1;
		cout << ans << '\n';
	}

	return 0;
}