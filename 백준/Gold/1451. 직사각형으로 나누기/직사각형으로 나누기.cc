#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll b[55][55];
ll pfsum[55][55];

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
			char ch;
			cin >> ch;
			b[i][j] = ch - '0';
			pfsum[i][j] = pfsum[i - 1][j] + pfsum[i][j - 1] - pfsum[i - 1][j - 1] + b[i][j];
		}
	}
	ll ans = 0;
	//case 1 가로로 3등분
	if (m >= 3)
	{
		for (int div1 = 1; div1 <= m - 2; div1++)
		{
			for (int div2 = div1 + 1; div2 <= m-1; div2++)
			{
				ll a = pfsum[n][div1];
				ll b = pfsum[n][div2] - pfsum[n][div1];
				ll c = pfsum[n][m] - pfsum[n][div2];
				ans = max(ans, a * b * c);
			}
		}
	}
	//case 2 세로로 3등분
	if (n >= 3)
	{
		for (int div1 = 1; div1 <= n - 2; div1++)
		{
			for (int div2 = div1 + 1; div2 <= n - 1; div2++)
			{
				ll a = pfsum[div1][m];
				ll b = pfsum[div2][m] - pfsum[div1][m];
				ll c = pfsum[n][m] - pfsum[div2][m];
				ans = max(ans, a * b * c);
			}
		}
	}
	//case 3 가로로 2등분 한 다음 앞부분 2등분 -|
	if (n >= 2 && m >=2)
	{
		for (int div1 = 1; div1 <= m - 1; div1++)
		{
			for (int div2 = 1; div2 <= n -1; div2++)
			{
				ll a = pfsum[div2][div1];
				ll b = pfsum[n][div1] - pfsum[div2][div1];
				ll c = pfsum[n][m] - pfsum[n][div1];
				ans = max(ans, a * b * c);
			}
		}
	}
	//case 3 가로로 2등분 한 다음 뒷부분 2등분 |-
	if (n >= 2 && m >= 2)
	{
		for (int div1 = 1; div1 <= m - 1; div1++)
		{
			for (int div2 = 1; div2 <= n - 1; div2++)
			{
				ll a = pfsum[n][div1];
				ll b = pfsum[div2][m] - pfsum[div2][div1];
				ll c = pfsum[n][m] - pfsum[n][div1] - pfsum[div2][m] + pfsum[div2][div1];
				ans = max(ans, a * b * c);
			}
		}
	}
	// case 4 세로로 2등분 한 다음 윗부분 가로 2등분 ㅗ
	if (n >= 2 && m >= 2)
	{
		for (int div1 = 1; div1 <= n - 1; div1++)
		{
			for (int div2 = 1; div2 <= m - 1; div2++)
			{
				ll a = pfsum[div1][div2];
				ll b = pfsum[div1][m] - pfsum[div1][div2];
				ll c = pfsum[n][m] - pfsum[div1][m];
				ans = max(ans, a * b * c);
			}
		}
	}

	// case 4 세로로 2등분 한 다음 윗부분 가로 2등분 ㅜ
	if (n >= 2 && m >= 2)
	{
		for (int div1 = 1; div1 <= n - 1; div1++)
		{
			for (int div2 = 1; div2 <= m - 1; div2++)
			{
				ll a = pfsum[div1][m];
				ll b = pfsum[n][div2] - pfsum[div1][div2];
				ll c = pfsum[n][m] - pfsum[div1][m] - pfsum[n][div2] + pfsum[div1][div2];
				ans = max(ans, a * b * c);
			}
		}
	}

	cout << ans;
	return 0;
}
