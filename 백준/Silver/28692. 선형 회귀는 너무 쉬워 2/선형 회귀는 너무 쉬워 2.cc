#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll sx = 0, sy = 0, sxx = 0, sxy = 0;

	for (int i = 0; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		sx += x;
		sy += y;
		sxx += x * x;
		sxy += x * y;
	}

	if (sx*sx == n*sxx)
	{
		cout << "EZPZ";
		return 0;
	}
	double a2 = (n * sxy - sx * sy) / (double)(n * sxx - sx * sx);
	double b2 = (sy - a2 * sx) / (double)n;

	cout << fixed << setprecision(6) << a2 << ' ' << b2;

	return 0;
}