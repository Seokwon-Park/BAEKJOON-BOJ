#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

vector<ll> p(200005, -1);
vector<ll> urank(200005, 1);
vector<ll> isRoot(200005, 1);

int find(int x)
{
	if (p[x] < 0)return x;
	return p[x] = find(p[x]);
}

void union_(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (urank[a] < urank[b])
	{
		p[a] = b;
		urank[b] += urank[a];
		isRoot[b] = true;
		isRoot[a] = false;
	}
	else
	{
		p[b] = a;
		urank[a] += urank[b];
		isRoot[a] = true;
		isRoot[b] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		union_(u, v);
	}

	ll ans = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!isRoot[i])continue;
		ans *= urank[i];
		ans %= 1000000007;
	}

	cout << ans % 1000000007;

	return 0;
}