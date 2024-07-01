#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int a[105][105];
int b[105][105]; // 영역나누기 테스팅용.
int n;
int total;

// 주의할점 x가 row y가 col임
int func(int x, int y, int d1, int d2)
{
	vector<int> popul(5, 0);
	int five = total;
	for (int r = 1; r < x+d1; r++)
	{
		int tmp = 0;
		if (r >= x)
			tmp = r - x + 1;
		for (int c = 1; c <= y-tmp; c++)
		{
			b[r][c] = 1;
			popul[0] += a[r][c];
			five -= a[r][c];
		}
	}

	for (int r = 1; r <= x + d2; r++)
	{
		int tmp = 0;
		if (r > x)
			tmp = r - x;
		for (int c = y+1+tmp; c <= n; c++)
		{
			b[r][c] = 2;
			popul[1] += a[r][c];
			five -= a[r][c];

		}
	}

	for (int r = x+d1; r <= n; r++)
	{
		int tmp = min(y - d1 + r - x - d1, y - d1 + d2);
		for (int c = 1; c < tmp; c++)
		{
			b[r][c] = 3;
			popul[2] += a[r][c];
			five -= a[r][c];

		}
	}

	for (int r = x+d2+1; r <= n; r++)
	{
		int tmp = r-x-d2 + n-(y+d2);
		for (int c = max(n-tmp+1, y-d1+d2); c <= n; c++)
		{
			b[r][c] = 4;
			popul[3] += a[r][c];
			five -= a[r][c];
		}
	}

	popul[4] = five;
	sort(popul.begin(), popul.end());

	return abs(popul[0] - popul[4]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			total += a[i][j];
		}
	}

	
	int ans = INT_MAX;
	for (int d1 = 1; d1 <= n; d1++)
	{
		for (int d2 = 1; d2 <= n; d2++)
		{
			for (int x = 1; x <= n; x++)
			{
				for (int y = 1; y <= n; y++)
				{
					if (x + d1 + d2 > n) continue;
					if (y - d1 <1 || y + d2 >n) continue;
					ans = min(ans, func(x, y, d1, d2));
				}
			}
		}
	}

	cout << ans;

	return 0; 
}