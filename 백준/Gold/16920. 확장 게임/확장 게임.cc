#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

char board[1005][1005];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, m, pmx;
int players[10];
queue<pair<int, int>> q[10];
int fields[10];
int leftfield = 0;



void bfs()
{
	int p = 1;
	while (leftfield)
	{
		for (int i = 0; !q[p].empty() && i < players[p]; i++)
		{
			int qs = q[p].size();
			for(int j = 0; j< qs; j++)
			{
				auto [x, y] = q[p].front(); q[p].pop();
				for (int k = 0; k < 4; k++)
				{
					int tx = x + dx[k];
					int ty = y + dy[k];
					if (tx < 0 || ty < 0 || tx >= m || ty >= n)continue;
					if (board[ty][tx] != '.') continue;
					board[ty][tx] = p + '0';
					leftfield--;
					fields[p]++;
					q[p].push({ tx, ty });
				}
			}
		}
		//cout << '\n';
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << board[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
		bool canExtend = false;
		for (int i = 1; i <= pmx; i++)
		{
			if (!q[i].empty())
			{
				canExtend = true;
			}
		}
		if (!canExtend) break;

		p = p + 1 > pmx ? 1 : p + 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> pmx;
	
	for (int i = 1; i <= pmx; i++)
	{
		cin >> players[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char input;
			cin >> input;
			board[i][j] = input;
			if (isdigit(input))
			{
				q[input - '0'].push({ j,i });
				fields[input - '0']++;
			}
			else if(input == '.')
			{
				leftfield++;
			}
		}
	}

	bfs();

	for (int i = 1; i <= pmx; i++)
	{
		cout << fields[i] << ' ';
	}



	return 0;
}