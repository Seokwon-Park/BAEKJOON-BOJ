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

	double a, b, x;
	cin >> a >> b >> x;

	if (a > b)
		swap(a, b);
	double ans = 100 /(x / b + (100 - x) / a);
	cout << fixed << setprecision(6);
	cout << ans;
	

	return 0;
}
