#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	double x, y, d, t;
	cin >> x >> y >> d >> t;
	double dist = sqrt(x * x + y * y);
	
	double j = (int)(dist / d);
	double dt = 0.0;

	if (dist >= d)
	{
		dt += min({ t * (j + 1), dist, t * j + dist - (d * j) });
	}
	else
	{
		dt += min({dist, t * 2, t + (d - dist)});
	}

	cout << fixed << setprecision(9);
	cout << dt;

	return 0;
}