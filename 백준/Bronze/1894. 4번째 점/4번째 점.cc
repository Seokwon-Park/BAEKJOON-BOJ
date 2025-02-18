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

	double a, b, c, d, e, f, g, h;
	while (cin >> a >> b >> c >> d >> e >> f >> g >> h)
	{
		double dx;
		double dy;
		cout << fixed << setprecision(3);
		if (a == e && b == f)
		{
			dx = c - a;
			dy = d - b;
			cout << g + dx << ' ' << h + dy << '\n';
		}
		else if (a == g && b == h)
		{
			dx = c - a;
			dy = d - b;
			cout << e + dx << ' ' << f + dy << '\n';
		}
		else if (c == e && d == f)
		{
			dx = a - c;
			dy = b - d;
			cout << g + dx << ' ' << h + dy << '\n';
		}
		else // c== g && d== h
		{
			dx = a - c;
			dy = b - d;
			cout << e + dx << ' ' << f + dy << '\n';;
		}

	}

	return 0;
}



