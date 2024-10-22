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

	int n;
	cin >> n;

	ll ans = 0;
	ans += (n * 2 + 1) * (n * 2 + 1);
	for (int a = -n; a <= n; a++)
	{
		if (a == 0) continue;
		for (int b = -n; b <= n; b++)
		{
			int c = 1 - a - b;
			if (c <= n && c >= -n)
				ans++;
		}
	}
	cout << ans;

	return 0;
}