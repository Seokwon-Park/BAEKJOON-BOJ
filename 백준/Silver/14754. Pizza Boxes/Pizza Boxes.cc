#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll b[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		int j = max_element(b[i], b[i] + m) - b[i];
		v.push_back({ i, j });
	}

	for (int j = 0; j < m; j++)
	{
		ll mx = -1;
		int r = 0;
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			if (mx < b[i][j])
			{
				mx = b[i][j];
				r = i;
				c = j;
			}
		}
		v.push_back({ r, c });
	}

	for (auto [r, c] : v)
	{
		b[r][c] = 0;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans += b[i][j];
		}
	}

	cout << ans;

	return 0;
}