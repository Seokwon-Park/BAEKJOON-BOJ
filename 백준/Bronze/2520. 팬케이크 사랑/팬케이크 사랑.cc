#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		double a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;

		int f = min({ a / 8, b / 8, c / 4, d, e / 9 }) * 16;

		int g, h, i, j;
		cin >> g >> h >> i >> j;
		int can_make = g + h / 30 + i / 25 + j / 10;

		cout << min(f, can_make) << '\n';
	}



	return 0;
}