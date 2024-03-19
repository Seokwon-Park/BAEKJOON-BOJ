#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	
	int dec = 1;
	int k = 1;
	ll ans = 0;
	while (n >= dec * 10 - 1)
	{
		ans += (dec * 9) * k;
		dec *= 10;
		k++;
	}
	ans += (n - dec + 1) * k;

	cout << ans;

	return 0;
}
