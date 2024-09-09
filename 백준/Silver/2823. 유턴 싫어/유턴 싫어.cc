#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

char b[10][10];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] == 'X') continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
				if (b[ty][tx] == '.')cnt++;
			}
			if (cnt == 1)
			{
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;

	return 0;
}