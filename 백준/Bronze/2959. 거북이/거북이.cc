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

	vi v(4);
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	cout << min(v[0], v[1]) * min(v[2], v[3]);

	return 0;
}
