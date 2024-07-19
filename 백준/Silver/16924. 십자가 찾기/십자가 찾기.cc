#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int n, m;
char b[105][105];
char comp[105][105];


int make_cross(int x, int y)
{
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	int len = 1;
	while (1)
	{
		bool canCross = true;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i]*len;
			int ty = y + dy[i]*len;
			if (tx < 0 || ty < 0 || tx >= m || ty >= n || b[ty][tx] == '.')
			{
				canCross = false;
				break;
			}
		}
		if (canCross == false)
		{
			len -= 1;
			break;
		}
		len++;
	}
	if (len == 0)
		return -1;
	else
	{
		comp[y][x] = '*';
		for(int j = 1; j<=len ;j++)
		{
			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i] * j;
				int ty = y + dy[i] * j;
				comp[ty][tx] = '*';
			}
		}
		return len;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		fill(comp[i], comp[i] + m, '.');
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	vector<vector<int>> ans;
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 1; j < m-1; j++)
		{
			if (b[i][j] == '*')
			{
				int len = make_cross(j, i);
				if (len != -1)
				{
					ans.push_back({ i+1, j+1, len });
				}
			}
		}
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << comp[i][j];
	//	}
	//	cout << '\n';
	//}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] != comp[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto vec : ans)
	{
		for (auto i : vec)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}