#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> p(55, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool isDiffGroup(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (a < b) p[b] = a;
	else p[a] = b;
	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<tiii> edges;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			int dist;
			if (c >= 'a' && c <= 'z')
				dist = c - 'a' + 1;
			else if (c >= 'A' && c <= 'Z')
				dist = c - 'A' + 27;
			else
				dist = 0;
			if (dist != 0)
			{
				edges.push_back(tie(dist, i, j));
				total += dist;
			}
		}
	}

	sort(edges.begin(), edges.end());

	int cnt = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int u, v, cost;
		tie(cost, u, v) = edges[i];
		if (isDiffGroup(u, v))
		{
			total -= cost;
			cnt++;
		}

		if (cnt == n - 1)
			break;
	}

	if (cnt == n - 1)
	{
		cout << total;
	}
	else
	{
		cout << -1;
	}

	return 0;
}

