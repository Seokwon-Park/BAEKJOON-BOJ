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

	int n;
	double t;
	cin >> n >> t;
	vector<double> x(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	vector<double> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	double mn = -1e18;
	double mx = 1e18;

	for (int i = 0; i < n; i++)
	{
		mn = max(mn, x[i] - v[i] * t);
		mx = min(mx, x[i] + v[i] * t);
	}
	if (mn < mx+1e-9)
		cout << 1;
	else
		cout << 0;

	return 0;
}