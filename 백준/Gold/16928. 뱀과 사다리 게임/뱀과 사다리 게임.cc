#include <bits/stdc++.h>

using namespace std;

int sc[105];
bool visited[105];
int dist[105];

int bfs()
{
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int nxt = cur + i;
			if (sc[nxt] != 0)
				nxt = sc[nxt];
			if (visited[nxt]) continue;
			dist[nxt] = dist[cur] + 1;
			if (nxt == 100)
			{
				return dist[nxt];
			}
			visited[nxt] = true;
			q.push(nxt);
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		sc[x] = y;
	}

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		sc[x] = y;
	}
	
	cout << bfs();

	return 0;
}