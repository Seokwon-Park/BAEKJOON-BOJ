#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, k;
	cin >> c >> k;

	int res = 1;
	while (k--)
	{
		res *= 10;
	}

	int round = 0;
	if (res >= 10)
	{
		round = (c / (res / 10)) % 10;
	}
	int ans = c / res;
	if (round >= 5)ans += 1;
	ans *= res;
	cout << ans;

	return 0;
}