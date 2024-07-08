#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

char b[105][105];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (1)
	{
		int r, c;
		cin >> r >> c;
		if (r == 0 && c == 0)break;
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
				if (b[i][j] == '*')
				{
					cout << b[i][j];
					continue;
				}
				int res = 0;
				for (int k = 0; k < 8; k++)
				{
					int tx = j + dx[k];
					int ty = i + dy[k];
					if (tx < 0 || ty < 0 || tx >= c || ty >= r)continue;
					if (b[ty][tx] == '*')res++;
				}
				cout << res;
			}
			cout << '\n';
		}
	}


	return 0;
}