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

int b[8][7];
bool checked[8][7];

bool isUsed[7][7];
int ans;

void func(int r, int c)
{
	if (r == 8 && c == 0)
	{
		ans++;
		return;
	}
	if (checked[r][c])
	{
		if (c + 1 >= 7)
		{
			func(r+1, 0);
		}
		else
		{
			func(r, c+1);
		}
	}
	else
	{
		if (r + 1 < 8 && !checked[r + 1][c])
		{
			int x = b[r][c];
			int y = b[r + 1][c];

			if (x > y) swap(x, y);
			if (!isUsed[x][y])
			{
				checked[r][c] = true;
				checked[r + 1][c] = true;
				isUsed[x][y] = true;
				int nc = c+1;
				int nr = r;
				if (nc >= 7)
				{
					nc = 0;
					nr++;
				}
				func(nr, nc);
				checked[r][c] = false;
				checked[r + 1][c] = false;
				isUsed[x][y] = false;
			}
		}

		if (c + 1 < 7 && !checked[r][c + 1])
		{
			int x = b[r][c];
			int y = b[r][c + 1];

			if (x > y) swap(x, y);
			if (!isUsed[x][y])
			{
				checked[r][c] = true;
				checked[r][c + 1] = true;
				isUsed[x][y] = true;
				int nc = c+1;
				int nr = r;
				if (nc >= 7)
				{
					nc = 0;
					nr++;
				}
				func(nr, nc);
				checked[r][c] = false;
				checked[r][c + 1] = false;
				isUsed[x][y] = false;
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 8; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			int x = s[j] - '0';
			b[i][j] = x;
		}
	}

	func(0, 0);
	cout << ans;

	return 0;
}