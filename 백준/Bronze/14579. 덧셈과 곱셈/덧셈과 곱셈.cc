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

	int a, b;
	cin >> a >> b;
	ll ans = 1;
	for (int i = a; i <= b; i++)
	{
		ans *= i * (i + 1) / 2;
		ans %= 14579;
	}

	cout << ans;


	return 0;
}