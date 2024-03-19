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

	double a, b;
	cin >> a >> b;
	double m = (b - a) / 400;
	double ans = 1 / (1 + pow(10.0, m));
	cout << ans;


	return 0;
}