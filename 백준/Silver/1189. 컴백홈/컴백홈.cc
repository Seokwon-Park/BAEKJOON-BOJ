#include <bits/stdc++.h>

using namespace std;

int m[10][10];
int visited[10][10];
int r, c, k;
int answer = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void DFS(int x, int y, int moved)
{
	if (x == c - 1 && y == 0)
	{
		if (moved == k)
			answer++;
	}
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
		if (m[ty][tx] == 1 || visited[ty][tx] == 1) continue;

		visited[ty][tx] = 1;
		DFS(tx, ty, moved + 1);
		visited[ty][tx] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;

	for (int i = 0; i < r; i++)
	{
		string k;
		cin >> k;
		for (int j = 0; j < c; j++)
		{
			if (k[j] == '.')
			{
				m[i][j] = 0;
			}
			else
			{
				m[i][j] = 1;
			}
		}
	}

	visited[r-1][0] = 1;
	DFS(0, r-1, 1);
	cout << answer;

	return 0;
}