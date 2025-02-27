#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<ll> a(n), b(m);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		sort(b.begin(), b.end());

		ll result = 0;
		for (int i = 0; i < n; i++)
		{
			int ix = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			if (ix == 0)
			{
				result += b[ix];
			}
			else if (ix == m)
			{
				result += b[ix - 1];
			}
			else
			{
				ll l = a[i] - b[ix - 1];
				ll r = b[ix] - a[i];
				if (l > r)
				{
					result += b[ix];
				}
				else
				{
					result += b[ix - 1];
				}
			}
		}
		cout << result << '\n';
	}

	return 0;
}
