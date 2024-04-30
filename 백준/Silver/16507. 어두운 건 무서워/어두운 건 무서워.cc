#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[1005][1005];
int pfsum[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int r, c, q;
	cin >> r >> c >> q;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			pfsum[i][j] = pfsum[i - 1][j] + pfsum[i][j - 1] + b[i][j] - pfsum[i-1][j-1];
		}
	}


	while(q--)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int m = (r2 - r1 + 1) * (c2 - c1 + 1);
		int res = pfsum[r2][c2] - pfsum[r1-1][c2] - pfsum[r2][c1-1] + pfsum[r1-1][c1-1];
		cout << res/m << '\n';
	}

	return 0;
}