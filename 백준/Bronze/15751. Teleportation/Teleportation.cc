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

	int a, b, x, y;
	cin >> a >> b >> x >> y;
	if (a > b)
		swap(a, b);
	if (x > y)
		swap(x, y);
	int ans = b - a;
	ans = min(ans, abs(a - x) + abs(b - y));

	cout << ans;

	return 0;
}