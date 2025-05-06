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

	double pi = acos(-1);
	double d, h;
	cin >> d >> h;
	double r = d / 2.0 + 5.0;
	double ans = r * r * pi + 2 * pi * r * h;
	
	cout << fixed << setprecision(6) << ans;


	return 0;
}