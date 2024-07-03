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

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(m, vector<int>(n));
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> v[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = i+1; j < m; j++)
		{
			for (int k = j+1; k < m;k++)
			{
				int tmp = 0;
				for (int x = 0; x < n; x++)
				{
					tmp += max({ v[i][x], v[j][x] , v[k][x] });
				}
				ans = max(tmp, ans);
			}
		}
	}
	cout << ans;

	return 0;
}