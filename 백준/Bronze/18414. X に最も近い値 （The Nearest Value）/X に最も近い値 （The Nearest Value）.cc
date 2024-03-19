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

	int x, l, r;
	cin >> x >> l >> r;
	if (x < l)
		cout << l;
	else if (x > r)
		cout << r;
	else
		cout << x;

	return 0;
}