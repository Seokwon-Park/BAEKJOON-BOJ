#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

double v[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
	{
		cin >> v[i];
	}

	sort(v, v+10, greater<double>());

	double ans = 1;

	for (int i = 0; i < 9; i++)
	{
		ans *= v[i] / (i + 1);
	}
	cout << fixed;
	cout.precision(6);
	cout << ans * 1e9;

	return 0;
}