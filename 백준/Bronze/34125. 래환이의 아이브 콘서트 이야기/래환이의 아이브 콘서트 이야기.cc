#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

bool b[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> b[i][j];
		}
	}


	int d = INF;
	int rr = -1;
	int cc = -1;
	for (int r = 1; r <= n; r++)
	{
		for (int c = 1; c <= m; c++)
		{
			if (b[r][c]) continue;
			if (r + abs((m + 1) / 2 - c) < d)
			{
				rr = r;
				cc = c;
				d = r + abs((m + 1) / 2 - c);
			}
		}
	}

	if (rr == -1)
	{
		cout << -1;
	}
	else
	{
		cout << rr << ' ' << cc;
	}


	return 0;
}