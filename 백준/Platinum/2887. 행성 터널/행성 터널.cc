#include <bits/stdc++.h>

using namespace std;

set<int> adj[100005];
bool chk[100005];
vector<tuple<int, int, int, int>> idx_coord; // x, y, z, ix
unordered_map<int, tuple<int, int, int>> hsh; // x, y, z, ix


int get_d(int a, int b)
{
	int xa, ya, za, xb, yb, zb;
	tie(xa, ya, za) = hsh[a];
	tie(xb, yb, zb) = hsh[b];

	return min({ abs(xa - xb), abs(ya - yb), abs(za - zb) });
}


//이건 프림으로 해보자.
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		idx_coord.push_back(tie(x, y, z, i));
		hsh[i] = tie(x, y, z);
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;

	sort(idx_coord.begin(), idx_coord.end(), [](auto& a, auto& b)
		{
			int ax, ay, az, bx, by, bz, ia, ib;
			tie(ax, ay, az, ia) = a;
			tie(bx, by, bz, ib) = b;
			return ax < bx;
		});
	for (int i = 0; i < n - 1; i++)
	{
		int x, y, z, ix;
		int x2, y2, z2, ix2;
		tie(x, y, z, ix) = idx_coord[i];
		tie(x2, y2, z2, ix2) = idx_coord[i + 1];
		adj[ix].insert(ix2);
		adj[ix2].insert(ix);
	}

	sort(idx_coord.begin(), idx_coord.end(), [](auto& a, auto& b)
		{
			int ax, ay, az, bx, by, bz, ia, ib;
			tie(ax, ay, az, ia) = a;
			tie(bx, by, bz, ib) = b;
			return ay < by;
		});
	for (int i = 0; i < n - 1; i++)
	{
		int x, y, z, ix;
		int x2, y2, z2, ix2;
		tie(x, y, z, ix) = idx_coord[i];
		tie(x2, y2, z2, ix2) = idx_coord[i + 1];
		adj[ix].insert(ix2);
		adj[ix2].insert(ix);
	}

	sort(idx_coord.begin(), idx_coord.end(), [](auto& a, auto& b)
		{
			int ax, ay, az, bx, by, bz, ia, ib;
			tie(ax, ay, az, ia) = a;
			tie(bx, by, bz, ib) = b;
			return az < bz;
		});
	for (int i = 0; i < n - 1; i++)
	{
		int x, y, z, ix;
		int x2, y2, z2, ix2;
		tie(x, y, z, ix) = idx_coord[i];
		tie(x2, y2, z2, ix2) = idx_coord[i + 1];
		adj[ix].insert(ix2);
		adj[ix2].insert(ix);
	}


	int diff = 0;
	chk[1] = true;
	for (int nxt : adj[1])
	{
		pq.push({ get_d(1, nxt), 1, nxt });
	}

	int cnt = 0;
	int answer = 0;
	while (cnt < n - 1)
	{
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (chk[b]) continue;
		chk[b] = true;
		cnt++;
		answer += cost;
		diff = 0;
		for (int nxt : adj[b])
		{
			if (chk[nxt]) continue;
			
			pq.push({ get_d(b, nxt), b, nxt });
		}
	}

	cout << answer;


	return 0;
}