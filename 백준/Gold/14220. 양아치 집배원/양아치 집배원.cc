#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int b[505][505];
int dp[505][505];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> b[i][j];
			dp[i][j] = INF;
		}
	}

	for (int vis = 1; vis < n; vis++)
	{
		for (int s = 1; s<= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				if (s == e || b[s][e] == 0) continue;
				dp[vis][e] = min(dp[vis][e], dp[vis-1][s] + b[s][e]);
			}
		}
	}
	int ans = *min_element(dp[n - 1] + 1, dp[n - 1] + n + 1);
	cout << (ans == INF ? -1 : ans);


	return 0;
}