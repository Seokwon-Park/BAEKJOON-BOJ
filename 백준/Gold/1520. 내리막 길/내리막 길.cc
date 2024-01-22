#include <bits/stdc++.h>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int board[505][505];
int dp[505][505]; // 이 좌표로 내려오는 방법의 수
int m, n;

int dfs(int x, int y)
{
	if (x == n - 1 && y == m - 1)
		return 1;
	if (dp[y][x] != -1) // 만약 이미 탐색한 길이면
	{
		return dp[y][x]; // 이 길에서부터 도착지점까지 가는 경우의 수이므로 이미 기록된 값을 돌려준다.
	}
	dp[y][x] = 0; // 만약 여기서 더이상 진행할 수 없으면 도착점으로 가는 방법이 없다는 뜻이므로 0이 됨( -1은 아직 탐색 안함)
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
		if (board[ty][tx] >= board[y][x]) continue; //만약 다음 방향이 더 높은 위치면 진행할 수 없음
		// 더 낮은 수로 내려오기 때문에 이전 경로로는 돌아가지 않음. visited가 필요하지 않음.
		dp[y][x] += dfs(tx, ty);

	}
	return dp[y][x];
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	int answer = dfs(0, 0);
	cout << answer;

	return 0;
}