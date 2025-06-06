#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		int l = lcm(a, b);
		int mn = min(a, b);
		int mx = max(a, b);

		int x = -1, y = -1;
		for (int i = 0; i < l / mn; i++)
		{
			if ((c - mn * i) % mx == 0)
			{
				x = i;
				y = (c - mn * i) / mx;
			}
		}

		if (x < 0 || y < 0)
		{
			cout << "Impossible";
		}
		else
		{
			if (a < b)
			{
				cout << x << ' ' << y;
			}
			else
			{
				cout << y << ' ' << x;
			}
		}
		cout << '\n';
	}

	return 0;
}