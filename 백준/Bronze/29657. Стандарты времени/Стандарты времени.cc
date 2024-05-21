#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int h, m, s;
	cin >> h >> m >> s;

	int hh = 0, mm = 0, ss = 0;
	int res = h * b * c + m * c + s;
	hh = (res / (e * f)) % d;
	res %= e * f;
	mm = res / f;
	res %= f;
	ss = res;
	cout << hh << ' ' << mm << ' ' << ss;

	return 0;
}
