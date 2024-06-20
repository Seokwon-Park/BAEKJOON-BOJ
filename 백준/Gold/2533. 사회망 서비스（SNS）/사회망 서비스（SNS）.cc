// 풀이 참고해서 품
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<int> adj[1000005];
vector<int> tree[1000005];
int dp[1000005][2]; // cur을 root로 하는 서브 트리 EA일때, EA가 아닐때의 EarlyAdaptor 수

void make_tree(int cur, int parent)
{
	for (int nxt : adj[cur])
	{
		if (nxt == parent) continue;
		tree[cur].push_back(nxt);
		make_tree(nxt, cur);
	}
}

int func(int cur, bool isEA) // cur이 EarlyAdaptor인가 아닌가
{
	if (dp[cur][isEA] != -1)
		return dp[cur][isEA];

	int res = 0;
	if (isEA)
	{
		for (int nxt : tree[cur])
		{
			res += min(func(nxt, false), func(nxt, true));
		}
	}
	else
	{
		for (int nxt : tree[cur])
		{
			res += func(nxt, true);
		}
	}

	return dp[cur][isEA] = res + isEA;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		dp[i + 1][0] = -1;
		dp[i + 1][1] = -1;
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dp[n][0] = -1;
	dp[n][1] = -1;

	make_tree(1, -1);

	cout << min(func(1, 1), func(1, 0));

	return 0;
}
