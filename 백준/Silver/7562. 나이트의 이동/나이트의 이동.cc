#include <bits/stdc++.h>

using namespace std;

bool visited[305][305];
int moved[305][305];

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int l, tx, ty;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty())
	{
		int qx = q.front().first;
		int qy = q.front().second;
		if (qx == tx && qy == ty)
		{
			cout << moved[qy][qx] << '\n';
			return;
		}
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int xx = qx + dx[i];
			int yy = qy + dy[i];

			if (xx < 0 || yy < 0 || xx >= l || yy >= l)continue;
			if (visited[yy][xx]) continue;
			q.push({ xx,yy });
			visited[yy][xx] = true;
			moved[yy][xx] = moved[qy][qx]+1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		cin >> l;
		int sx, sy;
		cin >> sx >> sy;

		cin >> tx >> ty;


		bfs(sx, sy);
		visited[sy][sx] = true;

		for (int i = 0; i < l; i++)
		{
			fill(visited[i], visited[i] + l, false);
			fill(moved[i], moved[i] + l, 0);
		}
	}

	
	return 0;
}
