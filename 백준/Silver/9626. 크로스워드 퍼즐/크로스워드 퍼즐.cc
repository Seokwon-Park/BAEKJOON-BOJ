#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

char b[10][10];
char ans[20][20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int u, l, r, d;
	cin >> u >> l >> r >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	string pattern = "#.";
	for (int i = 0; i < u + n + d; i++)
	{
		int st = i % 2;
		for (int j = 0; j < l + m + r; j++)
		{
			ans[i][j] = pattern[(st + j) % 2];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans[u + i][l + j] = b[i][j];
		}
	}

	for (int i = 0; i < u + n + d; i++)
	{
		for (int j = 0; j < l + m + r; j++)
		{
			cout << ans[i][j];
		}
		cout << '\n';
	}




	return 0;
}
