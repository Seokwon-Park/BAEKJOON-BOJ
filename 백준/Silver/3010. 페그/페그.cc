#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

char b[7][7];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i <= 1; i++)
	{
		for (int j = 2; j <=4; j++)
		{
			cin >> b[i][j];
		}
	}
	for (int i = 2; i <= 4; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			cin >> b[i][j];
		}
	}
	for (int i = 5; i <= 6; i++)
	{
		for (int j = 2; j <= 4; j++)
		{
			cin >> b[i][j];
		}
	}


	int ans = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (b[i][j] == '.')
			{
				for (int k = 0; k < 4; k++)
				{
					int x = j + dx[k];
					int y = i + dy[k];
					int xx = j + dx[k] * 2;
					int yy = i + dy[k] * 2;
					if (x < 0 || y < 0 || x >= 7 || y >= 7 ||
						xx < 0 || yy < 0 || xx >= 7 || yy >= 7) continue;
					if (b[y][x] != 'o' || b[yy][xx] != 'o')continue;
					ans++;
				}
			}
		}
	}
	cout << ans;

	return 0;
}