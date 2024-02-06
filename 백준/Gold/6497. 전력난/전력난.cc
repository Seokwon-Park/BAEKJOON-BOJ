#include <bits/stdc++.h>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		int n, m;
		cin >> n >> m;

		vector<vector<pair<int, int>>> adj(n); // v, cost;
		vector<bool> chk(n, false);

		if (n == 0 && m == 0)
		{
			break;
		}

		int tot = 0;
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			tot += z;
			adj[x].push_back({ y, z });
			adj[y].push_back({ x, z });
		}

		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

		for (auto [nxt, nxtc] : adj[0])
		{
			pq.push({ nxtc, 0, nxt });
		}
		chk[0] = true;
		int cnt = 0;
		int mst = 0;
		while (cnt < n - 1)
		{
			int a, b, cost;
			tie(cost, a, b) = pq.top(); pq.pop();
			if (chk[b]) continue;
			mst += cost;
			cnt++;
			chk[b] = true;
			for (auto [nxt, nxtc] : adj[b])
			{
				if (!chk[nxt])
					pq.push({ nxtc, b, nxt });
			}

		}

		//cout << mst;
		cout << tot - mst << '\n';
	}

	return 0;
}
