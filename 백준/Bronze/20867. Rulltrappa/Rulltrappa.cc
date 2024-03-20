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
	
	double m, s, g;
	cin >> m >> s >> g;
	double a, b;
	cin >> a >> b;
	double l, r;
	cin >> l >> r;

	double lt = 1.0 / a * l + m / g;
	double rt = 1.0 / b * r + m / s;

	if (rt < lt)
		cout << "latmask";
	else
		cout << "friskus";


	return 0;
}
