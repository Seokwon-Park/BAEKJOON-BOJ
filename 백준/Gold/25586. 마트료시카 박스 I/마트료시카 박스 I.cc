#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

vector<int> adj[1005];

void PutBox(int st ,int val)
{
	queue<int> q;
	q.push(st);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (!adj[cur].empty())
		{
			for (int nxt : adj[cur])
			{
				q.push(nxt);
			}
		}
		else
		{
			adj[cur].push_back(val);
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;


	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;
		for (int j = 0; j < c; j++)
		{
			int x;
			cin >> x;
			adj[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		while (adj[i].size() > m)
		{
			int toPut = adj[i].back();
			adj[i].pop_back();
			PutBox(i, toPut);
		}
	}

	cout << 1 << '\n';
	cout << 0 << '\n';
	for (int i = 1; i <= n; i++)
	{
		cout << adj[i].size() << ' ';
		if (!adj[i].empty())
		{
			for (int j : adj[i])
				cout << j << ' ';
		}
		cout << '\n';

	}

	return 0;
}