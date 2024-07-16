#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> v(n);
	for(int i = 0; i<n ;i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = make_pair(x, y);
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (v[i].first == v[j].first && v[j].second == v[k].second)
				{
					ans = max(ans, abs(v[i].second - v[j].second) * abs(v[j].first - v[k].first));
				}
			}
		}
	}
	cout << ans;

	return 0;
}
