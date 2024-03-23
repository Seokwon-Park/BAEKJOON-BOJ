#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d;
	int p, m, n;
	cin >> a >> b >> c >> d;
	cin >> p >> m >> n;
	int r1 = a + b;
	int r2 = c + d;
	cout << (p % r1 <= a && p%r1 != 0? 1 : 0) + (p % r2 <= c && p % r2 != 0 ? 1 : 0) << '\n'
		<< (m % r1 <= a && m % r1 != 0 ? 1 : 0) + (m % r2 <= c && m % r2 != 0 ? 1 : 0) << '\n'
		<< (n % r1 <= a && n % r1 != 0 ? 1 : 0) + (n % r2 <= c && n % r2 != 0 ? 1 : 0);


	return 0;
}