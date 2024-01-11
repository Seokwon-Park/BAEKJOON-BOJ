#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[100005];
bool chk[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n , m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	priority_queue<int> paths;

	priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

	int cnt = 0;
	int answer = 0;
	chk[1] = true;
	for (auto [cost, v] : adj[1])
	{
		pq.push({ cost,1,v });
	}
	while(cnt < n-1)
	{
		int u, v, cost;
		tie(cost, u, v) = pq.top();
		pq.pop();
		if (chk[v]) continue;
		chk[v] = true;
		paths.push(cost);
		answer += cost;
		cnt++;
		for (auto [nxtc, nxt] : adj[v])
		{
			if (!chk[nxt]) 
				pq.push({ nxtc,v,nxt });
		}
	}

	cout << answer-paths.top();

	return 0;
}