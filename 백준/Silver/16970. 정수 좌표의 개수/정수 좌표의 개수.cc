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

	int n, m, k;
	cin >> n >> m >> k;

	int res = 0;
	for (int x1 = 0; x1 <= n; x1++)
	{
		for (int y1 = 0; y1 <= m; y1++)
		{
			for (int x2 = 0; x2 <= n; x2++)
			{
				for (int y2 = 0; y2 <= m; y2++)
				{
					int w = abs(x2 - x1);
					int h = abs(y2 - y1);
					int g = gcd(w, h);
					if (g + 1 == k)
						res++;
				}
			}
		}
	}
	cout << res/2;


	return 0;
}