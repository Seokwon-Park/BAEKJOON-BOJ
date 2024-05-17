#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int r, c, t;
int b[55][55];
bool isDust[55][55];
int bupdate[55][55];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<pii> aircleaner; // x , y

void dust()
{
	for (int i = 0; i < r; i++)
	{
		fill(bupdate[i], bupdate[i] + c, 0);
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] != 0 && b[i][j] != -1)
			{
				int dirs = 0;
				for (int k = 0; k < 4; k++)
				{
					int tx = j + dx[k];
					int ty = i + dy[k];
					if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
					if (b[ty][tx] == -1) continue;
					dirs++;
					bupdate[ty][tx] += b[i][j] / 5;
				}
				bupdate[i][j] -= b[i][j] / 5 * dirs;
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			b[i][j] += bupdate[i][j];
		}
	}
}

void cleaner()
{
	// 위쪽 청정기
	auto [ux, uy] = aircleaner[0];
	for (int y = uy - 1; y > 0; y--)
	{
		b[y][0] = b[y - 1][0];
	}
	for (int x = 0; x < c - 1; x++)
	{
		b[0][x] = b[0][x + 1];
	}
	for (int y = 0; y < uy; y++)
	{
		b[y][c - 1] = b[y + 1][c - 1];
	}
	for (int x = c - 1; x > 1; x--)
	{
		b[uy][x] = b[uy][x - 1];
	}
	b[uy][ux + 1] = 0;

	// 아래쪽 청정기
	auto [lx, ly] = aircleaner[1];
	for (int y = ly + 1; y < r - 1; y++)
	{
		b[y][0] = b[y + 1][0];
	}
	for (int x = 0; x < c - 1; x++)
	{
		b[r - 1][x] = b[r - 1][x + 1];
	}
	for (int y = r - 1; y > ly; y--)
	{
		b[y][c - 1] = b[y - 1][c - 1];
	}
	for (int x = c - 1; x > 1; x--)
	{
		b[ly][x] = b[ly][x - 1];
	}
	b[ly][lx + 1] = 0;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == -1)
				aircleaner.push_back({ j, i }); // x, y
		}
	}

	for (int i = 0; i < t; i++)
	{
		dust();
		cleaner();
		//for (int i = 0; i < r; i++)
		//{
		//	for (int j = 0; j < c; j++)
		//	{
		//		cout << b[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
	}

	int ans = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] == -1) continue;
			ans += b[i][j];
		}
	}

	cout << ans;


	return 0;
}