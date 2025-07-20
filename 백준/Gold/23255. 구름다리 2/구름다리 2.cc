#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

vector<int> adj[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> ans(n + 1, -1);
	ans[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		vector<bool> used(n + 1, 0);
		for (int j : adj[i])
		{
			if (ans[j] == -1) continue;
			used[ans[j]] = true;
		}
		int st = 1;
		while (used[st])
		{
			st++;
		}
		ans[i] = st;
	}

	for(int i = 1; i<= n;i ++)
	{
		cout << ans[i] << ' ';
	}


	return 0;
}