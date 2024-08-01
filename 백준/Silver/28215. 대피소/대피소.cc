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
	
	int n, k;
	cin >> n >> k;
	vector<pii> house(n);
	vector<int> comb(n, 0);
	fill(comb.begin(), comb.begin() + k, 1);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		house[i] = { x,y };
	}

	if (n == k)
	{
		cout << 0;
		return 0;
	}
	int ans = INF;
	do
	{
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if (comb[i] == 1)
			{
				v.push_back(i);
			}
		}

		vector<int> ds;
		for (int i = 0; i < n; i++)
		{
			if (comb[i] == 0)
			{
				int dist = INF;
				for (int j = 0; j < v.size(); j++)
				{
					auto [hx, hy] = house[i];
					auto [tx, ty] = house[v[j]];
					int tmp = abs(tx - hx) + abs(ty - hy);
					dist = min(dist, tmp);
				}
				ds.push_back(dist);
			}
		}
		int mx = *max_element(ds.begin(), ds.end());
		ans = min(ans, mx);
	} while (prev_permutation(comb.begin(), comb.end()));
	cout << ans;
	
	

	return 0;
}