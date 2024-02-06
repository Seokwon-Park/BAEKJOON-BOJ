#include <bits/stdc++.h>

using namespace std;

vector<int> p(10005, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void union_(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
}


bool isFriend(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return true;
	else return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> fm(n + 1);

	vector<tuple<int, int, int>> edges;
	for (int i = 1; i <= n; i++)
	{
		int fm;
		cin >> fm;
		edges.push_back({ fm, 0, i });
	}

	sort(edges.begin(), edges.end());

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int v, w;
		cin >> v >> w;
		if (!isFriend(v, w))
		{
			union_(v, w);
			cnt++;
		}
	}

	int ans = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int cost, a, b;
		tie(cost, a, b) = edges[i];
		if (isFriend(a, b)) continue;
		union_(a, b);
		ans += cost;
		cnt++;
		if (cnt == n)
		{
			if (ans > k)
			{
				cout << "Oh no";
			}
			else
			{
				cout << ans;
			}
			return 0;
		}
	}

	return 0;
}