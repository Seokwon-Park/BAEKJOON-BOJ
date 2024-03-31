#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int st, ed;
	cin >> st >> ed;
	int ix = 1;
	int n = 1;
	while (ix < 1005)
	{
		for (int i = 0; i < n; i++)
		{
			a[ix] = n;
			ix++;
			if (ix >= 1005) break;
		}
		n++;
	}

	int ans = 0;
	for (int i = st; i <= ed; i++)
	{
		ans += a[i];
	}

	cout << ans;

	return 0;
}