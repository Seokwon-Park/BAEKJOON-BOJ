#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a, b, c;
	cin >> a >> b >> c;
	a *= 0.229 * 0.324 *2;
	b *= 0.297 * 0.420 *2;
	c *= 0.210 * 0.297;

	cout << fixed;
	cout.precision(3);
	cout << a + b + c;

	return 0;
}