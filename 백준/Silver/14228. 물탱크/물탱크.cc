#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

double n, c;
double t[1000005];
double x[1000005];

bool isSafe(double mid)
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result += (x[i] - mid)* t[i];
		result = max(0.0, result);
		if (result > c)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	double st = 0;
	double en = INF;
	while (en - st > 1e-9)
	{
		double mid = (st + en) / 2;
		if (isSafe(mid))
		{
			en = mid;
		}
		else
		{
			st = mid;
		}
	}
	cout << fixed << setprecision(9);
	cout << st;

	return 0;
}