#include <bits/stdc++.h>

using namespace std;
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 0;
int max_a = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{	
			if (vis[i][j] == 1 || board[i][j] == 0) continue;
			cnt++;
			stack<pair<int, int>> s;
			vis[i][j] = 1;
			s.push({ i,j });			
			int area = 0;
			while (!s.empty())
			{
				area++;
				pair<int, int> cursor = s.top();
				s.pop();
				for (int k = 0; k < 4; k++)
				{
					int tx = cursor.first + dx[k];
					int ty = cursor.second + dy[k];
					if (tx < 0 || tx >= n || ty < 0 || ty >= m ) continue;
					if (vis[tx][ty] == 1 || board[tx][ty] != 1)continue;
					vis[tx][ty] = 1;
					s.push({ tx,ty });
				}
			}
			max_a = max(max_a, area);
		}
	cout << cnt << '\n' << max_a;
}
