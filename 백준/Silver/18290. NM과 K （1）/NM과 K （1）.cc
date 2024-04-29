#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int b[12][12];
bool selected[12][12];
int n, m, k;
int ans = INT_MIN;

void func(int x, int val)
{
	if (x == k)
	{
		ans = max(ans, val);
		return;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (selected[i][j]||
				selected[i + 1][j] ||
				selected[i - 1][j] ||
				selected[i][j + 1] ||
				selected[i][j - 1]) continue;
			selected[i][j] = true;
			func(x + 1, val + b[i][j]);
			selected[i][j] = false;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> b[i][j];

	func(0, 0);

	cout << ans;

	return 0;
}