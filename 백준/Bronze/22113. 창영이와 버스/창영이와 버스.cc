#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int se[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n ,m;
	cin >> n >> m;

	vector<int> v(m);
	for (auto& i : v)
	{
		cin >> i;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> se[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < m - 1; i++)
	{
		ans += se[v[i]][v[i + 1]];
	}
	cout << ans;

	
	
	return 0;
}



