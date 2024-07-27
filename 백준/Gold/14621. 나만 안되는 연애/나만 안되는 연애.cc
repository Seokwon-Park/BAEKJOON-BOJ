#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

char mw[1005];
int n, m;
vector<int> p(1005, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool isSameGroup(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return true;
	else return false;
}

void union_(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (p[a] < p[b]) p[a] = b;
	else p[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> mw[i];
	}

	vector<tiii> edges;
	for (int i = 0; i < m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		edges.push_back(tie(d, u, v));
	}

	sort(edges.begin(), edges.end());

	int ans = 0;
	int connected = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v, d;
		tie(d, u, v) = edges[i];
		if (mw[u] != mw[v] && !isSameGroup(u, v))
		{
			union_(u, v);
			ans += d;
			connected++;
		}
		if (connected == n - 1)
		{
			cout << ans;
			return 0;
		}
	}

	cout << -1;
	return 0;
}