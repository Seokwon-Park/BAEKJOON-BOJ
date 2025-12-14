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

bool board[150][150];
bool other[50][50];
bool cpy[50][50];

int n, m, r, c;

bool compare(int sr, int sc)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[sr + i][sc + j] == other[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void rotate()
{
	memcpy(cpy, other, sizeof(cpy));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			other[j][r - i - 1] = cpy[i][j];
		}
	}
	swap(r, c);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);



	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			board[50 + i][50 + j] = c - '0';
		}
	}

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char c;
			cin >> c;
			other[i][j] = c - '0';
		}
	}

	int ans = INF;
	for (int rot = 0; rot < 4; rot++)
	{
		for (int i = 0; i <= 100; i++)
		{
			for (int j = 0; j <= 100; j++)
			{
				if (compare(i, j))
				{
					int rs = i;
					int cs = j;
					int re = i + r;
					int ce = j + c;

					int ns = 50;
					int ms = 50;
					int ne = 50 + n;
					int me = 50 + m;

					int sx = min(cs, ms);
					int sy = min(rs, ns);
					int ex = max(ce, me);
					int ey = max(re, ne);

					
					ans = min(ans, (ex-sx) * (ey-sy));
				}
			}
		}
		rotate();
	}

	cout << ans;


	return 0;
}
