#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	if (a == 0 || b == 0)
	{
		cout << 0;
		return 0;
	}
	ll l = lcm(a, b);
	ll c = (l / b) + (l / a);
	cout << l / c;
}