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
	
	int a, b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		if (a + b + c + d == 0) break;
		if (a == 0)
		{
			a = d / b / c;
		}
		if (b == 0)
		{
			b = d / a / c;
		}
		if (c == 0)
		{
			c = d / a / b;
		}
		if (d == 0)
		{
			d = a * b * c;
		}
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}

	
	return 0;
}
