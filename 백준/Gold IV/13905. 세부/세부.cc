#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

vector<int> p(100005, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_same_group(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return true;
	return false;
}

void uni(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, s, e;
	cin >> n >> m >> s >> e;

	vector<tuple<int, int, int>> edges(m);
	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edges[i] = tie(cost, a, b);
	}

	sort(edges.begin(), edges.end(), greater<tuple<int,int,int>>());

	int ans = 0;
	vector<int> costs;
	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		tie(cost, a, b) = edges[i];
		uni(a, b);// 둘을 합친다.
		costs.push_back(cost);
		if (is_same_group(s, e))
		{
			cout << *min_element(costs.begin(), costs.end());
			return 0;
		}
	}
	
	cout << 0;
	return 0;
}
