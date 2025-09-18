#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll x, y;
	cin >> x >> y;
	ll z = x + y;

	while (x)
	{
		if (x % 3 == 2)
		{
			cout << 0;
			return 0;
		}
		x /= 3;
	}

	while (y)
	{
		if (y % 3 == 2)
		{
			cout << 0;
			return 0;
		}
		y /= 3;
	}

	while (z)
	{
		if (z % 3 != 1)
		{
			cout << 0;
			return 0;
		}
		z /= 3;
	}

	cout << 1;

	return 0;
}