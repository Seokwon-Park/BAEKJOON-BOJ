#include <bits/stdc++.h>

using namespace std;

int dx[4] = { -1, 0, 1,0 };
int dy[4] = { 0, -1, 0,1 };
bool isused[30];

int snum;
int ynum;

char board[10][10];
int res[10][10];
bool visited[10][10];
int answer = 0;

bool bfs(int i)
{
	int x = i % 5;
	int y = i / 5;
	queue<pair<int, int>> q;
	for (int j = 0; j < 5; j++)
		fill(visited[j], visited[j] + 10, false);
	int area = 0;
	q.push({ x,y });
	visited[y][x] = true;
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		area++;
		for (int j = 0; j < 4; j++)
		{
			int tx = curX + dx[j];
			int ty = curY + dy[j];
			if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5) continue;
			if (visited[ty][tx] || res[ty][tx] == 0) continue;
			q.push({ tx,ty });
			visited[ty][tx] = true;
		}
	}
	if (area == 7) return true;
	else return false;
}

void func(int l, int prev)
{
	if (l == 7)
	{
		if (snum >= 4)
		{
			if (bfs(prev))
			{

				//cout << prev / 5 << ' ' << prev % 5 << '\n';
				//for (int i = 0; i < 5; i++)
				//{
				//	for (int j = 0; j < 5; j++)
				//	{
				//		cout << res[i][j];
				//	}
				//	cout << '\n';
				//}

				answer++;
			}
		}
		return;
	}
	for (int i = prev; i < 25; i++)
	{
		if (isused[i]) continue;
		int x = i % 5;
		int y = i / 5;
		// 일단 처음 좌표를 둔다. 0~25

		isused[i] = true;
		if (board[y][x] == 'S')
			snum++;
		else
			ynum++;
		res[y][x] = 1;
		func(l + 1, i);
		res[y][x] = 0;
		if (board[y][x] == 'S')
			snum--;
		else
			ynum--;
		isused[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 5; j++)
		{
			board[i][j] = str[j];
		}
	}

	func(0, 0);

	cout << answer;

	return 0;
}
