#include <bits/stdc++.h>

using namespace std;

int n, m, k;
char board[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

unordered_map<string, int> um;
string str;

void dfs(int x, int y, int depth)
{
	if (board[y][x] != str[depth]) return;
	if (depth + 1 == str.length())
	{
		um[str]++;
		return;
	}

	for (int i = 0; i < 8; i++)
	{
		int tx = x + dx[i];
		if (tx < 0 || tx >= m) tx = (tx + m) % m;
		int ty = y + dy[i];
		if (ty < 0 || ty >= n) ty = (ty + n) % n;
		char c = board[ty][tx];
		if (c != str[depth + 1]) continue;
		dfs(tx, ty, depth + 1);

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c;
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> str;
		if (um.find(str) == um.end())
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					dfs(j, i, 0);
				}
			}
		cout << um[str] << '\n';
	}

	return 0;
}