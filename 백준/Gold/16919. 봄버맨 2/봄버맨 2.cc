#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

char b[205][205];
int timer[205][205];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c, n;
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'O')
			{
				timer[i][j] = 1;
			}
		}
	}

	int repeat = (n - 2) % 4 + 1;
	while (repeat--)
	{
		vector<pii> remove;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (b[i][j] == 'O')
				{
					timer[i][j]++;
				}
				if (b[i][j] != 'O')
				{
					b[i][j] = 'O';
				}
				if (timer[i][j] == 3)
				{
					remove.push_back({ j, i });
				}
			}
		}

		for (auto [x, y] : remove)
		{
			timer[y][x] = 0;
			b[y][x] = '.';
			for (int k = 0; k < 4; k++)
			{
				int tx = x + dx[k];
				int ty = y + dy[k];
				if (tx < 0 || ty < 0 || tx >= c || ty >= r) continue;
				timer[ty][tx] = 0;
				b[ty][tx] = '.';
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << b[i][j];
		}
		cout << '\n';
	}

	return 0;
}