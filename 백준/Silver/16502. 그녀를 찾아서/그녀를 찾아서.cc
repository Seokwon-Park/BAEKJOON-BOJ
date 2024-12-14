#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

vector<int> adj[4];
double d[4][4];
int n, m;
double ans[4];

void dfs(int depth, int node, double res)
{
	if (depth == n)
	{
		ans[node] += res;
		return;
	}
	for (int nxt : adj[node])
	{
		dfs(depth + 1, nxt, res*d[node][nxt]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		char a, b;
		cin >> a >> b;
		a -= 'A';
		b -= 'A';
		adj[a].push_back(b);
		cin >> d[a][b];
	}

	for (int i = 0; i < 4; i++)
	{
		dfs(0, i, 1);
	}

	double total = 0.0;
	for (int i = 0; i < 4; i++)
	{
		total += ans[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cout << fixed << setprecision(2);
		cout << ans[i]/total *100.0 << '\n';
	}
	return 0;
}
