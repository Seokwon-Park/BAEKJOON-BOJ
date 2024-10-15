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

	int n, k;
	cin >> n >> k;

	n *= 1000;
	k *= 1000;
	int ans = 0;
	if (k + k / 2 + k / 4 <= n)
	{
		ans = max(ans, k + k / 2 + k / 4);
	}
	if (k * 2 + k + k / 2 <= n)
	{
		ans = max(ans, k * 2 + k + k / 2);
	}
	if (k * 7 <= n)
	{
		ans = max(ans, k * 7);
	}

	cout << ans;

	return 0;
}