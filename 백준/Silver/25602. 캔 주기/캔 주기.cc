#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n, k;
int a[10];
int r[10][10];
int m[10][10];
int ans = 0;
int cur = 0;

void func(int x)
{
	if (x == k)
	{
		ans = max(ans, cur);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] <= 0) continue;
			a[i]--;
			if (a[j] <= 0)
			{
				a[i]++;
				continue;
			}
			a[j]--;
			cur += r[x][i] + m[x][j];
			func(x + 1);
			cur -= r[x][i] + m[x][j];
			a[i]++;
			a[j]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> r[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
		}
	}

	func(0);
	
	cout << ans;

	return 0;
}