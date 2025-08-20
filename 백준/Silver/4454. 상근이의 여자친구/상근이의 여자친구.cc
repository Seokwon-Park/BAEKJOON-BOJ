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

double a, b, c, d, m, t;
bool solve(double mid)
{
	return (a * mid * mid * mid +
		b * mid * mid +
		c * mid +
		d) * m <= t;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> a >> b >> c >> d >> m >> t)
	{
		double st = 0.0f;
		double en = 1e10;

		for (int i = 0; i < 400; i++)
		{
			double mid = (st + en) / 2.0;
			if (solve(mid))
			{
				st = mid;
			}
			else
			{
				en = mid;
			}
		}

		double result = floor(st * 100.0) / 100.0;
		cout << fixed << setprecision(2) << result << '\n';
	}

	return 0;
}