#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;



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
		cout << fixed;
		cout << setprecision(2);
		cout << '$';
		cout << 350.34 * a + 230.9 * b + 190.55 * c + 125.30 * d + 180.90 * e << '\n';
	}

	return 0;
}