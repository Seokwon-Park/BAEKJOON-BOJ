#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int sd[2005];
int gd[2005];
int hd[2005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		fill(sd, sd + 2005, INF);
		fill(gd, gd + 2005, INF);
		fill(hd, hd + 2005, INF);
		int n, m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;
		vector<vector<pii>> adj(2005);
		for (int i = 0; i < m; i++)
		{
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back({ d,b });
			adj[b].push_back({ d,a });
		}

		sd[s] = 0;
	
		priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0,s });
		while (!pq.empty())
		{
			auto [dist, cur] = pq.top();
			pq.pop();
			if (dist != sd[cur]) continue;
			for(auto [nxtd, nxt]: adj[cur])
			{
				if (sd[cur] + nxtd < sd[nxt])
				{
					sd[nxt] = sd[cur] + nxtd;
					pq.push({ sd[nxt], nxt});
				}
			}
		}

		gd[g] = 0;
		pq.push({ 0,g });
		while (!pq.empty())
		{
			auto [dist, cur] = pq.top();
			pq.pop();
			if (dist != gd[cur]) continue;
			for (auto [nxtd, nxt] : adj[cur])
			{
				if (gd[cur] + nxtd < gd[nxt])
				{
					gd[nxt] = gd[cur] + nxtd;
					pq.push({ gd[nxt], nxt });
				}
			}
		}

		hd[h] = 0;
		pq.push({ 0,h });
		while (!pq.empty())
		{
			auto [dist, cur] = pq.top();
			pq.pop();
			if (dist != hd[cur]) continue;
			for (auto [nxtd, nxt] : adj[cur])
			{
				if (hd[cur] + nxtd < hd[nxt])
				{
					hd[nxt] = hd[cur] + nxtd;
					pq.push({ hd[nxt], nxt });
				}
			}
		}

		vector<int> ans;
		for (int i = 0; i < t; i++)
		{
			int target;
			cin >> target;
			int shortest = sd[target];
			int case1 = sd[g] + gd[h] + hd[target];
			int case2 = sd[h] + hd[g] + gd[target];

			if ((shortest == case1) || (shortest == case2))
				ans.push_back(target);
		}

		sort(ans.begin(), ans.end());

		for (auto i : ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}