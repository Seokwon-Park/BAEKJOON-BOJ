#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool board[105][105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 4; i++)
	{
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for(int y = ly; y <ry; y++)
			for (int x = lx; x < rx; x++)
			{
				board[y][x] = 1;
			}
	}

	int ans = 0;
	for (int y = 0; y <= 100; y++)
		for (int x = 0; x <= 100; x++)
			if (board[y][x]) ans++;

	cout << ans;

	return 0;
}