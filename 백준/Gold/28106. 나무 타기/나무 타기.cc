#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 998244353;

int p[2005]; // 부모노드
int a[2005]; // 점프 가능한 거리
int d[2005]; // 루트노드로 부터 거리
ll dp[2005]; // dp
vector<int> child[2005]; // 자식노드 배열
int root = -1;

ll DP(int k)
{
	// 해당 노드의 dp값이 있으면 그냥 리턴
	if (dp[k] != -1)
		return dp[k];
	// 없으면 해당노드의 부모노드와의 거리를 계산해서
	// k노드까지 뛸수있는 부모노드들의 dp값을 더하기
	ll res = 0;
	for (int i = p[k]; i != 0; i = p[i])
	{
		if (d[k] - d[i] <= a[i])
		{
			res += DP(i);
			res %= MOD;
		}
	}
	return dp[k] = res;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	fill(dp, dp + 2005, -1);
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		if (p[i] != 0)
		{
			child[p[i]].push_back(i);
		}
		else
		{
			dp[i] = 1;
			root = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int dist = 0;
		for (int j = p[i]; j != 0; j = p[j])
		{
			dist++;
		}
		d[i] = dist;
	}



	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (child[i].empty())
		{
			ans += DP(i);
			ans %= MOD;
		}
	}
	cout << ans;


	return 0;
}

