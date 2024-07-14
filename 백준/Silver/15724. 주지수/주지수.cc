#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[1025][1025];
int pfsum[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			pfsum[i][j] = pfsum[i - 1][j] + pfsum[i][j - 1] - pfsum[i - 1][j - 1] + b[i][j];
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pfsum[x2][y2] - pfsum[x1 - 1][y2] - pfsum[x2][y1 - 1] + pfsum[x1 - 1][y1 - 1] << '\n';
	}


	return 0;
}