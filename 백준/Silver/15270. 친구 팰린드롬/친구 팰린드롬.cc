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

vector<int> adj[25];
bool isUsed[25];
int n, m;

int ans = 0;
void func(int x, int cnt)
{
	if (x > n)
	{
		ans = max(ans, cnt);
		return;
	}
	if (isUsed[x])
	{
		func(x + 1, cnt);
		return;
	}

	func(x + 1, cnt);

	for (int nxt : adj[x])
	{
		if (isUsed[nxt]) continue;
		isUsed[x] = true;
		isUsed[nxt] = true;
		func(x + 1, cnt + 2);
		isUsed[x] = false;
		isUsed[nxt] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}

	func(1, 0);

	if (n > ans)
	{
		ans += 1; // 가운데 세우기
	}

	cout << ans;

	return 0;
}