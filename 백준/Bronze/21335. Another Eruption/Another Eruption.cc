#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a;
	cin >> a;

	a = sqrt(a / acos(-1));
	cout << fixed;
	cout.precision(6);
	cout << a * 2.0 * acos(-1);

	return 0;
}
