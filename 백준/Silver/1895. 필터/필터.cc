#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[45][45];
int a[45][45];

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
	int t;
	cin >> t;
	for (int i = 0; i < r-2; i++)
	{
		for (int j = 0; j < c - 2; j++)
		{
			vector<int> v;
			for (int x = 0; x < 3; x++)
			{
				for(int y = 0; y <3; y++)
				{
					v.push_back(b[i + x][j + y]);
				}
			}
			sort(v.begin(), v.end());
			a[i][j] = v[4];
		}
	}

	int ans = 0;
	for (int i = 0; i < r - 2; i++)
	{
		for (int j = 0; j < c - 2; j++)
		{
			if (a[i][j] >= t)
				ans++;
		}
	}
	cout << ans;

	return 0;
}