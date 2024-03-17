#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vi v(n);
	for (auto& i : v)
		cin >> i;

	int b, c;
	cin >> b >> c;

	ll ans = 0;
	
	for (auto i : v)
	{
		ll imb = (ll)max(i - b, 0);
		ans += imb / c + (imb % c == 0 ? 0 : 1)+1;
	}
	cout << ans;

	return 0;
}