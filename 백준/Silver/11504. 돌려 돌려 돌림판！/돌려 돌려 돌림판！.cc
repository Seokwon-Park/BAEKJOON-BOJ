#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		int x = 0;
		for (int i = 0; i < m; i++)
		{
			int xi;
			cin >> xi;
			x = x * 10 + xi;
		}
		int y = 0;
		for (int i = 0; i < m; i++)
		{
			int yi;
			cin >> yi;
			y = y * 10 + yi;
		}
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int res = 0;
			for (int j = 0; j < m; j++)
			{
				res = res * 10 + v[(i + j)%n];
			}
			if (res <= y && res >= x)
				ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}
