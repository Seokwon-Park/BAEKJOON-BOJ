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

ll a, b, l, k;
ld p, q;

bool func(ld x, ld y, ld len, int cur)
{
	if (cur == l)
	{
		return true;
	}
	ld unit = len / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) continue;
			if (p >= x + unit * i && p <= x + unit * (i + 1) &&
				q >= y + unit * j && q <= y + unit * (j + 1))
			{
				return func(x + unit * i, y + unit * j, unit, cur + 1);
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> l >> k >> p >> q;
		ld len = 1.0;
		while (k--)
		{
			len *= 3.0;
		}
		p -= a;
		q -= b;
		if (p < 0.0 || q < 0.0 || p >len || q > len)
			cout << 0 << '\n';
		else
			cout << func(0, 0, len, 0) << '\n';
	}


	return 0;
}