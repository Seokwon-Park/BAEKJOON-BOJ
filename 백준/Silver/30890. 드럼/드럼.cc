#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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

	int x, y;
	cin >> x >> y;

	int l = lcm(x, y);

	int xx = l / x;
	int yy = l / y;

	for (int i = 1; i <= l; i++)
	{
		if (!(i % xx) && !(i % yy))
		{
			cout << 3;
		}
		else if (!(i % xx))
		{
			cout << 1;
		}
		else if (!(i % yy))

		{
			cout << 2;
		}
	}

	return 0;
}