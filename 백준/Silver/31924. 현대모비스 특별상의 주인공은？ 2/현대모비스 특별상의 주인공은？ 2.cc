#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

char board[105][105];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

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
			cin >> board[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int dir = 0; dir < 8; dir++)
			{
				string res = "";
				bool chk = false;
				for (int k = 0; k < 5; k++)
				{
					int tx = j + dx[dir] * k;
					int ty = i + dy[dir] * k;
					if (tx < 0 || ty < 0 || tx >= n || ty >= n)
					{
						chk = true;
						break;
					}
					res += board[ty][tx];
				}
				if (!chk)
				{
					if (res == "MOBIS")
						ans++;

				}
			}
		}
	}

	cout << ans;

	return 0;
}