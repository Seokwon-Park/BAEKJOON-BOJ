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

vector<int> child[100005];
int parent[100005];
pii cost[100005];

ll dp[2][100005];// 0 : w, 1 : b

void func(int node)
 {
	dp[0][node] = cost[node].first;
	dp[1][node] = cost[node].second;
	for (int nxt : child[node])
	{
		func(nxt);
		dp[0][node] += min(dp[0][nxt], dp[1][nxt]);
		dp[1][node] += dp[0][nxt];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < 2; i++)
	{
		fill(dp[i], dp[i] + n, INF);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int p, c;
		cin >> p >> c;
		child[p].push_back(c);
		parent[c] = p;
	}

	for (int i = 0; i < n; i++)
	{
		int w, b;
		cin >> w >> b;
		cost[i] = { w,b };
	}

	func(0);

	cout << min(dp[0][0], dp[1][0]);

	return 0;
}