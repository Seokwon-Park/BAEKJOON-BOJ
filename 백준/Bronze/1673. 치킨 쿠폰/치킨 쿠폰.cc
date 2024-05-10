#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	while (cin >> n >> k)
	{
		int ans = n;
		int coupon = n;
		while (coupon >= k)
		{
			ans += coupon / k;
			coupon = coupon % k + coupon / k;
		}
		cout << ans << '\n';
	}

	return 0;
}