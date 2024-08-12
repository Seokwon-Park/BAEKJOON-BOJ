#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int n;
double l, w, h;

bool solve(double mid)
{
	ll res = (ll)floor(l / mid) * (ll)floor(w / mid) * (ll)floor(h / mid);
	return res >= n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> l >> w >> h;

	double st = 0;
	double en = 1'000'000'000;

	for(int i = 0; i< 10000; i++)
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
	cout << fixed << setprecision(9);
	cout << st;
	

	return 0;
}