#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l, r, x;
	cin >> n >> l >> r >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		int res = 0;
		int mn = INF;
		int mx = 0;
		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) != 0)
			{
				res += v[j];
				mx = max(mx, v[j]);
				mn = min(mn, v[j]);
			}
		}
		if (res >= l && res <= r && mx - mn >= x)
			ans++;
	}
	cout << ans;

	return 0;
}

