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
		ll n, m;
		cin >> n >> m;
		ll nsum = 0;
		ll msum = 0;
	
		vector<ll> nv(n);
		vector<ll> mv(m);
		for (int i = 0; i < n; i++)
		{
			cin >> nv[i];
			nsum += nv[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> mv[i];
			msum += mv[i];
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (nv[i] * n < nsum && nv[i] *m  >msum)
			{
				ans++;
			}
		}
		cout << ans;
		cout << '\n';
	}

	return 0;
}