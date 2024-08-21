#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll h[300005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;
	cin >> n >> d;

	int target = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		h[m]++;
		if (m > target)
			target = m;
	}

	ll ans = 0;
	for (int i = 0; i < d; i++)
	{
		if (target == 0) break;
		ans += h[target];
		target--;
		h[target] += h[target + 1];
		h[target + 1] = 0;
	}

	cout << ans;

	return 0;
}