#include <bits/stdc++.h>

using namespace std;

using ll = long long;

char board[105][105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++ )
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'W')
				board[i][j] = 'B';
			else
				board[i][j] = 'W';
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c != board[i][j])
				ans++;
		}
	}

	cout << ans;

	return 0;
}