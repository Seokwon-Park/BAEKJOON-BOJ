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

	const double PI = acos(-1.0);
	double n;
	cin >> n;
	// n = pi* r^2;
	double r = sqrt(n / PI);
	cout << fixed;
	cout.precision(6);
	cout << 2.0 * r * PI;

	return 0;
}