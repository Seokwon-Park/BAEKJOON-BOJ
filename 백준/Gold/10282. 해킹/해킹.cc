#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int dist[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while(tc--)
	{
		int n, d, c;
		cin >> n >> d >> c;
		fill(dist, dist + n + 1, 0x3f3f3f3f);
		vector<pii> adj[10005];
		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].push_back({ s, a });
		}

		priority_queue<pii, vector<pii>, greater<pii>> pq;
		dist[c] = 0;
		pq.push({ dist[c], c });
		while (!pq.empty())
		{
			auto [cost, u] = pq.top();
			pq.pop();
			if (cost != dist[u]) continue;
			for (auto [nxtc, v] : adj[u])
			{
				if(cost + nxtc < dist[v])
				{
					dist[v] = cost + nxtc;
					pq.push({ dist[v] , v });
				}
			} 
		}

		cout << count_if(dist + 1, dist + n + 1, [](const int& a)
			{ return a < 0x3f3f3f3f; }) << ' ';
		int t= 0;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] != 0x3f3f3f3f)
				t= max(t, dist[i]);
		}
		cout << t;
		cout << '\n';
	}

	return 0;
}