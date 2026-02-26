#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int dp[15][30][30]; // 원점을 15,15로
int dx[6] = {-1,0,1,1,0,-1};
int dy[6] = {0,-1,-1,0,1,1};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	dp[0][15][15] = 1;

	for (int i = 1; i <= 14; i++)
	{
		for (int y = 0; y < 30; y++)
		{
			for (int x = 0; x < 30; x++)
			{
				for (int j = 0; j < 6; j++)
				{
					dp[i][x][y] += dp[i - 1][x + dx[j]][y + dy[j]];
				}
			}
		}
	}

	while (t--)
	{
		int n;
		cin >> n;

		cout << dp[n][15][15] << '\n';
	}

	return 0;
}