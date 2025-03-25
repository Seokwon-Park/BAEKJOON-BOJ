#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

vector<pair<double, int>> adj[200005];
bool visited[200005];
double d[200005];
int n, m;
vector<int> linked;

//1(학교)와 연결되는 간선중 음수인 간선이 있나?
bool isMinus()
{
	queue<int> q;
	q.push(1);
	visited[1] = true;
	bool minus = false;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto [nc, nxt] : adj[cur])
		{
			if (nc < 0)
				minus = true;
			if (visited[nxt]) continue;
			q.push(nxt);
			linked.push_back(nxt);
			visited[nxt] = true;
		}
	}
	return minus;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		double cost = (a + b) / 2.0;
		adj[u].push_back({ cost, v });
		adj[v].push_back({ cost, u });
	}
	double t;
	cin >> t;

	if (isMinus()) // 음수인 간선이 있으면 1과 연결된 모든 노드가 T이하가 될 수 있음.
	{
		cout << linked.size();
		sort(linked.begin(), linked.end());
		if (linked.size() > 0)
		{
			cout << '\n';
			for (auto i : linked)
				cout << i << ' ';
		}
	}
	else
	{
		fill(d, d + 200005, DBL_MAX);
		priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
		d[1] = 0;
		pq.push({ 0,1 });
		while (!pq.empty())
		{
			auto [cost, cur] = pq.top();
			pq.pop();
			if (cost != d[cur]) continue;
			for (auto [nc, nxt] : adj[cur])
			{
				if (cost + nc < d[nxt])
				{
					d[nxt] = cost + nc;
					pq.push({ cost + nc, nxt });
				}
			}
		}
		vector<int> result;
		// 1은 학교이므로 제외
		for (int i = 2; i <= n; i++)
		{
			if (d[i] <= t)
			{
				result.push_back(i);
			}
		}
		cout << result.size();
		if (result.size() > 0)
		{
			cout << '\n';
			for (auto i : result)
			{
				cout << i << ' ';
			}
		}
	}


	return 0;
}