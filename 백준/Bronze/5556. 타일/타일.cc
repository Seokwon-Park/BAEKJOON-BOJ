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

	int n;
	cin >> n;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (x >= n / 2)
		{
			x = n - 1 - x;
		}
		if (y >= n / 2)
		{
			y = n - 1 - y;
		}

		int res = min(x, y);

		cout << res % 3 + 1;
		cout << '\n';
		//(0, 3)
		// 0, 1, 2, 3
		// 0 ,1, 1, 0
		// 
		// 0, 1, 2, 3, 4
		// 0 ,1, 2, 1, 0



	}

	return 0;
}