#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int n, k;
bool visited[2][500005];

int bfs(int n)
{
	queue<int> q;
	q.push(n);
	int time = 0;
	visited[time % 2][n] = true;
	while (!q.empty())
	{
		int qs = q.size();
		if (k > 500000) return -1;
		if (visited[time % 2][k])
			return time;
		time++;
		for (int i = 0; i < qs; i++)
		{
			int cur = q.front(); q.pop();
			for (int nxt : {cur - 1, cur + 1, cur * 2})
			{
				if (nxt < 0 || nxt> 500000) continue;
				if (visited[time % 2][nxt]) continue;
				visited[time%2][nxt] = true;
				q.push(nxt);
			}
		}
		k += time;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	cout << bfs(n);

	return 0;
}