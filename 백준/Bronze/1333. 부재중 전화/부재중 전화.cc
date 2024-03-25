#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, l, d;
	cin >> n >> l >> d;
	// l<= time < l+5;
	int ans = d;
	int mod = (ans % (l + 5) == 0? l+5: ans%(l+5));
	int mx = (n-1) * (l + 5) +l;
	while (mod < l || l + 5 <= mod)
	{
		if (ans >= mx) break;
		ans += d;
		mod = (ans % (l + 5) == 0 ? l + 5 : ans % (l + 5));
	}
	cout << ans;

	return 0;
}