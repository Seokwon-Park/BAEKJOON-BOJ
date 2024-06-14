#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n, m;
int dp[10][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m;
		vector<int> loc(n);
		for (int i = 1; i <= n; i++)
		{
			loc[i - 1] = i;
			fill(dp[i], dp[i] + n + 1, 0);
		}
		vector<tiii> simsa(m);
		for (int i = 0; i < m; i++)
		{
			int v, a, b;
			cin >> v >> a >> b;
			dp[a][b] += v;
		}

		int ways = 0;
		int mx = 0;
		do
		{
			int score = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = i+1; j < n; j++)
				{
					if (loc[i] < loc[j])
						score += dp[i + 1][j + 1];
					else
						score += dp[j + 1][i + 1];
				}
			}
			if (score > mx)
			{
				mx = score;
				ways = 1;
			}
			else if (score == mx)
			{
				ways++;
			}
		} while (next_permutation(loc.begin(), loc.end()));

		cout << mx << ' ' << ways << '\n';
	}

	return 0;
}