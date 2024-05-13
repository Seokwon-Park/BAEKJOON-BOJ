#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll k;
	cin >> k;
	ll ans = 0;
	for (int i = 0; i < (k - 1) / 5; i++)
	{
		ans += (i + 1) * 30 * 5;
	}
	ans += ((k - 1) / 5 + 1) * 30 * ((k-1) % 5+1);
	cout << ans;

	return 0;
}
