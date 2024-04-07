#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[4][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	queue<pii> q;
	q.push({ 0,0 });
	while (!q.empty())
	{
		auto [x, y] = q.front(); q.pop();
		int move = b[y][x];
		if (move == 0) continue;
		for (int i = 0; i < 2; i++)
		{
			int tx = x + move * (i % 2);
			int ty = y + move * ((i + 1) % 2);
			if (tx >= n || ty >= n) continue;
			if (tx == n - 1 && ty == n - 1)
			{
				cout << "HaruHaru";
				return 0;
			}
			q.push({ tx,ty });
		}
	}
	cout << "Hing";

	return 0;
}