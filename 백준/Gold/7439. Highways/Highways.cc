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

pii v[800];

vector<int> p(800, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool tryUnion(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;
	p[a] = b;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	int cnt = 0;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (tryUnion(u, v))
		{
			cnt++;
		}
	}

	vector<tiii> edges;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			auto [x1, y1] = v[i];
			auto [x2, y2] = v[j];

			int xg = x1 - x2;
			int yg = y1 - y2;
			int cost = xg * xg + yg * yg;
			edges.push_back(tie(cost, i, j));
		}
	}

	sort(edges.begin(), edges.end());

	for (auto [cost, u, v] : edges)
	{
		if (tryUnion(u, v))
		{
			cout << u << ' ' << v << '\n';
		}
	}

	return 0;
}