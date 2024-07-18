#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[8][8];
int bc[8][8]; // bcopy
int n;

void flip(int ix, bool isRow)
{
	for (int i = 0; i < 8; i++)
	{
		if (isRow)
		{
			if (bc[ix][i] == 0)
				bc[ix][i] = 1;
			else
				bc[ix][i] = 0;
		}
		else
		{
			if (bc[i][ix] == 0)
				bc[i][ix] = 1;
			else
				bc[i][ix] = 0;
		}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	int ans = INF;
	for (int i = 1; i <= (1 << 16); i++)
	{
		int t = 0;
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				bc[r][c] = b[r][c];
			}
		}
		for (int j = 0; j < 8; j++)
		{
			if ((1 << j) & i)
			{
				flip(j, true);
				t++;
			}
		}
		for (int j = 8; j < 16; j++)
		{
			if ((1 << j) & i)
			{
				flip(j - 8, false);
				t++;
			}
		}
		int one = 0; // 1의 갯수
		int zero = 0;
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				if (bc[r][c] == 1)
					one++;
				else
					zero++;
			}
		}
		ans = min(ans, t + min(one, zero));
	}
	cout << ans;


	return 0;
}
