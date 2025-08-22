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

int v[305][305];
int dp[305][305];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	memset(v, -1, 305*305*4);
	memset(dp, -1, 305*305*4);
	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) continue; // 서->동 안됨
		v[a][b] = max(v[a][b], c);
	}

	// 1번 도시에서 출발하는 경우만 ㅇㅈ 나머지는 ㄴㄴ
	dp[1][1] = 0;


	// 도시를 i개 방문했을때
	for (int i = 1; i < m; i++)
	{
		// 마지막으로 방문한 도시(점점 커져야 하기 때문에 최소 i번도시임)
		for (int j = i; j <= n; j++)
		{
			if (dp[i][j] == -1)continue;
			// 다음에 방문할 도시 j to k
			for (int k = j+1; k <= n; k++)
			{
				if (v[j][k] == -1) continue; // 항공편이 없으면 다른도시
				dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + v[j][k]);
			}
		}
	}

	int ans = 0;
	//아무튼 i개의 도시를 거쳐서 n에 도달한 케이스중 최댓값
	for (int i = 2; i <= m; i++)
	{
		ans = max(ans, dp[i][n]);
	}

	cout << ans;

	return 0;
}