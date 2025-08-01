
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll m, seed, x1, x2;
	cin >> m >> seed >> x1 >> x2;
	ll a = 0;
	for (int i = 0; i < m; i++)
	{
		ll x = x2 - x1;
		x = x < 0 ? x + m : x;
		ll y = ((x1 - seed) * i) % m;
		y = y < 0 ? y + m: y;
		if (x == y)
		{
			a = i;
			break;
		}
	}

	ll c = x1 - (a * seed) % m;
	c = c < 0 ? c + m : c;
	cout << a << ' ' << c;

	return 0;
}