#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll x, y;
	cin >> x >> y;
	x = abs(x);
	y = abs(y);

	while (x != 0 || y != 0)
	{
		int xmod = x % 3;
		int ymod = y % 3;

		if ((xmod + 1) % 3 == 0)
		{
			x++;
		}
		else if ((xmod - 1) % 3 == 0)
		{
			x--;
		}
		else if ((ymod + 1) % 3 == 0)
		{
			y++;
		}
		else if((ymod - 1) % 3 == 0)
		{
			y--;
		}
		else
		{
			cout << 0;
			return 0;
		}

		if (x % 3 != 0 || y % 3 != 0)
		{
			cout << 0;
			return 0;
		}

		x /= 3;
		y /= 3;
	}

	cout << 1;

	return 0;
}