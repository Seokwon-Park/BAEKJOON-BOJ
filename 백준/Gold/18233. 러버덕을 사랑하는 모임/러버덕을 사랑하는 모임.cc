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

	int n, p, e;
	cin >> n >> p >> e;

	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}



	bool isAns = false;
	if (n >= p)
	{
		vector<bool> c(n, 0);
		fill(c.end() - p, c.end(), 1);

		do
		{
			vector<int> ans(n);
			int mn = 0;
			int mx = 0;
			for (int i = 0; i < n; i++)
			{
				if (c[i])
				{
					auto [x, y] = v[i];
					mn += x;
					mx += y;
					ans[i] += x;
				}
			}

			if (mn <= e && mx >= e)
			{
				int left = e - mn;
				for (int i = 0; i < n; i++)
				{
					if (c[i])
					{
						auto [x, y] = v[i];
						if (y - x < left)
						{
							ans[i] = y;
							left -= y - x;
						}
						else
						{
							ans[i] += left;
							left = 0;
						}
					}
					if (left == 0) break;
				}
				for (auto i : ans)
				{
					cout << i << ' ';
				}
				isAns = true;
				break;
			}
		} while (next_permutation(c.begin(), c.end()));
	}

	if (!isAns)
	{
		cout << -1;
	}

	return 0;
}