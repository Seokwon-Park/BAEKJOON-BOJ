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

	vector<vector<ll>> rows(n);
	vector<vector<ll>> cols(m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			rows[i].push_back(b[i][j]);
			cols[j].push_back(b[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int j = max_element(rows[i].begin(), rows[i].end()) - rows[i].begin();
		b[i][j] = 0;
	}

	for (int j = 0; j < m; j++)
	{
		int i = max_element(cols[j].begin(), cols[j].end()) - cols[j].begin();
		b[i][j] = 0;
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